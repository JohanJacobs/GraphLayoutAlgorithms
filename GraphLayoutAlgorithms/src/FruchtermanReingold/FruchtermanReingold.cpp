#include <iostream>
#include <algorithm>
#include <cassert>

#include "FruchtermanReingold.h"
#include "base/Vector2.h"
#include "base/RandomValues.h"

namespace Layouts
{
	FruchtermanReingold::FruchtermanReingold()
	:m_Width{1.0f}, m_Height{1.0f}
	{

	}

	FruchtermanReingold::~FruchtermanReingold()
	{

	}

	void FruchtermanReingold::CreateVertex(const std::string& vertex_name)
	{
		m_Vertex.emplace_back(vertex_name);
	}

	void FruchtermanReingold::CreateEdge(const std::string& from_vertex_name, const std::string& too_vertex_name)
	{
		m_Edge[from_vertex_name] = too_vertex_name;
	}

	void FruchtermanReingold::Step(uint32_t iterations)
	{		
		// pseudo-code
		//area := W * L; {W and L are width and length of the frame} 
		float area = m_Width * m_Height;

		float t = 10.0f * m_Vertex.size(); // temprature

		// assign random positions to the vertex based on the area 		
		//G := (V,E); {the vertices are assigned random initial positions}
		for (auto& vertex : m_Vertex)
		{
			vertex.SetPosition(RandomNumbers::GetFloat(),RandomNumbers::GetFloat());
		}

		float k = std::sqrt(area);


		for (uint32_t iteration=0; iteration < iterations; iteration++)
		{
			//{ calculate repulsive forces }
			for (auto& vertex : m_Vertex)
			{
				vertex.SetDisplacement(0.0f, 0.0f);
				for (auto& other_vertex : m_Vertex)
				{
					if (other_vertex.GetName() == vertex.GetName())
						continue;
					
					// {Vector between the two positions of the two vertices }
					auto distance_vector = vertex.GetPosition() - other_vertex.GetPosition();
					float distance_vector_magnitude = distance_vector.Magnitude();
					auto distance_normalized = Vector2::Normalize(distance_vector);

					//v.disp = v.disp + (delta / |delta|)*Fr(|delta|) { |delta| is magnitude of the vector }
					float Fr = ((k*k) / distance_vector_magnitude);
					auto new_displacement = vertex.GetDisplacement() + distance_normalized * Fr;
					vertex.SetDisplacement(new_displacement.x(),new_displacement.y());
				}
			}

			//{ calculate attractive forces }
			for ( const auto& [from_vertex_name, too_vertex_name] : m_Edge)
			{
				auto& from_vertex_data = GetVertexData(from_vertex_name);
				auto& too_vertex_data = GetVertexData(from_vertex_name);

				auto distance_vector = from_vertex_data.GetPosition() - too_vertex_data.GetPosition();
				auto distance_vector_magnitude = distance_vector.Magnitude();
				auto fa = (distance_vector_magnitude*distance_vector_magnitude)/k;

				auto attractive_force = Vector2::Normalize(distance_vector) * fa;
				auto from_vertex_new_displacement = from_vertex_data.GetDisplacement() - attractive_force;
				from_vertex_data.SetDisplacement(from_vertex_new_displacement.x(),from_vertex_new_displacement.y());

				auto too_vertex_new_displacement = too_vertex_data.GetDisplacement() + attractive_force;
				too_vertex_data.SetDisplacement(too_vertex_new_displacement.x(),too_vertex_new_displacement.y());
			}
			
			//{ limit maximum displacement to the temprature t and prevent from being ouside the frame }
			for (auto& vertex : m_Vertex)
			{
				auto displacement_normalized = Vector2::Normalize(vertex.GetDisplacement());
				auto new_position = vertex.GetPosition() + (displacement_normalized * std::min(vertex.GetDisplacement().Magnitude(),t));
				
				// limit to the screen bounds 
				float new_x = std::min(m_Width/2.0f, std::max(-m_Width/2,new_position.x()));
				float new_y = std::min(m_Height/2.0f, std::max(-m_Height/2,new_position.y()));
				vertex.SetPosition(new_x, new_y);
			}

			//{ reduce the temprature }
			if (t > 0.01f)
			{
				t = t * 0.95f;
			}
			else
			{
				t = 0.01f;
			}
		}
		/*
			//area := W * L; {W and L are width and length of the frame} 
			//G := (V,E); {the vertices are assigned random initial positions}
			//k := Sqrt ( area |V|);
			function Fa(Z) = (x*x) / k;
			function Fr(Z) = (k*k) / z;

			for i := 1 to iterations do 
				
				{ calculate repulsive forces }
				for v in V do
					{each vertex has two vectors: .pos and .disp}
					v.disp := 0;
					for u in V do 
						if u != v then
							{Vector between the two positions of the two vertices }
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

	FruchtermanReingoldVertex& FruchtermanReingold::GetVertexData(const std::string& vertex_name)	
	{
		auto result = std::find_if(std::begin(m_Vertex),std::end(m_Vertex), [&](const FruchtermanReingoldVertex& v){ return v.GetName() == vertex_name;});

		assert(result != std::end(m_Vertex));
		// if (result == std::end(m_Vertex))
		// {
		// 	std::assert("GetVertexData(): vertex_name not found"); // not sure if this is correct but lets use it for now.
		// }

		return *result; //de reference the pointer.
	}

	const std::vector<FruchtermanReingoldVertex>& FruchtermanReingold::GetVertex() const
	{
		return m_Vertex;
	}

	const std::unordered_map<std::string,std::string>& FruchtermanReingold::GetEdge() const
	{
		return m_Edge;
	}

	void FruchtermanReingold::PrintGraphData() const
	{
		PrintVetexData();
		PrintEdgeData();
	}

	void FruchtermanReingold::PrintVetexData() const
	{
		std::cout << "---- Vertex ----\n";
		
		for (const auto& vertex : m_Vertex)
		{
			std::cout << vertex.GetName() << "\n";
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