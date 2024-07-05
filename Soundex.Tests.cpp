#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
 // ASSERT_EQ(soundex,"A200");
 generateSoundex("AVPHF", soundex);
 // ASSERT_EQ(soundex,"A100");
 generateSoundex("EVAPH", soundex);
 // ASSERT_EQ(soundex,"E110");
 generateSoundex("EXCELLENT", soundex);
 // ASSERT_EQ(soundex,"E245");
 generateSoundex("ROBERT", soundex);
 // ASSERT_EQ(soundex,"R163");
}
