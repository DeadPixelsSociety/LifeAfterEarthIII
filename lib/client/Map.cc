#include <iostream>
#include <cassert>

#include <client/Map.h>

lae3::client::Map::Map(const lae3::common::Random &random, sf::Texture *texture) :
    lae3::common::Map(random)
    , m_texture(texture)
    , m_vertex(sf::Quads, lae3::common::Map::MAP_WIDTH * lae3::common::Map::MAP_HEIGHT * 4)
{
    // Generate the level
    generate();

    // Generate the vertex array
    generateVertexArray();
}

/* virtual */ lae3::client::Map::~Map()
{
    //dtor
}

/* virtual */ void lae3::client::Map::render(sf::RenderWindow &window) const
{
    window.draw(m_vertex);
}

void lae3::client::Map::generateVertexArray()
{
    for(int i=0; i < MAP_HEIGHT; i++)
    {
        for(int j=0; j < MAP_WIDTH; j++)
        {
            // Get type of tile
            TileType type = m_tiles[i + j * MAP_WIDTH];

            // Get the vertex
            sf::Vertex* quad = &m_vertex[(i + j * MAP_WIDTH) * 4];

            // Set posisition of vertex
            quad[0].position = sf::Vector2f(i * TILE_WIDTH, j * TILE_HEIGHT);
            quad[1].position = sf::Vector2f((i + 1) * TILE_WIDTH, j * TILE_HEIGHT);
            quad[2].position = sf::Vector2f((i + 1) * TILE_WIDTH, (j + 1) * TILE_HEIGHT);
            quad[3].position = sf::Vector2f(i * TILE_WIDTH, (j + 1) * TILE_HEIGHT);

            // Set color
            /// TODO add texture
            switch (type)
            {
            case lae3::common::Map::GROUND:
                quad[0].color = sf::Color::Green;
                quad[1].color = sf::Color::Green;
                quad[2].color = sf::Color::Green;
                quad[3].color = sf::Color::Green;
                break;

            case lae3::common::Map::WALL:
                quad[0].color = sf::Color::Black;
                quad[1].color = sf::Color::Black;
                quad[2].color = sf::Color::Black;
                quad[3].color = sf::Color::Black;
                break;

            default:
                std::cerr << "Tile type invalid" << std::endl;
                assert(false);
            }
        }
    }
}
