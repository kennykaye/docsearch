#include <string>
#include <vector>
#include <algorithm>
#include "engine/Tokenizer.h"
#include "engine/StopWords.h"
#include "util/StringUtils.h"

namespace engine {
  using std::string;
  using std::vector;
  using engine::Tokens;

  Tokenizer::Tokenizer(Tokens tokens) {
    tokens_ = tokens;
  }

  Tokenizer::~Tokenizer() {}

  void Tokenizer::FilterStopWords() {
    auto begin = tokens_.begin();
    auto end = tokens_.end();

    auto it = std::remove_if(begin, end, [this](const Token &t) {
      return engine::stopwords::IsStopWord(t.GetNormalized());
    });

    tokens_.erase(it, end);
  }

  void Tokenizer::NormalizeTokens() {
    // TODO: Remove trailing punctuation
    for (auto &t : tokens_) {
      t.SetNormalized(util::stringutils::ToLowercase(t.GetWord()));
    }
  }

  void Tokenizer::StemTokens() {
  }

  Tokens Tokenizer::GetTokens() {
    return tokens_;
  }

}
