#include "Tile.h"

namespace client
{
  client::Tile::Tile(int id,sf::Texture &t): m_ID(id),m_width(TILE_WIDTH),m_height(TILE_HEIGHT)
  {
    m_sprite = new sf::Sprite();
    m_sprite->setTexture(t);
    
    initType();
  }

  void client::Tile::initType()
  {
    switch(m_ID)
      {
      case GROUND:
	m_sprite->setTextureRect(sf::IntRect(0,0,m_width,m_height));
	break;
      case WALL:
	m_sprite->setTextureRect(sf::IntRect(m_width,0,m_width,m_height));
	break;
      }

  }

  void client::Tile::update()
  {
    m_sprite->setPosition(m_x * m_width, m_y * m_height);
  }

  void client::Tile::display(sf::RenderWindow* w)
  {
    w->draw(*m_sprite);
  }

  client::Tile::~Tile()
  {
    delete m_sprite;
  }
}
