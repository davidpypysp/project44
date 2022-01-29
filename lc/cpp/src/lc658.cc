#include "src/base.h"

class Solution2 {
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    auto comp = [](int a, int b) {
      if (abs(a) == abs(b)) {
        return a > b;
      }
      return abs(a) > abs(b);
    };

    priority_queue<int, vector<int>, decltype(comp)> pq(comp);

    for (int num : arr) {
      pq.push(num - x);
      if (pq.size() > k) {
        pq.pop();
      }
    }

    vector<int> result;
    while (pq.empty() == false) {
      result.push_back(pq.top() + x);
      pq.pop();
    }
    return result;
  }
};

class Solution {
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    int index = std::lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    if ((index == arr.size()) ||
        (index > 0 && abs(arr[index - 1] - x) <= abs(arr[index] - x))) {
      index--;
    }
    int left = index - 1;
    int right = index + 1;

    int count = 1;
    while (count < k) {
      int diff_left = (left >= 0) ? abs(x - arr[left]) : INT_MAX;
      int diff_right = (right < arr.size()) ? abs(x - arr[right]) : INT_MAX;

      if (diff_left <= diff_right) {
        left--;
      } else {
        right++;
      }
      count++;
    }

    vector<int> result(arr.begin() + (left + 1), arr.begin() + right);
    return result;
  }
};

int main() {
  std::cout << "Test" << std::endl;
  vector<int> input = {1, 2, 3, 4, 5};
  Solution solution;
  solution.findClosestElements(input, 4, 3);
}