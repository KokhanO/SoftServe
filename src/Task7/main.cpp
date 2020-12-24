#include <iostream>
#include "Generator.h"
#include "Validator.h"
#include "ConsoleInteraction.h"
#include "Range.h"

int main(int argc, char** argv)
{
	long long top_border;
	if (2 != argc || 
		true != Validator::TryParseToLongLong(std::string(argv[1]), top_border) ||
		top_border < 1)
	{
		ConsoleInteraction::Manual();
		return 0;
	}

	Generator it(1);

	ConsoleInteraction::coutAllNaturalNumbersInRange(it, top_border);

}


