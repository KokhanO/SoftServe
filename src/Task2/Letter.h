#pragma once
#include "2DShape.h"

class Letter:public Shape2D
{
public:
	Letter() = delete;
	Letter(const float width,const float length);
	~Letter() = default;

private:
};
