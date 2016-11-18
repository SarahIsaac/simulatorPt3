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

		std::cout << std::endl;
		EventQueue queue(cpu_count, task_mix, task_freq, io_count, context_cost, ready_set_type, min_p, max_p, miss_penalty, size_of_cache, mem_type);
		queue.start_simulator();
		std::cout << std::endl;

		std::cout << "press any letter to run again, press 'q' to quit: ";
		std::cin >> command;
	}

	// test cases

	EventQueue q1(5, .5, 5, 3, 5, "FIFO", 3, 29, 1, 24, "SC");
	q1.start_simulator();
	std::cout << std::endl;

	EventQueue q2(5, .5, 5, 3, 5, "FIFO", 3, 29, 1, 24, "FIFO");
	q2.start_simulator();
	std::cout << std::endl;

	EventQueue q3(5, .5, 5, 3, 5, "FIFO", 3, 29, 1, 24, "MRU");
	q3.start_simulator();
	std::cout << std::endl;

	EventQueue q4(5, .5, 5, 3, 5, "FIFO", 3, 29, 1, 24, "LRU");
	q4.start_simulator();
	std::cout << std::endl;

	EventQueue q5(5, .5, 5, 3, 5, "SJF", 3, 29, 1, 24, "SC");
	q5.start_simulator();
	std::cout << std::endl;

	EventQueue q6(5, .5, 5, 3, 5, "SJF", 3, 29, 1, 24, "FIFO");
	q6.start_simulator();
	std::cout << std::endl;

	EventQueue q7(5, .5, 5, 3, 5, "SJF", 3, 29, 1, 24, "MRU");
	q7.start_simulator();
	std::cout << std::endl;

	EventQueue q8(5, .5, 5, 3, 5, "SJF", 3, 29, 1, 24, "LRU");
	q8.start_simulator();
	std::cout << std::endl;

	EventQueue q9(5, .5, 5, 3, 5, "ASJF", 3, 29, 1, 24, "SC");
	q9.start_simulator();
	std::cout << std::endl;

	EventQueue q10(5, .5, 5, 3, 5, "ASJF", 3, 29, 1, 24, "FIFO");
	q10.start_simulator();
	std::cout << std::endl;

	EventQueue q11(5, .5, 5, 3, 5, "ASJF", 3, 29, 1, 24, "MRU");
	q11.start_simulator();
	std::cout << std::endl;

	EventQueue q12(5, .5, 5, 3, 5, "ASJF", 3, 29, 1, 24, "LRU");
	q12.start_simulator();
	std::cout << std::endl;

	EventQueue q13(5, .5, 5, 3, 5, "RR", 3, 29, 1, 24, "SC");
	q13.start_simulator();
	std::cout << std::endl;

	EventQueue q14(5, .5, 5, 3, 5, "RR", 3, 29, 1, 24, "FIFO");
	q14.start_simulator();
	std::cout << std::endl;

	EventQueue q15(5, .5, 5, 3, 5, "RR", 3, 29, 1, 24, "MRU");
	q15.start_simulator();
	std::cout << std::endl;

	EventQueue q16(5, .5, 5, 3, 5, "RR", 3, 29, 1, 24, "LRU");
	q16.start_simulator();
	std::cout << std::endl;

	return 0;
}