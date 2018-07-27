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
	ID_SpellItem::Candlelight,
	ID_SpellItem::Oakflesh,
	ID_SpellItem::Magelight,
	ID_SpellItem::Stoneflesh,
	ID_SpellItem::DetectLife,
	ID_SpellItem::Ironflesh,
	ID_SpellItem::Telekinesis,
	ID_SpellItem::TransmuteOreMineral,
	ID_SpellItem::Waterbreathing,
	ID_SpellItem::DetectDead,
	ID_SpellItem::Ebonyflesh,
	ID_SpellItem::Paralyze,
	ID_SpellItem::Dragonhide,
	ID_SpellItem::MassParalysis,
	ID_SpellItem::BoundSword,
	ID_SpellItem::ConjureFamiliar,
	ID_SpellItem::RaiseZombie,
	ID_SpellItem::BoundBattleAxe,
	ID_SpellItem::ConjureFlameAtronach,
	ID_SpellItem::ReanimateCorpse,
	ID_SpellItem::SoulTrap,
	ID_SpellItem::BanishDaedra,
	ID_SpellItem::BoundBow,
	ID_SpellItem::ConjureFrostAtronach,
	ID_SpellItem::Revenant,
	ID_SpellItem::CommandDaedra,
	ID_SpellItem::ConjureDragonPriest,
	ID_SpellItem::ConjureDremoraLord,
	ID_SpellItem::ConjureStormAtronach,
	ID_SpellItem::DreadZombie,
	ID_SpellItem::ExpelDaedra,
	ID_SpellItem::FlameThrall,
	ID_SpellItem::DeadThrall,
	ID_SpellItem::FrostThrall,
	ID_SpellItem::StormThrall,
	ID_SpellItem::Flames,
	ID_SpellItem::Frostbite,
	ID_SpellItem::Sparks,
	ID_SpellItem::FireRune,
	ID_SpellItem::Firebolt,
	ID_SpellItem::FrostRune,
	ID_SpellItem::IceSpike,
	ID_SpellItem::LightningBolt,
	0x00067970,
	ID_SpellItem::ChainLightning,
	ID_SpellItem::Fireball,
	ID_SpellItem::flameCloak,
	ID_SpellItem::FrostCloak,
	ID_SpellItem::IceStorm,
	ID_SpellItem::LightningCloak,
	ID_SpellItem::IcySpear,
	ID_SpellItem::Incinerate,
	ID_SpellItem::Thunderbolt,
	ID_SpellItem::WallOfFlames,
	ID_SpellItem::WallOfFrost,
	ID_SpellItem::WallOfStorms,
	ID_SpellItem::Blizzard,
	ID_SpellItem::FireStorm,
	ID_SpellItem::LightningStorm,
	ID_SpellItem::Clairvoyance,
	ID_SpellItem::Courage,
	ID_SpellItem::Fury,
	ID_SpellItem::Calm,
	ID_SpellItem::Fear,
	ID_SpellItem::Muffle,
	ID_SpellItem::Frenzy,
	ID_SpellItem::Rally,
	ID_SpellItem::Invisibility,
	ID_SpellItem::Pacify,
	ID_SpellItem::Rout,
	ID_SpellItem::CallToArms,
	ID_SpellItem::Harmony,
	ID_SpellItem::Hysteria,
	ID_SpellItem::Mayhem,
	ID_SpellItem::Healing,
	ID_SpellItem::WardLesser,
	ID_SpellItem::FastHealing,
	ID_SpellItem::HealingHands,
	ID_SpellItem::WardSteadfast,
	ID_SpellItem::TurnLesserUndead,
	ID_SpellItem::CloseWounds,
	ID_SpellItem::WardGreater,
	ID_SpellItem::HealOther,
	ID_SpellItem::RepelLesserUndead,
	ID_SpellItem::TurnUndead,
	ID_SpellItem::CircleOfProtection,
	ID_SpellItem::GrandHealing,
	ID_SpellItem::RepelUndead,
	ID_SpellItem::TurnGreaterUndead,
	ID_SpellItem::BaneoftheUndead,
	ID_SpellItem::GuardianCircle
};

void main()
{
	PrintNote("[%s] started, press numpad 9 to level all magic skills", SCR_NAME);

	while (TRUE)
	{
		bool added = FALSE;
		if (GetKeyPressed(VK_NUMPAD9)) {
			for (int i = 0; i < sizeof(magic_skills) / sizeof(char*); i++)
				Game::AdvanceSkill(magic_skills[i], 10000000);
			PrintNote("[%s] All magic skills leveled up", SCR_NAME);
			Wait(500);
		} else
		if (GetKeyPressed(VK_NUMPAD8)) {
			CActor *player = Game::GetPlayer();
			for (int i = 0; i < sizeof(spells[i]) / sizeof(int); i++)
				if (!Actor::HasSpell(player, Game::GetFormById(spells[i]))) {
					SpellItem *spell = (SpellItem*)Game::GetFormById(spells[i]);
					Actor::AddSpell(player, spell, false);
					added = TRUE;
				}
				else
					added = FALSE;
			if (added)
				PrintNote("[%s] All spells added", SCR_NAME);
			else
				PrintNote("[%s] You already own these spells", SCR_NAME);
			Wait(500);
		}
		Wait(0);
	}
}

