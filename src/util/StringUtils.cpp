#include <sstream>
#include <string>
#include <vector>
#include "util/StringUtils.h"

namespace util {
namespace stringutils {
  using std::istringstream;
  using std::string;
  using std::vector;

  vector<string> Split(const string &source, const char &delimiter) {
    vector<string> result;
    istringstream stream(source);

    for (string token; getline(stream, token, delimiter);) {
      result.push_back(token);
    }

    return result;
  }

} // namespace string
} // namespace utilities
