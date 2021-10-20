#include "FruchtermanReingold.h"

#include <iostream>

namespace Layouts
{

	void FruchtermanReingold::CreateVertex(const std::string& vertex_name)
	{
		m_Vertex.push_back(vertex_name);
	}

	void FruchtermanReingold::CreateEdge(const std::string& from_vertex_name, const std::string& too_vertex_name)
	{
		m_Edge[from_vertex_name] = too_vertex_name;
	}

	void FruchtermanReingold::PrintGraphData() const
	{
		PrintVetexData();
		PrintEdgeData();
	}

	FruchtermanReingold::FruchtermanReingold()
	{

	}

	FruchtermanReingold::~FruchtermanReingold()
	{

	}

	void FruchtermanReingold::PrintVetexData() const
	{
		std::cout << "---- Vertex ----\n";
		
		for (const auto& vertex : m_Vertex)
		{
			std::cout << vertex << "\n";
		}

		std::cout << "---- Vertex End----\n\n";
	}

	void FruchtermanReingold::PrintEdgeData() const
	{
		std::cout << "---- Edges ----\n";
		
		for (const auto& [from_vertex, too_vertex] : m_Edge)
		{
			std::cout << from_vertex << " - " << too_vertex << "\n";
		}
		
		std::cout << "---- Edges End----\n\n";
	}

}