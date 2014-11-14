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
                virtual ~CommunicationThread();

                void setPort(const unsigned short port);

                void start();
                void stop();
                void sendPacket(const sf::Packet &packet);
                bool receivePacket(sf::Packet &packet);

            protected:

            private:
                sf::Thread m_thread;
                unsigned int m_port;
                bool m_continue;
                sf::Mutex m_mutex;

                std::list<sf::Packet> m_inPackets;
                std::list<sf::Packet> m_outPackets;

                void run();
        };
    }
}

#endif // COMMUNICATIONTHREAD_H
