#include "src/base.h"

class MyHashMap
{
public:
	MyHashMap()
	{
		capacity = 1000;
		buckets.resize(1000);
	}

	int get_hash(int key)
	{
		return key % capacity;
	}

	void put(int key, int value)
	{
		int hash = get_hash(key);
		auto &bucket = buckets[hash];
		for (auto it = bucket.begin(); it != bucket.end(); it++)
		{
			if (it->first == key)
			{
				it->second = value;
				return;
			}
		}
		bucket.push_back({key, value});
	}

	int get(int key)
	{
		int hash = get_hash(key);
		auto &bucket = buckets[hash];
		for (auto it = bucket.begin(); it != bucket.end(); it++)
		{
			if (it->first == key)
			{
				return it->second;
			}
		}
		return -1;
	}

	void remove(int key)
	{
		int hash = get_hash(key);
		auto &bucket = buckets[hash];
		for (auto it = bucket.begin(); it != bucket.end(); it++)
		{
			if (it->first == key)
			{
				bucket.erase(it);
				return;
			}
		}
	}

	vector<list<pair<int, int>>> buckets;
	int capacity;
};

int main()
{
	std::cout << "no test" << std::endl;
}