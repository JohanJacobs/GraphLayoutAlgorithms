#include "gtest/gtest.h"

#include "GraphLayoutAlgorithms/Vertex/IVertex.h"

struct VertexTest : testing::Test
{
	std::shared_ptr<Vertex::IVertex> vertex;

	VertexTest()
	{
		vertex = Vertex::IVertex::CreateVertex();
	}

	~VertexTest()
	{
		vertex.reset();
	}

}; 

TEST_F(VertexTest, vertex_name_tests_default)
{	
	std::string default_name{ "vertex" };
	EXPECT_STRCASEEQ(default_name.c_str(), vertex->GetName().c_str());	
}

TEST_F(VertexTest, vertex_set_position)
{	
	vertex->SetPosition(1, 2);
	EXPECT_EQ(true, vertex->GetPosition() == Vector2(1, 2));
}

TEST_F(VertexTest, vertex_isEquivalent)
{
	auto v1 = Vertex::IVertex::CreateVertex("v1", Vector2(1.0f, 2.0f));
	auto v2 = Vertex::IVertex::CreateVertex("v2", Vector2(1.0f,2.0f));	
	EXPECT_EQ(true, (v1 == v1));
}

TEST_F(VertexTest, vertex_isNotEquivalent)
{
	auto v1 = Vertex::IVertex::CreateVertex("v1", Vector2(1.0f, 2.0f));
	auto v2 = Vertex::IVertex::CreateVertex("v2", Vector2(1.0f, 2.0f));
	EXPECT_EQ(false, (v1 == v2));
}