
#include "2DShape.h"

Shape_2D::Shape_2D(const float length, const float height, const float width):length_(length),height_(height),width_(width)
{


}

bool Shape_2D::operator <=() {

	if (length_ <= shape.length_ && height_ <= shape.height_ && width_ <= shape.width_)
	{
		return true;
	}
	return false;
}

