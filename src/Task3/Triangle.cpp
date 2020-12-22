#include "Triangle.h"
#include <cmath>
Triangle::Triangle(const std::string& name, const double a, const double b, const double c) : name_(name), ShapeTwoD((a + b + c), 0.0f), a_(a), b_(b), c_(c)
{
	semi_perimeter_ = perimeter_ / 2;
	area_ =		sqrt(semi_perimeter_ * (semi_perimeter_ - a_) *		//formula herona
					(semi_perimeter_ - b_) * (semi_perimeter_ - c_));
}

std::string Triangle::getName() const
{
	return name_;
}

double Triangle::getSquare() const
{
	return ShapeTwoD::getSquare();
}


bool Triangle::triangleExistence(const double a, const double b, const double c)
{
	if ((a < b + c) && (b < a + c) && (c < a + b))
	{
		return true;
	}
	return false;
}

Triangle* Triangle::getTriangle(const std::string& name, const double a, const double b, const double c)
{
	if (triangleExistence(a, b, c))
	{
		return new Triangle(name, a, b, c);
	}

	return nullptr;
}
