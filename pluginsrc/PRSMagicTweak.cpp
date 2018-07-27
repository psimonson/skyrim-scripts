/* 
	USE THIS ONE AS A TEMPLATE FOR YOUR SCRIPT PLUGINS
*/

#include "common\skyscript.h"
#include "common\obscript.h"
#include "common\types.h"
#include "common\enums.h"
#include "common\plugin.h"

#define SCR_NAME "PRSMagicTweak"

char *magic_skills[] = {
	"alteration",
	"illusion",
	"conjuration",
	"destruction",
	"restoration",
	"enchanting",
	"alchemy"
};

int spells[] = {
	ID_SpellItem::Blizzard,
	ID_SpellItem::BoundBattleAxe,
	ID_SpellItem::BoundBow,
	ID_SpellItem::BoundSword,
	ID_SpellItem::DreadZombie,
	ID_SpellItem::CallToArms,
	ID_SpellItem::Calm,
	ID_SpellItem::ConjureDragonPriest,
	ID_SpellItem::Candlelight,
	ID_SpellItem::ChainLightning,
	ID_SpellItem::CircleOfProtection,
	ID_SpellItem::Clairvoyance,
	ID_SpellItem::CloseWounds,
	ID_SpellItem::ConjureDragonPriest,
	ID_SpellItem::ConjureDremoraLord,
	ID_SpellItem::ConjureFamiliar,
	ID_SpellItem::ConjureFlameAtronach,
	ID_SpellItem::ConjureFrostAtronach,
	ID_SpellItem::ConjureStormAtronach,
	ID_SpellItem::Courage,
	ID_SpellItem::DeadThrall,
	ID_SpellItem::DetectDead,
	ID_SpellItem::DetectLife,
	ID_SpellItem::DiseaseAtaxia,
	ID_SpellItem::DiseaseBoneBreakFever,
	ID_SpellItem::DiseaseBrainRot,
	ID_SpellItem::DiseaseRattles,
	ID_SpellItem::DiseaseRockjoint,
	ID_SpellItem::DiseaseSanguinareVampiris,
	ID_SpellItem::DiseaseWitbane,
	ID_SpellItem::Dragonhide,
	ID_SpellItem::DreadZombie
};

void main()
{
	PrintNote("[%s] started, press numpad 9 to level all magic skills", SCR_NAME);

	while (TRUE)
	{
		if (GetKeyPressed(VK_NUMPAD9)) {
			for (int i = 0; i < sizeof(magic_skills) / sizeof(char*); i++)
				Game::AdvanceSkill(magic_skills[i], 10000000);
			PrintNote("[%s] All magic skills leveled up", SCR_NAME);
			Wait(500);
		} else
		if (GetKeyPressed(VK_NUMPAD8)) {
			CActor *player = Game::GetPlayer();
			for (int i = 0; i < sizeof(spells[i]) / sizeof(int); i++)
				if (Actor::HasSpell(player, Game::GetFormById(spells[i]))) {
					SpellItem *spell = (SpellItem*)Game::GetFormById(spells[i]);
					Actor::AddSpell(player, spell, false);
				}
			PrintNote("[%s] All spells added", SCR_NAME);
			Wait(500);
		}
		Wait(0);
	}
}

