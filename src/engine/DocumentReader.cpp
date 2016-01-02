#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "engine/Token.h"
#include "engine/DocumentReader.h"
#include "util/StringUtils.h"


namespace engine {
  using std::string;
  using std::vector;
  using std::ifstream;
  using engine::Token;
  using engine::Tokens;

  DocumentReader::DocumentReader(string title, string author, string path) {
    offset_ = 0;
    title_ = title;
    author_ = author;
    path_ = path;
  }

  DocumentReader::~DocumentReader() {};

  string DocumentReader::GetTitle() const {
    return title_;
  }

  string DocumentReader::GetAuthor() const {
    return author_;
  }

  string DocumentReader::GetPath() const {
    return path_;
  }

  Tokens DocumentReader::GetTokens() {
    Tokens total;
    offset_ = 0;
    Lines lines = DocumentReader::GetLines_();

    for (auto &line : lines) {
      Tokens tokens = DocumentReader::GetTokensPerLine_(line);
      total.insert(total.end(), tokens.begin(), tokens.end());
    }

    return total;
  }

  Tokens DocumentReader::GetTokensPerLine_(const string &line) {
    Tokens tokens;
    vector<string> words = util::stringutils::Split(line, ' ');

    for (auto &word : words) {
      Token token = Token();
      token.SetWord(word);
      token.SetOffset(offset_);
      tokens.push_back(token);
      ++offset_;
    }

    return tokens;
  }

  Lines DocumentReader::GetLines_() const {
    string line;
    Lines lines;
    ifstream stream(DocumentReader::GetPath());

    if (!stream.is_open()) {
      throw std::runtime_error("Unable to open file " + path_);
    }

    while (std::getline(stream, line)) {
      lines.push_back(line);
    }

    if (stream.bad()) {
      throw std::runtime_error("error while reading file " + path_);
    }

    stream.close();
    return lines;
  }

} // namespace engine
