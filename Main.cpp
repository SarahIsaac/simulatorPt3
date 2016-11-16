#include <iostream>
#include "EventQueue.h"

int main()
{
	int cpu_count;
	double task_mix;
	double task_freq;
	int io_count;
	int context_cost;
	std::string ready_set_type;
	int min_p;
	int max_p;
	int miss_penalty;
	int size_of_cache;
	std::string mem_type;

	char command = 'x';

	while (command != 'q')
	{
		std::cout << "Number of cpu: ";
		std::cin >> cpu_count;
		std::cout << "Task Mix (between 0 and 1): ";
		std::cin >> task_mix;
		std::cout << "Task Frequency: ";
		std::cin >> task_freq;
		std::cout << "Number of io devices: ";
		std::cin >> io_count;
		std::cout << "Cost of context switch: ";
		std::cin >> context_cost;
		std::cout << "Type of Ready Set (FIFO, SJF, ASJF, RR): ";
		std::cin >> ready_set_type;
		std::cout << "Lower bound of page distribution: ";
		std::cin >> min_p;
		std::cout << "Upper bound of page distribution: ";
		std::cin >> max_p;
		std::cout << "Penalty for cache miss: ";
		std::cin >> miss_penalty;
		std::cout << "Size of cache: ";
		std::cin >> size_of_cache;
		std::cout << "Memory type (SC, FIFO, MRU, LRU): ";
		std::cin >> mem_type;

		EventQueue queue(cpu_count, task_mix, task_freq, io_count, context_cost, ready_set_type, min_p, max_p, miss_penalty, size_of_cache, mem_type);
		queue.start_simulator();
		std::cout << std::endl;

		std::cout << "press any letter to run again, press 'q' to quit: ";
		std::cin >> command;
	}

	return 0;
}