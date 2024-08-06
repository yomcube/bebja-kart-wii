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

//Can Always Drift [Supastarrio]
kmWrite32(0x808B5B1C, 0x00000000);

//Enhanced Start Line (LE-CODE replica) [Kazuki]
kmCallDefAsm(0x807EAA94) {
loc_0x0:
  lis r12, 0x809C
  lwz r12, -10520(r12)
  lwz r12, 4(r12)
  lwz r12, 0(r12)
  lhz r10, 10(r12)
  lwz r11, 16(r12)
  add r11, r11, r10
  add r12, r12, r11
  lhz r11, 4(r12)
  cmpwi r11, 0x2
  blt- loc_0x40
  lhz r11, 60(r12)
  cmplwi r11, 65535
  bne- loc_0x40
  addi r12, r12, 0x24
  b loc_0x44

loc_0x40:
  addi r12, r12, 0x8

loc_0x44:
  lfs f2, 0(r12)
  lfs f0, 8(r12)
  lwz r12, 16(r12)
  lis r11, 0x8168
  stw r12, 12832(r11)
  stfs f2, 412(r3)
  nop 
  lfs f19, -21836(r30)
  .opword 0x0000000c
  lis r12, 0x8168
  lfs f1, 12832(r12)
  lis r12, 0x8000
  lbz r12, 24359(r12)
  lis r10, 0x809B
  cmpwi r12, 0xEC
  ori r11, r10, 0xD728
  beq- loc_0xA8
  cmpwi r12, 0x10
  ori r11, r10, 0xC788
  beq- loc_0xA8
  cmpwi r12, 0x54
  lis r11, 0x809A
  ori r11, r11, 0xBD68
  beq- loc_0xA8
  ori r11, r10, 0x8F68

loc_0xA8:
  lwz r11, 0(r11)
  lwz r11, 2960(r11)
  cmpwi r11, 0x1
  bne+ loc_0xBC
  fneg f1, f1

loc_0xBC:
  stfs f1, 428(r3)
}



//Items on Minimap [stebler] #1
kmCallDefAsm(0x80858194) {
loc_0x0:
  lis r3, 0x809C
  lwz r3, 13848(r3)
  lwz r4, 580(r3)
  lwz r4, 0(r4)
  lhz r4, 8(r4)
  lwz r3, 584(r3)
  add r3, r4, r3
  mulli r3, r3, 0x1B4
  addi r3, r3, 0x1A4
}

//Items on Minimap [stebler] #2
kmCallDefAsm(0x807EA450) {
loc_0x0:
  addi r26, r27, 0x1
  lis r5, 0x809C
  lwz r5, 13848(r5)
  lwz r6, 580(r5)
  lwz r6, 0(r6)
  lhz r6, 8(r6)
  lwz r5, 584(r5)
  add r5, r6, r5
  add r26, r26, r5
}

//Items on Minimap [stebler] #3
kmCallDefAsm(0x807EA6E0) {
loc_0x0:
  bctrl 
  li r26, 0x0
  addi r23, r24, 0x1A4

loc_0xC:
  li r25, 0x0

loc_0x10:
  mr r3, r23
  lis r12, 0x8063
  ori r12, r12, 0xD798
  mtctr r12
  bctrl 
  lis r3, 0x808D
  ori r3, r3, 0x3900
  stw r3, 0(r23)
  mr r3, r24
  addi r28, r28, 0x1
  mr r4, r28
  mr r5, r23
  lis r12, 0x8063
  ori r12, r12, 0xD278
  mtctr r12
  bctrl 
  addi r3, r1, 0x20
  stw r23, 0(r3)
  lis r6, 0x808A
  ori r4, r6, 0x9477
  ori r5, r6, 0x9482
  ori r6, r6, 0x9491
  li r7, 0x0
  lis r12, 0x805C
  ori r12, r12, 0x2C60
  mtctr r12
  bctrl 
  mr r3, r23
  lis r5, 0x808A
  ori r4, r5, 0x9477
  ori r5, r5, 0xA007
  lis r12, 0x8063
  ori r12, r12, 0xD9C0
  mtctr r12
  bctrl 
  stb r26, 129(r23)
  stb r25, 130(r23)
  lis r6, 0x808A
  ori r3, r6, 0xF7C0
  bl loc_0xC0
  .opword 0x000c182c
  ori r12, r2, 0x5820
  .opword 0x7840848c
  xori r28, r4, 36864

loc_0xC0:
  mflr r4
  lbzx r4, r4, r26
  add r5, r3, r4
  mr r3, r23
  ori r4, r6, 0xA7C8
  lis r12, 0x8063
  ori r12, r12, 0xE0F0
  mtctr r12
  bctrl 
  addi r23, r23, 0x1B4
  addi r25, r25, 0x1
  lis r3, 0x809C
  lwz r3, 13848(r3)
  mulli r4, r26, 0x24
  add r3, r3, r4
  lwz r3, 80(r3)
  cmpw r25, r3
  blt+ loc_0x10
  addi r26, r26, 0x1
  cmpwi r26, 0xF
  blt+ loc_0xC
}

//Items on Minimap [stebler] #4
kmCallDefAsm(0x807EACA8) {
loc_0x0:
  bctrl 
  lwz r3, 364(r31)
  cmpwi r3, 0x0
  beq- loc_0x78
  lwz r3, 408(r31)
  li r4, 0xA0
  stb r4, 184(r3)
  lis r4, 0x4140
  stw r4, 76(r3)
  stw r4, 80(r3)
  li r3, 0x1
  stb r3, 128(r31)
  lis r3, 0x809C
  lwz r3, 13848(r3)
  lbz r4, 129(r31)
  mulli r4, r4, 0x24
  add r3, r3, r4
  lwz r4, 88(r3)
  lbz r5, 130(r31)
  cmpw r5, r4
  bge- loc_0x78
  li r4, 0x0
  stb r4, 128(r31)
  lwz r3, 76(r3)
  rlwinm r4, r5, 2, 0, 29
  lwzx r3, r3, r4
  addi r4, r3, 0x44
  lswi r5, r4, 12
  addi r4, r31, 0x19C
  stswi r5, r4, 12

loc_0x78:
}


