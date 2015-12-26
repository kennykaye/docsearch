#include <string>
#include <vector>
#include <algorithm>
#include "engine/Tokenizer.h"
#include "engine/StopWords.h"
#include "util/StringUtils.h"
#include "porter2_stemmer/porter2_stemmer.h"

namespace engine {
namespace tokenizer {
  using namespace engine::tokenizer::internal;

  using std::string;
  using std::vector;
  using engine::Tokens;

  void Tokenize(Tokens &tokens) {

    for (auto &token : tokens) {
      NormalizeToken(token);
      StemToken(token);
    }

    FilterStopWords(tokens);
  }

namespace internal {

  void FilterStopWords(Tokens &tokens) {
    auto begin = tokens.begin();
    auto end = tokens.end();

    auto it = std::remove_if(begin, end, [](const Token &t) {
      return engine::stopwords::IsStopWord(t.GetNormalized());
    });

    tokens.erase(it, end);
  }

  void NormalizeToken(Token &token) {
    string word = token.GetWord();
    word = util::stringutils::TrimPunctuation(word);
    word = util::stringutils::ToLowercase(word);
    token.SetNormalized(word);
  }

  void StemToken(Token &token) {
    string stem = token.GetNormalized();
    Porter2Stemmer::stem(stem);
    token.SetStem(stem);
  }

} // namespace internal
} // namespace tokenizer
} // namepsace engine
