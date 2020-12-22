#include <iostream>
#include "Iterator.h"
#include "Validator.h"
#include "ConsoleInteraction.h"

int main(int argc, char** argv)
{
	long long border;
	if (2 != argc || true != Validator::TryParseToLongLong(std::string(argv[1]), border))
	{
		ConsoleInteraction::Manual();
		return 0;
	}

	for (Iterator a(1); a < border; ++a)
	{
		std::cout << a.getNum() << ',';
	}
	
}


