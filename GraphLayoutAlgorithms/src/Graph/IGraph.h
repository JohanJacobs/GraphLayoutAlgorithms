#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Vertex/IVertex.h"

namespace Graphs
{
	/*
		Interface for graph data.
	*/
	class IGraph
	{
	public:
		std::shared_ptr<IGraph> static CreateGraph();
		
	public:
		virtual void CreateVertex(const std::string& vertex_name) =0;
		virtual void CreateVertex(const std::string& vertex_name, const Vector2& vertex_position )=0;
		virtual const std::vector<std::shared_ptr<Vertex::IVertex>>& GetVertices() const = 0;
		virtual std::vector<std::shared_ptr<Vertex::IVertex>>& GetVertices() = 0;

		virtual void CreateEdge(const std::string& from_vertex_name, const std::string& too_vertex_name)=0;
		virtual const std::vector<std::pair<std::string, std::string>>& GetEdges() const = 0;

		virtual void PrintGraphData() const = 0;

		virtual ~IGraph()
		{	}
	private:
	};
}