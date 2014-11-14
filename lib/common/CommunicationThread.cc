#include <iostream>
#include <SFML/Network.hpp>

#include <common/CommunicationThread.h>

/* explicit */ lae3::common::CommunicationThread::CommunicationThread() :
    m_thread(&lae3::common::CommunicationThread::run, this)
    , m_port(4242)
    , m_continue(true)
{
    //ctor
}

/* virtual */ lae3::common::CommunicationThread::~CommunicationThread()
{
    m_thread.terminate();
}

void lae3::common::CommunicationThread::setPort(const unsigned short port)
{
    m_port = port;
}


void lae3::common::CommunicationThread::start()
{
    std::cout << "port: " << m_port << std::endl;
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

void lae3::common::CommunicationThread::sendPacket(const sf::Packet &packet)
{
    //
}

bool lae3::common::CommunicationThread::receivePacket(sf::Packet &packet)
{
    return false;
}

void lae3::common::CommunicationThread::run()
{
    // Create the UDP socket
    sf::UdpSocket socket;
    socket.setBlocking(false);
    sf::Socket::Status status;

    // Try to bind the port
    do
    {
        status = socket.bind(m_port++);
    }
    while (status != sf::Socket::Done);

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
        if (socket.receive(packet, remoteAddress, remotePort) == sf::Socket::Done)
        {
            ///TODO Add packet to inPackets
            std::cout << "Packet Receiv" << std::endl;
        }

        // Send packet if it's needed
        m_mutex.lock();
        if (m_outPackets.size() != 0)
        {
            socket.send(m_outPackets.front(), sf::IpAddress::LocalHost, socket.getLocalPort());
        }
        m_mutex.unlock();

        m_mutex.lock();
        continueSafe = m_continue;
        m_mutex.unlock();
    }

    std::cout << socket.getLocalPort() << std::endl;
}
