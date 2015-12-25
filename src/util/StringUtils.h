#pragma once
#include <string>
#include <vector>

namespace util {
namespace stringutils {

  std::vector<std::string>
  Split(const std::string &source, const char &delimiter);

  std::string ToLowercase(std::string source);

} // namespace string
} // namespace utilities
