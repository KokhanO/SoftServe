#include <iostream>
#include <thread>

#include "ConsoleInteraction.h"
#include "Validator.h"


void countLuckyTicketsInRange(long long b, long long a, int* res)
{
	while (b <= a)
	{
		if ((((b % 10000) / 1000) + ((b % 100000) / 10000) + ((b % 1000000) / 100000)) ==
			(((b % 1000) / 100) + ((b % 100) / 10) + (b % 10)))
		{
			++(*res);
		}
		++b;
	}
}


int main(int argc, char** argv)
{

	long long ticketsRange;
	if (2 != argc ||
		6 != std::string(argv[1]).size() ||
		true != Validator::TryParseToLongLong(std::string(argv[1]), ticketsRange)||
		0 > ticketsRange)
	{
		ConsoleInteraction::Manual();
		return 0;
	}

	int luckyTickets = 0;

	int tmpLTicketsThread1 = 0;
	std::thread th(countLuckyTicketsInRange, 0, ticketsRange / 2, &tmpLTicketsThread1);

	int tmpLTicketsThread2 = 0;
	countLuckyTicketsInRange(ticketsRange / 2 + 1, ticketsRange, &tmpLTicketsThread2);

	th.join();

	luckyTickets = tmpLTicketsThread1 + tmpLTicketsThread2;
	std::cout << "There is " << luckyTickets << " Lucky Tickets in range from ";
	std::cout.width(6);
	std::cout.fill('0');
	std::cout << 0 << " to ";
	std::cout.width(6);
	std::cout.fill('0');
	std::cout << ticketsRange << std::endl;
}
