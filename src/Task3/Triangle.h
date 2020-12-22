#pragma once
#include <string>
#include "Shape2D.h"

class Triangle :public ShapeTwoD
{
public:
	static const int kNumOfSides = 3;

	Triangle(const std::string& name, double a, double b, double c);
	std::string getName()const;
	double getSquare() const;

	static bool triangleExistence(const double a, const double b, const double c);
	static Triangle* getTriangle(const std::string& name, double a, double b, double c);
private:
	std::string name_;
	double a_;
	double b_;
	double c_;
	double semi_perimeter_;
};