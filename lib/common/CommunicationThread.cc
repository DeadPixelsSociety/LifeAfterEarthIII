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

void lae3::common::CommunicationThread::sendPacket(const sf::Packet &packet, const sf::IpAddress &ip)
{
    sendPacket(packet, ip, m_port);
}

void lae3::common::CommunicationThread::sendPacket(const sf::Packet &packet, const sf::IpAddress &ip, const unsigned short port)
{
    // Add the packet to out list
    m_mutex.lock();
    m_outPackets.push_back(UdpPacket(packet, ip, port));
    m_mutex.unlock();
}

bool lae3::common::CommunicationThread::receivePacket(sf::Packet &packet)
{
    return receivePacket(packet, m_port);
}

bool lae3::common::CommunicationThread::receivePacket(sf::Packet &packet, const unsigned short port)
{
    return false;
}

void lae3::common::CommunicationThread::run()
{
    // Create the UDP socket
    sf::UdpSocket socket;
    socket.setBlocking(false);

    // Try to bind the port
    if (socket.bind(m_port) != sf::Socket::Done)
    {
        std::cerr << "Failed to connect with the server" << std::endl;
        return;
    }

    std::cout << "port = " << m_port << std::endl;

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
            UdpPacket &udpPacket = m_outPackets.front();
            sf::Packet outPacket = udpPacket.getPacket();
            if (socket.send(outPacket, udpPacket.getIPDestination(), udpPacket.getPortDestination()) != sf::Socket::Done)
            {
                std::cerr << "Error during send packet" << std::endl;
            }
            m_outPackets.pop_front();
        }
        m_mutex.unlock();

        m_mutex.lock();
        continueSafe = m_continue;
        m_mutex.unlock();
    }
}
