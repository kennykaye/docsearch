#pragma once
#include "engine/Token.h"

namespace engine {
  class Tokenizer {
    public:
      Tokenizer(engine::Tokens tokens);
      ~Tokenizer();

      engine::Tokens GetTokens();
      void FilterStopWords();
      void NormalizeTokens();
      void StemTokens();

    private:
      engine::Tokens tokens_;
  };
} // namespace engine
