#ifndef COMMUNICATIONTHREAD_H
#define COMMUNICATIONTHREAD_H

#include <list>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

namespace lae3
{
    namespace common
    {
        class CommunicationThread
        {
            public:
                explicit CommunicationThread();
                explicit CommunicationThread(const unsigned short port);
                virtual ~CommunicationThread();

                unsigned short getPort();

                void start();
                void stop();
                void sendPacket(sf::Packet &packet, const sf::IpAddress &ip);
                void sendPacket(sf::Packet &packet, const sf::IpAddress &ip, const unsigned short &port);
                bool receivePacket(sf::Packet &packet);
                bool receivePacket(sf::Packet &packet, const unsigned short port);

            protected:

            private:
                sf::Thread m_thread;
                unsigned short m_port;
                bool m_continue;
                sf::Mutex m_mutex;

                sf::UdpSocket m_socket;
                std::list<sf::Packet> m_inPackets;

                void run();
        };
    }
}

#endif // COMMUNICATIONTHREAD_H
