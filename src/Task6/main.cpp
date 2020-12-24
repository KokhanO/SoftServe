#include "ConsoleInteraction.h"
#include "Validator.h"
#include <thread>
#include "LuckyTicketsCounter.h"

int main(int argc, char** argv)
{

	long long bottom_border = 0;
	long long top_border = 0;
	if (4 != argc ||
		6 != std::string(argv[2]).size() ||
		6 != std::string(argv[3]).size() ||
		!Validator::TryParseToLongLong(std::string(argv[2]), bottom_border) ||
		!Validator::TryParseToLongLong(std::string(argv[3]), top_border) ||
		bottom_border > top_border ||
		bottom_border < 0)
	{
		ConsoleInteraction::Manual();
		return 0;
	}

	int luckyTickets;

	if ("Moscow" == std::string(argv[1]))
	{
		luckyTickets = LuckyTicketsCounter::getNumOfMoscowLuckyTicketsInRange((int)bottom_border, (int)top_border);
	}
	else if ("Piter" == std::string(argv[1]))
	{
		luckyTickets = LuckyTicketsCounter::getNumOfPiterLuckyTicketsInRange((int)bottom_border, (int)top_border);
	}
	else
	{
		ConsoleInteraction::Manual();
		return 0;
	}

	ConsoleInteraction::coutNumOfLuckyTicketsInRange(luckyTickets, (int)bottom_border, (int)top_border);
	
}
