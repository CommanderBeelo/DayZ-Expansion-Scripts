/**
 * ExpansionChatColors.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2022 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class ExpansionChatColors: ExpansionColorSettingsBase
{
	string SystemChatColor;
	string AdminChatColor;
	string GlobalChatColor;
	string DirectChatColor;
	string TransportChatColor;
	string PartyChatColor;
	string TransmitterChatColor;

	void Update()
	{
		//! Make sure none of the colors are zero (all transparent)
		if (!SystemChatColor)
			Set("SystemChatColor", ARGB(255, 186, 69, 186));
		if (!AdminChatColor)
			Set("AdminChatColor", ARGB(255, 192, 57, 43));
		if (!GlobalChatColor)
			Set("GlobalChatColor", ARGB(255, 88, 195, 247));
		if (!DirectChatColor)
			Set("DirectChatColor", ARGB(255, 255, 255, 255));
		if (!TransportChatColor)
			Set("TransportChatColor", ARGB(255, 255, 206, 9));
		if (!PartyChatColor)
			Set("PartyChatColor", ARGB(255, 10, 250, 122));
		if (!TransmitterChatColor)
			Set("TransmitterChatColor", ARGB(255, 249, 255, 73));
	}
}