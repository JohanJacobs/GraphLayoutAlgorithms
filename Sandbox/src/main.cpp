#include <iostream>

#include "GraphLayoutAlgorithms.h"

int main()
{
	std::cout << "Hello, learning graph layout algorithms!\n";
	
	auto g = Graphs::IGraph::CreateGraph(Graphs::GraphType::UndirectedGraph);

	// add vertices 
	g->AddVertex(Vertex::IVertex::CreateVertex(Vertex::VertexType::StandardVertex, "node1", Vector2(0.1f, 0.1f)));
	g->AddVertex(Vertex::IVertex::CreateVertex(Vertex::VertexType::StandardVertex, "node2", Vector2(0.5f, 0.5f)));
	g->AddVertex(Vertex::IVertex::CreateVertex(Vertex::VertexType::StandardVertex, "node3", Vector2(0.9f, 0.9f)));
	g->AddVertex(Vertex::IVertex::CreateVertex(Vertex::VertexType::StandardVertex, "node4", Vector2(0.5f, 0.1f)));
	g->AddVertex(Vertex::IVertex::CreateVertex(Vertex::VertexType::StandardVertex, "node5", Vector2(0.9f, 0.5f)));
	g->AddVertex(Vertex::IVertex::CreateVertex(Vertex::VertexType::StandardVertex, "node6", Vector2(0.2f, 0.5f)));
	g->AddVertex(Vertex::IVertex::CreateVertex(Vertex::VertexType::StandardVertex, "node7", Vector2(0.1f, 0.9f)));

	//add endges
	g->CreateEdge("node1", "node2");
	g->CreateEdge("node1", "node4");
	g->CreateEdge("node2", "node4");
	g->CreateEdge("node2", "node3");
	g->CreateEdge("node3", "node4");
	g->CreateEdge("node4", "node5");
	g->CreateEdge("node6", "node7");
	g->CreateEdge("node5", "node7");

	// create layout
	Layouts::FruchtermanReingold fg(g);
	fg.Step(50);

	return 0;
}