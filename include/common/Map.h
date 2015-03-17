#ifndef MAP_COMMON_H
#define MAP_COMMON_H

#include <vector>

#include <common/Random.h>

namespace lae3
{
    namespace common
    {
        class Map
        {
            public:
                constexpr static int MAP_WIDTH = 50;
                constexpr static int MAP_HEIGHT = 50;
		constexpr static int WATER_LEVEL = 120;
		constexpr static int GROUND_LEVEL = 150;
		constexpr static int MOUNTAIN_LEVEL = 210;

                enum TileType
                {
                    WALL,
                    GROUND,
		    WATER
                };

                Map(const lae3::common::Random &random);

            protected:
                std::vector<TileType> m_tiles;
                lae3::common::Random m_random;

                void generate();
                void generateWall(float p);
                void generateWall();

            private:
        };
    }
}

#endif // MAP_COMMON_H
