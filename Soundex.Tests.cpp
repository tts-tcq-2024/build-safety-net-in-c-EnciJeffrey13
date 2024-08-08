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
#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>
void generateSoundex(const char *name, char *soundex){
    char mappings[] = "01230120022455012623010202";
    memset(soundex, '0', 4);
    soundex[0] = toupper(name[0]);
    int sIndex = 1, i = 1;
    while(++i < strlen(name) && sIndex < 4){
        char c = toupper(name[i]) - 65;
        if (mappings[c] != '0' && mappings[c] != soundex[sIndex - 1]) 
            soundex[sIndex++] = mappings[c];
    }
    soundex[4] = '\0';
}

#endif // SOUNDEX_H
