#include "src/base.h"

#include <set>

class Solution {
public:
  int findRadius(vector<int> &houses, vector<int> &heaters) {
    std::set<int> heater_set;

    for (int heater : heaters) {
      heater_set.insert(heater);
    }

    int result = 0;
    for (int house : houses) {
      auto it = heater_set.lower_bound(house);

      int dist = INT_MAX;
      if (it != heater_set.begin()) {
        dist = std::min(dist, house - *std::prev(it));
      }

      if (it != heater_set.end()) {
        dist = std::min(dist, *it - house);
      }
      result = std::max(result, dist);
    }
    return result;
  }
};

int main() {
  vector<int> house = {1, 5};
  vector<int> heaters = {2};

  Solution solution;
  int result = solution.findRadius(house, heaters);
  std::cout << "result = " << result << std::endl;
}