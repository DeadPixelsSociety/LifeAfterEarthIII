#include <iostream>
#include <SFML/Network.hpp>

#include <server/Listener.h>

/* explicit */ lae3::server::Listener::Listener() :
    m_MAX_CLIENTS(2)
    , m_continue(true)
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
    while(m_continue)
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
            else
            {
                // The listener socket is not ready, test all other sockets (the clients)
                for (std::list<sf::TcpSocket*>::iterator it = m_clients.begin(); it != m_clients.end(); ++it)
                {
                    sf::TcpSocket& client = **it;
                    if (m_pSocketSelector->isReady(client))
                    {
                        // The client has sent some data, we can receive it
                        sf::Packet packet;
                        sf::Socket::Status status= client.receive(packet);
                        if (status == sf::Socket::Done)
                        {
                            std::string name;
                            packet >> name;

                            std::cout << "Player #" << m_clients.size() << ": " << name << std::endl;

                            // Send the port fort listen
                            packet.clear();
                            sf::Uint16 port = 4242 + m_clients.size();
                            packet << port;
                            if (client.send(packet) != sf::Socket::Done)
                            {
                                std::cerr << "Error during send packet" << std::endl;
                            }

                            // Check if it's the last player
                            if (m_MAX_CLIENTS == m_clients.size())
                            {
                                m_continue = false;
                            }
                        }
                        else if (status == sf::Socket::Disconnected)
                        {
                            // Remove client of differents lists
                            std::cout << "Client disconnected" << std::endl;
                            m_pSocketSelector->remove(client);
                            m_clients.remove(&client);
                            std::cout << "number of clients : " << m_clients.size() << std::endl;
                            break;
                        }
                        else
                        {
                            std::cerr << "Error during receive packet." << std::endl;
                        }
                    }
                }
            }
        }
    }

    // Disconnect all socket to continue with udp
    for (std::list<sf::TcpSocket*>::iterator it = m_clients.begin(); it != m_clients.end(); ++it)
    {
        sf::TcpSocket& client = **it;

        client.disconnect();
    }
}
