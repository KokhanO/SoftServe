#pragma once
class ShapeTwoD
{
public:
	ShapeTwoD() = delete;
	ShapeTwoD(double perimeter = 0, double square = 0);
	~ShapeTwoD() = default;
	double getPerimeter()const;
	double getSquare()const;

	bool operator<(const ShapeTwoD& right) const;
protected:
	double perimeter_;
	double area_;
};




