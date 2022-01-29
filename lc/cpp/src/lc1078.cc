#include "src/base.h"

class Solution {
public:
  vector<string> findOcurrences(string text, string first, string second) {
    vector<string> words;
    stringstream ss(text);

    string word;
    while (getline(ss, word, ' ')) {
      if (word == "")
        continue;
      words.push_back(word);
    }

    vector<string> result;
    for (int i = 0; i < words.size(); i++) {
      auto current = words[i];
      if (current == first && i + 2 < words.size() && words[i + 1] == second) {
        result.push_back(words[i + 2]);
      }
    }
    return result;
  }
};

int main() {
  Solution sol;
  //   auto result = sol.findOcurrences("alice is a good girl she is a good
  //   student",
  //                                    "a", "good");
  auto result = sol.findOcurrences("we will we will rock you", "we", "will");

  for (auto str : result) {
    std::cout << str << " ";
  }
  std::cout << std::endl;
  return 0;
}