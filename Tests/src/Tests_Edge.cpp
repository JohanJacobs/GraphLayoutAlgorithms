#include "gtest/gtest.h"

#include "GraphLayoutAlgorithms/edge/IEdge.h"
#include "GraphLayoutAlgorithms/Vertex/IVertex.h"

#include <string>

/*
	testing for the EDGE classes
*/

struct EdgeTest : testing::Test
{
	std::shared_ptr<Vertex::IVertex> v1;
	std::shared_ptr<Vertex::IVertex> v2;
	std::shared_ptr<Vertex::IVertex> v3;
	std::shared_ptr<Vertex::IVertex> v4;
	

	EdgeTest()
	{
		v1 = Vertex::IVertex::CreateVertex("vertex 1");
		v2 = Vertex::IVertex::CreateVertex("vertex 2");
		v3 = Vertex::IVertex::CreateVertex("vertex 3");
		v4 = Vertex::IVertex::CreateVertex("vertex 4");
	}

	~EdgeTest()
	{
		v1.reset();
		v2.reset();
		v3.reset();
		v4.reset();
	}
};

TEST_F(EdgeTest, CreateAnEdge)
{
	auto edge = Edge::IEdge::CreateEdge(v1, v2);

	EXPECT_STRCASEEQ(std::string("vertex 1").c_str(), edge->From()->GetName().c_str());
	EXPECT_STRCASEEQ(std::string("vertex 2").c_str(), edge->Too()->GetName().c_str());	
}

TEST_F(EdgeTest, ModifyEdge)
{
	auto edge = Edge::IEdge::CreateEdge(v1, v2);
	edge->Set(v4, v3);
	EXPECT_STRCASEEQ(std::string("vertex 4").c_str(), edge->From()->GetName().c_str());
	EXPECT_STRCASEEQ(std::string("vertex 3").c_str(), edge->Too()->GetName().c_str());
}
