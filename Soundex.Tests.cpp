#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
 // ASSERT_EQ(soundex,"A200");
}// #include <gtest/gtest.h>
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
