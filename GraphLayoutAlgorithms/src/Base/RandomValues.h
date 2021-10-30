#include <random>
class RandomNumbers
{
    public:
        static float GetFloat(float median = 0.0f, float stdev = 0.0001f)
        {
            std::random_device rd{};
            std::mt19937 gen{rd()};
            std::normal_distribution<> d{ median, stdev };
            return float(d(gen));
        }
        static Vector2 GetVector2(float median = 0.0f, float stdev = 0.0001f)
        {
            return Vector2(GetFloat(median, stdev), GetFloat(median, stdev));
        }
    private:        
};