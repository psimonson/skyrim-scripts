/* 
	USE THIS ONE AS A TEMPLATE FOR YOUR SCRIPT PLUGINS
*/

#include "common\skyscript.h"
#include "common\obscript.h"
#include "common\types.h"
#include "common\enums.h"
#include "common\plugin.h"

#define CONFIG_FILE "weather.ini"
#define SCR_NAME "Weather"

struct TWeather 
{
	int id;
	char *name;
};

TWeather weather_ids[] = {
	{ID_TESWeather::DefaultWeather, "DefaultWeather"},
    {ID_TESWeather::SovngardeDark, "SovngardeDark"},
    {ID_TESWeather::RiftenOvercastFog, "RiftenOvercastFog"},
    {ID_TESWeather::EditorCloudPreview, "EditorCloudPreview"},
    {ID_TESWeather::SkyrimClear_A, "SkyrimClear_A"},
    {ID_TESWeather::SkyrimCloudy_A, "SkyrimCloudy_A"},
    /*ID_TESWeather::SkyrimClearSN_A,
    ID_TESWeather::SkyrimCloudySN_A,
    ID_TESWeather::SkyrimClearTU_A,
    ID_TESWeather::SkyrimCloudyTU_A,
    ID_TESWeather::SkyrimClearFF_A,
    ID_TESWeather::SkyrimCloudyFF_A,
    ID_TESWeather::SkyrimClearRE_A,
    ID_TESWeather::SkyrimCloudyRE_A,
    ID_TESWeather::SkyrimClearCO_A,
    ID_TESWeather::SkyrimCloudyCO_A,
    ID_TESWeather::SkyrimClearMA_A,
    ID_TESWeather::SkyrimCloudyMA_A,
    ID_TESWeather::SkyrimClearVT_A,
    ID_TESWeather::SkyrimCloudyVT_A,
    ID_TESWeather::FXWthrInvertWindowsWinterhold,*/ // 20
    {ID_TESWeather::SovngardeClear, "SovngardeClear"},
    {ID_TESWeather::FXSkyrimStormBlowingGrass, "FXSkyrimStormBlowingGrass"},
    {ID_TESWeather::SkyrimCloudyVT, "SkyrimCloudyVT"},
    {ID_TESWeather::SkyrimFogVT, "SkyrimFogVT"},
    {ID_TESWeather::SkyrimOvercastRainVT, "SkyrimOvercastRainVT"}, // 25
    /*ID_TESWeather::SkyrimClearVT,
    ID_TESWeather::SkyrimCloudySN,
    ID_TESWeather::SkyrimClearSN,*/   // 28
    {ID_TESWeather::SkyrimCloudyTU, "SkyrimCloudyTU"},
    {ID_TESWeather::SkyrimOvercastRainTU, "SkyrimOvercastRainTU"}, // 30
    {ID_TESWeather::SkyrimStormRainTU, "SkyrimStormRainTU"}, 
    {ID_TESWeather::SkyrimClearTU, "SkyrimClearTU"},
    //ID_TESWeather::SkyrimCloudyFF,
    {ID_TESWeather::SkyrimFogFF, "SkyrimFogFF"},
    /*ID_TESWeather::SkyrimOvercastRainFF,
    ID_TESWeather::SkyrimStormRainFF,*/
    {ID_TESWeather::SkyrimClearFF, "SkyrimClearFF"},
    /*ID_TESWeather::SkyrimCloudyRE,
    ID_TESWeather::SkyrimFogRE,
    ID_TESWeather::SkyrimOvercastRainRE, // 40
    ID_TESWeather::SkyrimClearRE,*/ 
    /*ID_TESWeather::SkyrimCloudyCO,
    ID_TESWeather::SkyrimFogCO,
    ID_TESWeather::SkyrimClearCO,
    ID_TESWeather::SkyrimCloudyMA,
    ID_TESWeather::SkyrimFogMA,
    ID_TESWeather::SkyrimOvercastRainMA,
    ID_TESWeather::SkyrimClearMA,*/
    {ID_TESWeather::KarthspireRedoubtFog, "KarthspireRedoubtFog"},
    {ID_TESWeather::SkyrimDA02Weather, "SkyrimDA02Weather"}, // 50
    {ID_TESWeather::SolitudeBluePalaceFog, "SolitudeBluePalaceFog"}, 
    {ID_TESWeather::SolitudeBluePalaceFogNMARE, "SolitudeBluePalaceFogNMARE"},
    {ID_TESWeather::SolitudeBluePalaceFogFEAR, "SolitudeBluePalaceFogFEAR"},
    {ID_TESWeather::SolitudeBluePalaceFogARENA, "SolitudeBluePalaceFogARENA"},
    {ID_TESWeather::BloatedMansGrottoFog, "BloatedMansGrottoFog"},// 55
    {ID_TESWeather::SkuldafnCloudy, "SkuldafnCloudy"}, 
    {ID_TESWeather::SkyrimMQ206weather, "SkyrimMQ206weather"},
    //ID_TESWeather::FXWthrInvertLightMarkarth,
    //ID_TESWeather::FXWthrInvertWindowsWindhelm2,
    //ID_TESWeather::HelgenAttackWeather, // 60
    //ID_TESWeather::FXWthrInvertLightsSolitude, 
    //ID_TESWeather::FXWthrInvertLightsWhiterun,
    //ID_TESWeather::FXWthrInvertWindowsWhiterun,
    {ID_TESWeather::FXMagicStormRain, "FXMagicStormRain"},
    {ID_TESWeather::SkyrimOvercastWar, "SkyrimOvercastWar"},
    {ID_TESWeather::SkyrimStormSnow, "SkyrimStormSnow"},
    {ID_TESWeather::SkyrimStormRain, "SkyrimStormRain"},
    {ID_TESWeather::SkyrimOvercastRain, "SkyrimOvercastRain"},
    {ID_TESWeather::SkyrimFog, "SkyrimFog"},
    //ID_TESWeather::FXWthrSunlightWhite,
    {ID_TESWeather::FXWthrSunlight, "FXWthrSunlight"},
    {ID_TESWeather::BlackreachWeather, "BlackreachWeather"},
    //ID_TESWeather::FXWthrInvertWindowsWindhelm,
    //ID_TESWeather::WorldMapWeather,
    {ID_TESWeather::SovngardeFog, "SovngardeFog"},
    //ID_TESWeather::FXWthrInvertDayNighWarm,
    //ID_TESWeather::FXWthrCaveBluePaleLight,
    {ID_TESWeather::FXWthrCaveBlueSkylight, "FXWthrCaveBlueSkylight"},
    //ID_TESWeather::FXWthrInvertDayNight,
    {ID_TESWeather::SkyrimOvercastSnow, "SkyrimOvercastSnow"},
    //ID_TESWeather::TESTCloudyRain,
    //ID_TESWeather::SkyrimCloudy,
    {ID_TESWeather::SkyrimClear, "SkyrimClear"}
};

