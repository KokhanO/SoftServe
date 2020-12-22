#include <iostream>
#include "ConsoleInteraction.h"
#include "TriangleSortedCollection.h"

int main(int argc, char** argv)
{
	if (1 != argc)
	{
		std::cout << "please run .exe without params" << std::endl;
		return 0;
	}

	TriangleCollection a;
	do
	{
		a.AddTriangle();
		a.PrintTrianglesInDecresingOrder();
	} while (ConsoleInteraction::cinContinueProgram());

}