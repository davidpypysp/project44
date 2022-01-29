#include "src/base.h"

class Solution {
public:
  char findTheDifference(string s, string t) {
    unordered_map<char, int> umap;
    for (char c : s) {
      umap[c]++;
    }
    for (char c : t) {
      umap[c]--;
    }

    for (auto [c, cnt] : umap) {
      if (cnt != 0) {
        return c;
      }
    }
    return '$';
  }
};

int main() {
  Solution sol;
  char result = sol.findTheDifference("abcd", "abcde");
  std::cout << "result: " << result << std::endl;
}