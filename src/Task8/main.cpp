#include "ConsoleInteraction.h"
#include "Validator.h"


int main(int argc, char** argv)
{
	long long bottomBoundaty;
	long long topBoundary;
	if (3 != argc ||
		true != Validator::TryParseToLongLong(std::string(argv[1]), bottomBoundaty) ||
		true != Validator::TryParseToLongLong(std::string(argv[2]), topBoundary) ||
		bottomBoundaty > topBoundary ||
		bottomBoundaty < 0)
	{
		ConsoleInteraction::Manual();
		return 0;
	}

	unsigned long long FibonacciNumbers[2];
	FibonacciNumbers[0] = 0;
	FibonacciNumbers[1] = 1;
	for (int i = 0; FibonacciNumbers[i % 2] <= topBoundary; ++i)
	{
		if (FibonacciNumbers[i % 2] >= bottomBoundaty)
		{
			std::cout << FibonacciNumbers[i % 2] << '\n';
		}

		FibonacciNumbers[i % 2] = FibonacciNumbers[(i + 1) % 2] + FibonacciNumbers[i % 2];
	}
}
