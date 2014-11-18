#include "Map.h"
#include <cstdlib>
namespace client
{

  client::Map::Map()
  {
    init();
  }


  // initialize the map with 0
  void client::Map::init()
  {
    for(int i=0;i<HEIGHT;i++)
      {
	for(int j=0;j<WIDTH;j++)
	  {
	    m_tab[i][j] = 0;
	  }
      }
  }

 
  void client::Map::display()
  {
    for(int i=0;i<HEIGHT;i++)
      {
	for(int j=0;j<WIDTH;j++)
	  {
	    std::cout<<m_tab[i][j];
	  }
	std::cout<<std::endl;
      }
  }

  /// generate p percent of walls randomly in the map 
  void client::Map::generateWall(float p)
  {
    ///TODO: à migrer vers le serveur
    float random = (float)( ( rand() % 100 ) / 100.0);
    
    for(int i=0;i<HEIGHT;i++)
      {
	for(int j=0;j<WIDTH;j++)
	  {
	    random = (float)( ( rand() % 100 ) / 100.0);

	    if(p > random) 
	      {
		m_tab[i][j] = WALL;
	      }
	  }
      }

    
  }


  client::Map::~Map()
  {
  }
  
}
