#include "ConsoleInteraction.h"
#include <iostream>

void ConsoleInteraction::coutCompareLettersResult(Letter& a, Letter& b)
{
	if (a <= b)
	{
		std::cout << "Yes you can fit first letter in second" << std::endl;
	}
	else
	{
		std::cout << "No you can't fit it there!" << std::endl;
	}
}

#include <regex>
bool ConsoleInteraction::cinContinueProgram()
{
	std::cout << "Do you want to continue program? Y/N" << std::endl;
	std::string answer = "Y|yes";
	std::regex regAnswer(answer, std::regex_constants::icase);
	std::cin >> answer;
	std::cin.ignore(255, '\n');
	if (std::regex_match(answer, regAnswer))
	{
		return true;
	}
	return false;
}

void ConsoleInteraction::coutManual()
{
	std::cout << "Please input four float numbers greater than zero, representing "
		<< "width and length of two letters" << std::endl;
}
