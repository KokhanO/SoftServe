#include "ChessBoard.h"

ChessBoard::ChessBoard(const unsigned short rows, const unsigned short columns): rows_(rows), columns_(columns)
{

}

void ChessBoard::fillBoard(const WhiteCell& white_cell, const BlackCell& black_cell)
{
	for (int i = 0; i < columns_; ++i)
	{
		for (int j = 0; j < rows_; ++j)
		{
			if ((i + j) % 2)
			{
				board_.push_back(new BlackCell(black_cell));
			}
			else
			{
				board_.push_back(new WhiteCell(white_cell));
			}

		}
	}
}


unsigned short ChessBoard::getRows()
{
	return rows_;
}

unsigned short ChessBoard::getColumns()
{
	return columns_;
}
