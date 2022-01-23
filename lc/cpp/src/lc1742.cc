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

int main() {}