#include "LuckyTicketsCounter.h"
#include <thread>
#include <functional>

int LuckyTicketsCounter::getNumOfPiterLuckyTicketsInRange(const int bottom_border, const int top_border)
{
	int tmpTicketsThread1 = 0;
	int tmpTicketsThread2 = 0;
	if (bottom_border < top_border / 2)
	{
		std::thread th(LuckyTicketsCounter::countPiterLuckyTicketsInRange, bottom_border, top_border / 2, std::ref(tmpTicketsThread1));
		countPiterLuckyTicketsInRange(top_border / 2 + 1, top_border, std::ref(tmpTicketsThread2));
		th.join();
	}
	else
	{
		countMoscowLuckyTicketsInRange(bottom_border, top_border, std::ref(tmpTicketsThread2));
	}
	return tmpTicketsThread1+tmpTicketsThread2;
}

int LuckyTicketsCounter::getNumOfMoscowLuckyTicketsInRange(const int bottom_border, const int top_border)
{
	int tmpTicketsThread1 = 0;
	int tmpTicketsThread2 = 0;
	if (bottom_border < top_border / 2)
	{
		std::thread th(LuckyTicketsCounter::countMoscowLuckyTicketsInRange, bottom_border, top_border / 2, std::ref(tmpTicketsThread1));
		countMoscowLuckyTicketsInRange(top_border / 2 + 1, top_border, std::ref(tmpTicketsThread2));
		th.join();
	}
	else
	{
		countMoscowLuckyTicketsInRange(bottom_border, top_border, std::ref(tmpTicketsThread2));
	}
	return tmpTicketsThread1 + tmpTicketsThread2;
}

void LuckyTicketsCounter::countPiterLuckyTicketsInRange(int bottom_border, int top_border, int& result)
{
	while (bottom_border <= top_border)
	{
		int firstHalf = bottom_border / 1000;
		int secondHalf = bottom_border % 1000;

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

		++bottom_border;
	}
}

void LuckyTicketsCounter::countMoscowLuckyTicketsInRange(int bottom_border, int top_border, int& result)
{
	while (bottom_border <= top_border)
	{
		int firstHalf = bottom_border / 1000;
		int secondHalf = bottom_border % 1000;

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

		++bottom_border;
	}
}
