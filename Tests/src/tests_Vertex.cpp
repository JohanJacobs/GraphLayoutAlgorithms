#include "gtest/gtest.h"

#include "Vertex/IVertex.h"

struct VertexTest : testing::Test
{
	std::shared_ptr<Vertex::IVertex> vertex;

	VertexTest()
	{
		vertex = Vertex::IVertex::CreateVertex(Vertex::VertexType::StandardVertex);
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
