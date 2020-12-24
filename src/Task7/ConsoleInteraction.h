#pragma once
#include <iostream>

namespace ConsoleInteraction
{
	void Manual()
	{
		std::cout << "run .exe with long long > 0 representing top border" << std::endl;
	}

	void coutAllNaturalNumbersInRange(Generator& it, const long long& top_border)
	{
		long long first = it.getCurrentNum();
		for (; it < top_border; ++it)
		{
			if (first != it.getCurrentNum())
			{
				std::cout << ',';
			}
			std::cout << it.getCurrentNum();
		}
	}
}

