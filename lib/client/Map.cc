#include <iostream>
#include <cassert>

#include <client/Map.h>

lae3::client::Map::Map(const lae3::common::Random &random, sf::Texture *texture) :
    lae3::common::Map(random)
    , m_texture(texture)
{
    generate();
}

lae3::client::Map::~Map()
{
    //dtor
}

/* virtual */ void lae3::client::Map::render(sf::RenderWindow &window) const
{
    ///TODO Remove Tile matrix and add vertex
    for(int i=0; i < MAP_HEIGHT; i++)
    {
        for(int j=0; j < MAP_WIDTH; j++)
        {
            sf::RectangleShape rect({ 10.0f, 10.0f });
            rect.setPosition({ i * 10.0f, j * 10.0f });
            rect.setOutlineThickness(0.25f);
            rect.setOutlineColor(sf::Color::Black);

            switch (m_tiles[i + j * MAP_WIDTH])
            {
            case lae3::common::Map::GROUND:
                rect.setFillColor(sf::Color::Green);
                break;

            case lae3::common::Map::WALL:
                rect.setFillColor(sf::Color::Black);
                break;

            default:
                std::cerr << "Tile type invalid" << std::endl;
                assert(false);
            }

            window.draw(rect);
        }
    }
}
