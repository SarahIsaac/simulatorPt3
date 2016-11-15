#include <iostream>
#include "EventQueue.h"

int main()
{
	int cpuNum;
	int ioDevice;
	double taskFreq;
	double switchCost;
	double taskMix;
	int min_page;
	int max_page;

	//EventQueue(int cpu_c, double mix, double freq, int io, int cost, std::string ready_set_type)

	std::cout << "FIFO with taskmix ratio 1/1" << std::endl;
	EventQueue event_q(2, 1, 10, 2, 4, "fifo", 1, 6, 1, 10);
	event_q.start_simulator();
	std::cout << std::endl;

	//std::cout << "FIFO with taskmix ratio 1/10" << std::endl;
	//EventQueue event_q1(2, .1, 10, 2, 1, "fifo");
	//event_q1.start_simulator();
	//std::cout << std::endl;

	//std::cout << "SJF with taskmix ratio 1/1" << std::endl;
	//EventQueue event_q2(2, 1, 10, 2, 1, "sjf");
	//event_q2.start_simulator();
	//std::cout << std::endl;

	//std::cout << "SJF with taskmix ratio 1/10" << std::endl;
	//EventQueue event_q3(2, .1, 10, 2, 1, "sjf");
	//event_q3.start_simulator();
	//std::cout << std::endl;

	//std::cout << "ASJF with taskmix ratio 1/1" << std::endl;
	//EventQueue event_q4(2, 1, 10, 2, 1, "asjf");
	//event_q4.start_simulator();
	//std::cout << std::endl;

	//std::cout << "ASJF with taskmix ratio 1/10" << std::endl;
	//EventQueue event_q5(2, .1, 10, 2, 1, "asjf");
	//event_q5.start_simulator();
	//std::cout << std::endl;

	//std::cout << "RR with taskmix ratio 1/1" << std::endl;
	//EventQueue event_q6(2, 1, 10, 2, 1, "rr");
	//event_q6.start_simulator();
	//std::cout << std::endl;

	//std::cout << "RR with taskmix ratio 1/10" << std::endl;
	//EventQueue event_q7(2, .1, 10, 2, 1, "rr");
	//event_q7.start_simulator();
	//std::cout << std::endl;

	return 0;
}