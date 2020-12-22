#include <iostream>
#include <thread>
#include <omp.h>
#include <chrono>

#include "ConsoleInteraction.h"
#include "Validator.h"


void countMoscowLuckyTicketsInRange(long long bottomBorder, long long topBorder, int& result);

void countPiterLuckyTicketsInRange(long long bottomBorder, long long topBorder, int& result);

int main(int argc, char** argv)
{

	long long ticketsRange;
	if (3 != argc ||
		6 != std::string(argv[2]).size() ||
		true != Validator::TryParseToLongLong(std::string(argv[2]), ticketsRange) ||
		0 > ticketsRange)
	{
		ConsoleInteraction::Manual();
		return 0;
	}

	int luckyTickets = 0;

	int tmpLTicketsThread1 = 0;
	int tmpLTicketsThread2 = 0;

	if ("moscow" == std::string(argv[1]))
	{
		std::thread th(countMoscowLuckyTicketsInRange, 0, ticketsRange / 2, std::ref(tmpLTicketsThread1));
		countMoscowLuckyTicketsInRange(ticketsRange / 2 + 1, ticketsRange, tmpLTicketsThread2);
		th.join();

	}
	else if ("piter" == std::string(argv[1]))
	{
		std::thread th(countPiterLuckyTicketsInRange, 0, ticketsRange / 2, std::ref(tmpLTicketsThread1));
		countPiterLuckyTicketsInRange(ticketsRange / 2 + 1, ticketsRange, tmpLTicketsThread2);
		th.join();
	}
	else
	{
		ConsoleInteraction::Manual();
		return 0;
	}

	luckyTickets = tmpLTicketsThread1 + tmpLTicketsThread2;

	std::cout << "There is " << luckyTickets << " Lucky Tickets in range from ";
	std::cout.width(6);
	std::cout.fill('0');
	std::cout << 0 << " to ";
	std::cout.width(6);
	std::cout.fill('0');
	std::cout << ticketsRange << std::endl;


}


void countMoscowLuckyTicketsInRange(long long bottomBorder, long long topBorder, int& result)
{

	while (bottomBorder <= topBorder)
	{
		int firstHalf = bottomBorder / 1000;
		int secondHalf = bottomBorder % 1000;

		int sumOfTwoNumsFirstHalf = firstHalf / 100 + firstHalf % 10;
		int sumOfTwoNumsSecondHalf = secondHalf / 100 + secondHalf % 10;

		int diff = (sumOfTwoNumsFirstHalf - sumOfTwoNumsSecondHalf);
		if (diff <= 9 && diff >= -9)
		{
			if (((secondHalf % 100) / 10) - ((firstHalf % 100) / 10) == diff)
			{
				++result;
			}
		}

		++bottomBorder;
	}

	/*while (bottomBorder <= topBorder)
	{
		int part1 = (((bottomBorder % 10000) / 1000) + ((bottomBorder % 100000) / 10000) + ((bottomBorder % 1000000) / 100000));
		int part2 = (((bottomBorder % 1000) / 100) + ((bottomBorder % 100) / 10) + (bottomBorder % 10));

		if (part1 == part2)
		{
			++(result);
		}
		++bottomBorder;
	}*/
}



void countPiterLuckyTicketsInRange(long long bottomBorder, long long topBorder, int& result)
{
	while (bottomBorder <= topBorder)
	{
		int firstHalf = bottomBorder / 1000;
		int secondHalf = bottomBorder % 1000;

		int sumOfTwoNumsFirstHalf = firstHalf / 100 + firstHalf % 10;
		int sumOfTwoNumsSecondHalf = secondHalf / 100 + secondHalf % 10;

		int diff = (sumOfTwoNumsFirstHalf - sumOfTwoNumsSecondHalf);
		if (diff <= 9 && diff >= -9)
		{
			if (((firstHalf % 100) / 10) - ((secondHalf % 100) / 10) == diff)
			{
				++result;
			}
		}

		++bottomBorder;
	}

	/*while (bottomBorder <= topBorder)
	{
		if ((((bottomBorder % 10000) / 1000) + ((bottomBorder % 100) / 10) + ((bottomBorder % 1000000) / 100000)) ==
			(((bottomBorder % 1000) / 100) + ((bottomBorder % 100000) / 10000) + (bottomBorder % 10)))
		{
			++(result);
		}
		++bottomBorder;
	}*/
}
