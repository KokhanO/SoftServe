#include "TriangleSortedCollection.h"
#include "ConsoleInteraction.h"
#include <iostream>

void TriangleCollection::AddTriangle()
{
	try 
	{
		triangle_collection_.insert(ConsoleInteraction::getTriangle());
	}
	catch(...)
	{
		std::cout << "Wrong data!" << std::endl;
	}
}

void TriangleCollection::PrintTrianglesInDecresingOrder()
{
	auto it = triangle_collection_.rbegin();
	for (; it != triangle_collection_.rend(); ++it)
	{
		std::cout << it->getName() << '\t' << it->getSquare() << std::endl;
	}
}
