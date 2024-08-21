#include <gtest/gtest.h>
#include "Soundex.h"

// Test that consonants are replaced with the appropriate digits
TEST(SoundexTestSuite, ReplacesConsonantsWithAppropriateDigits) {
    char soundex[5];
    generateSoundex("AX", soundex);
    ASSERT_STREQ(soundex, "A200");

    generateSoundex("HERMAN", soundex);
    ASSERT_STREQ(soundex, "H655");

    generateSoundex("HERMANN", soundex);
    ASSERT_STREQ(soundex, "H655");

    generateSoundex("MEHUL", soundex);
    ASSERT_STREQ(soundex, "M040");

    generateSoundex("MAHUL", soundex);
    ASSERT_STREQ(soundex, "M040");
}

// Test that names with similar sounds generate the same Soundex code
TEST(SoundexTestSuite, HandlesNamesWithSimilarSounds) {
    char soundex1[5], soundex2[5];
    generateSoundex("Ashcraft", soundex1);
    generateSoundex("Ashcroft", soundex2);
    ASSERT_STREQ(soundex1, soundex2);

    generateSoundex("Rupert", soundex1);
    generateSoundex("Robert", soundex2);
    ASSERT_STREQ(soundex1, soundex2);
}

// Test that names with varying lengths are handled correctly
TEST(SoundexTestSuite, HandlesNamesOfDifferentLengths) {
    char soundex[5];
    generateSoundex("A", soundex);
    ASSERT_STREQ(soundex, "A000");

    generateSoundex("Ab", soundex);
    ASSERT_STREQ(soundex, "A100");

    generateSoundex("Able", soundex);
    ASSERT_STREQ(soundex, "A140");
}

// Test that names with adjacent letters mapping to the same digit are handled correctly
TEST(SoundexTestSuite, HandlesAdjacentLettersWithSameDigit) {
    char soundex[5];
    generateSoundex("Bbbb", soundex);
    ASSERT_STREQ(soundex, "B100");

    generateSoundex("Cccc", soundex);
    ASSERT_STREQ(soundex, "C200");
}
