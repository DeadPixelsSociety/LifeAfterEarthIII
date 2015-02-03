#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <common/Protocol.h>

namespace lae3
{
    namespace server
    {
        class World
        {
            public:
                explicit World();
                virtual ~World();

                lae3::common::UpdateData getUpdateData() const;

                void update(lae3::common::CodeCommande codeCommande);

            protected:

            private:
                sf::Vector2f m_position;
        };
    }
}

#endif // WORLD_H
