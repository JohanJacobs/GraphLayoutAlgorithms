#include <iostream>
#include <iomanip>

#include <algorithm>
#include <cassert>

#include "FruchtermanReingold.h"
#include "base/Vector2.h"
#include "base/RandomValues.h"

namespace Layouts
{
	FruchtermanReingold::FruchtermanReingold()
	:m_Width{3.0f}, m_Height{3.0f}
	{

	}

	FruchtermanReingold::~FruchtermanReingold()
	{

	}

	void FruchtermanReingold::CreateVertex(const std::string& vertex_name)
	{
		CreateVertex(vertex_name,Vector2(RandomNumbers::GetFloat(),RandomNumbers::GetFloat()));
	}

	void FruchtermanReingold::CreateVertex(const std::string& vertex_name, const Vector2& vertex_position)
	{
		m_Vertex.emplace_back(vertex_name, vertex_position);
	}

	void FruchtermanReingold::CreateEdge(const std::string& from_vertex_name, const std::string& too_vertex_name)
	{
		m_Edge.push_back(std::make_pair(from_vertex_name, too_vertex_name));
	}

	void FruchtermanReingold::Step(uint32_t iterations)
	{
		float area = m_Width * m_Height;
		float k = std::sqrt(area / m_Vertex.size());
		float t = 10.0f * m_Vertex.size(); // temprature
		
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
					
					// Vector between the two positions of the two vertices 
					auto distance_vector = vertex.GetPosition() - other_vertex.GetPosition();
					float distance_vector_magnitude = distance_vector.Magnitude();
					auto distance_normalized = Vector2::Normalize(distance_vector);

					//v.disp = v.disp + (delta / |delta|)*Fr(|delta|) { |delta| is magnitude of the vector }
					if (distance_vector_magnitude == 0.0f)
						distance_vector_magnitude = 1.0f;

					float Fr = ((k*k) / distance_vector_magnitude);

					auto new_displacement = vertex.GetDisplacement() + distance_normalized * Fr;
					vertex.SetDisplacement(new_displacement.x(), new_displacement.y());
				}
			}

			//{ calculate attractive forces }
			for ( const auto& [from_vertex_name, too_vertex_name] : m_Edge)
			{
				auto& from_vertex_data = GetVertexData(from_vertex_name);
				auto& too_vertex_data = GetVertexData(too_vertex_name);

				auto distance_vector = from_vertex_data.GetPosition() - too_vertex_data.GetPosition();
				auto distance_vector_magnitude = distance_vector.Magnitude();
				auto distnace_vector_normalized = Vector2::Normalize(distance_vector);

				auto fa = (distance_vector_magnitude * distance_vector_magnitude)/k;
				auto attractive_force = distnace_vector_normalized * fa;
				auto from_vertex_new_displacement = from_vertex_data.GetDisplacement() - attractive_force;
				from_vertex_data.SetDisplacement(from_vertex_new_displacement.x(),from_vertex_new_displacement.y());

				auto too_vertex_new_displacement = too_vertex_data.GetDisplacement() + attractive_force;
				too_vertex_data.SetDisplacement(too_vertex_new_displacement.x(),too_vertex_new_displacement.y());
			}

			//{ limit maximum displacement to the temprature t and prevent from being ouside the frame }
			for (auto& vertex : m_Vertex)
			{
				auto displacement_normalized = Vector2::Normalize(vertex.GetDisplacement());
				float displacement_magnitude = vertex.GetDisplacement().Magnitude();

				auto new_position = vertex.GetPosition() + (displacement_normalized * std::min(displacement_magnitude, t));

				// limit to the screen bounds 
				float half_width = m_Width / 2.0f;
				float half_height = m_Height / 2.0f;

				float new_x = std::min(half_width, std::max(-half_width, new_position.x()));
				float new_y = std::min(half_height, std::max(-half_height, new_position.y()));

				vertex.SetPosition(new_x, new_y);

			}

			//{ reduce the temprature }
			if (t > 0.01f)
			{
				t = t * 0.90f;
			}
			else
			{
				t = 0.01f;
			}
		}		
	}

	FruchtermanReingoldVertex& FruchtermanReingold::GetVertexData(const std::string& vertex_name)	
	{
		auto result = std::find_if(std::begin(m_Vertex),std::end(m_Vertex), [&](const FruchtermanReingoldVertex& v){ return v.GetName() == vertex_name;});

		assert(result != std::end(m_Vertex));

		return *result; //de reference the pointer.
	}

	const std::vector<FruchtermanReingoldVertex>& FruchtermanReingold::GetVertex() const
	{
		return m_Vertex;
	}

	const std::vector<std::pair<std::string,std::string>>& FruchtermanReingold::GetEdge() const
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
			std::cout << vertex.GetName() << " - " << vertex.GetPosition().x() << "/"<< vertex.GetPosition().y() << "\n";
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