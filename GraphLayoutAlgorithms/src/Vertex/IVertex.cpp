#include "IVertex.h"
#include "StandardVertex.h"
#include <stdexcept>

namespace Vertex
{	
	std::shared_ptr<Vertex::IVertex> IVertex::CreateVertex(VertexType vertex_type, const std::string& vertex_name, const Vector2& position /*= Vector2(0.0f, 0.0f)*/)
	{
		switch (vertex_type)
		{
		case VertexType::StandardVertex:
				return std::make_shared<Vertex::StandardVertex>(vertex_name, position);
				break;
		}
		throw std::logic_error("The method or operation is not implemented.");
	}

}