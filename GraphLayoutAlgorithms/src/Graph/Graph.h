#pragma once
#include <string>
#include <vector>

#include "Graph/IGraph.h"
#include "Vertex/IVertex.h"
#include "Base/Vector2.h"
#include "Vertex/IVertex.h"

namespace Graphs
{
	class Graph : public IGraph
	{
	public:
		void CreateVertex(const std::string& vertex_name);
		void CreateVertex(const std::string& vertex_name, const Vector2& vertex_position);
		const std::vector<std::shared_ptr<Vertex::IVertex>>& GetVertices() const { return m_Vertex; }
		std::vector<std::shared_ptr<Vertex::IVertex>>& GetVertices() { return m_Vertex; }
		
		void CreateEdge(const std::string& from_vertex_name, const std::string& too_vertex_name);	
		const std::vector<std::pair<std::string, std::string>>& GetEdges() const { return m_Edge; }
		

		void PrintGraphData() const;

	private:	
		void PrintVetexData() const;
		void PrintEdgeData() const;

	private:
		std::vector<std::shared_ptr<Vertex::IVertex>> m_Vertex;
		std::vector<std::pair<std::string, std::string>> m_Edge;
	};
}