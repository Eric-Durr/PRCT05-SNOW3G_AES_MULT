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
      LFSR<int> secuence(length, {2, 9});
      THEN("All the atributes must be as expected")
      {
        CHECK(secuence.at(length - 1) == 1);
        CHECK(secuence.length() == 10);
        CHECK(secuence.taps() == std::set<int>{2, 9});
        CHECK(secuence.to_string() ==
              "\n"
              "[ 1 1 1 1 1 1 1 1 1 1 ]\n"
              "      ^             ^ \n");
      }
      secuence.step();
      AND_THEN("Taking one step changes the vector")
      {
        CHECK(secuence[length - 1] == 1);
        CHECK(secuence.length() == 10);
        CHECK(secuence.taps() == std::set<int>{2, 9});
        CHECK(secuence.to_string() ==
              "\n"
              "[ 0 1 1 1 1 1 1 1 1 1 ]\n"
              "      ^             ^ \n");
      }
      AND_THEN("Generating a secuence changes the vector and returns larger LFSR object")
      {
        CHECK(secuence.generate(13).to_string() ==
              "\n"
              "[ 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 1 ]\n"
              "      ^             ^                           \n");

        CHECK(secuence.length() == 10);
        CHECK(secuence.to_string() ==
              "\n"
              "[ 1 1 0 0 1 0 0 0 1 1 ]\n"
              "      ^             ^ \n");
      }
    }
    AND_WHEN("Creating LFSR object with default input 0")
    {
      LFSR<int> secuence(length, {1, 5}, 0);
      THEN("All the atributes must be as expected")
      {
        CHECK(secuence.at(length - 1) == 0);
        CHECK(secuence.length() == 10);
        CHECK(secuence.taps() == std::set<int>{1, 5});
        CHECK(secuence.to_string() ==
              "\n"
              "[ 0 0 0 0 0 0 0 0 0 0 ]\n"
              "    ^       ^         \n");
      }
      secuence.step();
      AND_THEN("Taking one step changes the vector")
      {
        CHECK(secuence.at(length - 1) == 0);
        CHECK(secuence.length() == 10);
        CHECK(secuence.taps() == std::set<int>{1, 5});
        CHECK(secuence.to_string() ==
              "\n"
              "[ 0 0 0 0 0 0 0 0 0 0 ]\n"
              "    ^       ^         \n");
      }
    }
  }
}