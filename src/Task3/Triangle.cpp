#include "Triangle.h"
#include <cmath>
Triangle::Triangle(const std::string& name, const double side_a,
					const double side_b, const double side_c)
					: name_(name), Shape2D((side_a + side_b + side_c), 0.0f),
					side_a_(side_a), side_b_(side_b), side_c_(side_c)
{
	semi_perimeter_ = perimeter_ / 2;
	area_ =		sqrt(semi_perimeter_ * (semi_perimeter_ - side_a_) *		//formula herona
					(semi_perimeter_ - side_b_) * (semi_perimeter_ - side_c_));
}

std::string Triangle::getName() const
{
	return name_;
}

double Triangle::getArea() const
{
	return Shape2D::getArea();
}


bool Triangle::triangleExistence(const double side_a, 
								const double side_b, 
								const double side_c)
{
	return (side_a < side_b + side_c) &&
			(side_b < side_a + side_c) && 
			(side_c < side_a + side_b);
}

Triangle* Triangle::getTriangle(const std::string& name,
								const double side_a, 
								const double side_b, 
								const double side_c)
{
	if (triangleExistence(side_a, side_b, side_c))
	{
		return new Triangle(name, side_a, side_b, side_c);
	}

	return nullptr;
}
