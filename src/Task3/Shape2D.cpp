#include "Shape2D.h"

ShapeTwoD::ShapeTwoD(double perimeter, double square) :perimeter_(perimeter), area_(square)
{

}

double ShapeTwoD::getPerimeter() const
{
	return perimeter_;
}

double ShapeTwoD::getSquare() const
{
	return area_;
}

bool ShapeTwoD::operator<(const ShapeTwoD& right) const
{
	return area_ < right.area_;
}
