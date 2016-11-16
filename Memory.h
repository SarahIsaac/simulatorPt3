#include <iostream>
#include <queue>
#include <list>

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

class MRUMemory : public Memory
{
private:
	std::deque<int> cache;

public:
	MRUMemory() : Memory() {};
	MRUMemory(int size_of, int miss) : Memory(size_of, miss) { }

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
		// TODO correctly implement this algorithm
		// will somehow need to know the task..or the whole thing of tasks?
		if (cache.size() > size_of_cache)
		{
			cache.pop_front();
		}
		cache.push_back(page_num);
	}
};

class LRUMemory : public Memory
{
private:
	std::list<int> cache;

public:
	LRUMemory() : Memory() {};
	LRUMemory(int size_of, int miss) : Memory(size_of, miss) { }

	int accessMemory(int page_number)
	{
		for each (int page_num in cache)
		{
			if (page_num == page_number)
			{
				cache.remove(page_number);
				cache.push_back(page_number);
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

struct SecondChancePage{
	int page_num;
	bool safe;
};

class SecondChanceMemory : public Memory
{
private:
	std::vector<SecondChancePage> cache;
	int current_index;

public:
	SecondChanceMemory() : Memory() {};
	SecondChanceMemory(int size_of, int miss) : Memory(size_of, miss) 
	{
		current_index = 0;
	}

	int accessMemory(int page_number)
	{
		if (cache.size() == 0) addToMemory(page_number);
		else
		{
			for (int i = 0; i < cache.size() - 1; i++)
			{
				if (cache[i].page_num == page_number)
				{
					cache[i].safe = true;
					return 0;
				}
			}
			addToMemory(page_number);
		}
		return missed_penalty;
	}

	void addToMemory(int page_number)
	{
		if (cache.size() < size_of_cache)
		{
			SecondChancePage s = { page_number, false };
			cache.push_back(s);
			if (cache.size() != 1)
				current_index++;
		}
		else
		{
			bool spot_found = false;
			int here;
			if (current_index == (cache.size() - 1))
			{
				here = 0;
			}
			else 
				here = current_index++;
			while (spot_found == false)
			{
				if (cache[here].safe == false)
				{
					current_index = here;
					spot_found = true;
				}
				else
				{
					cache[here].safe = false;
				}
				if (here == cache.size() - 1) 
					here = 0;
				else 
					here++;
			}
			cache.erase(cache.begin() + current_index);
			SecondChancePage s = { page_number, false };
			cache.push_back(s);
		}

		for each (SecondChancePage page in cache)
		{
			page.safe = false;
		}
	}
};