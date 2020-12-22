#include "ConsoleInteraction.h"
#include "Validator.h"

void ConsoleInteraction::Manual()
{
	std::cout << "start program with no argv " << std::endl;
}

void ConsoleInteraction::ProgramTypeManual()
{
	std::cout << "input 1 if you want count string presistence only " <<
		"or 2 if you want to change first string on second" << std::endl;
}

unsigned short ConsoleInteraction::getProgramType()
{
	std::string answer;
	std::cin >> answer;
	unsigned short ansNum;
	if (true != Validator::TryParseToUShort(answer, ansNum) || (1 != ansNum && 2 != ansNum))
	{
		std::cout << "Wrong answer!" << std::endl;
		return 0;
	}
	return ansNum;
}
