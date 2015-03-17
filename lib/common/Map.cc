#include <common/Map.h>
#include <common/Perlin2D.h>
#include <cmath>

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
  
  int base_1i = 10;
  int base_1j = 10;

  int base_2i = 40;
  int base_2j = 40;
    
  const int RADIUS = 10;
  
  // Generate relief
  for(int i=0;i<MAP_HEIGHT;i++)
    {
      for(int j=0;j<MAP_WIDTH;j++)
        {
	  //placing base
	  if( abs(base_1i - i) + abs(base_1j - j) < RADIUS
	      || abs(base_2i - i) + abs(base_2j - j) < RADIUS)
	    {
	      type = GROUND;
	    }
	  //using perlin noise
	    else
	    {
	      alt = p.get(i,j);
	    
	      if(alt < WATER_LEVEL)
		{
		  type = WATER;
		}
	      else if(alt > GROUND_LEVEL && alt < MOUNTAIN_LEVEL)
		{
		  type = GROUND;
		}
	      else
		{
		  type = WALL;
		}
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
