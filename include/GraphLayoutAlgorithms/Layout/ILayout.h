#pragma once
#include <stdint.h>
#include "GraphLayoutAlgorithms/Graph/IGraph.h"
namespace Layouts
{	
	/*
		Interface for graph layouts
	*/
	class ILayout
	{
	public:
		virtual void Step(uint32_t iterations = 50) = 0;						
		virtual ~ILayout()
		{	}
	};
}