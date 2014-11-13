#include <iostream>

#include <client/CommunicationThread.h>

/* explicit */ lae3::client::CommunicationThread::CommunicationThread() :
    m_thread(&lae3::client::CommunicationThread::run, this)
{
    //ctor
}

/* virtual */ lae3::client::CommunicationThread::~CommunicationThread()
{
    //dtor
}

void lae3::client::CommunicationThread::start()
{
    m_thread.launch();
}

void lae3::client::CommunicationThread::run()
{
    std::cout << "Thread run" << std::endl;
}
