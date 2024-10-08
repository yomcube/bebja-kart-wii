#include <kamek.hpp>
#include <BKW.hpp>
#include <MarioKartWii/Item/ItemSlot.hpp>
#include <MarioKartWii/Item/ItemManager.hpp>
#include <MarioKartWii/Race/RaceData.hpp>
#include <MarioKartWii/Race/RaceInfo/RaceInfo.hpp>
#include <SlotExpansion/CupsConfig.hpp>

// Copied from
// https://github.com/Brawlboxgaming/Variety-Pack/blob/main/code/Race/Item/Roulette.cpp

namespace BKW {
namespace MiscCodes {
static int AccurateItemRoulette(Item::ItemSlotData *itemSlotData, u16 itemBoxType, u8 position, ItemId prevRandomItem, bool r7){
    const u8 playerId = RaceInfo::sInstance->playerIdInEachPosition[position-1];
    const GameMode gameMode = RaceData::sInstance->racesScenario.settings.gamemode;
    if (gameMode != MODE_BATTLE && 
    gameMode != MODE_PRIVATE_BATTLE && 
    gameMode != MODE_PUBLIC_BATTLE){
        Item::Player *itemPlayer = &Item::Manager::sInstance->players[playerId];
        return itemSlotData->DecideItem(itemBoxType, position, itemPlayer->isHuman, 0x1, itemPlayer);
    }
    return itemSlotData->DecideRouletteItem(itemBoxType, position, prevRandomItem, r7);
}
kmCall(0x807ba1e4, AccurateItemRoulette);
kmCall(0x807ba428, AccurateItemRoulette);
kmCall(0x807ba598, AccurateItemRoulette);

} // namespace MiscCodes
} // namespace VP