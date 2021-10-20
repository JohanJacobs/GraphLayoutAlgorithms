#include <string>
#include <vector>
#include <unordered_map>

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

	class FruchtermanReingold
	{
	public:
		void CreateVertex(const std::string& vertex_name);
		void CreateEdge(const std::string& from_vertex_name, const std::string& too_vertex_name);

		void Step(int iterations = 50);

		void PrintGraphData() const ;

		FruchtermanReingold();
		~FruchtermanReingold();
	private:
		void PrintVetexData() const;
		void PrintEdgeData() const;
	private:
		std::vector<std::string> m_Vertex;
		std::unordered_map<std::string, std::string> m_Edge;
	};
}