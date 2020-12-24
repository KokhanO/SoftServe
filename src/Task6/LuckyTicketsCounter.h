#pragma once
class LuckyTicketsCounter
{
public:
	static int getNumOfPiterLuckyTicketsInRange(const int bottom_border, const int top_border);
	static int getNumOfMoscowLuckyTicketsInRange(const int bottom_border, const int top_border);
private:
	static void countPiterLuckyTicketsInRange(int bottom_border, int top_border, int& result);
	static void countMoscowLuckyTicketsInRange(int bottom_border, int top_border, int& result);
};