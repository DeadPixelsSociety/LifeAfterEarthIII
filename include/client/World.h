#ifndef WORLD_H
#define WORLD_H

#include <common/Protocol.h>
#include <common/Random.h>
#include <client/ClientObject.h>
#include <client/Map.h>

namespace lae3
{
    namespace client
    {
        class World : public ClientObject
        {
            public:
                explicit World(const lae3::common::Random &random, ResourceManager &resources);
                virtual ~World();

                virtual void render(sf::RenderWindow &window) const override;
                void update(lae3::common::UpdateData &data);

            protected:

            private:
                lae3::client::Map m_map;
        };
    }
}

#endif // WORLD_H
