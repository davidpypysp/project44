#include "src/base.h"

class Solution {
public:
  int numJewelsInStones(string jewels, string stones) {
    unordered_set<char> hash_set;
    for (char c : jewels) {
      hash_set.insert(c);
    }

    int result = 0;
    for (char c : stones) {
      if (hash_set.find(c) == hash_set.end()) {
        result++;
      }
    }
    return stones.size() - result;
  }
};

int main() {}