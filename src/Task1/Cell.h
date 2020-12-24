#ifndef _CELL_H
#define _CELL_H

#include <string>

using namespace std;

class Cell {
  public:
    Cell() = delete;

    Cell(char texture, string piece);

    void display();

    char getTexture();

    ~Cell() = default;


  private:
    string piece_;

    char texture_;

};
class WhiteCell : public Cell {
  public:
    WhiteCell() = delete;

    WhiteCell(char texture, string piece = "0");

};
class BlackCell : public Cell {
  public:
    BlackCell() = delete;

    BlackCell(char texture, string piece = "0");

};
#endif
