#ifndef PROTOCOL_H
#define PROTOCOL_H

namespace lae3
{
    namespace common
    {
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
