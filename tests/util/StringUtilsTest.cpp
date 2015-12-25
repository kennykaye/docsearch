#include "catch.hpp"
#include "util/StringUtils.h"

using std::string;
using std::vector;
using util::stringutils::Split;
using util::stringutils::ToLowercase;

TEST_CASE("Strings can be split by delimiter", "[string] [utils]") {

  SECTION("Can split a comma seperated list of integers") {
    string source = "1,2,3,4,5";
    char delimiter = ',';
    vector<string> ints = Split(source, delimiter);
    int size = static_cast<int>(ints.size());
    for (int i = 0; i < size; ++i) {
      REQUIRE(std::stoi(ints[i]) == i + 1);
    }
  }

  SECTION("Can split a comma seperated list of words") {
    string source = "The,lazy,brown,fox";
    string wordsArray[4] = {"The", "lazy", "brown", "fox"};
    char delimiter = ',';
    vector<string> words = Split(source, delimiter);
    int size = static_cast<int>(words.size());
    for (int i = 0; i < size; ++i) {
      REQUIRE(words[i] == wordsArray[i]);
    }
  }

  SECTION("Can split a space seperated list of integers") {
    string source = "1 2 3 4 5";
    char delimiter = ' ';
    vector<string> ints = Split(source, delimiter);
    int size = static_cast<int>(ints.size());
    for (int i = 0; i < size; ++i) {
      REQUIRE(std::stoi(ints[i]) == i + 1);
    }
  }

  SECTION("Can split a space seperated list of strings") {
    string source = "The lazy brown fox";
    string wordsArray[4] = {"The", "lazy", "brown", "fox"};
    char delimiter = ' ';
    vector<string> words = Split(source, delimiter);
    int size = static_cast<int>(words.size());
    for (int i = 0; i < size; ++i) {
      REQUIRE(words[i] == wordsArray[i]);
    }
  }

  SECTION("When no delimiter, returns vector with original string") {
    string source = "1,2,3,4,5";
    char delimiter = ' ';
    vector<string> vect = Split(source, delimiter);
    REQUIRE_FALSE(vect.empty());
    REQUIRE(vect.size() == 1);
    REQUIRE(vect.front() == source);
  }
}

TEST_CASE("Can transform a string to lowercase", "[string] [utils]") {

  SECTION("An all lowercase string remains lowercase") {
    string lower = "all lowercase";
    REQUIRE(ToLowercase(lower) == lower);
  }

  SECTION("An all uppercase string becomes lowercase") {
    string upper = "ALL LOWERCASE";
    string lower = "all lowercase";
    REQUIRE(ToLowercase(upper) == lower);
  }

  SECTION("A mixed case string becomes lowercase") {
    string mixed = "all LOwERcASe";
    string lower = "all lowercase";
    REQUIRE(ToLowercase(mixed) == lower);
  }

  SECTION("Numerals are not transformed") {
    string mixed = "all LOWERCASE 12345";
    string lower = "all lowercase 12345";
    REQUIRE(ToLowercase(mixed) == lower);
  }
}
