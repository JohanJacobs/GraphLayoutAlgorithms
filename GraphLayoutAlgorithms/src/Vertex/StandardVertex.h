#pragma once 
#include "Vertex/IVertex.h"
#include "base/Vector2.h"

namespace Vertex
{
    /*
        the Fruchterman Reingold algorithm requires that each vertex has a position and a displacement. 
        This class contains both the Vertex and displacement data 
    */

    class StandardVertex:public Vertex::IVertex
    {
    public:
        StandardVertex(const std::string& name,const Vector2& position = Vector2(0.5f,0.5f))
        :m_Name{name},m_Pos(position)
        {

        }

        const Vector2& GetPosition() const override{return m_Pos;}
        
        void SetPosition(float x, float y) override
        {
            m_Pos.Set(x,y);
        }

        const std::string& GetName() const override {return m_Name;}
                
    private:
        std::string m_Name;
        Vector2 m_Pos;
    };
}