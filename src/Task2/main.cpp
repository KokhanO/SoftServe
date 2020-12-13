#include <iostream>

#include "Letter.h"
#include "ConsoleDataParser.h"
#include "ConsoleInteraction.h"


int main(int argc, char** argv)
{
	
	do
	{
		ConsoleInteraction::coutManual();
		bool validData = false;
		float arr[4];
		do
		{
			if (false == (ConsoleDataParser::TryParseConsoleData(arr, 4)))
			{
				break;
			}

			validData = true;
		} while (false);

		if (validData)
		{
			Letter a(arr[0], arr[1]);
			Letter b(arr[2], arr[3]);
			ConsoleInteraction::coutCompareLettersResult(a, b);
		}
		else
		{
			std::cout << "Wrong Data!!" << std::endl;
		}

	} while (ConsoleInteraction::cinContinueProgram());
	

	/*for (int i = 1; i < argc; ++i)
	{
		if (v.validatingData(std::string(argv[i])) != SUCCESS)
		{
			validData = false;
		}
	}*/


	/*if (validData && EXPECTED_AMOUNT_OF_ARGC == argc)
	{
		Letter a(stof(std::string(argv[1])), stof(std::string(argv[2])));
		Letter b(stof(std::string(argv[3])), stof(std::string(argv[4])));
		v.comparingResults(a, b);
	}
	else
	{
		v.manual();

		while (v.continueProgram() != FAILURE)
		{
			v.manual();
			std::string a_x, a_y;
			std::string b_x, b_y;
			std::cin >> a_x >> a_y;
			std::cin >> b_x >> b_y;
			if (v.validatingData(a_x) == SUCCESS && v.validatingData(a_y) == SUCCESS &&
				v.validatingData(b_x) == SUCCESS && v.validatingData(b_y) == SUCCESS)
			{
				Letter a(stof(a_x), stof(a_y));
				Letter b(stof(b_x), stof(b_y));
				v.comparingResults(a, b);
			}
			else
			{
				v.manual();
			}
		}

	}*/


}