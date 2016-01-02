#pragma once
#include <string>
#include <vector>

namespace engine {
  class Token {
    public:
      Token();

      std::string GetWord() const;
      std::string GetNormalized() const;
      std::string GetStem() const;
      int GetOffset() const;

      void SetWord(std::string word);
      void SetNormalized(std::string word);
      void SetStem(std::string stem);
      void SetOffset(int offset);

    private:
      std::string word_;
      std::string stem_;
      std::string normalized_;
      int offset_;
  };

  using Tokens = std::vector<engine::Token>;
} // namespace engine
