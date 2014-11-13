#include <iostream>

#include <common/CommunicationThread.h>

/* explicit */ lae3::common::CommunicationThread::CommunicationThread() :
    m_thread(&lae3::common::CommunicationThread::run, this)
{
    //ctor
}

/* virtual */ lae3::common::CommunicationThread::~CommunicationThread()
{
    //dtor
}

void lae3::common::CommunicationThread::start()
{
    m_thread.launch();
}

void lae3::common::CommunicationThread::run()
{
    std::cout << "Thread run" << std::endl;
}