int cur_weather_num;

void main()
{
	BYTE key_up = IniReadInt(CONFIG_FILE, "main", "key_up", 0);
	BYTE key_down = IniReadInt(CONFIG_FILE, "main", "key_down", 0);
	PrintNote("[%s] launched", SCR_NAME);
	while (TRUE)
	{
		if (GetKeyPressed(key_up))
		{
			int weather_size = sizeof(weather_ids) / sizeof(weather_ids[0]);
			if (cur_weather_num >= weather_size) cur_weather_num = 0;
			TESForm *weather = Game::GetFormById(weather_ids[cur_weather_num].id);
			if (weather)
			{
				Weather::ForceActive((TESWeather *)weather, TRUE);
				PrintNote("weather %s (%d/%d)", weather_ids[cur_weather_num].name, cur_weather_num + 1, weather_size);
			}
			cur_weather_num++;
			Wait(500);
		}
		if (GetKeyPressed(key_down))
		{
			cur_weather_num--;
			int weather_size = sizeof(weather_ids) / sizeof(weather_ids[0]);
			if (cur_weather_num < 0) cur_weather_num = weather_size - 1;
			TESForm *weather = Game::GetFormById(weather_ids[cur_weather_num].id);
			if (weather)
			{
				Weather::ForceActive((TESWeather *)weather, TRUE);
				PrintNote("weather %s (%d/%d)", weather_ids[cur_weather_num].name, cur_weather_num + 1, weather_size);
			}
			Wait(500);
		}
		
		Wait(0);
	}
}

