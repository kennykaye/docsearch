#pragma once
#include <string>
#include <vector>
#include "engine/Token.h"

namespace engine {

  using Lines = std::vector<std::string>;

  class DocumentReader {
    public:
      DocumentReader(std::string title, std::string author, std::string path);

      int GetUid() const;
      std::string GetTitle() const;
      std::string GetAuthor() const;
      std::string GetPath() const;
      engine::Tokens GetTokens();

    private:
      static int newUID;
      const int UID_;
      int offset_;
      std::string title_;
      std::string author_;
      std::string path_;
      Lines GetLines_() const;
      engine::Tokens GetTokensPerLine_(const std::string &line);
  };
} // namespace engine
