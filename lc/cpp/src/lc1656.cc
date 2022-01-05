#include <string>
#include <vector>

using namespace std;

class OrderedStream
{
public:
	OrderedStream(int n)
	{
		capacity = n;
		index = 0;
	}

	vector<string> insert(int idKey, string value)
	{
		container[idKey - 1] = value;

		vector<string> result;
		while (index < capacity && container[index].size() > 0)
		{
			result.push_back(container[index]);
			index++;
		}
		return result;
	}

	int index;
	int capacity;
	string container[1000];
};

int main()
{
	OrderedStream *obj = new OrderedStream(2);
	vector<string> param_1 = obj->insert(3, "aaaaa");
}

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */