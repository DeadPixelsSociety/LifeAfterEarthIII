#ifndef COMMUNICATIONTHREAD_H
#define COMMUNICATIONTHREAD_H

#include <SFML/System.hpp>

namespace lae3
{
    namespace common
    {
        class CommunicationThread
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
