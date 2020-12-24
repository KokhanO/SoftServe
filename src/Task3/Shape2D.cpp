#include "Shape2D.h"

Shape2D::Shape2D(double perimeter, double square) :perimeter_(perimeter), area_(square)
{


}

double Shape2D::getPerimeter() const {

	return perimeter_;
}

double Shape2D::getArea() const {

	return area_;
}

bool Shape2D::operator <(const Shape2D& right) const {

	return area_ < right.area_;
}

