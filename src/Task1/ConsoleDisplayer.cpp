#include "ConsoleDisplayer.h"
#include <iostream>

void ConsoleInteraction::DisplayChessBoard(ChessBoard& chess_board)
{
    for (int i = 0; i < chess_board.getColumns(); ++i)
    {
        for (int j = 0; j < chess_board.getRows(); ++j)
        {
            (chess_board.board_[(i* chess_board.getRows()) + j])->display();
        }
        cout << endl;
    }
}
