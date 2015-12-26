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
  using engine::Tokens;

  DocumentReader::DocumentReader(string title, string author, string path) {
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

  Tokens DocumentReader::GetTokens() const {
    Tokens total;
    Lines lines = DocumentReader::GetLines_();

    for (size_t i = 0; i != lines.size(); ++i) {
      Tokens tokens = DocumentReader::GetTokensPerLine_(lines[i], i);
      tokens.insert(total.end(), total.begin(), tokens.end());
    }

    return total;
  }

  Tokens DocumentReader::GetTokensPerLine_(const string &line, int num) const {
    Tokens tokens;
    vector<string> words = util::stringutils::Split(line, ' ');

    for (size_t i = 0; i != words.size(); ++i) {
      Token token = Token();
      token.SetWord(words[i]);
      token.SetWordNumber(i);
      token.SetLineNumber(num);
      tokens.push_back(token);
    }

    return tokens;
  }

  Lines DocumentReader::GetLines_() const {
    string line;
    Lines lines;
    ifstream stream(DocumentReader::GetPath());

    if (!stream.is_open()) {
      throw std::runtime_error("Unable to open file");
    }

    while (std::getline(stream, line)) {
      lines.push_back(line);
    }

    if (stream.bad()) {
      throw std::runtime_error("error while reading file");
    }

    stream.close();
    return lines;
  }

} // namespace engine
