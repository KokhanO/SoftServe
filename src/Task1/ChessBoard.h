#pragma once

#include <vector>
using namespace std;

class WhiteCell;
class BlackCell;
class Cell;

class ChessBoard {
  public:
    ChessBoard() = delete;

    ChessBoard(const unsigned short rows, const unsigned short columns);

    void fillBoard(const WhiteCell & white_cell, const BlackCell & black_cell);

    unsigned short getRows();

    unsigned short getColumns();

    vector<Cell*> board_;


  private:
    unsigned short rows_;

    unsigned short columns_;

};

