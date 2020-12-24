#pragma once
#include <string>
#include "Shape2D.h"

class Triangle :public Shape2D
{
public:
	static const int kNumOfSides = 3;
	
	Triangle(const std::string& name, double side_a, double side_b, double side_c);
	std::string getName()const;
	double getArea() const;

	static bool triangleExistence(const double side_a, const double side_b, const double side_c);
	static Triangle* getTriangle(const std::string& name, double side_a, double side_b, double side_c);
private:
	std::string name_;
	double side_a_;
	double side_b_;
	double side_c_;
	double semi_perimeter_;
};