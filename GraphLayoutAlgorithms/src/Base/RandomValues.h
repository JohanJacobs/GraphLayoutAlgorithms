#include <random>
class RandomNumbers
{
    public:
        static float GetFloat()
        {
            std::random_device rd{};
            std::mt19937 gen{rd()};
            std::normal_distribution<> d{0.5f,0.1f};
            return float(d(gen));
        }
    private:        
};