#pragma once 
#include <string>

#include "base/Vector2.h"

namespace Layouts
{
    /*
        the Fruchterman Reingold algorithm requires that each vertex has a position and a distplacement. 
        This class contains both the Vertex and displacement data 
    */

    class FruchtermanReingoldVertex
    {
    public:
        FruchtermanReingoldVertex(const std::string& name,const Vector2& position = Vector2(0.5f,0.5f))
        :m_Name{name},m_Pos(position)
        {

        }

        const Vector2& GetPosition() const {return m_Pos;}
        
        void SetPosition(float x, float y)
        {
            m_Pos.Set(x,y);
        }

        const std::string& GetName() const {return m_Name;}
                
    private:
        std::string m_Name;
        Vector2 m_Pos;
    };
}