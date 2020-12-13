#pragma once
#include <string>
#include "Shape2D.h"
#include <exception>
#
class Triangle :public Shape2D
{
public:
	Triangle(std::string name, float a, float b, float c);
	std::string getName()const;
	float getSquare() const;

	static bool triangleExistence(const float a, const float b, const float c);
private:
	std::string name_;
	float a_;
	float b_;
	float c_;
	float semi_perimeter_;
};