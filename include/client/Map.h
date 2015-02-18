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
                Map(const lae3::common::Random &random, sf::Texture *texture = nullptr);
                ~Map();

                virtual void render(sf::RenderWindow &window) const override;

            private:
                sf::Texture *m_texture;
        };
    }
}


#endif // MAP_H
