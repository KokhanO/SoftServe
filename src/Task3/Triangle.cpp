#include "Triangle.h"

Triangle::Triangle(std::string name, float a, float b, float c) : name_(name), Shape2D((a + b + c), 0.0f), a_(a), b_(b), c_(c)
{
	semi_perimeter_ = perimeter_ / 2;
	square_ =		sqrt(semi_perimeter_ * (semi_perimeter_ - a_) *		//formula herona
					(semi_perimeter_ - b_) * (semi_perimeter_ - c_));
}

std::string Triangle::getName() const
{
	return name_;
}

float Triangle::getSquare() const
{
	return Shape2D::getSquare();
}


bool Triangle::triangleExistence(const float a, const float b, const float c)
{
	if ((a < b + c) && (b < a + c) && (c < a + b))
	{
		return true;
	}
	return false;
}
