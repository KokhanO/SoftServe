#include "ConsoleDisplayer.h"
#include "Validator.h"
#include "Cell.h"
#include "ChessBoard.h"

void coutManual()
{
	std::cout << "Pass on two unsigned short numbers representing "
		<< "rows and columns" << std::endl;
}

int main(int argc, char** argv)
{

	bool trigger = false;
	unsigned short arr[2];
	do
	{
		if (3 != argc)
		{
			break;
		}

		for (int i = 1; i < argc; ++i)
		{
			if (!(Validator::TryParseToUShort(string(argv[i]), arr[i - 1])))
			{
				break;
			}
		}

		trigger = true;

	} while (false);

	if (trigger)
	{
		ChessBoard CB(arr[0], arr[1]);
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

