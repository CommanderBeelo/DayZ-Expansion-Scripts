/**
 * ExpansionAirdropLoot.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2022 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class ExpansionAirdropLootVariant
{
	string Name;
	ref TStringArray Attachments;
	float Chance;

	void ExpansionAirdropLootVariant( string name, TStringArray attachments = NULL, float chance = 1 )
	{
		Name = name;
		Attachments = attachments;
		Chance = chance;
	}
}

class ExpansionAirdropLoot : ExpansionAirdropLootVariant
{
	int QuantityPercent;
	int Max;
	ref array< ref ExpansionAirdropLootVariant > Variants;

	void ExpansionAirdropLoot( string name, TStringArray attachments = NULL, float chance = 1, int quantityPercent = -1, array< ref ExpansionAirdropLootVariant > variants = NULL, int max = -1 )
	{
		QuantityPercent = quantityPercent;
		Max = max;
		Variants = variants;
	}
}
