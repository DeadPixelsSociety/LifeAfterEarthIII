#include <iostream>
#include <SFML/Network.hpp>

#include <server/Listener.h>

/* explicit */ lae3::server::Listener::Listener() :
    m_pListener(new sf::TcpListener())
{
    //ctor
}

/* virtual */ lae3::server::Listener::~Listener()
{
    delete m_pListener;
    m_pListener = nullptr;
}

void lae3::server::Listener::start()
{
    m_pListener->listen(4242);

    for(;;)
    {
        sf::TcpSocket client;
        if (m_pListener->accept(client) == sf::Socket::Done)
        {
            // A new client just connected!
            std::cout << "New connection received from " << client.getRemoteAddress() << std::endl;
        }
    }
}
