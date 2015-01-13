#include <common/UdpPacket.h>

/* explicit */ lae3::common::UdpPacket::UdpPacket(const sf::Packet packet, const sf::IpAddress &ipDestionation, const unsigned short &portDestination) :
    m_packet(packet)
    , m_ipDestination(ipDestionation)
    , m_portDestionation(portDestination)
{
    //ctor
}

/* virtual */ lae3::common::UdpPacket::~UdpPacket()
{
    //dtor
}

sf::Packet lae3::common::UdpPacket::getPacket() const
{
    return m_packet;
}

sf::IpAddress lae3::common::UdpPacket::getIPDestination() const
{
    return m_ipDestination;
}

unsigned short lae3::common::UdpPacket::getPortDestination() const
{
    return m_portDestionation;
}
