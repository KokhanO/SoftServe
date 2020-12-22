#include "ConsoleDataParser.h"
#include <iostream>
#include "Validator.h"

bool ConsoleDataParser::TryParseConsoleData(float arr[], const int size)
{
		std::string tmp;
		for (int i = 0; i < size; ++i)
		{
			std::getline(std::cin, tmp);
			std::cin.ignore(0, '\n');

			if (!(Validator::TryParseToFloat(tmp, arr[i])) || arr[i] < 1)
			{
				return false;
			}
		}

		return true;

}
