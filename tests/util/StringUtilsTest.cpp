#include "catch.hpp"
#include "util/StringUtils.h"

using std::string;
using std::vector;
using util::stringutils::Split;

TEST_CASE("Strings can be split by delimiter", "[string] [utils]") {

  SECTION("Can split a comma seperated list of integers") {
    string source = "1,2,3,4,5";
    char delimiter = ',';
    vector<string> ints = Split(source, delimiter);
    for (int i = 0; i < ints.size(); ++i) {
      REQUIRE(std::stoi(ints[i]) == i + 1);
    }
  }

  SECTION("Can split a comma seperated list of words") {
    string source = "The,lazy,brown,fox";
    string wordsArray[4] = {"The", "lazy", "brown", "fox"};
    char delimiter = ',';
    vector<string> words = Split(source, delimiter);
    for (int i = 0; i < words.size(); ++i) {
      REQUIRE(words[i] == wordsArray[i]);
    }
  }

  SECTION("Can split a space seperated list of integers") {
    string source = "1 2 3 4 5";
    char delimiter = ' ';
    vector<string> ints = Split(source, delimiter);
    for (int i = 0; i < ints.size(); ++i) {
      REQUIRE(std::stoi(ints[i]) == i + 1);
    }
  }

  SECTION("Can split a space seperated list of strings") {
    string source = "The lazy brown fox";
    string wordsArray[4] = {"The", "lazy", "brown", "fox"};
    char delimiter = ' ';
    vector<string> words = Split(source, delimiter);
    for (int i = 0; i < words.size(); ++i) {
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
