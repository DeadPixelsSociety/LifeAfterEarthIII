#ifndef WORLD_H
#define WORLD_H

#include <common/Protocol.h>
#include <client/ClientObject.h>

namespace lae3
{
    namespace client
    {
        class World : public ClientObject
        {
            public:
                explicit World();
                virtual ~World();

                virtual void render(sf::RenderWindow &window) const override;
                void update(lae3::common::UpdateData &data);

            protected:

            private:
                // For test
                sf::Vector2f m_position;
        };
    }
}

#endif // WORLD_H
