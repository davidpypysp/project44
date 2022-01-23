#include "src/base.h"

class Solution {
public:
  int countConsistentStrings(string allowed, vector<string> &words) {
    std::unordered_set<char> uset(allowed.begin(), allowed.end());

    int result = 0;
    for (auto &word : words) {
      int counted = 1;
      for (auto &c : word) {
        if (uset.find(c) == uset.end()) {
          counted = 0;
          break;
        }
      }
      result += counted;
    }

    return result;
  }
};

int main() {
  string allowed = "ab";
  vector<string> words = {"ad", "bd", "aaab", "baa", "badab"};

  Solution solution;
  int result = solution.countConsistentStrings(allowed, words);
}