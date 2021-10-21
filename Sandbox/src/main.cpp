#include <iostream>

#include "FruchtermanReingold/FruchtermanReingold.h"
#include "base/Vector2.h"
void testFruchtermanReingold()
{
	Layouts::FruchtermanReingold fr;

	fr.CreateVertex("node1");
	fr.CreateVertex("node2");

	std::cout << "Vertex Names: " << ((fr.GetVertex()[0].GetName() =="node1" && fr.GetVertex()[1].GetName() =="node2")?"Pass":"FAIL") << "\n";	

	std::cout << "Vertex Count: " << ((fr.GetVertex().size()==2)?"Pass":"FAIL") << "\n";	

	fr.CreateEdge("node1","node2");
	std::cout << "Edge Count: " << ((fr.GetEdge().size()==1)?"Pass":"FAIL") << "\n";
		


}

int main()
{
	std::cout << "Hello, learning graph layout algorithms!\n";
		
	testFruchtermanReingold();

	return 0;
}