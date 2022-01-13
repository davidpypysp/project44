#include "src/base.h"

class Solution
{
public:
	vector<string> findWords(vector<string> &words)
	{
		unordered_map<char, int> hash_map;
		vector<vector<char>> keyboard = {
			{'z', 'x', 'c', 'v', 'b', 'n', 'm'},
			{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'},
			{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'}};

		for (int i = 0; i < 3; i++)
		{
			for (auto c : keyboard[i])
			{
				hash_map[c] = i;
			}
		}

		vector<string> result;
		for (auto &word : words)
		{
			int hash = hash_map[tolower(word[0])];
			int in_row = true;
			for (auto &c : word)
			{
				if (hash_map[tolower(c)] != hash)
				{
					in_row = false;
					break;
				}
			}
			if (in_row)
			{
				result.push_back(word);
			}
		}
		return result;
	}
};

int main()
{
	Solution solution;
	vector<string> input = {"Hello", "Alaska", "Dad", "Peace"};
	auto result = solution.findWords(input);
}