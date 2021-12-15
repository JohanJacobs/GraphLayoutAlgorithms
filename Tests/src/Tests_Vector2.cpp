#include "gtest/gtest.h"
#include "GraphLayoutAlgorithms/Base/Vector2.h"
Vector2 CreateVectorTest(float x, float y)
{
	Vector2 g(x, y);
	return g;
}

Vector2 SetMethod(float a,float b)
{
	Vector2 g;
	g.Set(a, b);
	return g;
}

bool TestAssignment(float a, float b,float c, float d)
{
	Vector2 g(a, b);
	Vector2 h(c,d);
	return h == g;
}

float GetMagnitude(float a, float b)
{
	Vector2 g(a, b);
	return g.Magnitude();
}

TEST(Vector2, ConstructorTest)
{
	EXPECT_EQ(1, CreateVectorTest(1, 2).x());
	EXPECT_EQ(2, CreateVectorTest(1, 2).y());
}

TEST(Vector2, SetMethodTest)
{
	EXPECT_EQ(1, SetMethod(1, 2).x());
	EXPECT_EQ(2, SetMethod(1, 2).y());
}

TEST(Vector2, MagnitudeTest)
{
	EXPECT_EQ(5, GetMagnitude(4, 3));
}

TEST(Vector2, MagnitudeTestReverse)
{
	EXPECT_EQ(5, GetMagnitude(3, 4));
}

TEST(Vector2, operator_equal_true)
{
	EXPECT_EQ(true, TestAssignment(1, 2,1,2));
}

TEST(Vector2, operator_equal_false)
{
	EXPECT_EQ(false, TestAssignment(1, 2,2,2));
}

TEST(Vector2, Normalise)
{
	EXPECT_FLOAT_EQ(1.0f, Vector2::Normalize(Vector2(4, 4)).Magnitude());
}