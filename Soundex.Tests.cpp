#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTestSuite, GeneratesCorrectCodes) {
    char soundex[5];

    generateSoundex("AX", soundex);
    ASSERT_STREQ(soundex, "A200");

    generateSoundex("HERMAN", soundex);
    ASSERT_STREQ(soundex, "H655");

    generateSoundex("MAHUL", soundex);
    ASSERT_STREQ(soundex, "M040");

    generateSoundex("Ashcraft", soundex);
    ASSERT_STREQ(soundex, "A226");

    generateSoundex("Robert", soundex);
    ASSERT_STREQ(soundex, "R163");

    generateSoundex("Bbbb", soundex);
    ASSERT_STREQ(soundex, "B100");
}
