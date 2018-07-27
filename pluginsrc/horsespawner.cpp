/*
			HORSE SPAWNER SCRIPT PLUGIN EXAMPLE

	THIS FILE IS A PART OF THE SKYRIM DRAGON SCRIPT PROJECT	
				(C) Alexander Blade 2011
			http://Alexander.SannyBuilder.com
*/

#include "common\skyscript.h"
#include "common\obscript.h"
#include "common\types.h"
#include "common\enums.h"
#include "common\plugin.h"
#include <math.h>

#define CONFIG_FILE "horsespawner.ini"
#define SCR_NAME "Horse spawner"

void GetRelXyFromRef(TESObjectREFR *ref, float dist, float addangle, float *x, float *y)
{
	float rzrot = ObjectReference::GetAngleZ(ref);
	rzrot = (float)(rzrot * 3.14 / 180) + addangle;
	if (x) *x = dist*sin(rzrot);
	if (y) *y = dist*cos(rzrot);
}

void main()
{
	BYTE key = IniReadInt(CONFIG_FILE, "main", "key", 0);
	PrintNote("[%s] started, press '%s' to use", SCR_NAME, GetKeyName(key).c_str());
	while (TRUE)
	{
		if (GetKeyPressed(key))
		{
			PrintNote("[%s] : spawning horse", SCR_NAME);
			CActor *player = Game::GetPlayer(); 
			CActor *horse = Game::GetPlayersLastRiddenHorse();
			if (!horse)
			{
				 /* if object to cast has no multiply parent classes then dyn_cast result will be the same as input src object
				 it's necessary to do such casts only if you want to verify object class */
				horse = (CActor *)dyn_cast(Game::GetFormById(ID_Character::SolitudePlayersHorseRef), "TESForm", "CActor");
				if (!horse)
				{
					PrintNote("you shouldn't see this : invalid horse id specified, terminating script");
					return;
				}
				TESNPC *player_npc = (TESNPC *)dyn_cast(Game::GetFormById(ID_TESNPC::Player), "TESForm", "TESNPC");
				if (!player_npc)
				{
					PrintNote("you shouldn't see this : invalid player_npc id specified, terminating script");
					return;
				}
				// for ex. SetActorOwner has 1st param as TESObjectREFR* , CActor is alerady a REFR class by itself
				// u must not make dyn_cast 
				ObjectReference::SetActorOwner((TESObjectREFR *)horse, player_npc);
				TESObjectCELL * pc = ObjectReference::GetParentCell((TESObjectREFR *)horse);
				PrintNote("cell 0x%08x", pc);
				//ObjectReference::SetFactionOwner((TESObjectREFR *)horse, (TESFaction *)Game::GetFormById(ID_TESFaction::PlayerFaction));
				//Cell::SetFactionOwner((TESObjectCELL *)horse, (TESFaction *)Game::GetFormById(ID_TESFaction::PlayerFaction));
			}
			if (Actor::IsDead(horse)) 
			{
				PrintNote("[%s] : your horse may look like dead for some time", SCR_NAME);
				Actor::Resurrect(horse);
			}
			Actor::ResetHealthAndLimbs(horse);
			float xdif, ydif;
			GetRelXyFromRef((TESObjectREFR *)player, 300, 0, &xdif, &ydif);
			ObjectReference::MoveTo((TESObjectREFR *)horse, (TESObjectREFR *)player, xdif, ydif, 0, TRUE);
			PrintNote("[%s] : horse spawned", SCR_NAME);
			Wait(500);
		}
		Wait(0); // In order to switch between script threads Wait() must be called anyway
	}
}

