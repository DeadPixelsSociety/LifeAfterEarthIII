#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <SFML/Network.hpp>

#include <server/ServerObject.h>

namespace lae3
{
    namespace server
    {
        class Player : public ServerObject
        {
            public:
                explicit Player(std::string name, sf::IpAddress ip, unsigned short port);
                virtual ~Player();

                std::string getName() const;
                sf::IpAddress getIP() const;
                unsigned short getPort() const;

            protected:

            private:
                std::string m_name;
                sf::IpAddress m_ip;
                unsigned short m_port;
        };
    }
}

#endif // PLAYER_H
