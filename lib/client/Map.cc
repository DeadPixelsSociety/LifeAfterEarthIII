#include <iostream>
#include <cassert>

#include <client/Map.h>

lae3::client::Map::Map(const lae3::common::Random &random, ResourceManager &resources) :
    lae3::common::Map(random)
    , m_vertex(sf::Quads, lae3::common::Map::MAP_WIDTH * lae3::common::Map::MAP_HEIGHT * 4)
{
    // Load the tileset
    m_texture = resources.getTexture("ground_tileset.png");

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
    window.draw(m_vertex, m_texture);
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

            // Set texture
            float u = 0.0f;
            float v = 0.0f;

            switch (type)
            {
            case lae3::common::Map::GROUND:
                /// TODO redo the tileset
                u = 64.0f;
                v = 0.0f;

                quad[0].texCoords = { u, v };
                quad[1].texCoords = { u, v + 64.0f };
                quad[2].texCoords = { u + 64.0f, v + 64.0f };
                quad[3].texCoords = { u + 64.0f, v };
                break;

            case lae3::common::Map::WALL:
                /// TODO redo the tileset
                u = 0.0f;
                v = 64.0f;

                quad[0].texCoords = { u, v };
                quad[1].texCoords = { u, v + 64.0f };
                quad[2].texCoords = { u + 64.0f, v + 64.0f };
                quad[3].texCoords = { u + 64.0f, v };
                break;
		
	    case lae3::common::Map::WATER:
	      quad[0].color = sf::Color::Blue;
	      quad[1].color = sf::Color::Blue;
	      quad[2].color = sf::Color::Blue;
	      quad[3].color = sf::Color::Blue;
	      break;
	      
            default:
                std::cerr << "Tile type invalid" << std::endl;
                assert(false);
            }
        }
    }
}
