#include <iostream>
#include <SFML/Network.hpp>

#include <server/Listener.h>

/* explicit */ lae3::server::Listener::Listener() :
    m_MAX_CLIENTS(2)
    , m_pListener(new sf::TcpListener())
    , m_pSocketSelector(new sf::SocketSelector())
{
    m_pListener->listen(4242);

    m_pSocketSelector->add(*m_pListener);
}

/* virtual */ lae3::server::Listener::~Listener()
{
    // Free all sockets
    for (std::list<sf::TcpSocket*>::iterator it = m_clients.begin(); it != m_clients.end(); ++it)
    {
        sf::TcpSocket *client = *it;
        delete client;
        client = nullptr;
    }

    delete m_pListener;
    m_pListener = nullptr;

    delete m_pSocketSelector;
    m_pSocketSelector = nullptr;
}

void lae3::server::Listener::start()
{
    while(m_clients.size() < m_MAX_CLIENTS)
    {
        // Waiting new data form socket
        if (m_pSocketSelector->wait())
        {
            // If the listener has a new connexion
            if (m_pSocketSelector->isReady(*m_pListener))
            {
                sf::TcpSocket *client = new sf::TcpSocket();
                if (m_pListener->accept(*client) == sf::Socket::Done)
                {
                    // A new client just connected!
                    std::cout << "Socket #" << m_clients.size()+1 << " was created" << std::endl;

                    // Add to list of client the new client
                    m_clients.push_back(client);

                    // Add to socket selector the new client
                    m_pSocketSelector->add(*client);
                }
                else
                {
                    // Error, we won't get a new connection, delete the socket
                    delete client;
                    client = nullptr;
                }
            }
        }
    }
}
