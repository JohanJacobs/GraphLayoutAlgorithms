#pragma once
#include <string>
#include <memory>

#include "Base/Vector2.h"
namespace Vertex
{
	class IVertex
	{
	public:
		std::shared_ptr<Vertex::IVertex> static CreateVertex(const std::string& vertex_name = "vertex", const Vector2& position = Vector2(0.0f, 0.0f));

	public:
		virtual const Vector2& GetPosition() const = 0;
		virtual void SetPosition(float x, float y) = 0;

		virtual const std::string& GetName() const = 0;

		virtual ~IVertex()
		{	}
	};
}