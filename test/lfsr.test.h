#include "../include/Catch2/catch.h"
#include "../include/lfsr.h"

SCENARIO("Testing unint32 LFSR class basic features")
{
  GIVEN("A registers length and the position of taps")
  {
    int length = 10;
    /* taps are 2 and 6 */
    WHEN("Creating an LFSR object")
    {
      LFSR<int> secuence(length, {2, 6});
      THEN("All the atributes must be as expected")
      {
        CHECK(secuence.at(0) == 1);
        CHECK(secuence.length() == 10);
        CHECK(secuence.taps() == std::set<int>{2, 6});
        CHECK(secuence.to_string() == "[ 1 1 1 1 1 1 1 1 1 1 ]");
      }
      secuence.step();
      AND_THEN("Taking one step changes the vector")
      {
        CHECK(secuence.at(0) == 1);
        CHECK(secuence.length() == 10);
        CHECK(secuence.taps() == std::set<int>{2, 6});
        CHECK(secuence.to_string() == "[ 1 1 1 1 1 1 1 1 1 1 ]");
      }
    }
  }
}