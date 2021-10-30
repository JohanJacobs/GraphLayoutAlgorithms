#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Vertex/IVertex.h"

namespace Graphs
{
	enum class GraphType
	{
		UndirectedGraph=0
	};
	/*
		Interface for graph data.
	*/
	class IGraph
	{
	public:

		std::shared_ptr<IGraph> static CreateGraph(GraphType graph_type);

	public:

		virtual void AddVertex(std::shared_ptr<Vertex::IVertex> vertex) = 0;		
		virtual const std::vector<std::shared_ptr<Vertex::IVertex>>& GetVertices() const = 0;
		virtual std::vector<std::shared_ptr<Vertex::IVertex>>& GetVertices() = 0;
		virtual size_t VertexCount() const = 0;

		virtual void CreateEdge(const std::string& from_vertex_name, const std::string& too_vertex_name)=0;
		virtual const std::vector<std::pair<std::string, std::string>>& GetEdges() const = 0;

		virtual void PrintGraphData() const = 0;

		virtual const std::string& Name() const = 0;
		virtual void SetName(const std::string& graph_name)= 0;

		virtual ~IGraph()
		{	}
	private:
	};
}