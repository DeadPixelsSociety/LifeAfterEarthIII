#ifndef VIEW_H
#define VIEW_H

#include <SFML/Graphics.hpp>

#include <client/ClientObject.h>

namespace lae3
{
    namespace client
    {
        class View : public ClientObject, public sf::View
        {
            public:
                explicit View(sf::Vector2u sizeWindow);
                virtual ~View();

                void updateMoveState(sf::Vector2i updateMoveState);

            protected:

            private:
                constexpr static unsigned int MOVE_TOP = 0x1;
                constexpr static unsigned int MOVE_LEFT = 0x2;
                constexpr static unsigned int MOVE_BOTTOM = 0x4;
                constexpr static unsigned int MOVE_RIGHT = 0x8;

                sf::Vector2u m_sizeWindow;
                unsigned int m_state;
        };
    }
}

#endif // VIEW_H
