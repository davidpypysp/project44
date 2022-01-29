#include "src/base.h"

class KthLargest {
public:
  KthLargest(int k, vector<int> &nums) {
    capacity = k;
    for (int num : nums) {
      add(num);
    }
  }

  int add(int val) {
    min_heap.push(val);
    if (min_heap.size() > capacity) {
      min_heap.pop();
    }
    return min_heap.top();
  }

  int capacity;
  priority_queue<int, vector<int>, std::greater<int>> min_heap;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main() {}