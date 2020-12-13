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



Triangle ConsoleInteraction::getTriangle()
{
	ConsoleInteraction::coutManual();
	std::string name;
	std::getline(std::cin, name);

	float arr[3];
	for (int i = 0; i < 3; ++i)
	{
		std::string tmp;
		std::getline(std::cin, tmp);
		if (false == Validator::TryParseToFloat(tmp, arr[i]) || arr[i] < 1)
		{
			throw "invalid argumenst!\n";
		}
	}
	if (Triangle::triangleExistence(arr[0], arr[1], arr[2]))
	{
		return Triangle(name, arr[0], arr[1], arr[2]);
	}
	throw "invalid argumenst!\n";
}
