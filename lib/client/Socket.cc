#include <SFML/Network.hpp>

#include <client/Socket.h>

/* explicit */ lae3::client::Socket::Socket() :
    m_pSocket(new sf::TcpSocket())
{
    //ctor
}

/* virtual */ lae3::client::Socket::~Socket()
{
    delete m_pSocket;
    m_pSocket = nullptr;
}

void lae3::client::Socket::connect(sf::IpAddress address)
{
    m_pSocket->connect(address, 4242);
}
