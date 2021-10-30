#include "IVertex.h"
#include "StandardVertex.h"

namespace Vertex
{	
	std::shared_ptr<Vertex::IVertex> IVertex::CreateVertex( const std::string& vertex_name, const Vector2& position /*= Vector2(0.0f, 0.0f)*/)
	{
		return std::make_shared<Vertex::StandardVertex>(vertex_name, position);		
	}
}