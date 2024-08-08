#include <kamek.hpp>
#include <MarioKartWii/Race/RaceData.hpp>
#include <Settings/UI/SettingsPanel.hpp>
#include <BKW.hpp>

namespace BKW {
namespace MiscCodes {

//Show Battle Map Icons [CLF78]
kmWrite8(0x8088BFF7, 0x00000001);

//Allow Looking Backwards During Respawn [Ro]
kmWrite32(0x805A228C, 0x60000000);

//Allow looking backwards during the countdown [Gaberboo]
kmWrite32(0x805A225C, 0x38800001);

//Can Always Drift [Supastarrio]
kmWrite32(0x808B5B1C, 0x00000000);

//No Bullet Bill Icon [Anarion]
kmWrite32(0x807BA5D0, 0x60000000);

//Accurate Explosion Damage [MrBean, CLF78]
kmWrite16(0x80572690, 0x00004800);
kmWrite16(0x80569F68, 0x00004800);

//Allow Mega in a Mega [Unnamed]
kmWrite32(0x807BB764, 0x60000000);

//Better Bullet Bill Curve Tightness [davidevgen]
kmWrite32(0x80891FCC, 0x447A0000);

//Allow All Vehicles in Battle Mode [Nameless / Scruffy]
kmWrite32(0x805DE7B4, 0x38000000);
kmWrite32(0x80553F98, 0x3880000A);
kmWrite32(0x8084FEF0, 0x48000044);
kmWrite32(0x80860A90, 0x38600000);

//Show Minimap Topography [Mu1hwu]
kmWrite8(0x80389060, 0);

//Disable Low Battery Notification [Diamond]
kmWrite16(0x805C379A, 0xFFFF);

//Remove Mushroom Bug [Vega]
kmWrite8(0x807BA077, 0);

//Disable Data Save Reset For Region ID Change [Vega]
kmWrite32(0x80544928, 0x7C601B78);

//Remove Worldwide Option [Chadderz]
kmWrite16(0x8064B982, 0x00000005);
kmWrite32(0x8064BA10, 0x60000000);
kmWrite32(0x8064BA38, 0x60000000);
kmWrite32(0x8064BA50, 0x60000000);
kmWrite32(0x8064BA5C, 0x60000000);
kmWrite16(0x8064BC12, 0x00000001);
kmWrite16(0x8064BC3E, 0x00000484);
kmWrite16(0x8064BC4E, 0x000010D7);
kmWrite16(0x8064BCB6, 0x00000484);
kmWrite16(0x8064BCC2, 0x000010D7);

//Never Burn Out [JoshuaMK]
kmWrite16(0x80595B18, 0x00004800);

//Change VR Limit [XeR]
// 0x4E20 = 20000
kmWrite16(0x80528E12, 0x00004E20);
kmWrite16(0x80528E1A, 0x00004E20);
kmWrite16(0x8061C3C6, 0x00004E20);
kmWrite16(0x8061C3D2, 0x00004E20);
kmWrite16(0x8083A7AE, 0x00004E20);
kmWrite16(0x8083A7B6, 0x00004E20);

//Allow pausing before the race starts [Sponge]
kmWrite32(0x80856A28, 0x48000050);

//Mirror Mode TTs
static void MirrorModeTTs() {
u8 dis = Pulsar::Settings::Mgr::GetSettingValue(static_cast<Pulsar::Settings::Type>(SETTINGSTYPE_BKW), SETTINGBKW_RADIO_MIRRORMODETTS);
	if (dis!= 1) {
			asm(
				"cmpwi r24,2;"
  				 "bne end;"
  				 "li r7,1;" // this flag should always be 0 in TTs
   				 "loc_0xC:"
				"stw r7, 2960(r31);"
				);
			}
		}
kmCall(0x8053056C, MirrorModeTTs);

//Disable HUD [Bully]
static void DisableHUD() {
	u8 dis = Pulsar::Settings::Mgr::GetSettingValue(static_cast<Pulsar::Settings::Type>(SETTINGSTYPE_BKW), SETTINGBKW_RADIO_DISABLEHUD);
	if (dis != 1) {
		asm("stfs f1, 0x0184 (r27);"); // Original instruction
	}
}
kmCall(0x807EC68C, DisableHUD);

} // namespace MiscCodes
} // namespace BKW
