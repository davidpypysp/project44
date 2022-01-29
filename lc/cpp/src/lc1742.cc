#include "src/base.h"

class Solution {
public:
  int get_sum(int num) {
    int sum = 0;
    while (num != 0) {
      sum += num % 10;
      num /= 10;
    }
    return sum;
  }

  int countBalls(int lowLimit, int highLimit) {
    unordered_map<int, int> sum_count_map;

    int max = 0;
    for (int i = lowLimit; i <= highLimit; i++) {
      int sum = get_sum(i);
      sum_count_map[sum]++;

      if (max < sum_count_map[sum]) {
        max = sum_count_map[sum];
      }
    }
    return max;
  }
};

int main() {
  vector<int> arr({1, 2, 3});
  auto it0 = arr.begin();
  std::cout << "it begin: " << *it0 << std::endl;
  auto it = arr.end();
  std::cout << "it end: " << *std::next(it) << std::endl;
  std::cout << "v3" << arr[2] << std::endl;
}