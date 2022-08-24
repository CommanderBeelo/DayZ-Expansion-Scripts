/**
 * MainMenu.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2022 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class MainMenu
{
	override Widget Init()
	{
		super.Init();

		string version;
		GetGame().GetVersion( version );
		string expansion_version;

		if ( GetDayZGame() )
			expansion_version = GetDayZGame().GetExpansionClientVersion();

		if (expansion_version)
#ifdef EDITOR
			m_Version.SetText( "DayZ SA #main_menu_version" + " " + version + "   DayZ Expansion #main_menu_version" + " " + expansion_version + " #STR_EDITOR_MAIN_MENU_VERSION" + " " + GetEditor().Version);
#else
			m_Version.SetText( "DayZ SA #main_menu_version" + " " + version + "   DayZ Expansion #main_menu_version" + " " + expansion_version );
#endif
		else
			m_Version.SetText( "DayZ SA #main_menu_version" + " " + version );

		return layoutRoot;
	}
}