#include <iostream>

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
        if (clock.getElapsedTime().asMilliseconds() >= 16.67)
        {
            clock.restart();
            sf::Packet packet;
            packet << position.x << position.y;

            for (unsigned int i = 0; i < listener.getPlayers().size(); ++i)
            {
                lae3::server::Player &player = listener.getPlayers()[i];
                comThread.sendPacket(packet, player.getIP(), player.getPort());
            }

            position.x++;
            position.y++;
        }
        else
        {
            sf::sleep(sf::milliseconds(16.67));
        }
    }

	return EXIT_SUCCESS;
}
