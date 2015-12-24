#include <iostream>
#include <fstream>
#include "catch.hpp"
#include "engine/DocumentReader.h"

using std::string;
using std::vector;
using engine::DocumentReader;

TEST_CASE("DocumentReader can read plain text files", "[engine]") {
  string title = "test doc";
  string author = "test author";
  string path = "tests/engine/existent.txt";
  DocumentReader reader(title, author, path);

  SECTION("Can construct document reader") {
    REQUIRE_NOTHROW(DocumentReader r(title, author, path));
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

  SECTION("Can get the terms in a document") {
    vector<string> terms = reader.GetTerms();

    for (int i = 0; i < terms.size(); ++i) {
      REQUIRE(std::stoi(terms[i]) == i);
    }
  };

  SECTION("Throws exception when opening nonexistent file") {
    DocumentReader r("title", "author", "nonexistent.txt");
    REQUIRE_THROWS(r.GetTerms());
  }

  SECTION("Throws an exception when opening empty file") {
    DocumentReader r("title", "author", "tests/engine/emtpy.txt");
    REQUIRE_THROWS(r.GetTerms());
  }
};
