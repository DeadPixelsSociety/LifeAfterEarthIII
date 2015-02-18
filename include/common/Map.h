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

                enum TileType
                {
                    WALL,
                    GROUND,
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
