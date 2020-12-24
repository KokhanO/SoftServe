#include "ConsoleInteraction.h"
#include <iostream>
#include <iomanip>

void ConsoleInteraction::Manual()
{
	std::cout << "start the .exe file with the name of method(\"Moscow\" or \"Piter\"),\n " <<
		"and two valid 6 digit number as a bottom and top border," <<
		" using 0 at the begining if needed!" << std::endl;
}

void ConsoleInteraction::coutNumOfLuckyTicketsInRange(const int num_of_lucky_tickets,
														const int bottom_border,
														const int top_border)
{
	std::cout << "There is " << num_of_lucky_tickets << " Lucky Tickets in range from ";
	std::cout.width(6);
	std::cout.fill('0');
	std::cout << bottom_border << " to ";
	std::cout.width(6);
	std::cout.fill('0');
	std::cout << top_border << std::endl;
}
