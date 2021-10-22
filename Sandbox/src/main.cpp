#include <iostream>

#include "FruchtermanReingold/FruchtermanReingold.h"
#include "base/Vector2.h"
#include "Graph/Graph.h"

void testFruchtermanReingold()
{
	Graphs::Graph g;
	g.CreateVertex("node1", Vector2(0.1f, 0.1f));
	g.CreateVertex("node2", Vector2(0.5f, 0.5f));
	g.CreateVertex("node3", Vector2(0.9f, 0.9f));
	g.CreateVertex("node4", Vector2(0.5f, 0.1f));
	g.CreateVertex("node5", Vector2(0.9f, 0.5f));
	g.CreateVertex("node6", Vector2(0.2f, 0.5f));
	g.CreateVertex("node7", Vector2(0.1f, 0.9f));

	Layouts::FruchtermanReingold fr(g);

	std::cout << "Vertex Names: " << ((g.GetVertices()[0]->GetName() =="node1" && g.GetVertices()[1]->GetName() =="node2")?"Pass":"FAIL") << "\n";
	std::cout << "Vertex Position[1]: " << ((g.GetVertices()[0]->GetPosition().x() == 0.1f && g.GetVertices()[0]->GetPosition().y() ==0.1f )?"Pass":"FAIL") << "\n";
	std::cout << "Vertex Position[2]: " << ((g.GetVertices()[1]->GetPosition().x() == 0.5f && g.GetVertices()[1]->GetPosition().y() ==0.5f )?"Pass":"FAIL") << "\n";
	std::cout << "Vertex Position[4]: " << ((g.GetVertices()[3]->GetPosition().x() == 0.5f && g.GetVertices()[3]->GetPosition().y() ==0.1f )?"Pass":"FAIL") << "\n";

	std::cout << "Vertex Count: " << ((g.GetVertices().size()==7)?"Pass":"FAIL") << "\n";

	g.CreateEdge("node1","node2");
	g.CreateEdge("node1","node4");
	g.CreateEdge("node2","node4");
	g.CreateEdge("node2","node3");
	g.CreateEdge("node3","node4");
	g.CreateEdge("node4","node5");
	g.CreateEdge("node6","node7");
	g.CreateEdge("node5","node7");

	std::cout << "Edge Count: " << ((g.GetEdges().size()==8)?"Pass":"FAIL") << "\n";
	std::cout << "Edge Count: " << ((g.GetEdges().size())) << "\n";

	fr.Step(50);

	std::cout << "Node1 pos: " << ((std::round(g.GetVertices()[0]->GetPosition().x()*10000) == 15000.0f && std::round(g.GetVertices()[0]->GetPosition().y()*10000) == -1014.0f )?"Pass":"FAIL") << "\n";
	std::cout << "Node2 pos: " << ((std::round(g.GetVertices()[1]->GetPosition().x()*10000) == 11781.0f && std::round(g.GetVertices()[1]->GetPosition().y()*10000) == -11041.0f )?"Pass":"FAIL") << "\n";
	std::cout << "Node3 pos: " << ((std::round(g.GetVertices()[2]->GetPosition().x()*10000) == 5156.0f && std::round(g.GetVertices()[2]->GetPosition().y()*10000) == -15000.0f )?"Pass":"FAIL") << "\n";

	g.PrintGraphData();

}

int main()
{
	std::cout << "Hello, learning graph layout algorithms!\n";
		
	testFruchtermanReingold();

	return 0;
}