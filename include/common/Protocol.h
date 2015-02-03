#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <SFML/Network.hpp>

namespace lae3
{
    namespace common
    {
        enum class CodeCommande : sf::Int8
        {
            MOVE_UP,
            MOVE_DOWN,
            MOVE_LEFT,
            MOVE_RIGHT,
        };

        struct UpdateData
        {
            float x;
            float y;
        };

        sf::Packet& operator>>(sf::Packet& packet, CodeCommande& code)
        {
            sf::Int8 data;
            packet >> data;
            code = static_cast<CodeCommande>(data);
            return packet;
        }

        sf::Packet& operator<<(sf::Packet& packet, const CodeCommande& code)
        {
            return packet << static_cast<sf::Int8>(code);
        }

        sf::Packet& operator>>(sf::Packet& packet, UpdateData& data)
        {
            return packet >> data.x >> data.y;
        }

        sf::Packet& operator<<(sf::Packet& packet, const UpdateData& data)
        {
            return packet << data.x << data.y;
        }

        class Protocol
        {
            public:
                static bool registerPlayer(const std::string &name, const std::string &ip, const unsigned short &port, const sf::Uint16 &portUDP);
            protected:
            private:
        };
    }
}

#endif // PROTOCOL_H
