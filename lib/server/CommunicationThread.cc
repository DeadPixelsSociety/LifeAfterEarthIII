#include <iostream>

#include <server/CommunicationThread.h>

/* explicit */ lae3::server::CommunicationThread::CommunicationThread() :
    m_thread(&lae3::server::CommunicationThread::run, this)
{
    //ctor
}

/* virtual */ lae3::server::CommunicationThread::~CommunicationThread()
{
    m_thread.terminate();
}

void lae3::server::CommunicationThread::start()
{
    // Launch the thread
    m_thread.launch();
}

void lae3::server::CommunicationThread::run()
{
    for (;;)
    {
        std::cout << "Thread run." << std::endl;
    }
}
