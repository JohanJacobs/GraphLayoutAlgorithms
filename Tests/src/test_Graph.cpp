#include "gtest/gtest.h"

#include "Graph/Graph.h"

#include <string>

const std::string GraphNameTest(std::string name)
{
	Graphs::Graph g("test name");
	return g.Name();
}


TEST(Graph, graph_name_test)
{
	EXPECT_STRCASEEQ(std::string("test name").c_str(), GraphNameTest("test name").c_str());
}



