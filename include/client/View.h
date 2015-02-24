#ifndef VIEW_H
#define VIEW_H

#include <SFML/Graphics.hpp>

namespace lae3
{
    namespace client
    {
        class View
        {
            public:
                constexpr static float VIEW_WIDTH = 500.0f;
                constexpr static float VIEW_HEIGHT = 500.0f;

                View();
                virtual ~View();

                static sf::FloatRect computeViewport(unsigned width, unsigned height);

            protected:

            private:
        };
    }
}

#endif // VIEW_H
