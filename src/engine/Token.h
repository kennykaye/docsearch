#pragma once
#include <string>
#include <vector>

namespace engine {
  class Token {
    public:
      Token();
      ~Token();

      std::string GetWord() const;
      std::string GetNormalized() const;
      std::string GetStem() const;
      int GetLineNumber() const;
      int GetWordNumber() const;

      void SetWord(std::string word);
      void SetNormalized(std::string word);
      void SetStem(std::string stem);
      void SetLineNumber(int num);
      void SetWordNumber(int num);

    private:
      std::string word_;
      std::string stem_;
      std::string normalized_;
      std::string nullString_;
      int nullInt_;
      int lineNumber_;
      int wordNumber_;
  };

  using Tokens = std::vector<Token>;
} // namespace engine
