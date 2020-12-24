#include <iostream>
#include "ConsoleInteraction.h"
#include "TriangleSortedCollection.h"
#include "Triangle.h"

void TriangleCollection::AddTriangle() {

	Triangle* a = ConsoleInteraction::getTriangle();
	if (a)
	{
		triangle_collection_.insert(*a);
	}
	else
	{
		std::cout << "couldn't create such triangle!" << std::endl;
	}
}

void TriangleCollection::PrintTrianglesInDecresingOrder() {

	auto it = triangle_collection_.rbegin();
	for (; it != triangle_collection_.rend(); ++it)
	{
		std::cout << it->getName() << '\t' << it->getArea() << std::endl;
	}
}

