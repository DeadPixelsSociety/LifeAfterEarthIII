#include <cmath>

#include <common/Perlin2D.h>
#include <common/Map.h>

lae3::common::Perlin2D::Perlin2D() :
    m_tab(Map::MAP_WIDTH * Map::MAP_HEIGHT)
{
    init();
    initValue();
    initInterpolations();
}

lae3::common::Perlin2D::~Perlin2D()
{
    //dtor
}

void lae3::common::Perlin2D::init()
{
    for(int i=0; i < Map::MAP_WIDTH; i++)
    {
        for(int j=0; j < Map::MAP_HEIGHT; j++)
        {
            m_tab[i + j * Map::MAP_WIDTH] = -1;
        }
    }
}

void lae3::common::Perlin2D::initValueCenterMountain()
{
    int a = Map::MAP_WIDTH / 10;
    for(int i=0; i < Map::MAP_WIDTH; i += OFFSET)
    {
        for(int j=0; j < Map::MAP_HEIGHT; j += OFFSET)
        {
            if(i > a && i < Map::MAP_WIDTH - a && j > a && j < Map::MAP_HEIGHT - a)
            {
                m_tab[i + j * Map::MAP_WIDTH] =  Perlin2D::random(GROUND-40,256);
            }
            else
            {
                m_tab[i + j * Map::MAP_WIDTH] = Perlin2D::random(50,100);
            }
        }
    }
}

void lae3::common::Perlin2D::initValueRandom()
{
    for(int i=0; i < Map::MAP_WIDTH; i += OFFSET)
    {
        for(int j=0; j < Map::MAP_HEIGHT; j += OFFSET)
        {
            m_tab[i + j * Map::MAP_WIDTH] = Perlin2D::random(0,256);
        }
    }
}

void lae3::common::Perlin2D::initValue()
{
    initValueCenterMountain();
}

double lae3::common::Perlin2D::get(int x, int y)const
{
    return m_tab[x + y * Map::MAP_WIDTH];
}

void lae3::common::Perlin2D::initInterpolations()
{
    int Ai = 0;
    int Aj = 0;

    int Bi, Bj, Ci, Cj, Di, Dj, Ei, Ej, Fi, Fj;

    double ratioEAB = 0.0;
    double ratioFDC = 0.0;
    double ratioMEF = 0.0;

    for (int i=0; i < Map::MAP_WIDTH; i++)
    {
        for (int j=0; j < Map::MAP_HEIGHT; j++)
        {
            if (i % OFFSET != 0 || j % OFFSET != 0)
            {
                if (m_tab[i + j * Map::MAP_WIDTH] == -1)
                {
                    Ai = OFFSET * (i / OFFSET);
                    Aj = OFFSET * (j / OFFSET);

                    Bi = Ai;
                    Bj = Aj + OFFSET;
                    Ci = Ai + OFFSET;
                    Cj = Aj + OFFSET;
                    Di = Ai + OFFSET;
                    Dj = Aj;

                    Ei = Ai;
                    Ej = j;

                    Fi = Di;
                    Fj = j;

                    ratioEAB = -1;
                    ratioFDC = -1;

                    if(inMap(Ei,Ej))
                    {
                        ratioEAB = static_cast<double>(Ej - Aj) / static_cast<double>(OFFSET);

                        m_tab[Ei + Ej * Map::MAP_WIDTH] = interpolation(m_tab[Ai + Aj * Map::MAP_WIDTH], m_tab[Bi + Bj * Map::MAP_WIDTH], ratioEAB);
                    }
                    if(inMap(Fi,Fj))
                    {
                        ratioFDC = static_cast<double>(Fj - Dj) / static_cast<double>(OFFSET);

                        m_tab[Fi + Fj * Map::MAP_WIDTH] = interpolation(m_tab[Di + Dj * Map::MAP_WIDTH], m_tab[Ci + Cj * Map::MAP_WIDTH], ratioFDC);
                    }

                    ratioMEF = static_cast<double>(i-Ei)/static_cast<double>(OFFSET);
                    if( inMap(Ei,Ej) && inMap(Fi,Fj) )
                    {
                        m_tab[i + j * Map::MAP_WIDTH] = interpolation(m_tab[Ei + Ej * Map::MAP_WIDTH], m_tab[Fi + Fj * Map::MAP_WIDTH], ratioMEF);
                    }
                }
            }
        }
    }
}

double lae3::common::Perlin2D::interpolation(double a,double b, double t)
{
    return polynomial_interpolation(a,b,t);
}

double lae3::common::Perlin2D::polynomial_interpolation(double a,double b, double t)
{
    double u = (1.0 - cos(t * M_PI)) * 0.5;

    return linear_interpolation(a, b, u);
}

double lae3::common::Perlin2D::linear_interpolation(double a,double b, double t)
{
    return a * (1.0 - t) + b * (t);
}

double lae3::common::Perlin2D::random(int a,int b)
{
    return static_cast<double>(rand() % (b - a) + a);
}

double lae3::common::Perlin2D::random()
{
    return static_cast<double>(Perlin2D::random(0, 1000)) / 1000.0;
}

void lae3::common::Perlin2D::display()
{
    for(int i=0; i < Map::MAP_WIDTH; i++)
    {
        for(int j=0; j < Map::MAP_HEIGHT; j++)
        {
            std::cout << m_tab[i + j * Map::MAP_WIDTH] << "   ";
        }
        std::cout << '\n';
    }
}
