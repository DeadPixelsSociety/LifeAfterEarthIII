#ifndef COMMUNICATIONTHREAD_H
#define COMMUNICATIONTHREAD_H

#include <SFML/System.hpp>

#include <client/ClientObject.h>

namespace lae3
{
    namespace client
    {
        class CommunicationThread : public ClientObject
        {
            public:
                explicit CommunicationThread();
                virtual ~CommunicationThread();

                void start();

            protected:

            private:
                sf::Thread m_thread;

                void run();
        };
    }
}

#endif // COMMUNICATIONTHREAD_H
