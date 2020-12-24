#include <iostream>
#include 



int main(int argc, char** argv)
{

	unsigned short arr[2];
	bool trigger = false;
	do
	{
		if (3 != argc)
		{
			break;
		}

		for (int i = 1; i < argc; ++i)
		{
			if (!(Validator::TryParseToUShort(string(argv[i]), arr[i - 1])) || arr[i - 1] > 100)
			{
				break;
			}
		}

		trigger = true;

	} while (false);

	if (trigger)
	{
		ChessBoard CB(arr[0], arr[1]); // нужно ли покрывать юнит тестами конструктор, если используется валидатор
		WhiteCell WC('q');
		BlackCell BC('w');
		CB.fillBoard(WC, BC);
		ConsoleInteraction::DisplayChessBoard(CB);
	}
	else
	{
		coutManual();
	}



}
