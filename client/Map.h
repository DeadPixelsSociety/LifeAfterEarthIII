#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tile.h"
#define MAP_WIDTH 10
#define MAP_HEIGHT 10
namespace client
{
  enum
  {
    GROUND,
    WALL
  };


  class Tile;
  class Map
  {
    
  public:
    Map(sf::Texture &t);
    ~Map();
    
    void init();
    int getTab(int i ,int j){return m_tab[i][j]->getID();}
    int setTab(int n,int i,int j){m_tab[i][j]->setID(n);}

    void update();
    void display();
    void display(sf::RenderWindow *w);
    
    void generateWall(float p);
    void generateWall();
    
        
  private:
    
    Tile* m_tab[MAP_HEIGHT][MAP_WIDTH];
    sf::Texture m_texture;
    
  protected:
  };
  
}
  




#endif
