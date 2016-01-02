#include <iostream>
#include <fstream>
#include "catch.hpp"
#include "engine/Document.h"

using std::string;
using std::vector;
using engine::Tokens;
using engine::Document;

TEST_CASE("Document can read plain text files", "[engine]") {
  string title = "test doc";
  string author = "test author";
  string path = "tests/engine/existent.txt";
  Document reader(title, author, path);

  SECTION("Can construct document reader") {
    REQUIRE_NOTHROW(Document r(title, author, path));
  }

  SECTION("Can get the document uid") {
    REQUIRE(reader.GetUid());
  }

  SECTION("Can get the document title") {
    REQUIRE(reader.GetTitle() == title);
  }

  SECTION("Can get document author") {
    REQUIRE(reader.GetAuthor() == author);
  }

  SECTION("Can get document path") {
    REQUIRE(reader.GetPath() == path);
  }

  SECTION("Can get the tokens in a document") {
    REQUIRE_NOTHROW(reader.GetTokens());

    Tokens tokens = reader.GetTokens();

    REQUIRE(!tokens.empty());

    for (size_t i = 0; i != tokens.size(); ++i) {
      int offset = tokens[i].GetOffset();
      int word = std::stoi(tokens[i].GetWord());
      REQUIRE(offset == i);
      REQUIRE(word == i);
    }
  }

  SECTION("Document Uid's are unique") {
    vector<int> docs;

    for (int i = 0; i < 10000; ++i) {
      Document r("title", "author", "path/to/" + std::to_string(i));
      docs.push_back(r.GetUid());
    }

    std::sort(docs.begin(), docs.end());
    REQUIRE(std::adjacent_find(docs.begin(), docs.end()) == docs.end());
  }

  SECTION("Throws exception when opening nonexistent file") {
    Document r("title", "author", "nonexistent.txt");
    REQUIRE_THROWS(r.GetTokens());
  }

  SECTION("Throws an exception when opening empty file") {
    Document r("title", "author", "tests/engine/emtpy.txt");
    REQUIRE_THROWS(r.GetTokens());
  }

};
