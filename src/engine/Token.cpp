#include "engine/Token.h"

namespace engine {
  using std::string;

  Token::Token() {
    word_ = "";
    stem_ = "";
    normalized_ = "";
    offset_ = -1;
  };

  string Token::GetWord() const {
    return word_;
  }

  string Token::GetNormalized() const {
    return normalized_;
  }

  string Token::GetStem() const {
    return stem_;
  }

  int Token::GetOffset() const {
    return offset_;
  }

  void Token::SetWord(string word) {
    word_ = word;
  }

  void Token::SetStem(string stem) {
    stem_ = stem;
  }

  void Token::SetNormalized(string word) {
    normalized_ = word;
  }

  void Token::SetOffset(int offset) {
    offset_ = offset;
  }

} // namespace engine
