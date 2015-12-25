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

} // namespace string
} // namespace utilities
