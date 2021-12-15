#include <string>
#include <vector>
#include <unordered_map>

#include "GraphLayoutAlgorithms/Vertex/StandardVertex.h"
#include "GraphLayoutAlgorithms/Graph/IGraph.h"
#include "GraphLayoutAlgorithms/Layout/ILayout.h"

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

	// simple struct to keep track of the properties used.
	struct FructermanReingoldProperties
	{
		// default values will cause no movement on the graph.
		FructermanReingoldProperties(std::size_t vertex_count = 0, float area = 0.0f, float t = 0.0f,float half_width = 0.0f, float half_height = 0.0f,float k = 0.0f)
			:vertex_count{ vertex_count }, area{ area }, t{ t }, half_width{ half_width }, half_height{ half_height }, k{k}
		{

		}
		~FructermanReingoldProperties() = default;

		std::size_t vertex_count;
		float area;		// area * width 
		float k;		// sqrt( |area|)
		float t;		// temperature
		float half_width;
		float half_height;
	};

	class FruchtermanReingold : public Layouts::ILayout
	{
	public:
		void Step(uint32_t iterations = 50) override;

		FruchtermanReingold(std::shared_ptr<Graphs::IGraph> graph);
		~FruchtermanReingold();

	private:
		const std::shared_ptr<Vertex::IVertex>& GetVertexData(const std::string& vertex_name);

		void CalculateRepulsiveForces(float k);
		void CalculateAttractiveForces(float k);
		void ConstrainDisplacement(float t);
		float UpdateTemprature(float t);

	private:
		std::shared_ptr<Graphs::IGraph> m_Graph;
		float m_Width;
		float m_Height;
		std::unordered_map<std::string, Vector2> m_Displacement;
	};
}