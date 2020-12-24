#include "ConsoleInteraction.h"
#include "StringComparer.h"
#include "Validator.h"

int main(int argc, char** argv)
{
	if (1 != argc)
	{
		ConsoleInteraction::Manual();
		return 0;
	}

	ConsoleInteraction::ProgramTypeManual();
	unsigned short ansNum = ConsoleInteraction::getProgramType();
	

	std::string path = getPath(std::string(argv[0]));

	std::string nameOfFile = "source.txt";
	std::fstream in;
	in.open(path + nameOfFile, std::ios::in);

	if (!in.is_open())
	{
		std::cerr << "Failed to open file: " << nameOfFile << std::endl;
		return 0;
	}


	std::string nameOfTmpFile = "output.txt";
	std::fstream out;
	out.open(path + nameOfTmpFile, std::ios::out | std::ios::app);

	if (!out.is_open())
	{
		std::cerr << "Failed to open file: " << nameOfFile << std::endl;
		return 0;
	}
	
	std::string strToSearch;
	std::string strToReplace;
	if (1 == ansNum)
	{
		std::cout << "input string to search: " << std::endl;
		std::cin >> strToSearch;
	}
	else
	{
		std::cout << "input string to search: " << std::endl;
		std::cin >> strToSearch;
		std::cout << "input string to replace for: " << std::endl;
		std::cin >> strToReplace;
	}
	int counter = 0;
	std::string strToFind;

	while (in)
	{
		std::string line;
		std::getline(in, line);

		out << line;
		if (!in)
		{
			break;
		}

		if (line == strToFind)
			++counter;

		out << '\n';
	}
	std::cout << counter;
	in.close();
	out.close();

}
