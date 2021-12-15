#include "IGraph.h"

#include "Graph.h"

namespace Graphs
{
	std::shared_ptr<Graphs::IGraph> IGraph::CreateGraph()
	{
		return std::make_shared<Graph>();
	}
}