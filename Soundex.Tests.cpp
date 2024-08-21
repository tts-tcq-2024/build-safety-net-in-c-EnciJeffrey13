#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTestSuite, GeneratesCorrectSoundexCodes) {
    char soundex[5];
    
    generateSoundex("AX", soundex);       ASSERT_STREQ(soundex, "A200");
    generateSoundex("HERMAN", soundex);   ASSERT_STREQ(soundex, "H655");
    generateSoundex("MAHUL", soundex);    ASSERT_STREQ(soundex, "M040");
    generateSoundex("Ashcraft", soundex); ASSERT_STREQ(soundex, "A226");
    generateSoundex("Robert", soundex);   ASSERT_STREQ(soundex, "R163");
}
