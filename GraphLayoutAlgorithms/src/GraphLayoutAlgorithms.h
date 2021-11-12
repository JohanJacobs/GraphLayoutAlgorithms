#include "Layout/ILayout.h"
#include "Graph/IGraph.h"
#include "Vertex/IVertex.h"
#include "Edge/IEdge.h"

// layouts
#include "FruchtermanReingold/FruchtermanReingold.h"
namespace GLA
{
	class Factory
	{
	public:
		static std::shared_ptr<Graphs::IGraph> CreateGraph()
		{
			return Graphs::IGraph::CreateGraph();
		}
		static std::shared_ptr<Vertex::IVertex> CreateVertex(const std::string& vertex_name, const Vector2& vertex_position = Vector2(0.0f, 0.0f))
		{
			return Vertex::IVertex::CreateVertex(vertex_name, vertex_position);
		}
	};	
}