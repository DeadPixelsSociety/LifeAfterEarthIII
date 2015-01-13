#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <SFML/Graphics.hpp>

#define MAP_WIDTH 50
#define MAP_HEIGHT MAP_WIDTH

enum
  {
    GROUND,
    WALL
  };

namespace client
{

  class Tile;

  class Map
  {
  public:
    Map(sf::Texture &t);
    ~Map();
    
    void update();
    void display(sf::RenderWindow *w);
    void display();
    void init();
    
    void generate();
    void generateWall(float p);
    void generateWall();

  private:
    Tile* m_tab[MAP_HEIGHT][MAP_WIDTH];
    sf::Texture m_texture;
  };

}
#endif
