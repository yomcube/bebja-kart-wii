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
	++Pulsar::UI::SettingsPanel::pageCount;

	// Radio button count for new page
	Pulsar::UI::SettingsPanel::radioButtonCount[SETTINGSTYPE_BKW] = 2;
	// Disable HUD
	Pulsar::UI::SettingsPanel::buttonsPerPagePerRow[SETTINGSTYPE_BKW][0] = 2;
	// MirrorModeTTs
        Pulsar::UI::SettingsPanel::buttonsPerPagePerRow[SETTINGSTYPE_BKW][1] = 3;
}

//Pulsar::Ghost::Manager also has a callback which can be set using SetCb
//That callback will be called as each ghost is loaded

} // namespace BKW
