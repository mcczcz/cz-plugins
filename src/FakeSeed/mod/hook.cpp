#include "ll/api/memory/Hook.h"
#include "mc/network/packet/StartGamePacket.h"
#include "mc/world/level/LevelSeed64.h"
#include "mc/world/level/LevelSettings.h"
#include "mod/Global.h"
#include <cstdint>
#include <random>

namespace {

std::int64_t generateRandomSeed() {
    thread_local std::mt19937_64 generator{std::random_device{}()};
    return std::uniform_int_distribution<std::int64_t>{}(generator);
}

} // namespace

LL_AUTO_TYPE_INSTANCE_HOOK(
    StartGamePacketHook,
    HookPriority::Normal,
    StartGamePacket,
    &StartGamePacket::$write,
    void,
    ::BinaryStream& stream
) {
    auto* packet = this;

    packet->mSettings->mSeed->mValue = FakeSeed::config.randomSeedEnabled
        ? generateRandomSeed()
        : FakeSeed::config.fakeSeed;

    origin(stream);
}
