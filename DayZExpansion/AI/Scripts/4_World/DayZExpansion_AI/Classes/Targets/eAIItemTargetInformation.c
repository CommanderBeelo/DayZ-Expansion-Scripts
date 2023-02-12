class eAIItemTargetInformation extends eAIEntityTargetInformation
{
	private ItemBase m_Item;

	void eAIItemTargetInformation(EntityAI target)
	{
		Class.CastTo(m_Item, target);
	}

	override bool IsActive()
	{
		if (!super.IsActive())
			return false;

		return m_Item.GetHierarchyRootPlayer() == null;
	}

	//! @note not using state cache for item targets as they wouldn't be removed from it
	override vector GetPosition(eAIBase ai = null, bool actual = false)
	{
		return m_Item.GetPosition();
	}

	//! @note not using state cache for item targets as they wouldn't be removed from it
	override float GetThreat(eAIBase ai = null)
	{
#ifdef EAI_TRACE
		auto trace = CF_Trace_1(this, "GetThreat").Add(ai);
#endif

		if (m_Item.GetHealth("", "") <= 0.0)
			return 0.0;

		if (m_Item.GetHierarchyRootPlayer())
			return 0.0;  //! Has been picked up since we last saw it

		if (ai)
		{
			bool canBandage = ai.IsBleeding() && m_Item.Expansion_CanBeUsedToBandage();

			Magazine targetMag;

			if (canBandage && ai.GetBandageToUse())
			{
				//! Don't need to pick up bandage if AI already has one in inventory
				return 0.0;
			}
			else if (m_Item.IsWeapon() || m_Item.Expansion_IsMeleeWeapon() || canBandage || (Class.CastTo(targetMag, m_Item) && targetMag.GetAmmoCount()))
			{
				ItemBase itemInHands = ai.GetItemInHands();
				Weapon_Base gunInHands;

				if (!canBandage && itemInHands && !itemInHands.IsDamageDestroyed())
				{
					if (Class.CastTo(gunInHands, itemInHands))
					{
						if (gunInHands.Expansion_HasAmmo())
							return 0.0;
					}
					else if (itemInHands.Expansion_IsMeleeWeapon() && m_Item.Expansion_IsMeleeWeapon())
					{
						return 0.0;
					}
				}

				//! Ignore magazines and ammo if AI has no gun
				if (m_Item.IsMagazine() && !gunInHands && !ai.GetWeaponToUse())
					return 0.0;

				Weapon_Base gun;
				if (Class.CastTo(gun, m_Item))
				{
					Magazine mag;

					//! Ignore guns we don't have ammo for so we don't keep picking up guns that we can't use
					if (!ai.eAI_HasAmmoForFirearm(gun, mag, false))
						return 0.0;
				}

				float distance = GetDistanceSq(ai, true);
				if (distance < 0.001)
					distance = 0.001;

				float q;
				if (m_Item.IsWeapon())
				{
					q = 1000000;
				}
				else if (m_Item.IsAmmoPile())
				{
					q = 1000;
				}
				else if (m_Item.Expansion_IsMeleeWeapon() || m_Item.IsMagazine())
				{
					q = 10000;
				}
				else
				{
					distance = Math.Sqrt(distance);
					q = 12;  //! Threat level 0.4 at 30 m
				}

				return q / distance;
			}
		}

		return 0.0;
	}

	override float CalculateThreat(eAIBase ai = null)
	{
		Error("eAIItemTargetInformation::CalculateThreat should not be called!");

		return 0.0;
	}

	override bool ShouldRemove(eAIBase ai = null)
	{
#ifdef EAI_TRACE
		auto trace = CF_Trace_1(this, "ShouldRemove").Add(ai);
#endif

		return GetThreat(ai) <= 0.1;
	}
};
