#include <cstdlib>
#include <Map.h>
#include <Tile.h>
#include <Perlin2D.h>

client::Map::Map(sf::Texture &t):m_texture(t)
{
  init();
  generate();
}


// initialize the map with 0
void client::Map::init()
{
  for(int i=0;i<MAP_HEIGHT;i++)
    {
      for(int j=0;j<MAP_WIDTH;j++)
	{
	  m_tab[i][j] = new Tile(0,m_texture);
	  m_tab[i][j]->setPosition(j,i);
	}
    }
}

void client::Map::generate()
{

  Perlin2D p;
  int value;

  for(int i=0;i<MAP_HEIGHT;i++)
    {
      for(int j=0;j<MAP_WIDTH;j++)
	{
	  value = p.get(i,j);
	  
	  if(value < 200){ value = GROUND; }
	  else{ value = WALL;}
	  
	  m_tab[i][j]->setID(value);
	}
    }
}
void client::Map::update()
{
  for(int i=0;i<MAP_HEIGHT;i++)
    {
      for(int j=0;j<MAP_WIDTH;j++)
	{
	  m_tab[i][j]->update();
	}
    }
}
 
//display the map in the terminal
void client::Map::display()
{
  for(int i=0;i<MAP_HEIGHT;i++)
    {
      for(int j=0;j<MAP_WIDTH;j++)
	{
	  std::cout<<m_tab[i][j]->getID();
	}
      std::cout<<std::endl;
    }
}


//graphic display of the map
void client::Map::display(sf::RenderWindow *w)
{
  for(int i=0;i<MAP_HEIGHT;i++)
    {
      for(int j=0;j<MAP_WIDTH;j++)
	{
	  m_tab[i][j]->display(w);
	}
    }
}

/// generate p percent of walls randomly in the map 
void client::Map::generateWall(float p)
{
  ///TODO: à migrer vers le serveur
  float random = (float)( ( rand() % 100 ) / 100.0);
    
  for(int i=0;i<MAP_HEIGHT;i++)
    {
      for(int j=0;j<MAP_WIDTH;j++)
	{
	  random = (float)( ( rand() % 100 ) / 100.0);

	  if(p > random) 
	    {
	      m_tab[i][j]->setID(WALL);
	    }
	}
    }

    
}


//generate a square of walls around the map
void client::Map::generateWall()
{

  for(int i=0;i<MAP_HEIGHT;i++)
    {
      for(int j=0;j<MAP_WIDTH;j++)
	{
	  if(i == 0 || i == MAP_HEIGHT-1 || j == 0 || j == MAP_WIDTH -1)
	    {
	      m_tab[i][j]->setID(WALL);
	    }
	}
    }
}


client::Map::~Map()
{
  //desalloc Tiles
  for(int i=0;i<MAP_HEIGHT;i++)
    {
      for(int j=0;j<MAP_WIDTH;j++)
	{

	  delete m_tab[i][j];
	      
	}
    }



  
}
