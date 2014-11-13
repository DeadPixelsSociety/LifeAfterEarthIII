#ifndef COMMUNICATIONTHREAD_H
#define COMMUNICATIONTHREAD_H

#include <SFML/System.hpp>
#include <server/ServerObject.h>

namespace lae3
{
    namespace server
    {
        class CommunicationThread : public ServerObject
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
