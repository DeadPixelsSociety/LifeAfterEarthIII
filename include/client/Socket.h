#ifndef SOCKET_H
#define SOCKET_H

#include <client/ClientObject.h>
namespace sf
{
    class TcpSocket;
    class IpAddress;
}

namespace lae3
{
    namespace client
    {
        class Socket : public ClientObject
        {
            public:
                explicit Socket();
                virtual ~Socket();

                void connect(sf::IpAddress address);

            protected:

            private:
                sf::TcpSocket *m_pSocket;
        };
    }
}

#endif // SOCKET_H
