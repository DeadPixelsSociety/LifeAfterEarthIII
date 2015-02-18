#ifndef PERLIN2D_H
#define PERLIN2D_H

#include <iostream>

#include <common/Map.h>

namespace lae3
{
    namespace common
    {
        class Perlin2D
        {
            public:
                enum AltThreshold : int
                {
                    DEEP_SEA = 10,
                    SEA = 50,
                    SAND = 70,
                    GROUND = 200,
                };

                constexpr static int OFFSET = 3;

                Perlin2D();
                virtual ~Perlin2D();

                void init();
                void initValue();
                void initValueRandom();
                void initValueCenterMountain();
                void initInterpolations();

                double linear_interpolation(double a, double b, double t);
                double polynomial_interpolation(double a, double b, double t);
                double interpolation(double a, double b, double t);

                void display();

                static double random(int a, int b);
                static double random();

                bool inMap(int i,int j)
                {
                    return (i >= 0 && i < Map::MAP_WIDTH && j >= 0 && j < Map::MAP_HEIGHT);
                }

                void operator()()
                {
                    display();
                }

                double get(int i, int j) const;

            private:
                std::vector<double> m_tab;
        };
    }
}

#endif // PERLIN2D_H
