#ifndef RANDOM_H
#define RANDOM_H

#include <random>

namespace lae3
{
    namespace common
    {
        class Random
        {
            public:
                Random();
                explicit Random(unsigned int seed);

                unsigned int getSeed() const;

                int computeUniformInteger(int min, int max);
                float computeUniformFloat(float min, float max);
                float computeNormalFloat(float mean, float stddev);
                bool computeBernoulli(float p);

            private:
                unsigned int m_seed;
                std::mt19937 m_engine;
        };
    }
}


#endif // RANDOM_H
