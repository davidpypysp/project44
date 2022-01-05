#include "base.h"

#include <queue>

class RecentCounter
{
public:
	RecentCounter()
	{
	}

	int ping(int t)
	{
		q.push(t);
		while (q.size() > 1 && t - q.front() > 3000)
		{
			q.pop();
		}
		return q.size();
	}

	std::queue<int> q;
};

int main()
{
	RecentCounter counter;
	std::cout << counter.ping(1) << std::endl;
	std::cout << counter.ping(100) << std::endl;
	std::cout << counter.ping(3000) << std::endl;
	std::cout << counter.ping(3002) << std::endl;
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
