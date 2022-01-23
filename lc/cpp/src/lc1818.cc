#include "src/base.h"

class Solution {
public:
  int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2) {
    const int mod = 1e9 + 7;
    long long sum = 0;

    for (int i = 0; i < nums1.size(); i++) {
      sum += abs(nums1[i] - nums2[i]);
    }

    std::set<int> tree_set(nums1.begin(), nums1.end());

    int max_decr = 0;
    for (int i = 0; i < nums1.size(); i++) {
      auto it = tree_set.lower_bound(nums2[i]);

      int diff = INT_MAX;
      if (it != tree_set.end()) {
        diff = std::min(diff, *it - nums2[i]);
      }
      if (it != tree_set.begin()) {
        diff = std::min(diff, nums2[i] - *std::prev(it));
      }
      max_decr = std::max(abs(nums1[i] - nums2[i]) - diff, max_decr);
    }
    return (sum - max_decr) % mod;
  }
};

int main() {
  vector<int> nums1 = {1, 10, 4, 4, 2, 7};
  vector<int> nums2 = {9, 3, 5, 1, 7, 4};
  Solution solution;
  int result = solution.minAbsoluteSumDiff(nums1, nums2);
  std::cout << result << std::endl;
}