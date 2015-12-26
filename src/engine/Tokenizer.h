#pragma once
#include "engine/Token.h"

namespace engine {
namespace tokenizer {

  void Tokenize(Tokens &tokens);

namespace internal {

  void FilterStopWords(Tokens &tokens);
  void NormalizeToken(Token &token);
  void StemToken(Token &token);

} // namespace internal
} // namespace tokenizer
} // namespace engine
