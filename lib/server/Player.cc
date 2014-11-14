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
