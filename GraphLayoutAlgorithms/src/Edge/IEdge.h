#pragma once
#include "vertex/IVertex.h"
namespace Edge{
	class IEdge
	{
	public:
		static std::shared_ptr<IEdge> CreateEdge(std::shared_ptr<Vertex::IVertex> from_vertex, std::shared_ptr<Vertex::IVertex> too_vertex);

		virtual std::shared_ptr<Vertex::IVertex> From() = 0;
		virtual std::shared_ptr<Vertex::IVertex> Too() = 0;
		
		virtual const std::shared_ptr<Vertex::IVertex> From() const = 0;
		virtual const std::shared_ptr<Vertex::IVertex> Too() const = 0;

		virtual void Set(std::shared_ptr<Vertex::IVertex> from_vertex, std::shared_ptr<Vertex::IVertex> too_vertex)=0;
		
		virtual ~IEdge() = default;
	private:

	};
}
