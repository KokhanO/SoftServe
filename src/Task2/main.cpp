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

}