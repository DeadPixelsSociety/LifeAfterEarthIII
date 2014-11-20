#ifndef TILE_H
#define TILE_H
#define TILE_WIDTH 32
#define TILE_HEIGHT 32
#include <iostream>
#include <SFML/Graphics.hpp>
enum
  {
    GROUND,
    WALL
  };

namespace client
{
  class Tile
  {
  public:
    Tile(int id,sf::Texture &t);

    void setID(int n){m_ID = n;initType();}
    int getID(){return m_ID;}

    void display(sf::RenderWindow* w);
    void update();

    void initType();

    void setPosition(int x,int y){m_x = x;m_y=y;}
    ~Tile();
  private:
    
  protected:
    int m_ID;
    const int m_width;
    const int m_height;
    int m_x;
    int m_y;
    sf::Sprite* m_sprite;
    
  };
}

#endif
