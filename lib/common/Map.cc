#include <common/Map.h>
#include <common/Perlin2D.h>

lae3::common::Map::Map(const lae3::common::Random &random) :
    m_tiles(MAP_WIDTH * MAP_HEIGHT)
    , m_random(random)
{
    //ctor
}

void lae3::common::Map::generate()
{
    Perlin2D p;
    int alt;
    TileType type;

    // Generate relief
    for(int i=0;i<MAP_HEIGHT;i++)
    {
        for(int j=0;j<MAP_WIDTH;j++)
        {
            alt = p.get(i,j);

            ///TODO Set to define and set value to water
            if(alt < 200)
            {
                type = GROUND;
            }
            else
            {
                type = WALL;
            }

            m_tiles[i + j * MAP_WIDTH] = type;
        }
    }
}

void lae3::common::Map::generateWall(float percent)
{
    float randNum = 0.0f;

    for(int i=0;i<MAP_HEIGHT;i++)
    {
        for(int j=0;j<MAP_WIDTH;j++)
        {
            randNum = m_random.computeUniformFloat(0.0f, 1.0f);

            if(percent > randNum)
            {
                m_tiles[i + j * MAP_WIDTH] = WALL;
            }
        }
    }
}


//generate a square of walls around the map
void lae3::common::Map::generateWall()
{
    for(int i=0;i<MAP_HEIGHT;i++)
    {
        for(int j=0;j<MAP_WIDTH;j++)
        {
            if(i == 0 || i == MAP_HEIGHT-1 || j == 0 || j == MAP_WIDTH -1)
            {
                m_tiles[i + j * MAP_WIDTH] = WALL;
            }
        }
    }
}
