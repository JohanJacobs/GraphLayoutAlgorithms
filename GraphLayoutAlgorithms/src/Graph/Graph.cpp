#include <iostream>
#include <algorithm>

#include "Graph.h"
#include "base/RandomValues.h"
#include "Vertex/StandardVertex.h"

namespace Graphs
{	
	Graph::Graph(const std::string& graph_name /*= "no name"*/)
		:m_Name{ graph_name }
	{

	}

	size_t Graph::VertexCount() const
	{
		return m_Vertex.size();
	}


	void Graph::SetName(const std::string& graph_name)
	{		
		m_Name = graph_name;
	}

	void Graph::AddEdge(std::shared_ptr<Edge::IEdge> new_edge)
	{
		m_Edge.push_back(new_edge);
	}

	void Graph::CreateEdge(const std::string& from_vertex_name, const std::string& too_vertex_name)
	{
		auto from_vertex = GetVertexOrCreate(from_vertex_name);
		auto too_vertex = GetVertexOrCreate(too_vertex_name);

		// does this edge already exist
		auto SearchForEdge = std::find_if(std::begin(m_Edge), std::end(m_Edge), [from_vertex, too_vertex](std::shared_ptr<Edge::IEdge> e) -> auto {
				// we assume everything is undirected 
			return (e->From() == from_vertex && e->Too() == too_vertex || e->From() == too_vertex && e->Too() == from_vertex);
			});

		if (SearchForEdge != std::end(m_Edge))
			return;

		m_Edge.push_back(Edge::IEdge::CreateEdge(from_vertex,too_vertex));
	}

	void Graph::PrintGraphData() const
	{
		PrintVetexData();
		PrintEdgeData();
	}

	const std::string& Graph::Name() const
	{
		return m_Name;
	}

	void Graph::AddVertex(std::shared_ptr<Vertex::IVertex> vertex)
	{
		m_Vertex.emplace_back(vertex);
	}

	std::shared_ptr<Vertex::IVertex> Graph::GetVertexOrCreate(const std::string& vertex_name) 
	{
		auto result = std::find_if(std::begin(m_Vertex), std::end(m_Vertex), [&](std::shared_ptr<Vertex::IVertex> v) {
			return (v->GetName() == vertex_name);
		});

		// vertex does not exist so create it and return .
		if (result == std::end(m_Vertex))
		{
			return Vertex::IVertex::CreateVertex(vertex_name);
		}

		return *result;
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

		for (const auto& edge : m_Edge)
		{
			std::cout << edge->From()->GetName() << " - " << edge->Too()->GetName() << "\n";
		}

		std::cout << "---- Edges End----\n\n";
	}
}