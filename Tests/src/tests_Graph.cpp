#include "gtest/gtest.h"

#include "graph/IGraph.h"
#include <string>


struct GraphTest : testing::Test
{
	std::shared_ptr<Graphs::IGraph> graph;

	GraphTest()
	{
		graph = Graphs::IGraph::CreateGraph();
	}

	~GraphTest()
	{
		graph.reset();
	}		
};

TEST_F(GraphTest, graph_name_tests)
{
	EXPECT_STRCASEEQ(std::string("no name").c_str(), graph->Name().c_str());
	
	std::string graph_name{ "Test graph." };
	graph->SetName(graph_name);

	EXPECT_STRCASEEQ(graph_name.c_str(), graph->Name().c_str());
}

TEST_F(GraphTest, graph_vertex_tests)
{
	auto v1 =  Vertex::IVertex::CreateVertex("vertex1");
	auto v2 = Vertex::IVertex::CreateVertex("vertex2");

	graph->AddVertex(v1);
	graph->AddVertex(v2);
	EXPECT_EQ(2, graph->VertexCount());
		
}


TEST_F(GraphTest, AddEdge)
{
	auto v1 = Vertex::IVertex::CreateVertex("vertex1");
	auto v2 = Vertex::IVertex::CreateVertex("vertex2");

	graph->AddVertex(v1);
	graph->AddVertex(v2);
	graph->AddEdge(Edge::IEdge::CreateEdge(v1, v2));
	EXPECT_EQ(1, graph->EdgeCount());	
}

TEST_F(GraphTest, CreateEdge)
{
	graph->CreateEdge("node3","node4");
	EXPECT_EQ(1, graph->EdgeCount());
}
