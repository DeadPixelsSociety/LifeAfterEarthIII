#ifndef CLIENTOBJECT_H
#define CLIENTOBJECT_H

namespace sf
{
    class RenderWindow;
}

namespace lae3
{
    namespace client
    {
        class ClientObject
        {
            public:
                explicit ClientObject();
                virtual ~ClientObject();

                virtual void render(sf::RenderWindow &window) const;
                virtual void update(const float dt);

            protected:

            private:
        };
    }
}

#endif // CLIENTOBJECT_H
