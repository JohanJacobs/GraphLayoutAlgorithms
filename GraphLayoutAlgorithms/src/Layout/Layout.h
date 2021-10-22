#pragma once
#include "Graph/Graph.h"
namespace Layout
{	
	/*
		Interface for graph layouts
	*/
	class ILayout
	{
	public:
		virtual void SetGraph(Graphs::Graph& graph) = 0;
		virtual void Step(uint32_t iterations = 50) = 0;						
		virtual ~ILayout()
		{	}
	};
}