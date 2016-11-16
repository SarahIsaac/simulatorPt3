#pragma once
#include <queue>

#include "Task.h"
#include "Event.h"
#include "Memory.h"

class BaseReadySet
{
public:
	int context_switch;
	int idle_cpu_count;
	Memory*  memory;

	BaseReadySet() {}
	BaseReadySet(int cpu_count, int c_switch, int miss_penalty, int size_of)
	{
		idle_cpu_count = cpu_count;
		context_switch = c_switch;
		memory = new LRUMemory(size_of, miss_penalty);
	}

	bool ableToAdd()
	{
		if (idle_cpu_count > 0)
			return true;
		else return false;
	}

	void add() { idle_cpu_count--; }
	void done() { idle_cpu_count++; }

	virtual CPUEvent scheduleNext(Task &t, int current_time)
	{
		int exec_time = t.get_job().duration + current_time + context_switch;
		exec_time += memory->accessMemory(t.get_job().resource_id);
		CPUEvent e(exec_time, t);
		return e;
	};

	virtual Task remove()
	{
		Task t;
		return t;
	}
	virtual void pushToWait(Task &t) { };
	virtual bool isEmpty() { return true; }
};


class FIFOReadySet : public BaseReadySet
{
private:
	std::queue<Task> task_queue;

public:
	FIFOReadySet() :BaseReadySet() {}
	FIFOReadySet(int cpu, int c_switch, int miss_penalty, int size_of) : BaseReadySet(cpu, c_switch, miss_penalty, size_of) {};

	void pushToWait(Task &t)
	{
		task_queue.push(t);
	}

	Task remove()
	{
		Task t = task_queue.front();
		task_queue.pop();
		return t;
	}

	bool isEmpty()
	{
		if (task_queue.empty())
			return true;
		else return false;
	}
};


class CompareTask {
public:
	bool operator() (Task t, Task t1) {
		return t.bursts[t.current_burst].duration > t1.bursts[t1.current_burst].duration;
	}
};

class SJFReadySet : public BaseReadySet
{
private:
	std::priority_queue<Task, std::vector<Task>, CompareTask> task_queue;

public:
	SJFReadySet() : BaseReadySet() {}
	SJFReadySet(int cpu, int c_switch, int miss_penalty, int size_of) : BaseReadySet(cpu, c_switch, miss_penalty, size_of) {};

	void pushToWait(Task &t) { task_queue.push(t); }

	Task remove()
	{
		Task t = task_queue.top();
		task_queue.pop();
		return t;
	}

	bool isEmpty()
	{
		if (task_queue.empty()) return true;
		else return false;
	}
};


class ApproximateCompareTask {
public:
	bool operator() (Task t, Task t1) {
		return t.current_approximate > t1.current_approximate;
	}
};

class ASJFReadySet : public BaseReadySet
{
private:
	std::priority_queue<Task, std::vector<Task>, ApproximateCompareTask> task_queue;
	int standard_start_approx;

public:
	ASJFReadySet() : BaseReadySet() {}
	ASJFReadySet(int cpu, int c_switch, int standard_start, int miss_penalty, int size_of) : BaseReadySet(cpu, c_switch, miss_penalty, size_of)
	{
		standard_start_approx = standard_start;
	};

	void pushToWait(Task &t)
	{
		if (t.current_burst == 0)
		{
			t.current_approximate = standard_start_approx;
		}
		else
		{
			t.calculateApproximate();
		}
		task_queue.push(t);
	}

	Task remove()
	{
		Task t = task_queue.top();
		task_queue.pop();
		return t;
	}

	bool isEmpty()
	{
		if (task_queue.empty()) return true;
		else return false;
	}
};

class RoundRobinReadySet : public BaseReadySet
{
private:
	std::queue<Task> task_queue;
	int interrupt_time;

public:
	RoundRobinReadySet() :BaseReadySet() {}
	RoundRobinReadySet(int cpu, int c_switch, int i_time, int miss_penalty, int size_of) : BaseReadySet(cpu, c_switch, miss_penalty, size_of)
	{
		interrupt_time = i_time;
	};

	CPUEvent scheduleNext(Task &t, int current_time)
	{
		int time;
		if (t.get_job().duration > interrupt_time)
		{
			int current_duration = t.get_job().duration;
			time = current_duration - interrupt_time;
			t.setCurrentDuration(time);
			time = interrupt_time;
		}
		else
		{
			time = t.get_job().duration;
			t.setCurrentDuration(0);
		}
		int exec_time = time + current_time + context_switch;
		exec_time += memory->accessMemory(t.get_job().resource_id);
		CPUEvent e(exec_time, t);
		return e;
	}

	void pushToWait(Task &t) { task_queue.push(t); }

	Task remove()
	{
		Task t = task_queue.front();
		task_queue.pop();
		return t;
	}

	bool isEmpty()
	{
		if (task_queue.empty()) 
			return true;
		else return false;
	}
};


