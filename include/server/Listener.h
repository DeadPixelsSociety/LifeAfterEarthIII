#ifndef LISTENER_H
#define LISTENER_H

#include <netdb.h>
#include <sys/socket.h>

#include <server/ServerObject.h>

namespace sf
{
    class TcpListener;
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

                void start();

            protected:

            private:
                sf::TcpListener *m_pListener;
        };
    }
}

#endif // LISTENER_H
