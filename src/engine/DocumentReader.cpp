#include <exception>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include "DocumentReader.h"
#include "util/StringUtils.h"


namespace engine {
  using std::string;
  using std::vector;
  using std::ifstream;

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

  vector<string> DocumentReader::GetTerms() const {
    vector<string> terms;
    vector<string> lines = DocumentReader::GetLines_();

    for (auto &line : lines) {
      vector<string> tokens = util::stringutils::Split(line, ' ');
      terms.insert(terms.end(), tokens.begin(), tokens.end());
    }

    return terms;
  }

  vector<string> DocumentReader::GetLines_() const {
    string line;
    vector<string> lines;
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
