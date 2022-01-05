#include "base.h"

class BrowserHistory
{
public:
	BrowserHistory(string homepage)
	{
		urls.push_back(homepage);
		index = 0;
		capacity = 1;
	}

	void visit(string url)
	{
		if (index == capacity - 1)
		{
			urls.push_back(url);
			index++;
			capacity++;
		}
		else
		{
			urls[++index] = url;
			capacity = index + 1;
			urls.resize(capacity);
		}
	}

	string back(int steps)
	{
		if (index - steps >= 0)
		{
			index -= steps;
			return urls[index];
		}
		index = 0;
		return urls[0];
	}

	string forward(int steps)
	{
		if (index + steps < capacity - 1)
		{
			index += steps;
			return urls[index];
		}
		index = capacity - 1;
		return urls[index];
	}

	vector<string> urls;
	int index;
	int capacity;
};

int main()
{
	BrowserHistory browser_history("leetcode.com");
	browser_history.visit("google.com");
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */