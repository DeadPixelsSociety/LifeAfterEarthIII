#include <iostream>
#include <SFML/Network.hpp>

#include <common/CommunicationThread.h>

/* explicit */ lae3::common::CommunicationThread::CommunicationThread() :
    m_thread(&lae3::common::CommunicationThread::run, this)
    , m_port(0)
    , m_continue(true)
{
    // Set socket unblocking
    m_socket.setBlocking(false);
}

/* explicit */ lae3::common::CommunicationThread::CommunicationThread(const unsigned short port) :
    m_thread(&lae3::common::CommunicationThread::run, this)
    , m_port(port)
    , m_continue(true)
{
    // Set socket unblocking
    m_socket.setBlocking(false);
}

/* virtual */ lae3::common::CommunicationThread::~CommunicationThread()
{
    m_thread.terminate();
    m_socket.unbind();
}

unsigned short lae3::common::CommunicationThread::getPort()
{
    unsigned short output;
    m_mutex.lock();
    output = m_port;
    m_mutex.unlock();
    return output;
}

void lae3::common::CommunicationThread::start()
{
    m_thread.launch();
}

void lae3::common::CommunicationThread::stop()
{
    // Set continue as false
    m_mutex.lock();
    m_continue = false;
    m_mutex.unlock();

    // Wait the and of thread
    m_thread.wait();
}

void lae3::common::CommunicationThread::sendPacket(sf::Packet &packet, const sf::IpAddress &ip)
{
    sendPacket(packet, ip, m_port);
}

void lae3::common::CommunicationThread::sendPacket(sf::Packet &packet, const sf::IpAddress &ip, const unsigned short &port)
{
    // Send packet
    m_mutex.lock();
    if (m_socket.send(packet, ip, port) != sf::Socket::Done)
    {
        std::cerr << "Error during send packet" << std::endl;
    }
    m_mutex.unlock();
}

bool lae3::common::CommunicationThread::receivePacket(sf::Packet &packet)
{
    return receivePacket(packet, m_port);
}

bool lae3::common::CommunicationThread::receivePacket(sf::Packet &packet, const unsigned short port)
{
    // If there is no packet
    if (m_inPackets.size() == 0)
    {
        return false;
    }

    // Stock the first packet
    packet = m_inPackets.front();
    m_inPackets.pop_front();

    return true;
}

void lae3::common::CommunicationThread::run()
{
    // Try to bind the port to the server
    if (m_port != 0 && m_socket.bind(m_port) != sf::Socket::Done)
    {
        std::cerr << "Failed to bind port" << std::endl;
        return;
    }
    // Try to bind the port to the client
    else if (m_port == 0 && m_socket.bind(sf::Socket::AnyPort) != sf::Socket::Done)
    {
        std::cerr << "Failed to bind port" << std::endl;
        return;
    }

    // Update the port
    m_mutex.lock();
    m_port = m_socket.getLocalPort();
    m_mutex.unlock();

    m_mutex.lock();
    bool continueSafe = m_continue;
    m_mutex.unlock();

    while (continueSafe)
    {
        // Listen socket
        sf::Packet packet;
        sf::IpAddress remoteAddress;
        unsigned short remotePort;

        // If it's a new packet
        m_mutex.lock();
        if (m_socket.receive(packet, remoteAddress, remotePort) == sf::Socket::Done)
        {
            m_inPackets.push_back(packet);
        }
        m_mutex.unlock();

        m_mutex.lock();
        continueSafe = m_continue;
        m_mutex.unlock();
    }
}
