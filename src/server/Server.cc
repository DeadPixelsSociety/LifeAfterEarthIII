#include <iostream>
#include <SFML/Window/Keyboard.hpp>

#include <server/Listener.h>
#include <common/CommunicationThread.h>

int main(int argc, char *argv[])
{
    // Gets names of player
	lae3::server::Listener listener;
	listener.start();

    // Start the communication with UdpSocket
    lae3::common::CommunicationThread comThread(4242);
    comThread.start();

    sf::Clock clock;
    clock.restart();

    // For test only
    sf::Vector2f position(0, 0);

	for (;;)
    {
        sf::Packet packet;

        // Check if players send data
        if (comThread.receivePacket(packet))
        {
            unsigned int keyInt;
            packet >> keyInt;
            sf::Keyboard::Key key = (sf::Keyboard::Key) keyInt;
            std::cout << key << std::endl;
        }

        // Check if it's needed to send data
        if (clock.getElapsedTime().asMilliseconds() >= 8.33)
        {
            clock.restart();

            // Send the new data
            for (unsigned int i = 0; i < listener.getPlayers().size(); ++i)
            {
                lae3::server::Player &player = listener.getPlayers()[i];
                comThread.sendPacket(packet, player.getIP(), player.getPort());
            }
        }
        else
        {
            // Wait timer
            sf::sleep(sf::milliseconds(8.33));
        }
    }

	return EXIT_SUCCESS;
}
