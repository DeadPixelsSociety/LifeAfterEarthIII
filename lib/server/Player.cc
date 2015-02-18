#include <iostream>

#include <server/Player.h>

/* explicit */ lae3::server::Player::Player(std::string name, sf::IpAddress ip, unsigned short port) :
    m_name(name)
    , m_ip(ip)
    , m_port(port)
{
    //ctor
}

/* virtual */ lae3::server::Player::~Player()
{
    //dtor
}

std::string lae3::server::Player::getName() const
{
    return m_name;
}

sf::IpAddress lae3::server::Player::getIP() const
{
    return m_ip;
}

unsigned short lae3::server::Player::getPort() const
{
    return m_port;
}
