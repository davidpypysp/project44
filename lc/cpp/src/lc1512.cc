#include "src/base.h"

class Solution
{
public:
	int numIdenticalPairs(vector<int> &nums)
	{
		unordered_map<int, int> hash_map;
		for (int i = 0; i < nums.size(); i++)
		{
			hash_map[nums[i]]++;
		}

		int result = 0;
		for (auto p : hash_map)
		{
			int val = p.second;
			result += val * (val - 1) / 2;
		}
		return result;
	}
};

int main()
{
	Solution solution;
	vector<int> input = {1, 2, 3, 1, 1, 3, 1};
	int result = solution.numIdenticalPairs(input);
	std::cout << "result: " << result << std::endl;
}