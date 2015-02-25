#ifndef LISTENER_H
#define LISTENER_H

#include <vector>

#include <server/ServerObject.h>
#include <server/Player.h>

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

                std::vector<Player> getPlayers() const;

                virtual void start(const sf::Int32 seed);

            protected:

            private:
                const unsigned int m_MAX_CLIENTS;
                bool m_continue;
                std::vector<sf::TcpSocket*> m_clients;
                std::vector<Player> m_players;

                sf::TcpListener *m_pListener;
                sf::SocketSelector *m_pSocketSelector;
        };
    }
}

#endif // LISTENER_H
