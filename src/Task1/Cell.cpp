#include "Cell.h"

Cell::Cell(char texture, string piece) :texture_(texture), piece_(piece)
{

}

void Cell::display()
{ 
	std::cout << texture_;
}



WhiteCell::WhiteCell(char texture, string piece) : Cell(texture, piece)
{

}

BlackCell::BlackCell(char texture, string piece) : Cell(texture, piece)
{

}

