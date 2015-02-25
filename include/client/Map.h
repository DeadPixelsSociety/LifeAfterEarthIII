#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>

#include <common/Random.h>
#include <common/Map.h>
#include <client/ClientObject.h>

namespace lae3
{
    namespace client
    {
        class Map : public ClientObject, public lae3::common::Map
        {
            public:
                constexpr static int TILE_WIDTH = 12;
                constexpr static int TILE_HEIGHT = 12;

                Map(const lae3::common::Random &random, sf::Texture *texture = nullptr);
                virtual ~Map();

                virtual void render(sf::RenderWindow &window) const override;

            private:
                sf::Texture *m_texture;
                sf::VertexArray m_vertex;

                void generateVertexArray();
        };
    }
}

#endif // MAP_H
