#ifndef LISTENER_H
#define LISTENER_H

#include <list>

#include <server/ServerObject.h>

namespace sf
{
    class TcpListener;
    class TcpSocket;
    class SocketSelector;
}

namespace lae3
{
    namespace server
    {
        class Listener : public ServerObject
        {
            public:
                explicit Listener();
                virtual ~Listener();

                virtual void start();

            protected:

            private:
                const unsigned int m_MAX_CLIENTS;
                std::list<sf::TcpSocket*> m_clients;

                sf::TcpListener *m_pListener;
                sf::SocketSelector *m_pSocketSelector;
        };
    }
}

#endif // LISTENER_H
