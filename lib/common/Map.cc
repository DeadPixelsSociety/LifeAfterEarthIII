#include <common/Map.h>
#include <common/Perlin2D.h>
#include <common/Pathfinding.h>
#include <cmath>
#include <cassert>

lae3::common::Map::Map(const lae3::common::Random &random) :
    m_tiles(MAP_WIDTH * MAP_HEIGHT)
    , m_random(random)
{
    //ctor
}

void lae3::common::Map::generate()
{
  bool generation_ok = false;

  // unless we don't get a valid generation
  // we generate it again and again
  while( !generation_ok )
    {
      Perlin2D p;
      int alt;
      TileType type;
  
      int base1_i = 10; 
      int base1_j = 10;

      int base2_i = 40;
      int base2_j = 40;
    
      const int RADIUS = 7;
  
      // Generate relief
      for(int i=0;i<MAP_HEIGHT;i++)
	{
	  for(int j=0;j<MAP_WIDTH;j++)
	    {
	      //placing base
	      if( abs(base1_i - i) + abs(base1_j - j) < RADIUS
		  || abs(base2_i - i) + abs(base2_j - j) < RADIUS)
		{
		  type = WATER;
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
  
      // check if all is ok
      lae3::common::Pathfinding path(*this);
      generation_ok = path.compute(base1_i, base1_j, base2_i, base2_j);
      
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

int lae3::common::Map::get(int i, int j)
{
  assert(exists(i, j));
  return m_tiles[i + j * MAP_WIDTH];
}

// get the manhathan distance between (i1, j1) and (i2, j2)
unsigned lae3::common::Map::distance(int i1, int j1, int i2, int j2)
{
  assert(exists(i1, j1));
  assert(exists(i2, j2));
  
  return abs(i1-i2) + abs(j1-j2);
}

std::vector< std::pair<int, int> > lae3::common::Map::neighbors(int i, int j)
{
  std::vector< std::pair<int, int> > res;

  if( exists(i+1, j) ){ res.push_back( std::make_pair(i+1, j) ); }
  if( exists(i-1, j) ){ res.push_back( std::make_pair(i-1, j) ); }
  if( exists(i, j+1) ){ res.push_back( std::make_pair(i, j+1) ); }
  if( exists(i, j-1) ){ res.push_back( std::make_pair(i, j-1) ); }
  
  return res;
}
