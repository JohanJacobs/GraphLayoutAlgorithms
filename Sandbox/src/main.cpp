#include <iostream>

#include "FruchtermanReingold/FruchtermanReingold.h"

int main()
{
	std::cout << "Hello, learning graph layout algorithms!\n";

	Layouts::FruchtermanReingold fr;
	fr.CreateVertex("user1");
	fr.CreateVertex("user2");

	fr.CreateEdge("user1", "user2");

	fr.PrintGraphData();
	return 0;
}