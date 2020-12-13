#pragma once
#include "Triangle.h"
#include <set>

class TriangleCollection
{
public:
	TriangleCollection() = default;
	~TriangleCollection() = default;

	void AddTriangle();
	void PrintTrianglesInDecresingOrder();

private:
	std::multiset<Triangle> triangle_collection_;
};
