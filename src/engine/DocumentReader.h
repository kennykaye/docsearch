#pragma once
#include <string>
#include <vector>
#include "engine/Token.h"

namespace engine {

  using Lines = std::vector<std::string>;

  class DocumentReader {
    public:
      DocumentReader(std::string title, std::string author, std::string path);
      ~DocumentReader();

      std::string GetTitle() const;
      std::string GetAuthor() const;
      std::string GetPath() const;
      engine::Tokens GetTokens() const;

    private:
      std::string title_;
      std::string author_;
      std::string path_;
      Lines GetLines_() const;
      engine::Tokens GetTokensPerLine_(const std::string &line, int num) const;
  };
} // namespace engine
