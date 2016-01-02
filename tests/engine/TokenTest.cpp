#include <sstream>
#include "catch.hpp"
#include "engine/Token.h"

using std::string;
using engine::Token;

TEST_CASE("A model representing tokens in document", "[engine]") {

  const string word = "Wordify";
  const string normalized = "wordify";
  const string stem = "word";
  const string nullString = "";
  const int offset = 125;
  const int nullNumber = -1;

  SECTION("Can construct a token") {
    REQUIRE_NOTHROW(Token t);
  }

  SECTION("Can set a token's word") {
    Token t;
    REQUIRE_NOTHROW(t.SetWord(word));
    REQUIRE(t.GetWord() == word);
  }

  SECTION("Can set a token's normalized form") {
    Token t;
    REQUIRE_NOTHROW(t.SetNormalized(normalized));
    REQUIRE(t.GetNormalized() == normalized);
  }

  SECTION("Can set a token's stem form") {
    Token t;
    REQUIRE_NOTHROW(t.SetStem(stem));
    REQUIRE(t.GetStem() == stem);
  }

  SECTION("Can set a token's offset") {
    Token t;
    REQUIRE_NOTHROW(t.SetOffset(offset));
    REQUIRE(t.GetOffset() == offset);
  }

  SECTION("Gets an empty string when getting an unset word") {
    Token t;
    REQUIRE(t.GetWord() == nullString);
  }

  SECTION("Gets an empty string when getting an unset normalized form") {
    Token t;
    REQUIRE(t.GetNormalized() == nullString);
  }

  SECTION("Gets an empty string when getting an unset stem form") {
    Token t;
    REQUIRE(t.GetStem() == nullString);
  }

  SECTION("Gets -1 when getting an unset offset") {
    Token t;
    REQUIRE(t.GetOffset() == nullNumber);
  }
}
