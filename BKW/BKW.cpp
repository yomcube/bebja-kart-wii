#include <MarioKartWii/Race/RaceData.hpp>
#include <Settings/UI/SettingsPanel.hpp>
#include <SlotExpansion/CupsConfig.hpp>
#include <BKW.hpp>

namespace BKW {
	
Pulsar::System *BKWPack::Create() {
	return new BKWPack(); //now Pulsar::sInstance is of type MyPack
}
Pulsar::System::Inherit CreateBKW(BKWPack::Create); //Create a Inherit that'll get called back by Pulsar::CreatePulsar

void BKWPack::AfterInit() {
	/*++Pulsar::UI::SettingsPanel::pageCount;

	// Radio button count for new page
	Pulsar::UI::SettingsPanel::radioButtonCount[SETTINGSTYPE_BKW] = 1;
	// Disable HUD
	Pulsar::UI::SettingsPanel::buttonsPerPagePerRow[SETTINGSTYPE_BKW][0] = 2;
	
	// Scroller count for new page
	Pulsar::UI::SettingsPanel::scrollerCount[SETTINGSTYPE_BKW] = 1;
	// Gamemode Scroller Option Count
	Pulsar::UI::SettingsPanel::optionsPerPagePerScroller[SETTINGSTYPE_BKW][0] = 1;*/
}

Gamemode BKWPack::GetGamemode() {
	const bool isRegs = Pulsar::CupsConfig::IsRegsSituation();
	const GameMode gameMode = RaceData::sInstance->racesScenario.settings.gamemode;
	const GameMode menuGameMode = RaceData::sInstance->menusScenario.settings.gamemode;
	const bool isTTs = gameMode == MODE_TIME_TRIAL || menuGameMode == MODE_TIME_TRIAL;
	const bool isRegional = gameMode == MODE_PUBLIC_VS || gameMode == MODE_PUBLIC_BATTLE || menuGameMode == MODE_PUBLIC_VS || menuGameMode == MODE_PUBLIC_BATTLE;
	if (!isRegs){
		if (!isTTs && !isRegional) {
			return static_cast<Gamemode>(Pulsar::Settings::Mgr::GetSettingValue(static_cast<Pulsar::Settings::Type>(SETTINGSTYPE_BKW), SETTINGBKW_SCROLLER_MODE));
		}
		return GAMEMODE_NORMAL;
	}
	return GAMEMODE_NONE;
}


//Pulsar::Ghost::Manager also has a callback which can be set using SetCb
//That callback will be called as each ghost is loaded

} // namespace BKW