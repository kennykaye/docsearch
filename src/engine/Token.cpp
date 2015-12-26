#include "engine/Token.h"

namespace engine {
  using std::string;

  Token::Token() {
    nullInt_ = -1;
    nullString_ = "";

    word_ = nullString_;
    stem_ = nullString_;
    normalized_ = nullString_;

    lineNumber_ = nullInt_;
    wordNumber_ = nullInt_;
  };

  Token::~Token() {};

  string Token::GetWord() const {
    return word_;
  }

  string Token::GetNormalized() const {
    return normalized_;
  }

  string Token::GetStem() const {
    return stem_;
  }

  int Token::GetLineNumber() const {
    return lineNumber_;
  }

  int Token::GetWordNumber() const {
    return wordNumber_;
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

  void Token::SetLineNumber(int num) {
    lineNumber_ = num;
  }

  void Token::SetWordNumber(int num) {
    wordNumber_ = num;
  }

} // namespace engine
