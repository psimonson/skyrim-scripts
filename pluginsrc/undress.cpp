/*
			ACTOR UNDRESS SCRIPT PLUGIN EXAMPLE

	THIS FILE IS A PART OF THE SKYRIM DRAGON SCRIPT PROJECT	
				(C) Alexander Blade 2011
			http://Alexander.SannyBuilder.com
*/

#include "common\skyscript.h"
#include "common\obscript.h"
#include "common\types.h"
#include "common\enums.h"
#include "common\plugin.h"

#define CONFIG_FILE "undress.ini"
#define SCR_NAME "Undress"

void main()
{
	// reading key from the config file
	BYTE key = IniReadInt(CONFIG_FILE, "main", "key", 0);
	PrintNote("[%s] started, LMB on any actor in console and press '%s'", SCR_NAME, GetKeyName(key).c_str());
	while (TRUE)
	{
		if (GetKeyPressed(key)) 
		{
			TESObjectREFR *obj = GetConsoleSelectedRef();
			// using dyn_cast to check if object is an actor
			CActor *act = (CActor *)dyn_cast(obj, "CActor", "CActor");
			if (act)
			{
				if (Game::GetPlayer() != act) 
				{
					Actor::UnequipAll(act); 
					PrintNote("[%s] : selected actor nuded as much as possible", SCR_NAME);
				} 
				else PrintNote("[%s] : you must undress player manually", SCR_NAME); 
			} 
			else PrintNote("[%s] : selected object is not an actor", SCR_NAME);
			Wait(500);
		}
		Wait(0); // In order to switch between script threads Wait() must be called anyway
	}
}