//Enhanced Ghost Replay [MrBean]
kmCallDefAsm(0x8062CCDC) {
loc_0x0:
  li r4, 0xD
  lis r5, 0x8062
  addi r5, r5, 0x2D08
  mtctr r5
  bctrl 
  lis r5, 0x809C
  lwz r5, 7736(r5)
  lwz r5, 0(r5)
  lwz r6, 228(r5)
  stw r6, 188(r5)
  lwz r6, 60(r5)
  stw r6, 228(r5)
  li r6, 0x0
  stw r6, 60(r5)
  mr r3, r31
  li r4, 0x3A
  nop 
  .opword 0x00000000
  lfs f19, 15360(r3)
  .opword 0x0000000f
  cmpwi r0, 0x34
  bnelr- 
  li r3, 0x1F
  lis r4, 0x809C
  lwz r4, 7736(r4)
  lwz r4, 0(r4)
  lwz r4, 228(r4)
  li r5, 0x5
  stw r5, 8(r4)
  li r5, 0x37
  stw r5, 68(r4)
  li r5, 0x0
  stw r5, 28(r4)
  stw r5, 32(r4)
  lwz r4, 0(r4)
  mflr r6
  bl loc_0xB0
  lwz r4, 68(r3)
  cmpwi r4, 0x37
  bne- loc_0xA8
  li r5, 0x2D
  stw r5, 68(r3)

loc_0xA8:
  mr r3, r4
  blr 

loc_0xB0:
  mflr r5
  mtlr r6
  stw r5, 16(r4)
  blr 
}


//Show Quit Confirmation Screen in Single Player [CLF78] #1
kmCallDefAsm(0x8062C66C) {
loc_0x0:
  mr r3, r31
  li r4, 0x2C
  lis r12, 0x8062
  ori r12, r12, 0x2D08
  mtctr r12
  bctrl 
  mr r3, r31
}

//Show Quit Confirmation Screen in Single Player [CLF78] #2
kmCallDefAsm(0x8062C7B0) {
loc_0x0:
  mr r3, r31
  li r4, 0x2C
  lis r12, 0x8062
  ori r12, r12, 0x2D08
  mtctr r12
  bctrl 
  mr r3, r31
}

//Hybrid Drift [Ismy & CLF78]
kmCallDefAsm(0x80578DCC) {
	loc_0x0:
  lwz r12, 0(r28)
  lwz r12, 0(r12)
  lwz r12, 20(r12)
  lwz r12, 0(r12)
  lwz r12, 4(r12)
  cmpwi r12, 0x2
  beq- loc_0x24
  li r0, 0x0
  b loc_0x28

loc_0x24:
  lwz r0, 20(r3)

loc_0x28:
  nop 
  .word 0x00000000
  lfs f18, -27892(r23)
  .word 0x00000006
  lwz r12, 0(r28)
  lwz r12, 0(r12)
  lwz r12, 20(r12)
  lwz r12, 0(r12)
  lwz r12, 4(r12)
  cmpwi r12, 0x2
  beq- loc_0x5C
  li r0, 0x0
  b loc_0x60

loc_0x5C:
  lwz r0, 20(r3)

loc_0x60:
  nop 
  .word 0x00000000
  lfs f18, -8280(r23)
  .word 0x00000004
  lwz r0, 20(r3)
  rlwinm. r12, r0, 0, 18, 18
  beq- loc_0x84
  ori r0, r0, 0x10
  stw r0, 20(r3)

loc_0x84:
  lwz r0, 4(r3)
  nop 
  .word 0x00000000
  lfs f18, -8168(r23)
  .word 0x00000004
  lwz r0, 20(r4)
  rlwinm. r12, r0, 0, 18, 18
  beq- loc_0xAC
  ori r0, r0, 0x10
  stw r0, 20(r4)

loc_0xAC:
  lwz r0, 4(r4)
  nop 
  .word 0x00000000
  lfs f18, -7928(r23)
  .word 0x00000003
  rlwinm. r0, r0, 0, 27, 27
  bne- loc_0xD0
  li r0, 0x0
  stw r0, 456(r3)

loc_0xD0:
  nop 
  .word 0x00000000
  lfs f18, -7228(r23)
  .word 0x00000004
  lwz r0, 20(r4)
  rlwinm. r12, r0, 0, 18, 18
  beq- loc_0xF4
  ori r0, r0, 0x10
  stw r0, 20(r4)

loc_0xF4:
  lwz r0, 4(r4)
  nop 
  .word 0x00000000
  lfs f18, 19112(r25)
  .word 0x00000005
  lwz r3, 4(r30)
  andi. r4, r3, 0x84
  beq- loc_0x128
  lwz r4, 20(r30)
  rlwinm r4, r4, 0, 28, 26
  stw r4, 20(r30)
  rlwinm r3, r3, 0, 4, 2
  stw r3, 4(r30)

loc_0x128:
  mr r3, r30
  .word 0x00000000
  .word 0x0059450e
  .word 0x00000020
  .word 0x04594a60
  nop 
  .word 0x045a35bc
  li r3, 0x0
  .word 0x02745ab0
  .word 0x00004800
  .word 0x028cb70a
}

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
