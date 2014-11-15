#include <server/Player.h>

/* explicit */ lae3::server::Player::Player(std::string name, unsigned short port) :
    m_name(name)
    , m_port(port)
{
    //ctor
}

/* virtual */ lae3::server::Player::~Player()
{
    //dtor
}

void lae3::server::Player::setName(const std::string &name)
{
    m_name = name;
}

void lae3::server::Player::setPort(const unsigned short port)
{
    m_port = port;
}

std::string lae3::server::Player::getName() const
{
    return m_name;
}

unsigned short lae3::server::Player::getPort() const
{
    return m_port;
}
