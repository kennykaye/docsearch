/*
Problem Statement:

  Find several lengthy plaintext documents with which you can experiment. The
  project is to create an inverted index from the documents, using the
  algorithms described above. You will also need to create an interface for
  input of queries and an engine for processing them. You can find a project
  partner on the forum.

Approach:

  Term processing
  1. Load terms from source text files
  2. Remove stopwords
  3. Tokenize terms
  4. Normalize terms
  5. Stem terms

  Indexing
  6. Aphabetically sort terms
  7. Sort terms by posting
  8. Consolidate terms into single dictionary
  9. Determine max frequency for each term
  10. Build postings list for each term
*/
#include <iostream>
#include "engine/DocumentReader.h"

using namespace std;

int main(int argc, char *argv[]) {

}
