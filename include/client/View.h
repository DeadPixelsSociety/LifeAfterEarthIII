#ifndef VIEW_H
#define VIEW_H

#include <SFML/Graphics.hpp>

namespace lae3
{
    namespace client
    {
        class View : public sf::View
        {
            public:
                explicit View(sf::Vector2u sizeWindow);
                virtual ~View();

            protected:

            private:
                sf::Vector2u m_sizeWindow;
        };
    }
}

#endif // VIEW_H
