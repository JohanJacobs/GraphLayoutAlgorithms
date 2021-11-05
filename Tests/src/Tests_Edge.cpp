#include "gtest/gtest.h"

#include "Edge/IEdge.h"
#include "Vertex/IVertex.h"
#include <string>

struct EdgeTest :testing::Test
{
	std::shared_ptr<Vertex::IVertex> v1, v2, v3, v4;
	std::string v1_name{ "vertex 1" };
	std::string v2_name{ "vertex 2" };
	std::string v3_name{ "vertex 3" };
	std::string v4_name{ "vertex 4" };
	EdgeTest()
	{
		v1 = Vertex::IVertex::CreateVertex(v1_name);
		v2 = Vertex::IVertex::CreateVertex(v2_name);
		v3 = Vertex::IVertex::CreateVertex(v3_name);
		v4 = Vertex::IVertex::CreateVertex(v4_name);
	}
};

TEST_F(EdgeTest, Edge_create)
{	
	auto edge = Edge::IEdge::CreateEdge(v1, v2);
	EXPECT_STRCASEEQ(v1_name.c_str(), edge->From()->GetName().c_str());
	EXPECT_STRCASEEQ(v2_name.c_str(), edge->Too()->GetName().c_str());
}

TEST_F(EdgeTest, Edge_change_too_vertex)
{
	auto edge = Edge::IEdge::CreateEdge(v1, v2);
	edge->Set(v4, v3);
	EXPECT_STRCASEEQ(v4_name.c_str(), edge->From()->GetName().c_str());
	EXPECT_STRCASEEQ(v3_name.c_str(), edge->Too()->GetName().c_str());
}