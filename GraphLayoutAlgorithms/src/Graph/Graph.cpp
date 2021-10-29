#include <iostream>

#include "Graph.h"
#include "base/RandomValues.h"
#include "Vertex/StandardVertex.h"


namespace Graphs
{
	void Graph::CreateEdge(const std::string& from_vertex_name, const std::string& too_vertex_name)
	{
		m_Edge.push_back(std::make_pair(from_vertex_name, too_vertex_name));
	}

	void Graph::PrintGraphData() const
	{
		PrintVetexData();
		PrintEdgeData();
	}



	void Graph::AddVertex(std::shared_ptr<Vertex::IVertex> vertex)
	{
		m_Vertex.emplace_back(vertex);
	}

	void Graph::PrintVetexData() const
	{
		std::cout << "---- Vertex ----\n";

		for (const auto& vertex : m_Vertex)
		{
			std::cout << vertex->GetName() << " - " << vertex->GetPosition().x() << "/" << vertex->GetPosition().y() << "\n";
		}

		std::cout << "---- Vertex End----\n\n";
	}

	void Graph::PrintEdgeData() const
	{
		std::cout << "---- Edges ----\n";

		for (const auto& [from_vertex, too_vertex] : m_Edge)
		{
			std::cout << from_vertex << " - " << too_vertex << "\n";
		}

		std::cout << "---- Edges End----\n\n";
	}
}