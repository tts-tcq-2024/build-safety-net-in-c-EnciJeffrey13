// #include <gtest/gtest.h>
// #include "Soundex.h"

// TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
//     char soundex[5];
//     generateSoundex("AX", soundex);
//     ASSERT_EQ(strcmp(soundex, "A200"), 0);
// }

// TEST(SoundexTestsuite, PadsWithZerosToEnsureLengthIsFour) {
//     char soundex[5];
//     generateSoundex("A", soundex);
//     ASSERT_EQ(strcmp(soundex, "A000"), 0);
// }

// TEST(SoundexTestsuite, IgnoresCase) {
//     char soundex1[5];
//     char soundex2[5];
//     generateSoundex("Ashcraft", soundex1);
//     generateSoundex("ashcraft", soundex2);
//     ASSERT_EQ(strcmp(soundex1, soundex2), 0);
// }

// TEST(SoundexTestsuite, CombinesMultipleCharactersCorrectly) {
//     char soundex[5];
//     generateSoundex("Robert", soundex);
//     ASSERT_EQ(strcmp(soundex, "R163"), 0);
// }

// TEST(SoundexTestsuite, HandlesNamesWithDifferentLengths) {
//     char soundex1[5];
//     char soundex2[5];
//     generateSoundex("A", soundex1);
//     generateSoundex("Abcdefg", soundex2);
//     ASSERT_EQ(strcmp(soundex1, "A000"), 0);
//     ASSERT_EQ(strcmp(soundex2, "A123"), 0);
// }

// TEST(SoundexTestsuite, HandlesNamesWithAdjacentSimilarCodes) {
//     char soundex[5];
//     generateSoundex("Pfister", soundex);
//     ASSERT_EQ(strcmp(soundex, "P236"), 0);
// }

// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
// #include <gtest/gtest.h>
// #include "Soundex.h"
 
// TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
// //AAA
//   char soundex[5];
// generateSoundex("$rrr", soundex);
// ASSERT_STREQ(soundex,"$666");
// }
 
// TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_1) {
// //AAA
// char soundex[5];
// generateSoundex("pvt", soundex);
// ASSERT_STREQ(soundex,"P130");
// }
 
// TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_2) {
// //AAA
//   char soundex[5];
// generateSoundex("*#12hi", soundex);
// ASSERT_STREQ(soundex,"*000");
// }
 
// TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_vowels) {
// //AAA
// char soundex[5];
// generateSoundex("aeiou", soundex);
// ASSERT_STREQ(soundex,"A000");
// }

// TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_space) {
// //AAA
// char soundex[5];
// generateSoundex(" ", soundex);
// ASSERT_STREQ(soundex," 000");
// }
 
// TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_3) {
// //AAA
// char soundex[5];
// generateSoundex("bcdlmnr", soundex);
// ASSERT_STREQ(soundex,"B234");
// }
#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTestSuite, ReplacesConsonantsWithAppropriateDigits) {
    char soundex[5];
    generateSoundex("brrr", soundex);
    ASSERT_STREQ(soundex, "B600");
}

TEST(SoundexTestSuite, ReplacesConsonantsWithAppropriateDigits_1) {
    char soundex[5];
    generateSoundex("pvt", soundex);
    ASSERT_STREQ(soundex, "P130");
}

TEST(SoundexTestSuite, HandlesSpecialCharacters) {
    char soundex[5];
    generateSoundex("*#12hi", soundex);
    ASSERT_STREQ(soundex, "H000");
}

TEST(SoundexTestSuite, IgnoresVowels) {
    char soundex[5];
    generateSoundex("aeiou", soundex);
    ASSERT_STREQ(soundex, "A000");
}

TEST(SoundexTestSuite, HandlesSpace) {
    char soundex[5];
    generateSoundex(" ", soundex);
    ASSERT_STREQ(soundex, " 000");
}

TEST(SoundexTestSuite, HandlesMultipleConsonants) {
    char soundex[5];
    generateSoundex("bcdlmnr", soundex);
    ASSERT_STREQ(soundex, "B234");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
