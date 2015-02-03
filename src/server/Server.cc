#include <iostream>
#include <SFML/Window/Keyboard.hpp>

#include <server/Listener.h>
#include <server/World.h>
#include <common/CommunicationThread.h>

int main(int argc, char *argv[])
{
    // Gets names of player
	lae3::server::Listener listener;
	listener.start();

    // Start the communication with UdpSocket
    lae3::common::CommunicationThread comThread(4242);
    comThread.start();

    // Create the world
    lae3::server::World world;

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
            lae3::common::CodeCommande codeCommande;
            packet >> codeCommande;
            world.update(codeCommande);
        }

        // Check if it's needed to send data
        if (clock.getElapsedTime().asMilliseconds() >= 8.33)
        {
            clock.restart();

            // Send the new data
            for (unsigned int i = 0; i < listener.getPlayers().size(); ++i)
            {
                packet.clear();
                packet << world.getUpdateData();
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
