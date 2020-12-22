#include "2DShape.h"

Shape2D::Shape2D(const float length, const float height, const float width):length_(length),height_(height),width_(width)
{

}

bool Shape2D::operator<=(const Shape2D& shape)
{
	if (length_ <= shape.length_ && height_ <= shape.height_ && width_ <= shape.width_)
	{
		return true;
	}
	return false;
}

