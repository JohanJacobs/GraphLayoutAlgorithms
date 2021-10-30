#include <string>
#include <vector>
#include <unordered_map>

#include "Vertex/StandardVertex.h"
#include "Graph/IGraph.h"
#include "Layout/ILayout.h"

namespace Layouts
{
	/*
		Graph Drawing by Force-Directed Placement 
		THOMAS M. J. FRUCHTERMAN* AND EDWARD M. REINGOLD
		SOFTWARE—PRACTICE AND EXPERIENCE, VOL. 21(1 1), 1129-1164 (NOVEMBER 1991)

		A Modification of the spring-embber model [Eades] for drawing undirected graphs with straight edges. 

		Layout criteria:
		- Distribute vertices evenly in the frame
		- Minimize edge crossings
		- Make edge lengths uniform
		- Reflect inherent symmetry
		- conform to the frame ( size )

		Graph Types :
		- Undirected 

		Edge types:
		- Straight		
	*/

	class FruchtermanReingold : public Layouts::ILayout
	{
	public:
		void Step(uint32_t iterations = 50) override;

		FruchtermanReingold(std::shared_ptr<Graphs::IGraph> graph);
		~FruchtermanReingold();

	private:
		const std::shared_ptr<Vertex::IVertex>& GetVertexData(const std::string& vertex_name);


	private:
		std::shared_ptr<Graphs::IGraph> m_Graph;
		float m_Width;
		float m_Height;
	};
}