#include <iostream>
#include "ConsoleInteraction.h"
#include "TriangleSortedCollection.h"

int main()
{
	TriangleCollection a;
	do
	{
		a.AddTriangle();
		a.PrintTrianglesInDecresingOrder();
	} while (ConsoleInteraction::cinContinueProgram());

}