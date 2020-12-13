#pragma once
class Shape2D
{
public:
	Shape2D() = delete;
	Shape2D(const float length, const float height, const float width = 0);
	bool operator <=(const Shape2D&);
private:
	float length_;
	float height_;
	float width_;
};