#pragma once
class Shape2D
{
public:
	Shape2D() = delete;
	Shape2D(float perimeter = 0, float square = 0);
	~Shape2D() = default;
	float getPerimeter()const;
	float getSquare()const;

	bool operator<(const Shape2D& right) const;
protected:
	float perimeter_;
	float square_;
};




