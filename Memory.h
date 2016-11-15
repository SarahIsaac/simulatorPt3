#include <iostream>
#include <queue>

class Memory
{
protected:
	int size_of_cache;
	int missed_penalty;

public:
	Memory() {}
	Memory(int size_of, int penalty)
	{
		size_of_cache = size_of;
		missed_penalty = penalty;
	}
	virtual int accessMemory(int page_number) { return 0; }
	virtual void addToMemory() { }
};

class FIFOMemory : public Memory
{
private:
	std::deque<int> cache;

public:
	FIFOMemory() : Memory() {};
	FIFOMemory(int size_of, int miss) : Memory(size_of, miss) { }

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