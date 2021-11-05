#pragma once
#include "Edge/IEdge.h"
namespace Edge
{
	class UndirectedEdge : public IEdge
	{
	public:

		UndirectedEdge(std::shared_ptr<Vertex::IVertex> from_vertex, std::shared_ptr<Vertex::IVertex> too_vertex);
		std::shared_ptr<Vertex::IVertex> From() override;


		std::shared_ptr<Vertex::IVertex> Too() override;


		const std::shared_ptr<Vertex::IVertex> From() const override;


		const std::shared_ptr<Vertex::IVertex> Too() const override;


		void Set(std::shared_ptr<Vertex::IVertex> from_vertex, std::shared_ptr<Vertex::IVertex> too_vertex) override;

	private:
		std::shared_ptr<Vertex::IVertex> m_From;
		std::shared_ptr<Vertex::IVertex> m_Too;

	};
}
