#include <kamek.hpp>
#include <MarioKartWii/Race/RaceData.hpp>
#include <Settings/UI/SettingsPanel.hpp>
#include <BKW.hpp>

namespace BKW {
namespace MiscCodes {

// Show Battle Map Icons [CLF78]
kmWrite8(0x8088BFF7, 1);

// Allow Looking Backwards During Respawn [Ro]
kmWrite32(0x805A228C, 0x60000000);

// Allow looking backwards during the countdown [Gaberboo]
kmWrite32(0x805A225C, 0x38800001);

// Can Always Drift [Supastarrio]
kmWrite32(0x808B5B1C, 0);

// No Bullet Bill Icon [Anarion]
kmWrite32(0x807BA5D0, 0x60000000);

// Accurate Explosion Damage [MrBean, CLF78]
kmWrite16(0x80572690, 0x4800);
kmWrite16(0x80569F68, 0x4800);

// Allow Mega in a Mega [Unnamed]
kmWrite32(0x807BB764, 0x60000000);

// Better Bullet Bill Curve Tightness [davidevgen]
kmWrite32(0x80891FCC, 0x447A0000);

// Allow All Vehicles in Battle Mode [Nameless / Scruffy]
kmWrite32(0x805DE7B4, 0x38000000);
kmWrite32(0x80553F98, 0x3880000A);
kmWrite32(0x8084FEF0, 0x48000044);
kmWrite32(0x80860A90, 0x38600000);

// Show Minimap Topography [Mu1hwu]
kmWrite8(0x80389060, 0);

// Disable Low Battery Notification [Diamond]
kmWrite16(0x805C379A, 0xFFFF);

// Remove Mushroom Bug [Vega]
kmWrite8(0x807BA077, 0);

// Disable Data Save Reset For Region ID Change [Vega]
kmWrite32(0x80544928, 0x7C601B78);

// Remove Worldwide Option [Chadderz]
kmWrite16(0x8064B982, 0x0005);
kmWrite32(0x8064BA10, 0x60000000);
kmWrite32(0x8064BA38, 0x60000000);
kmWrite32(0x8064BA50, 0x60000000);
kmWrite32(0x8064BA5C, 0x60000000);
kmWrite16(0x8064BC12, 0x0001);
kmWrite16(0x8064BC3E, 0x0484);
kmWrite16(0x8064BC4E, 0x10D7);
kmWrite16(0x8064BCB6, 0x0484);
kmWrite16(0x8064BCC2, 0x10D7);

// Never Burn Out [JoshuaMK]
kmWrite16(0x80595B18, 0x4800);

// Change VR Limit [XeR]
// 0x4E20 = 20000
kmWrite16(0x80528E12, 0x4E20);
kmWrite16(0x80528E1A, 0x4E20);
kmWrite16(0x8061C3C6, 0x4E20);
kmWrite16(0x8061C3D2, 0x4E20);
kmWrite16(0x8083A7AE, 0x4E20);
kmWrite16(0x8083A7B6, 0x4E20);

// Allow pausing before the race starts [Sponge]
kmWrite32(0x80856A28, 0x48000050);

// Green/Red Shells Never Break [Hamster35000vr]
kmWrite32(0x807B5E58, 0x60000000);

// Disable Lakitu When Going Backwards [CLF78]
kmWrite16(0x80535628, 0x4800);



//C2 CODES
// Mega Mushroom Increased FOV [TheLordScruffy]
kmCallDefAsm(0x805793AC) {
	lwz r4, 0(r28)
	lwz r29, 36(r4)
	cmpwi r29, 0x0
	beq - loc_0x28
	lwz r3, 4(r4)
	lwz r3, 12(r3)
	rlwinm. r3, r3, 0, 16, 16
	beq - loc_0x28
	lis r0, 0x41F0
	stw r0, 288(r29)

	loc_0x28:
}

// 480p Graphics Fix [Leseratte]
kmCallDefAsm(0x801BCDDC) {
	li r3, 3
	stb r3, 0x0019(r1)
}

// BRRES Anti-flicker
kmCallDefAsm(0x80052190) {
loc_0x0:
  lwz r4, 0(r3)
  lbz r5, 16(r4)
  andi. r5, r5, 0x40
  bne- loc_0x6C
  lwz r5, 40(r4)
  li r6, 0x20
  add r5, r4, r5
  b loc_0x2C

loc_0x20:
  addi r6, r6, 0x1
  cmpwi r6, 0x80
  bge- loc_0x6C

loc_0x2C:
  mr r7, r5
  lbzux r8, r7, r6
  cmplwi r8, 0
  beq+ loc_0x20
  cmplwi r8, 97
  bne- loc_0x6C
  lwz r7, 1(r7)
  not r8, r7
  rlwinm r7, r7, 8, 24, 31
  rlwinm. r8, r8, 0, 8, 31
  cmpwi cr1, r7, 0x27
  crorc 20, 2, 6
  bge- cr5, loc_0x74
  addi r6, r6, 0x5
  cmpwi r6, 0x80
  blt+ loc_0x2C

loc_0x6C:
  lwz r3, 0(r3)
  blr 

loc_0x74:
  lbz r5, 23(r4)
  cmplwi r5, 0
  bne- loc_0x88
  li r5, 0x1
  stb r5, 23(r4)

loc_0x88:
  lwz r5, 60(r4)
  add r4, r4, r5
  lbzu r5, 170(r4)
  lbz r6, 5(r4)
  cmpwi r5, 0x0
  lbz r5, 10(r4)
  beq- loc_0xB4
  cmpwi r6, 0x0
  beq- loc_0xB4
  cmpwi r5, 0x0
  bne+ loc_0x6C

loc_0xB4:
  lis r5, 0x800
  stw r5, 11(r4)
  lis r5, 0x9800
  ori r5, r5, 0x6108
  stw r5, 8(r4)
  lis r5, 0x3361
  ori r5, r5, 0x7D9
  stw r5, 4(r4)
  lis r5, 0x6106
  ori r5, r5, 0x8003
  stw r5, 0(r4)
  lwz r3, 0(r3)
	}




//TOGGLES
// Disable HUD [Bully]
static void DisableHUD() {
	u8 dis = Pulsar::Settings::Mgr::GetSettingValue(static_cast<Pulsar::Settings::Type>(SETTINGSTYPE_BKW), SETTINGBKW_RADIO_DISABLEHUD);
	if (dis != 1) {
		asm("stfs f1, 0x0184 (r27);"); // Original instruction
	}
}
kmCall(0x807EC68C, DisableHUD);

} // namespace MiscCodes
} // namespace BKW
