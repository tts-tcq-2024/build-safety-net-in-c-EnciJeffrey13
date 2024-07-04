#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
    // Arrange
    char soundex[5];

    // Act
    generateSoundex("AX", soundex);

    // Assert
    ASSERT_EQ(strcmp(soundex, "A200"), 0);
}

TEST(SoundexTestsuite, PadsWithZerosToEnsureLengthIsFour) {
    // Arrange
    char soundex[5];

    // Act
    generateSoundex("A", soundex);

    // Assert
    ASSERT_EQ(strcmp(soundex, "A000"), 0);
}

TEST(SoundexTestsuite, IgnoresCase) {
    // Arrange
    char soundex1[5];
    char soundex2[5];

    // Act
    generateSoundex("Ashcraft", soundex1);
    generateSoundex("ashcraft", soundex2);

    // Assert
    ASSERT_EQ(strcmp(soundex1, soundex2), 0);
}

TEST(SoundexTestsuite, CombinesMultipleCharactersCorrectly) {
    // Arrange
    char soundex[5];

    // Act
    generateSoundex("Robert", soundex);

    // Assert
    ASSERT_EQ(strcmp(soundex, "R163"), 0);
}

TEST(SoundexTestsuite, HandlesNamesWithDifferentLengths) {
    // Arrange
    char soundex1[5];
    char soundex2[5];

    // Act
    generateSoundex("A", soundex1);
    generateSoundex("Abcdefg", soundex2);

    // Assert
    ASSERT_EQ(strcmp(soundex1, "A000"), 0);
    ASSERT_EQ(strcmp(soundex2, "A123"), 0);
}

TEST(SoundexTestsuite, HandlesNamesWithAdjacentSimilarCodes) {
    // Arrange
    char soundex[5];

    // Act
    generateSoundex("Pfister", soundex);

    // Assert
    ASSERT_EQ(strcmp(soundex, "P236"), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
