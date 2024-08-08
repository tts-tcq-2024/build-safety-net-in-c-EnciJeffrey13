
#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
  // generateSoundex("HERMAN", soundex);
  // generateSoundex("HERMANN", soundex);
  // generateSoundex("MEHUL", soundex);
  // generateSoundex("MAHUL", soundex);

  //ASSERT_EQ(soundex,"A200");
}
