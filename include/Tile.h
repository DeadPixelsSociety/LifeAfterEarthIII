#ifndef TILE_H
#define TILE_H
#include <iostream>
#include <SFML/Graphics.hpp>

#define TILE_WIDTH 32
#define TILE_HEIGHT 32

namespace client
{

  enum
  {
    GROUND,
    WALL
  };

  class Tile
  {
  public:
    Tile(int id,sf::Texture &t);
    ~Tile();
    void initType();
    void update();
    void display(sf::RenderWindow *w);

    void setID(int id){m_ID= id;initType();}
    int getID(){return m_ID;}
    void setPosition(int i,int j){m_x = j; m_y = i;}

  private:
    int m_x;
    int m_y;
    int m_width;
    int m_height;
    int m_ID;
    sf::Sprite *m_sprite;
  };


}
#endif
