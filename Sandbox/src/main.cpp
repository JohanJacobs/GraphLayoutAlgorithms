#include <iostream>

#include "GraphLayoutAlgorithms/GraphLayoutAlgorithms.h"

int main()
{
	std::cout << "Hello, learning graph layout algorithms!\n";
	
	auto g = GLA::Factory::CreateGraph();

	// add vertices 
	g->AddVertex(GLA::Factory::CreateVertex("node1"));//, Vector2(0.1f, 0.1f)));
	g->AddVertex(GLA::Factory::CreateVertex("node2"));//, Vector2(0.5f, 0.5f)));
	g->AddVertex(GLA::Factory::CreateVertex("node3"));//, Vector2(0.9f, 0.9f)));
	g->AddVertex(GLA::Factory::CreateVertex("node4"));//, Vector2(0.5f, 0.1f)));
	g->AddVertex(GLA::Factory::CreateVertex("node5"));//, Vector2(0.9f, 0.5f)));
	g->AddVertex(GLA::Factory::CreateVertex("node6"));//, Vector2(0.2f, 0.5f)));
	g->AddVertex(GLA::Factory::CreateVertex("node7"));// , Vector2(0.1f, 0.9f)));

	for (const auto& vertex : g->GetVertices())
	{
		std::cout << vertex->GetName() << ": " << vertex->GetPosition().x() << "/" << vertex->GetPosition().y() << "\n";
	}

	//add edges
	g->CreateEdge("node1", "node2");
	g->CreateEdge("node1", "node4");
	g->CreateEdge("node2", "node4");
	g->CreateEdge("node2", "node3");
	g->CreateEdge("node3", "node4");
	g->CreateEdge("node4", "node5");
	g->CreateEdge("node6", "node7");
	g->CreateEdge("node5", "node7");
	g->CreateEdge("node5", "node6");
	
	// create layout
	Layouts::FruchtermanReingold fg(g);
	fg.Step(50);

	std::cout << "\n\nupdated positions\n";
	for (const auto& vertex : g->GetVertices())
	{
		std::cout << vertex->GetName() << ": " << vertex->GetPosition().x() << "/" << vertex->GetPosition().y() << "\n";
	}
	return 0;
}