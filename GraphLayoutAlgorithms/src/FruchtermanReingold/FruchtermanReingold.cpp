#include <iostream>
#include <iomanip>

#include <algorithm>
#include <cassert>

#include "FruchtermanReingold.h"
#include "base/Vector2.h"
#include "base/RandomValues.h"

namespace Layouts
{
	FruchtermanReingold::FruchtermanReingold(std::shared_ptr<Graphs::IGraph> graph)
	:m_Width{1.0f}, m_Height{1.0f},m_Graph{graph}
	{

	}

	FruchtermanReingold::~FruchtermanReingold()
	{

	}

	void FruchtermanReingold::Step(uint32_t iterations)
	{		
		m_Displacement.clear();

		FructermanReingoldProperties p(
			m_Graph->VertexCount(),
			m_Width * m_Height,
			(10.0f * m_Graph->VertexCount()),
			m_Width / 2.0f,
			m_Height / 2.0f,
			std::sqrt( (m_Width * m_Height)/ m_Graph->VertexCount())	
		);

		for (uint32_t iteration=0; iteration < iterations; iteration++)
		{
						
			CalculateRepulsiveForces(p.k);
						
			CalculateAttractiveForces(p.k);
						
			ConstrainDisplacement(p.t);

			p.t = UpdateTemprature(p.t);

		}		
	}

	const std::shared_ptr<Vertex::IVertex>& FruchtermanReingold::GetVertexData(const std::string& vertex_name)
	{
		auto result = std::find_if(std::begin(m_Graph->GetVertices()),std::end(m_Graph->GetVertices()), [&](const std::shared_ptr<Vertex::IVertex>& v){ return v->GetName() == vertex_name;});

		assert(result != std::end(m_Graph->GetVertices()));

		return *result; //de-reference the pointer.
	}

	void FruchtermanReingold::CalculateRepulsiveForces( float k)
	{
		for (auto& vertex : m_Graph->GetVertices())
		{
			m_Displacement[vertex->GetName()].Set(0.0f, 0.0f);

			for (auto& other_vertex : m_Graph->GetVertices())
			{
				if (other_vertex->GetName() == vertex->GetName())
					continue;


				Vector2 from_vertex_position = vertex->GetPosition();
				Vector2 too_vertex_position = other_vertex->GetPosition();

				// special case, 2 vertices have the same position, perturb the vector with a small amount to push vertices away from each other
				if (from_vertex_position == too_vertex_position)
				{
					Vector2 small_random_vector = RandomNumbers::GetVector2();
					from_vertex_position += small_random_vector;
				}

				auto distance_vector = from_vertex_position - too_vertex_position;
				float distance_vector_magnitude = distance_vector.Magnitude();

				auto distance_normalized = Vector2::Normalize(distance_vector);

				float Fr = ((k * k) / ((distance_vector_magnitude == 0.0f) ? 1.0f : distance_vector_magnitude));

				auto new_displacement = m_Displacement[vertex->GetName()] + (distance_normalized * Fr);
				m_Displacement[vertex->GetName()] = new_displacement;
			}
		}
	}

	void FruchtermanReingold::CalculateAttractiveForces(float k)
	{
		for (const auto& [from_vertex_name, too_vertex_name] : m_Graph->GetEdges())
		{
			auto& from_vertex_data = GetVertexData(from_vertex_name);
			auto& too_vertex_data = GetVertexData(too_vertex_name);

			auto distance_vector = from_vertex_data->GetPosition() - too_vertex_data->GetPosition();
			auto distance_vector_magnitude = distance_vector.Magnitude();
			auto distnace_vector_normalized = Vector2::Normalize(distance_vector);

			auto fa = (distance_vector_magnitude * distance_vector_magnitude) / k;
			auto attractive_force = distnace_vector_normalized * fa;

			auto from_vertex_new_displacement = m_Displacement[from_vertex_name] - attractive_force;
			m_Displacement[from_vertex_name] = from_vertex_new_displacement;

			auto too_vertex_new_displacement = m_Displacement[too_vertex_name] + attractive_force;
			m_Displacement[too_vertex_name] = too_vertex_new_displacement;
		}
	}

	void FruchtermanReingold::ConstrainDisplacement(float t)
	{
		float half_width = m_Width / 2.0f;
		float half_height= m_Height/ 2.0f;

		for (auto& vertex : m_Graph->GetVertices())
		{
			auto displacement_normalized = Vector2::Normalize(m_Displacement[vertex->GetName()]);
			float displacement_magnitude = m_Displacement[vertex->GetName()].Magnitude();

			auto new_position = vertex->GetPosition() + (displacement_normalized * std::min(displacement_magnitude, t));

			float new_x = std::min(half_width, std::max(-half_width, new_position.x()));
			float new_y = std::min(half_height, std::max(-half_height, new_position.y()));

			vertex->SetPosition(new_x, new_y);
		}
	}

	float FruchtermanReingold::UpdateTemprature(float t)
	{
		//reduce the temperature
		if (t > 0.01f)
		{
			t = t * 0.90f;
		}
		else
		{
			t = 0.01f;
		}

		return t;
	}

}