#include "catch.hpp"
#include "engine/Tokenizer.h"

using std::vector;
using engine::Token;
using engine::Tokens;
using engine::tokenizer::Tokenize;
using Words = std::vector<std::string>;

bool TokensHaveSameWords(const Tokens &a, const Tokens &b) {
  bool equal = true;
  for (size_t i = 0; i != a.size(); ++i) {
    if (a[i].GetNormalized() != b[i].GetNormalized()) {
      equal = false;
    }

    if (a[i].GetStem() != b[i].GetStem()) {
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

  Tokenize(tokens);

  return tokens;
}

TEST_CASE("Tokenizer can mutate a list of tokens", "[engine]") {

  SECTION("Can filter stopwords from a list of tokens") {
    Tokens source = CreateTokensFromWords({
      "The", "quick", "brown", "fox,", "also", "called", "Bartholomew",
      "jumped", "over", "Fido", "-", "who", "is", "known", "to", "be",
      "a", "very", "lazy", "brown", "dog!"
    });

    Tokens target = CreateTokensFromWords({
      "quick", "brown", "fox", "called", "bartholomew", "jumped",
      "fido", "known", "lazy", "brown", "dog",
    });

    Tokenize(source);

    REQUIRE(TokensHaveSameWords(source, target));
  }
}
