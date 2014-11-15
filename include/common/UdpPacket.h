#ifndef UDPPACKET_H
#define UDPPACKET_H

#include <SFML/Network.hpp>

namespace lae3
{
    namespace common
    {
        class UdpPacket : public sf::Packet
        {
            public:
                explicit UdpPacket(const sf::Packet packet, const sf::IpAddress &ipDestionation, const unsigned short &portDestination);
                virtual ~UdpPacket();

                sf::Packet getPacket() const;
                sf::IpAddress getIPDestination() const;
                unsigned short getPortDestination() const;

            protected:

            private:
                sf::Packet m_packet;
                sf::IpAddress m_ipDestination;
                unsigned short m_portDestionation;
        };
    }
}

#endif // UDPPACKET_H
