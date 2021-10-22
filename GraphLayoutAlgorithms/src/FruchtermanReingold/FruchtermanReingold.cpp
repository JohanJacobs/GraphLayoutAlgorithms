#include <iostream>
#include <iomanip>

#include <algorithm>
#include <cassert>

#include "FruchtermanReingold.h"
#include "base/Vector2.h"
#include "base/RandomValues.h"

namespace Layouts
{
	FruchtermanReingold::FruchtermanReingold(Graphs::IGraph& graph)
	:m_Width{3.0f}, m_Height{3.0f},m_Graph{graph}
	{

	}

	FruchtermanReingold::~FruchtermanReingold()
	{

	}

	void FruchtermanReingold::Step(uint32_t iterations)
	{		
		std::unordered_map<std::string, Vector2> displacement;

		float area = m_Width * m_Height;
		float k = std::sqrt(area / m_Graph.GetVertices().size());
		float t = 10.0f * m_Graph.GetVertices().size(); // temperature
		
		float half_width = m_Width / 2.0f;
		float half_height = m_Height / 2.0f;

		for (uint32_t iteration=0; iteration < iterations; iteration++)
		{
			//{ calculate repulsive forces }
			for (auto& vertex : m_Graph.GetVertices())
			{
				displacement[vertex.GetName()].Set(0.0f, 0.0f);
	
				for (auto& other_vertex : m_Graph.GetVertices())
				{
					if (other_vertex.GetName() == vertex.GetName())
						continue;
					
					// Vector between the two positions of the two vertices 
					auto distance_vector = vertex.GetPosition() - other_vertex.GetPosition();
					float distance_vector_magnitude = distance_vector.Magnitude();
					auto distance_normalized = Vector2::Normalize(distance_vector);

					//v.disp = v.disp + (delta / |delta|)*Fr(|delta|) { |delta| is magnitude of the vector }					

					float Fr = ((k*k) / ((distance_vector_magnitude == 0.0f)?1.0f:distance_vector_magnitude));

					auto new_displacement = displacement[vertex.GetName()] + distance_normalized * Fr;
					displacement[vertex.GetName()] = new_displacement; //displacement[vertex.GetName()].set(new_displacement);
				}
			}

			//{ calculate attractive forces }
			for ( const auto& [from_vertex_name, too_vertex_name] : m_Graph.GetEdges())
			{
				auto& from_vertex_data = GetVertexData(from_vertex_name);
				auto& too_vertex_data = GetVertexData(too_vertex_name);

				auto distance_vector = from_vertex_data.GetPosition() - too_vertex_data.GetPosition();
				auto distance_vector_magnitude = distance_vector.Magnitude();
				auto distnace_vector_normalized = Vector2::Normalize(distance_vector);

				auto fa = (distance_vector_magnitude * distance_vector_magnitude)/k;
				auto attractive_force = distnace_vector_normalized * fa;

				auto from_vertex_new_displacement = displacement[from_vertex_name] - attractive_force;
				displacement[from_vertex_name].Set(from_vertex_new_displacement.x(),from_vertex_new_displacement.y());

				auto too_vertex_new_displacement = displacement[too_vertex_name] + attractive_force;
				displacement[too_vertex_name].Set(too_vertex_new_displacement.x(),too_vertex_new_displacement.y());
			}

			//{ limit maximum displacement to the temprature t and prevent from being ouside the frame }
			for (auto& vertex : m_Graph.GetVertices())
			{
				auto displacement_normalized = Vector2::Normalize(displacement[vertex.GetName()]);
				float displacement_magnitude = displacement[vertex.GetName()].Magnitude();

				auto new_position = vertex.GetPosition() + (displacement_normalized * std::min(displacement_magnitude, t));
				
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

	void FruchtermanReingold::SetGraph(Graphs::IGraph& graph)
	{
		m_Graph = graph;
	}

	const FruchtermanReingoldVertex& FruchtermanReingold::GetVertexData(const std::string& vertex_name)
	{
		auto result = std::find_if(std::begin(m_Graph.GetVertices()),std::end(m_Graph.GetVertices()), [&](const FruchtermanReingoldVertex& v){ return v.GetName() == vertex_name;});

		assert(result != std::end(m_Graph.GetVertices()));

		return *result; //de-reference the pointer.
	}

}