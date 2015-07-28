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
		  GROUND=0,
		  WALL=1,
		  WATER=2
                };

                Map(const lae3::common::Random &random);
		std::vector<std::pair<int, int>> neighbors(int i, int j);

		int get(int i, int j);
	        unsigned distance(int i1, int j1, int i2, int j2);
		
            protected:
                std::vector<TileType> m_tiles;
                lae3::common::Random m_random;

                void generate();
                void generateWall(float p);
                void generateWall();

		bool exists(int i, int j)
		{
		  return (i>=0 && i<MAP_HEIGHT && j>=00 && j<MAP_WIDTH);
		}

		

            private:
        };
    }
}

#endif // MAP_COMMON_H
