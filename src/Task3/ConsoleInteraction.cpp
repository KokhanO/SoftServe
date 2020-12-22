#include "ConsoleInteraction.h"
#include "Triangle.h"
#include "Validator.h"
#include <iostream>



void ConsoleInteraction::coutManual()
{
	std::cout << "Manual: input required data, each of them on new line! \n"
		<< "Input Name of triangle, \n"
		<< "Input 3 float numbers greater than 0 representing "
		<< "triangle sides\n p.s. it has to be possible!" << std::endl;
}



#include <regex>
bool ConsoleInteraction::cinContinueProgram()
{
	std::cout << "Do you want to add one more triangle? Y/N" << std::endl;
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



Triangle* ConsoleInteraction::getTriangle()
{
	ConsoleInteraction::coutManual();
	std::string name;
	std::getline(std::cin, name);
	
	double sides[Triangle::kNumOfSides];
	for (int i = 0; i < Triangle::kNumOfSides; ++i)
	{
		std::string tmp;
		std::getline(std::cin, tmp);
		if (!Validator::TryParseToDouble(tmp, sides[i]) || sides[i] < 1)
		{
			return nullptr;
		}
	}

	return Triangle::getTriangle(name, sides[0], sides[1], sides[2]);
}
