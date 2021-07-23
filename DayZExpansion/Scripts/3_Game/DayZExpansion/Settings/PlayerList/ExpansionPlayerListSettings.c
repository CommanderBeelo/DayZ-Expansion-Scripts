/**
 * ExpansionPlayerListSettings.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

/**@class		ExpansionPlayerListSettings
 * @brief		Vehicle settings class
 **/
class ExpansionPlayerListSettings: ExpansionSettingBase
{
	bool EnablePlayerList;
	bool EnableTooltip;

	[NonSerialized()]
	private bool m_IsLoaded;
	
	// ------------------------------------------------------------
	// ExpansionPlayerListSettings OnRecieve
	// ------------------------------------------------------------
	override bool OnRecieve( ParamsReadContext ctx )
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionPlayerListSettings::OnRecieve - Start");
		#endif
		ExpansionPlayerListSettings setting;
		if ( !ctx.Read( setting ) )
		{
			Error("ExpansionPlayerListSettings::OnRecieve setting");
			return false;
		}

		CopyInternal( setting );

		m_IsLoaded = true;

		ExpansionSettings.SI_PlayerList.Invoke();
		
		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionPlayerListSettings::OnRecieve - End");
		#endif

		return true;
	}
	
	// ------------------------------------------------------------
	// ExpansionPlayerListSettings OnSend
	// ------------------------------------------------------------
	override void OnSend( ParamsWriteContext ctx )
	{
		ref ExpansionPlayerListSettings thisSetting = this;

		ctx.Write( thisSetting );
	}
	
	// ------------------------------------------------------------
	// ExpansionPlayerListSettings Send
	// ------------------------------------------------------------
	override int Send( PlayerIdentity identity )
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionPlayerListSettings::Send - Start");
		#endif
		
		if ( !IsMissionHost() )
		{
			return 0;
		}
		
		ScriptRPC rpc = new ScriptRPC;
		OnSend( rpc );
		rpc.Send( null, ExpansionSettingsRPC.PlayerList, true, identity );
		
		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionPlayerListSettings::Send - End and return");
		#endif
		return 0;
	}

	// ------------------------------------------------------------
	// ExpansionPlayerListSettings Copy
	// ------------------------------------------------------------
	override bool Copy( ExpansionSettingBase setting )
	{
		ExpansionPlayerListSettings s;
		if ( !Class.CastTo( s, setting ) )
			return false;

		CopyInternal( s );
		return true;
	}

	// ------------------------------------------------------------
	// ExpansionPlayerListSettings CopyInternal
	// ------------------------------------------------------------
	private void CopyInternal( ref ExpansionPlayerListSettings s )
	{
		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionPlayerListSettings::CopyInternal - Start");
		#endif

		EnablePlayerList = s.EnablePlayerList;
		EnableTooltip = s.EnableTooltip;

		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionPlayerListSettings::CopyInternal - End");
		#endif
	}
	
	// ------------------------------------------------------------
	// ExpansionPlayerListSettings IsLoaded
	// ------------------------------------------------------------
	override bool IsLoaded()
	{
		return m_IsLoaded;
	}
	
	// ------------------------------------------------------------
	// ExpansionPlayerListSettings Unload
	// ------------------------------------------------------------
	override void Unload()
	{
		m_IsLoaded = false;
	}

	// ------------------------------------------------------------
	// ExpansionPlayerListSettings OnLoad
	// ------------------------------------------------------------
	override bool OnLoad()
	{	
		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionPlayerListSettings::Load - Start");
		#endif
		
		m_IsLoaded = true;
		
		if ( FileExist( EXPANSION_PLAYERLIST_SETTINGS ) )
		{
			Print("[ExpansionPlayerListSettings] Loading settings");

			JsonFileLoader<ExpansionPlayerListSettings>.JsonLoadFile( EXPANSION_PLAYERLIST_SETTINGS, this );
	
			#ifdef EXPANSIONEXPRINT
			EXPrint("ExpansionPlayerListSettings::Load - End - Loaded");
			#endif

			return true;
		}

		Defaults();
		Save();

		#ifdef EXPANSIONEXPRINT
		EXPrint("ExpansionPlayerListSettings::Load - End - Not Loaded");
		#endif
		return false;
	}

	// ------------------------------------------------------------
	// ExpansionPlayerListSettings OnSave
	// ------------------------------------------------------------
	override bool OnSave()
	{
		Print("[ExpansionPlayerListSettings] Saving settings");

		JsonFileLoader<ExpansionPlayerListSettings>.JsonSaveFile( EXPANSION_PLAYERLIST_SETTINGS, this );

		return true;
	}
	
	// ------------------------------------------------------------
	// ExpansionPlayerListSettings Update
	// ------------------------------------------------------------
	override void Update( ExpansionSettingBase setting )
	{
		super.Update( setting );

		ExpansionSettings.SI_PlayerList.Invoke();
	}

	// ------------------------------------------------------------
	// ExpansionPlayerListSettings Defaults
	// ------------------------------------------------------------
	override void Defaults()
	{
		Print("[ExpansionPlayerListSettings] Loading default settings");

		EnablePlayerList = true;
		EnableTooltip = true;
	}
	
	// ------------------------------------------------------------
	override string SettingName()
	{
		return "Player List Settings";
	}
};