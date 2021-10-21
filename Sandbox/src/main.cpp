#include <iostream>

#include "FruchtermanReingold/FruchtermanReingold.h"
#include "base/Vector2.h"

void testFruchtermanReingold()
{
	Layouts::FruchtermanReingold fr;

	fr.CreateVertex("node1",Vector2(0.1f,0.1f));
	fr.CreateVertex("node2",Vector2(0.5f,0.5f));
	fr.CreateVertex("node3",Vector2(0.9f,0.9f));
	fr.CreateVertex("node4",Vector2(0.5f,0.1f));
	fr.CreateVertex("node5",Vector2(0.9f,0.5f));
	fr.CreateVertex("node6",Vector2(0.2f,0.5f));
	fr.CreateVertex("node7",Vector2(0.1f,0.9f));

	std::cout << "Vertex Names: " << ((fr.GetVertex()[0].GetName() =="node1" && fr.GetVertex()[1].GetName() =="node2")?"Pass":"FAIL") << "\n";	
	std::cout << "Vertex Position[1]: " << ((fr.GetVertex()[0].GetPosition().x() == 0.1f && fr.GetVertex()[0].GetPosition().y() ==0.1f )?"Pass":"FAIL") << "\n";
	std::cout << "Vertex Position[2]: " << ((fr.GetVertex()[1].GetPosition().x() == 0.5f && fr.GetVertex()[1].GetPosition().y() ==0.5f )?"Pass":"FAIL") << "\n";
	std::cout << "Vertex Position[4]: " << ((fr.GetVertex()[3].GetPosition().x() == 0.5f && fr.GetVertex()[3].GetPosition().y() ==0.1f )?"Pass":"FAIL") << "\n";

	std::cout << "Vertex Count: " << ((fr.GetVertex().size()==7)?"Pass":"FAIL") << "\n";

	fr.CreateEdge("node1","node2");
	fr.CreateEdge("node1","node4");
	fr.CreateEdge("node2","node4");
	fr.CreateEdge("node2","node3");
	fr.CreateEdge("node3","node4");
	fr.CreateEdge("node4","node5");
	fr.CreateEdge("node6","node7");
	fr.CreateEdge("node5","node7");

	std::cout << "Edge Count: " << ((fr.GetEdge().size()==8)?"Pass":"FAIL") << "\n";
	std::cout << "Edge Count: " << ((fr.GetEdge().size())) << "\n";

	fr.Step(50);

	std::cout << "Node1 pos: " << ((std::round(fr.GetVertex()[0].GetPosition().x()*10000) == -10.0f && std::round(fr.GetVertex()[0].GetPosition().y()*10000) == -5892.0f )?"Pass":"FAIL") << "\n";
	std::cout << "Node2 pos: " << ((std::round(fr.GetVertex()[1].GetPosition().x()*10000) == 2155.0f && std::round(fr.GetVertex()[1].GetPosition().y()*10000) == -7492.0f )?"Pass":"FAIL") << "\n";
	std::cout << "Node3 pos: " << ((std::round(fr.GetVertex()[2].GetPosition().x()*10000) == -10.0f && std::round(fr.GetVertex()[2].GetPosition().y()*10000) == -5892.f )?"Pass":"FAIL") << "\n";

	fr.PrintGraphData();

}

int main()
{
	std::cout << "Hello, learning graph layout algorithms!\n";
		
	testFruchtermanReingold();

	return 0;
}