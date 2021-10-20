#include <string>
#include <vector>
#include <unordered_map>

namespace Layouts
{
	class FruchtermanReingold
	{
	public:
		void CreateVertex(const std::string& vertex_name);
		void CreateEdge(const std::string& from_vertex_name, const std::string& too_vertex_name);

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