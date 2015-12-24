#pragma once
#include <string>
#include <vector>

namespace engine {

  class DocumentReader {
    public:
      DocumentReader(std::string title, std::string author, std::string path);
      ~DocumentReader();

      std::string GetTitle() const;
      std::string GetAuthor() const;
      std::string GetPath() const;
      std::vector<std::string> GetTerms() const;

    private:
      std::string title_;
      std::string author_;
      std::string path_;
      std::vector<std::string> GetLines_() const;
  };
} // namespace engine
