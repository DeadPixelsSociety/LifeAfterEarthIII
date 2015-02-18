#include <iostream>
#include <ctime>

#include <common/Random.h>


/* explicit */ lae3::common::Random::Random() :
    m_seed(std::time(nullptr))
    , m_engine(m_seed)
{
    //ctor
    std::cout << "seed = " << m_seed << std::endl;
}

lae3::common::Random::Random(unsigned int seed)
    : m_engine(seed)
{
    //ctor
}

unsigned int lae3::common::Random::getSeed() const
{
    return m_seed;
}

int lae3::common::Random::computeUniformInteger(int min, int max)
{
    std::uniform_int_distribution<int> dist(min, max);
    return dist(m_engine);
}

float lae3::common::Random::computeUniformFloat(float min, float max)
{
    std::uniform_real_distribution<float> dist(min, max);
    return dist(m_engine);
}

float lae3::common::Random::computeNormalFloat(float mean, float stddev)
{
    std::normal_distribution<float> dist(mean, stddev);
    return dist(m_engine);
}

bool lae3::common::Random::computeBernoulli(float p)
{
    std::bernoulli_distribution dist(p);
    return dist(m_engine);
}

