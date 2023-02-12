/**
 * Expansion_GraveBase.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2022 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class Expansion_GraveBase extends Inventory_Base
{
	protected bool m_ReceivedAttachments;
	protected int m_FliesIndex = -1;

	protected ref EffectParticle m_FliesEffect;
	protected ref EffectSound m_SoundFliesEffect;

	void Expansion_GraveBase()
	{
		RegisterNetSyncVariableBool("m_ReceivedAttachments");
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();


		// disabling flies effect for now, they might be a tad annoying...

		/* if (!m_FliesEffect)
			m_FliesEffect = new EffSwarmingFlies();
				
		if (m_FliesEffect && !SEffectManager.IsEffectExist(m_FliesIndex))
		{
			m_FliesEffect.SetDecalOwner(this);
			m_FliesIndex = SEffectManager.PlayOnObject(m_FliesEffect, this, "0 0.25 0");

			Particle part = m_FliesEffect.GetParticle();
			AddChild(part, -1);

			if (!m_SoundFliesEffect)
				PlaySoundSetLoop(m_SoundFliesEffect, "Flies_SoundSet", 1.0, 1.0);
		} */
	}

	override void EEDelete(EntityAI parent)
	{
		if (m_FliesEffect)
			m_FliesEffect.Stop();

		if (m_SoundFliesEffect)
			StopSoundSet(m_SoundFliesEffect);
	}

	#ifdef EXPANSION_MODSTORAGE
	override void CF_OnStoreSave(CF_ModStorageMap storage)
	{
		super.CF_OnStoreSave(storage);

		auto ctx = storage[DZ_Expansion];
		if (!ctx) return;

		ctx.Write(m_ReceivedAttachments);
	}
	
	override bool CF_OnStoreLoad(CF_ModStorageMap storage)
	{
		if (!super.CF_OnStoreLoad(storage))
			return false;

		auto ctx = storage[DZ_Expansion];
		if (!ctx) return true;

		if (!ctx.Read(m_ReceivedAttachments))
			return false;

		return true;
	}
	#endif

	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}

	override bool CanPutInCargo(EntityAI parent)
	{
		return false;
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if (m_ReceivedAttachments)
			return false;

		return super.CanReceiveAttachment(attachment, slotId);
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);

		if (GetInventory().AttachmentCount() < 1)
			Delete();
	}

	void MoveAttachmentsFromEntity(EntityAI entity, EntityAI handEntity, vector ground, vector orientation)
	{
		for (int i = 0; i < entity.GetInventory().GetAttachmentSlotsCount(); i++)
		{
			int slot = entity.GetInventory().GetAttachmentSlotId(i);
			EntityAI item = entity.GetInventory().FindAttachment(slot);

			if ( item )
				AddItem(entity, item, ground, orientation);
		}

		if ( handEntity )
			AddItem(handEntity, handEntity, ground, orientation);

		m_ReceivedAttachments = true;
		SetSynchDirty();
	}
	
	void AddItem(EntityAI entity, EntityAI item, vector ground, vector orientation)
	{
		float health;

		if (GetGame().IsServer())
		{
			health = item.GetHealth();
			item.SetHealth(item.GetMaxHealth()); // set item to max health, so we can move ruined items
		}

		if (GetInventory().CanAddAttachment(item))
		{
			if (GetGame().IsMultiplayer())
				ServerTakeEntityToInventory( FindInventoryLocationType.ATTACHMENT, item );
			else
				entity.LocalTakeEntityToTargetInventory(this, FindInventoryLocationType.ATTACHMENT, item);
		}
		else
		{
			if (GetGame().IsMultiplayer())
				entity.GetInventory().DropEntity(InventoryMode.SERVER, entity, item);
			else
				entity.GetInventory().DropEntity(InventoryMode.LOCAL, entity, item);

			item.SetPosition(ground);
			item.SetOrientation(orientation);
		}

		if (GetGame().IsServer())
			item.SetHealth(health);
	}
}

class Expansion_Gravecross extends Expansion_GraveBase {}
class Expansion_Gravecross_LowLifetime extends Expansion_GraveBase {}