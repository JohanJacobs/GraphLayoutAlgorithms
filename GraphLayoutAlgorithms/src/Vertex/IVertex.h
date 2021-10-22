#pragma once
#include <string>
#include "Base/Vector2.h"
namespace Vertex
{
	class IVertex
	{
	public:
		virtual const Vector2& GetPosition() const = 0;
		virtual void SetPosition(float x, float y) = 0;

		virtual const std::string& GetName() const = 0;

		virtual ~IVertex()
		{	}
	};
}