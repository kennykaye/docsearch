#include "catch.hpp"
#include "engine/Tokenizer.h"

using std::vector;
using engine::Token;
using engine::Tokens;
using engine::Tokenizer;
using Words = std::vector<std::string>;

bool TokensHaveSameWords(const Tokens &a, const Tokens &b) {
  bool equal = true;
  for (size_t i = 0; i != a.size(); ++i) {
    if (a[i].GetNormalized() != b[i].GetNormalized()) {
      equal = false;
    }
  }
  return equal;
}

Tokens CreateTokensFromWords(const Words &words) {
  Tokens tokens;

  for (auto &word : words) {
    Token token = Token();
    token.SetWord(word);
    tokens.push_back(token);
  }

  Tokenizer t(tokens);
  t.NormalizeTokens();

  return t.GetTokens();
}

TEST_CASE("Tokenizer can mutate a list of tokens", "[engine]") {

  Tokens source = CreateTokensFromWords({
    "The", "quick", "brown", "fox", ",", "also", "called", "Bartholomew",
    ",", "jumped", "over", "Fido", ",", "who", "is", "known", "to", "be",
    "a", "very", "lazy", "brown", "dog", "."
  });

  SECTION("Can normalze a list of tokens") {
    Tokens tokens = CreateTokensFromWords({
      "The", "QuIcK", "BROWN", "fox"
    });

    Tokens target = CreateTokensFromWords({
      "the", "quick", "brown", "fox"
    });

    Tokenizer t(tokens);
    t.NormalizeTokens();
    Tokens filtered = t.GetTokens();

    REQUIRE(TokensHaveSameWords(filtered, target));
  }

  SECTION("Can filter stopwords from a list of tokens") {
    Tokens target = CreateTokensFromWords({
      "quick", "brown", "fox", "called", "bartholomew", "jumped", "fido",
      "known", "lazy", "brown", "dog"
    });

    Tokenizer t(source);
    t.NormalizeTokens();
    t.FilterStopWords();
    Tokens filtered = t.GetTokens();

    REQUIRE(TokensHaveSameWords(filtered, target));
  }
}
