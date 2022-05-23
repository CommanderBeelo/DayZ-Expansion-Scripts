modded class CrashBase
{
	#ifdef DIAG
	#ifdef EXPANSIONMODNAVIGATION
	ExpansionMarkerModule m_MarkerModule;
	ExpansionMarkerData m_ServerMarker;
	#endif
	#endif

	eAIDynamicPatrol m_ExpansionAIPatrol;

	void CrashBase()
	{
		#ifdef DIAG
		#ifdef EXPANSIONMODNAVIGATION
		CF_Modules<ExpansionMarkerModule>.Get(m_MarkerModule);
		#endif
		#endif
	}

    string EventType()
    {
        return "";
    }

	override void EEInit()
	{
		super.EEInit();
        
		if ( !m_ExpansionAIPatrol )
		{
			m_ExpansionAIPatrol = PatrolManager().InitCrashPatrolSpawner(EventType(), GetPosition());

			#ifdef DIAG
			#ifdef EXPANSIONMODNAVIGATION
			if ( !m_MarkerModule )
				return;
			
			m_ServerMarker = m_MarkerModule.CreateServerMarker( EventType(), "Helicopter", GetPosition(), ARGB(255, 235, 50, 90), true );
			#endif
			#endif
		}
	}

	override void EEDelete(EntityAI parent)
	{
		super.EEDelete( parent );

		#ifdef DIAG
		#ifdef EXPANSIONMODNAVIGATION
		if ( !m_ServerMarker )
			return;
		
		m_MarkerModule.RemoveServerMarker( m_ServerMarker.GetUID() );
		#endif
		#endif

		if ( m_ExpansionAIPatrol )
			m_ExpansionAIPatrol.Delete();
	}

	void ~CrashBase()
	{
		#ifdef DIAG
		#ifdef EXPANSIONMODNAVIGATION
		if ( m_ServerMarker && m_MarkerModule )
			m_MarkerModule.RemoveServerMarker( m_ServerMarker.GetUID() );
		#endif
		#endif

		if ( m_ExpansionAIPatrol )
		{
			m_ExpansionAIPatrol.Despawn();
			m_ExpansionAIPatrol.Delete();
		}
	}
};

modded class Wreck_UH1Y
{
    override string EventType()
    {
        return "Wreck_UH1Y";
    }
};

modded class Wreck_Mi8_Crashed
{
    override string EventType()
    {
        return "Wreck_Mi8";
    }
};


modded class Wreck_Mi8
{
    override string EventType()
    {
        return "Wreck_Mi8";
    }
};

