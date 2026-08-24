#pragma once

#include "ll/api/io/LogLevel.h"
#include <cstdint>
#include <string>

namespace FakeSeed {

struct Config {
    int              version                  = 1;
    ll::io::LogLevel logLevel                 = ll::io::LogLevel::Info;
    std::string      language                 = "en_US";
    std::int64_t     fakeSeed                 = 4;
    bool             randomSeedEnabled        = false;
};

} // namespace FakeSeed
