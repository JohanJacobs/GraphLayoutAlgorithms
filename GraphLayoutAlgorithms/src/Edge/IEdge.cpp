#include "IEdge.h"
#include "Edge/Edges/UndirectedEdge.h"

namespace Edge
{

	std::shared_ptr<Edge::IEdge> IEdge::CreateEdge(std::shared_ptr<Vertex::IVertex> from_vertex, std::shared_ptr<Vertex::IVertex> too_vertex)
	{
		return std::make_shared<UndirectedEdge>(from_vertex, too_vertex);
	}
}