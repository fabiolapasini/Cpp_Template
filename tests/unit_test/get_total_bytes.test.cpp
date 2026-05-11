#include "utils.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace utils;

TEST(GetTotalBytes, GetTotalBytes_StandardImage) {
    EXPECT_EQ(utils::getTotalBytes(512, 512, 3), 786432);
}

TEST(GetTotalBytes, GetTotalBytes_ZeroDimensions) {
    EXPECT_EQ(utils::getTotalBytes(0, 512, 3), 0);
    EXPECT_EQ(utils::getTotalBytes(512, 0, 3), 0);
    EXPECT_EQ(utils::getTotalBytes(512, 512, 0), 0);
}

TEST(GetTotalBytes, GetTotalBytes_OverflowPrevention) {
    uint16_t w = 500;
    uint16_t h = 500;
    uint16_t c = 3;
    size_t expected = 750000;
    EXPECT_EQ(utils::getTotalBytes(w, h, c), expected);
}

TEST(GetTotalBytes, GetTotalBytes_MaxUint16) {
    uint16_t maxVal = 65535;
    EXPECT_EQ(utils::getTotalBytes(maxVal, 2, 1), 131070);
}
