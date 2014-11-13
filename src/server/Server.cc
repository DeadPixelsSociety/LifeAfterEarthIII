#include <iostream>

#include <server/Listener.h>
#include <server/CommunicationThread.h>

int main(int argc, char *argv[])
{
    // Gets names of player
	lae3::server::Listener listener;
	listener.start();

    // Start the communication with UdpSocket
    lae3::server::CommunicationThread comThread;
    comThread.start();

    sf::Clock clock;
    clock.restart();

	for (;;)
    {
        if (clock.getElapsedTime().asSeconds() >= 0.01667)
        {
            clock.restart();
            std::cout << "The main thread updating the game" << std::endl;
        }
        else
        {
            sf::sleep(sf::milliseconds(16.67));
        }
    }

	return EXIT_SUCCESS;
}
