#define _ARMA_

class CfgPatches
{
	class DayZExpansion_Quests_Dta_Core
	{
		units[] = {"ExpansionQuestNPCDenis","ExpansionQuestNPCBoris","ExpansionQuestNPCCyril","ExpansionQuestNPCElias","ExpansionQuestNPCFrancis","ExpansionQuestNPCGuo","ExpansionQuestNPCHassan","ExpansionQuestNPCIndar","ExpansionQuestNPCJose","ExpansionQuestNPCKaito","ExpansionQuestNPCLewis","ExpansionQuestNPCManua","ExpansionQuestNPCNiki","ExpansionQuestNPCOliver","ExpansionQuestNPCPeter","ExpansionQuestNPCQuinn","ExpansionQuestNPCRolf","ExpansionQuestNPCSeth","ExpansionQuestNPCTaiki","ExpansionQuestNPCLinda","ExpansionQuestNPCMaria","ExpansionQuestNPCFrida","ExpansionQuestNPCGabi","ExpansionQuestNPCHelga","ExpansionQuestNPCIrena","ExpansionQuestNPCJudy","ExpansionQuestNPCKeiko","ExpansionQuestNPCLina","ExpansionQuestNPCNaomi","ExpansionQuestItemBase","ExpansionQuestItemPaper","ExpansionQuestItemPackage"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Characters","DZ_Scripts","DZ_AI","DayZExpansion_Dta_Core"};
	};
};
class CfgVehicleClasses
{
	class Expansion_Npc
	{
		displayName = "Expansion Npc";
	};
};
class CfgVehicles
{
	class ExpansionQuestNPCBase;
	class SurvivorM_Mirek;
	class SurvivorM_Denis;
	class SurvivorM_Boris;
	class SurvivorM_Cyril;
	class SurvivorM_Elias;
	class SurvivorM_Francis;
	class SurvivorM_Guo;
	class SurvivorM_Hassan;
	class SurvivorM_Indar;
	class SurvivorM_Jose;
	class SurvivorM_Kaito;
	class SurvivorM_Lewis;
	class SurvivorM_Manua;
	class SurvivorM_Niki;
	class SurvivorM_Oliver;
	class SurvivorM_Peter;
	class SurvivorM_Quinn;
	class SurvivorM_Rolf;
	class SurvivorM_Seth;
	class SurvivorM_Taiki;
	class SurvivorF_Linda;
	class SurvivorF_Maria;
	class SurvivorF_Frida;
	class SurvivorF_Gabi;
	class SurvivorF_Helga;
	class SurvivorF_Irena;
	class SurvivorF_Judy;
	class SurvivorF_Keiko;
	class SurvivorF_Lina;
	class SurvivorF_Naomi;
	class SurvivorF_Eva;
	class SurvivorF_Baty;
	class Inventory_Base;
	class Paper;
	class eAI_SurvivorM_Mirek: SurvivorM_Mirek{};
	class eAI_SurvivorM_Denis: SurvivorM_Denis{};
	class eAI_SurvivorM_Boris: SurvivorM_Boris{};
	class eAI_SurvivorM_Cyril: SurvivorM_Cyril{};
	class eAI_SurvivorM_Elias: SurvivorM_Elias{};
	class eAI_SurvivorM_Francis: SurvivorM_Francis{};
	class eAI_SurvivorM_Guo: SurvivorM_Guo{};
	class eAI_SurvivorM_Hassan: SurvivorM_Hassan{};
	class eAI_SurvivorM_Indar: SurvivorM_Indar{};
	class eAI_SurvivorM_Jose: SurvivorM_Jose{};
	class eAI_SurvivorM_Kaito: SurvivorM_Kaito{};
	class eAI_SurvivorM_Lewis: SurvivorM_Lewis{};
	class eAI_SurvivorM_Manua: SurvivorM_Manua{};
	class eAI_SurvivorM_Niki: SurvivorM_Niki{};
	class eAI_SurvivorM_Oliver: SurvivorM_Oliver{};
	class eAI_SurvivorM_Peter: SurvivorM_Peter{};
	class eAI_SurvivorM_Quinn: SurvivorM_Quinn{};
	class eAI_SurvivorM_Rolf: SurvivorM_Rolf{};
	class eAI_SurvivorM_Seth: SurvivorM_Seth{};
	class eAI_SurvivorM_Taiki: SurvivorM_Taiki{};
	class eAI_SurvivorF_Linda: SurvivorF_Linda{};
	class eAI_SurvivorF_Maria: SurvivorF_Maria{};
	class eAI_SurvivorF_Frida: SurvivorF_Frida{};
	class eAI_SurvivorF_Gabi: SurvivorF_Gabi{};
	class eAI_SurvivorF_Helga: SurvivorF_Helga{};
	class eAI_SurvivorF_Irena: SurvivorF_Irena{};
	class eAI_SurvivorF_Judy: SurvivorF_Judy{};
	class eAI_SurvivorF_Keiko: SurvivorF_Keiko{};
	class eAI_SurvivorF_Eva: SurvivorF_Eva{};
	class eAI_SurvivorF_Naomi: SurvivorF_Naomi{};
	class eAI_SurvivorF_Baty: SurvivorF_Baty{};
	class ExpansionQuestNPCAIMirek: eAI_SurvivorM_Mirek
	{
		displayName = "Mirek";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAIDenis: eAI_SurvivorM_Denis
	{
		displayName = "Denis";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAIBoris: eAI_SurvivorM_Boris
	{
		displayName = "Boris";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAICyril: eAI_SurvivorM_Cyril
	{
		displayName = "Cyril";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAIElias: eAI_SurvivorM_Elias
	{
		displayName = "Elias";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAIFrancis: eAI_SurvivorM_Francis
	{
		displayName = "Francis";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAIGuo: eAI_SurvivorM_Guo
	{
		displayName = "Guo";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAIHassan: eAI_SurvivorM_Hassan
	{
		displayName = "Hassan";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAIIndar: eAI_SurvivorM_Indar
	{
		displayName = "Indar";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAIJose: eAI_SurvivorM_Jose
	{
		displayName = "Jose";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAIKaito: eAI_SurvivorM_Kaito
	{
		displayName = "Kaito";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAILewis: eAI_SurvivorM_Lewis
	{
		displayName = "Lewis";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAIManua: eAI_SurvivorM_Manua
	{
		displayName = "Manua";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAINiki: eAI_SurvivorM_Niki
	{
		displayName = "Niki";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAIOliver: eAI_SurvivorM_Oliver
	{
		displayName = "Oliver";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAIPeter: eAI_SurvivorM_Peter
	{
		displayName = "Peter";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAIQuinn: eAI_SurvivorM_Quinn
	{
		displayName = "Quinn";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAIRolf: eAI_SurvivorM_Rolf
	{
		displayName = "Rolf";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAISeth: eAI_SurvivorM_Seth
	{
		displayName = "Seth";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAITaiki: eAI_SurvivorM_Taiki
	{
		displayName = "Taiki";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAILinda: eAI_SurvivorF_Linda
	{
		displayName = "Linda";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAIMaria: eAI_SurvivorF_Maria
	{
		displayName = "Maria";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAIFrida: eAI_SurvivorF_Frida
	{
		displayName = "Frida";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAIGabi: eAI_SurvivorF_Gabi
	{
		displayName = "Gabi";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAIHelga: eAI_SurvivorF_Helga
	{
		displayName = "Helga";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAIIrena: eAI_SurvivorF_Irena
	{
		displayName = "Irena";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAIJudy: eAI_SurvivorF_Judy
	{
		displayName = "Judy";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAIKeiko: eAI_SurvivorF_Keiko
	{
		displayName = "Keiko";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAIEva: eAI_SurvivorF_Eva
	{
		displayName = "Eva";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAINaomi: eAI_SurvivorF_Naomi
	{
		displayName = "Naomi";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCAIBaty: eAI_SurvivorF_Baty
	{
		displayName = "Baty";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCMirek: eAI_SurvivorM_Mirek
	{
		displayName = "Mirek";
		vehicleClass = "Expansion_Trader";
	};
	class ExpansionQuestNPCDenis: SurvivorM_Denis
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCBoris: SurvivorM_Boris
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCCyril: SurvivorM_Cyril
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCElias: SurvivorM_Elias
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCFrancis: SurvivorM_Francis
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCGuo: SurvivorM_Guo
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCHassan: SurvivorM_Hassan
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCIndar: SurvivorM_Indar
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCJose: SurvivorM_Jose
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCKaito: SurvivorM_Kaito
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCLewis: SurvivorM_Lewis
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCManua: SurvivorM_Manua
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCNiki: SurvivorM_Niki
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCOliver: SurvivorM_Oliver
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCPeter: SurvivorM_Peter
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCQuinn: SurvivorM_Quinn
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCRolf: SurvivorM_Rolf
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCSeth: SurvivorM_Seth
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCTaiki: SurvivorM_Taiki
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCLinda: SurvivorF_Linda
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCMaria: SurvivorF_Maria
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCFrida: SurvivorF_Frida
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCGabi: SurvivorF_Gabi
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCHelga: SurvivorF_Helga
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCIrena: SurvivorF_Irena
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCJudy: SurvivorF_Judy
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCKeiko: SurvivorF_Keiko
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCLina: SurvivorF_Lina
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestNPCNaomi: SurvivorF_Naomi
	{
		scope = 2;
		vehicleClass = "Expansion_Npc";
	};
	class ExpansionQuestItemBase: Inventory_Base
	{
		scope = 2;
	};
	class ExpansionQuestItemPaper: ExpansionQuestItemBase
	{
		scope = 2;
		displayName = "Note";
		descriptionShort = "A questionable note that is hard to decipher..";
		model = "\dz\gear\consumables\Paper.p3d";
		isMeleeWeapon = 1;
		weight = 2;
		absorbency = 1;
		itemSize[] = {1,1};
		rotationFlags = 16;
		inventorySlot[] = {};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 15;
					healthLevels[] = {{1,{"DZ\gear\consumables\data\Loot_Paper.rvmat"}},{0.7,{"DZ\gear\consumables\data\Loot_Paper.rvmat"}},{0.5,{"DZ\gear\consumables\data\Loot_Paper_damage.rvmat"}},{0.3,{"DZ\gear\consumables\data\Loot_Paper_damage.rvmat"}},{0,{"DZ\gear\consumables\data\Loot_Paper_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "pickUpPaper_SoundSet";
					id = 797;
				};
			};
		};
	};
	class ExpansionQuestItemPackage: ExpansionQuestItemBase
	{
		scope = 2;
		displayName = "Package";
		descriptionShort = "A package. Only the reciver will know what it contains.";
		model = "\DayZExpansion\Objects\Gear\Box\box.p3d";
		isMeleeWeapon = 1;
		weight = 4;
		absorbency = 1;
		itemSize[] = {2,2};
		rotationFlags = 16;
		inventorySlot[] = {};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "pickUpPaper_SoundSet";
					id = 797;
				};
			};
		};
	};
};
