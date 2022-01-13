#include "src/base.h"
#include <list>

class MyHashSet
{
public:
	MyHashSet()
	{
		buckets_.resize(capacity_);
	}

	int get_hash(int key)
	{
		return key % capacity_;
	}

	void add(int key)
	{
		int hash = get_hash(key);
		auto &bucket = buckets_[hash];

		for (auto it = bucket.begin(); it != bucket.end(); it++)
		{
			if (*it == key)
			{
				return;
			}
		}
		bucket.push_back(key);
	}

	void remove(int key)
	{
		int hash = get_hash(key);
		auto &bucket = buckets_[hash];

		for (auto it = bucket.begin(); it != bucket.end(); it++)
		{
			if (*it == key)
			{
				bucket.erase(it);
				return;
			}
		}
	}

	bool contains(int key)
	{
		int hash = get_hash(key);
		auto &bucket = buckets_[hash];

		for (auto it = bucket.begin(); it != bucket.end(); it++)
		{
			if (*it == key)
			{
				return true;
			}
		}
		return false;
	}

	int capacity_ = 1000;
	vector<list<int>> buckets_;
};

int main()
{
	MyHashSet hs;
	hs.add(1);
	hs.add(2);
	std::cout << hs.contains(1) << std::endl;
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */