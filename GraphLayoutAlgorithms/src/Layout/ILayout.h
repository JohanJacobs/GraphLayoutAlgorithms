#pragma once
#include <stdint.h>
#include "Graph/IGraph.h"
namespace Layouts
{	
	/*
		Interface for graph layouts
	*/
	class ILayout
	{
	public:
		virtual void SetGraph(std::shared_ptr<Graphs::IGraph> graph) = 0;
		virtual void Step(uint32_t iterations = 50) = 0;						
		virtual ~ILayout()
		{	}
	};
}