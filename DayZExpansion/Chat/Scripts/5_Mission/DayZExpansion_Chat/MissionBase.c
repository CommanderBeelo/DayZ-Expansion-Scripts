modded class MissionBase
{
	override UIScriptedMenu CreateScriptedMenu(int id)
	{
		UIScriptedMenu menu = NULL;

		switch (id)
		{
		case MENU_CHAT_INPUT:
			menu = new ChatInputMenu;
			break;
		}

		if (menu)
		{
			menu.SetID(id);
		}
		else
		{
			menu = super.CreateScriptedMenu(id);
		}

		return menu;
	}
};
