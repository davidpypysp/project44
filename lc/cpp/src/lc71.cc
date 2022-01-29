#include "src/base.h"

class Solution {
public:
  string simplifyPath(string path) {
    istringstream iss(path);
    string current;
    vector<string> strs;
    while (getline(iss, current, '/')) {
      if (current == "" || current == ".")
        continue;
      if (current == ".." && !strs.empty()) {
        strs.pop_back();
      } else if (current != "..") {
        strs.push_back(current);
      }
    }

    ostringstream ss;
    for (auto current : strs) {
      ss << "/" << current;
    }

    return ss.str().empty() ? "/" : ss.str();
  }
};

int main() {
  string s = "/home/";
  Solution sol;
  auto result = sol.simplifyPath(s);
  return 0;
}