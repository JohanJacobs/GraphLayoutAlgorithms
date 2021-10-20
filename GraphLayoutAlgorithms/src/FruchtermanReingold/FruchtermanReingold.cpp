#include "FruchtermanReingold.h"

#include <iostream>

namespace Layouts
{

	void FruchtermanReingold::CreateVertex(const std::string& vertex_name)
	{
		m_Vertex.push_back(vertex_name);
	}

	void FruchtermanReingold::CreateEdge(const std::string& from_vertex_name, const std::string& too_vertex_name)
	{
		m_Edge[from_vertex_name] = too_vertex_name;
	}

	void Step(int iterations = 50)
	{
		// Pseudo code for the algorithm
		/*
			area := W * L; {W and L are width and length of the frame}
			G := (V,E); {the vertices are assigned random initial positions}
			k := Sqrt ( area |V|);
			function Fa(Z) = (x*x) / k;
			function Fr(Z) = (k*k) / z;

			for i := 1 to iterations do 
				
				{ calculate repulsive forces }
				for v in V do
					{each vertex has two vectors: .pos and .disp}
					v.disp := 0;
					for u in V do 
						if u != v then
							{Vector between teh two positions of the two vertices }
							Delta = v.pos - y.pos
							v.disp = v.disp + (delta / |delta|)*Fr(|delta|) { |delta| is magnitude of the vector }
						endif 
					end for 
				
				{ calculate attractive foreces }
				for e in E do 
					{each edge is an ordered pair of vertices v and u}
					delta = e.v.pos - e.u.pos
					e.v.disp = e.v.disp - (delta / |delta|) * Fa(|delta|)
					e.y.disp = e.u.disp + (delta / |delta|) * Fa(|delta|)
				end for 
				
				{ limit maximum displacement to the temprature t and prevent from being ouside the frame }
				for v in V do 
					v.pos = v.pos + (v.displ/ |v.disp|) * min (v.disp, t)l
					v.pos.x = min(W/2, max (-W/2, v.pos.x))
					v.pos.y = min (L/2, max(-L/2, v.pos.y))
				End for 

				{ reduce the temprature }
				cool(t)
			end for 
		*/

	}

	void FruchtermanReingold::PrintGraphData() const
	{
		PrintVetexData();
		PrintEdgeData();
	}

	FruchtermanReingold::FruchtermanReingold()
	{

	}

	FruchtermanReingold::~FruchtermanReingold()
	{

	}

	void FruchtermanReingold::PrintVetexData() const
	{
		std::cout << "---- Vertex ----\n";
		
		for (const auto& vertex : m_Vertex)
		{
			std::cout << vertex << "\n";
		}

		std::cout << "---- Vertex End----\n\n";
	}

	void FruchtermanReingold::PrintEdgeData() const
	{
		std::cout << "---- Edges ----\n";
		
		for (const auto& [from_vertex, too_vertex] : m_Edge)
		{
			std::cout << from_vertex << " - " << too_vertex << "\n";
		}
		
		std::cout << "---- Edges End----\n\n";
	}

}