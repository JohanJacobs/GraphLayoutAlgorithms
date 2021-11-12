#pragma once
#include <string>
#include <vector>

#include "Graph/IGraph.h"
#include "Vertex/IVertex.h"
#include "Base/Vector2.h"
#include "Vertex/IVertex.h"
#include "Edge/IEdge.h"

namespace Graphs
{
	class Graph : public IGraph
	{
	public:
		
		
		void AddVertex(std::shared_ptr<Vertex::IVertex> vertex) override;
		const std::vector<std::shared_ptr<Vertex::IVertex>>& GetVertices() const { return m_Vertex; }
		std::vector<std::shared_ptr<Vertex::IVertex>>& GetVertices() { return m_Vertex; }
		
		void AddEdge(std::shared_ptr<Edge::IEdge> new_edge) override;
		void CreateEdge(const std::string& from_vertex_name, const std::string& too_vertex_name) override;
		const std::vector<std::shared_ptr<Edge::IEdge>>& GetEdges() const { return m_Edge; }
		
		const std::string& Name() const override;
		void SetName(const std::string& graph_name) override;

		
		size_t VertexCount() const override;
		size_t EdgeCount() const override { return m_Edge.size(); }

		void PrintGraphData() const;

		Graph(const std::string& graph_name = "no name");		

	private:

		// Returns a vertex given its name. If the vertex does not exist it will be created.
		std::shared_ptr<Vertex::IVertex> GetVertexOrCreate(const std::string& vertex_name) ;

		void PrintVetexData() const;
		void PrintEdgeData() const;

	private:
		std::vector<std::shared_ptr<Vertex::IVertex>> m_Vertex;
		std::vector<std::shared_ptr<Edge::IEdge>> m_Edge;
		std::string m_Name;
	};
}