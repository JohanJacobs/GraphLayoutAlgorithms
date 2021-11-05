#include "UndirectedEdge.h"
namespace Edge
{
	
	UndirectedEdge::UndirectedEdge(std::shared_ptr<Vertex::IVertex> from_vertex, std::shared_ptr<Vertex::IVertex> too_vertex)
		:m_From{from_vertex},m_Too{too_vertex}
	{

	}

	std::shared_ptr<Vertex::IVertex> UndirectedEdge::From()
	{
		return m_From;
	}

	const std::shared_ptr<Vertex::IVertex> UndirectedEdge::From() const
	{
		return m_From;
	}

	std::shared_ptr<Vertex::IVertex> UndirectedEdge::Too()
	{
		return m_Too;
	}

	const std::shared_ptr<Vertex::IVertex> UndirectedEdge::Too() const
	{
		return m_Too;
	}

	void UndirectedEdge::Set(std::shared_ptr<Vertex::IVertex> from_vertex, std::shared_ptr<Vertex::IVertex> too_vertex)
	{
		m_From = from_vertex;
		m_Too = too_vertex;
	}
}