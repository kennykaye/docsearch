#include <sstream>
#include <string>
#include <vector>
#include "util/StringUtils.h"

namespace util {
namespace stringutils {
  using std::string;
  using std::vector;

  vector<string> Split(const string &source, const char &delimiter) {
    vector<string> result;
    std::istringstream stream(source);

    for (string token; getline(stream, token, delimiter);) {
      result.push_back(token);
    }

    return result;
  }

  string ToLowercase(string source) {
    std::transform(source.begin(), source.end(), source.begin(), ::tolower);
    return source;
  }

  string TrimPunctuation(string source) {
    if (source == "") {
      return source;
    }

    for (auto it = source.begin(); std::ispunct(*it);) {
      it = source.erase(it);
    }

    for (auto it = std::prev(source.end()); std::ispunct(*it); --it) {
      source.erase(it);
    }

    return source;
  }

} // namespace string
} // namespace utilities
