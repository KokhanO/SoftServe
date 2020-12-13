#include "Shape2D.h"

Shape2D::Shape2D(float perimeter, float square) :perimeter_(perimeter), square_(square)
{

}

float Shape2D::getPerimeter() const
{
	return perimeter_;
}

float Shape2D::getSquare() const
{
	return square_;
}

bool Shape2D::operator<(const Shape2D& right) const
{
	return square_ < right.square_;
}
