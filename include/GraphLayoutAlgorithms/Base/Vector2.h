#pragma once 
#include <cmath>
/*
    Simple Vector2 class.
*/

class Vector2
{    
public:
    Vector2(float x = 0.0f, float y = 0.0f)
    :m_x(x),m_y(y)
    {

    }
    
    ~Vector2() = default;

    void Set(float x, float y)
    {
        m_x = x;
        m_y = y;
    }

	void Set(const Vector2& other) 
	{
		m_x = other.m_x;
		m_y = other.m_y;
	}

    Vector2& operator=(const Vector2& other)
    {
        if (this == &other)
            return *this;
        m_x = other.m_x;
        m_y = other.m_y;
        return *this;
    }


    float Magnitude() const 
    {
        return std::sqrt(MagnitudeSquare());
    }

    float MagnitudeSquare() const 
    {
        return m_x * m_x + m_y * m_y;
    }

    float x() const 
    {
        return m_x;
    }
    float y() const 
    {
        return m_y;
    }

    friend bool operator==(const Vector2& lhs, const Vector2& rhs)
    {
        return lhs.m_x == rhs.m_x && lhs.m_y == rhs.m_y;
    }

	friend bool operator!=(const Vector2& lhs, const Vector2& rhs)
	{
        return !(lhs == rhs);
	}

    friend Vector2 operator-(const Vector2& lhs, const Vector2& rhs)
    {
        return Vector2(lhs.m_x - rhs.m_x, lhs.m_y - rhs.m_y);
    }

    friend Vector2 operator+(const Vector2& lhs, const Vector2& rhs)
    {
        return Vector2(lhs.m_x + rhs.m_x, lhs.m_y + rhs.m_y);
    }    

    Vector2& operator+=(const Vector2& rhs)
    {
        this->m_x += rhs.m_x;
        this->m_y += rhs.m_y;
        return *this;
    }

    friend Vector2 operator*(const Vector2& lhs, float rhs)  
    {
        return Vector2(lhs.m_x * rhs, lhs.m_y * rhs);
    }

    friend Vector2 operator*(float lhs,const Vector2& rhs)  
    {
        return Vector2(rhs.m_x * lhs, rhs.m_y * lhs);
    }

public:
    static Vector2 Normalize(const Vector2 vec)
    {
        float magnitude = vec.Magnitude();

        if (magnitude == 0.0f)
        {
            return Vector2();
        }        
                    
        return Vector2(vec.m_x/magnitude, vec.m_y/magnitude);                
    }

private:
    float m_x;
    float m_y;
};