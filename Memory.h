#include <iostream>
#include <queue>

class FIFOMemory
{
private:
	std::deque<int> cache;
	int size_of_cache;
	int missed_penalty;

public:
	FIFOMemory() {};
	FIFOMemory(int size_of, int miss)
	{
		size_of_cache = size_of;
		missed_penalty = miss;
	}

	int accessMemory(int page_number)
	{
		for each (int page_num in cache)
		{
			if (page_num == page_number)
			{
				return 0;
			}
		}
		addToMemory(page_number);
		return missed_penalty;	
	}

	void addToMemory(int page_num)
	{
		if (cache.size() > size_of_cache)
		{
			cache.pop_front();
		}
		cache.push_back(page_num);
	}
};