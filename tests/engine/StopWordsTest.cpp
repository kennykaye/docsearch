#include "catch.hpp"
#include "engine/StopWords.h"

TEST_CASE("A Class for identifying stop words", "[engine]") {

  SECTION("Can determine if a given word is a stop word") {
    typedef std::pair<std::string, bool> Pair;

    std::vector<Pair> values = {
      Pair("Sweater", false), Pair("a",      true),
      Pair("below",   true),  Pair("is",     true),
      Pair("glow",    false), Pair("picture", false),
      Pair("this",    true),  Pair("candles", false),
      Pair("they've", true),  Pair("very",    true),
      Pair{"also",    true},  Pair("",        true),
      Pair(",",       true),  Pair(".",       true),
      Pair(" ",       true),  Pair(":",       true),
      Pair("!",       true),  Pair("?",       true),
    };

    for (auto &pair : values) {
      REQUIRE(engine::stopwords::IsStopWord(pair.first) == pair.second);
    }
  }
}
