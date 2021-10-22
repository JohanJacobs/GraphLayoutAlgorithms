#pragma once
#include <stdint.h>
#include "Graph/IGraph.h"
namespace Layout
{	
	/*
		Interface for graph layouts
	*/
	class ILayout
	{
	public:
		virtual void SetGraph(Graphs::IGraph& graph) = 0;
		virtual void Step(uint32_t iterations = 50) = 0;						
		virtual ~ILayout()
		{	}
	};
}