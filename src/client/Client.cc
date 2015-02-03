#include <iostream>
#include <unistd.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include <common/CommunicationThread.h>
#include <common/Protocol.h>
#include <client/World.h>

void help();

int main(int argc, char *argv[])
{
    // Check parameters
    if (argc != 2)
    {
        help();
        return EXIT_FAILURE;
    }

    // Create the communication thread
    lae3::common::CommunicationThread comThread;
    comThread.start();

    // Wait to get the port of UDP
    while (comThread.getPort() == 0)
    {
        sleep(1);
    }

    // Register the player
    std::string name(argv[1]);
    if (!lae3::common::Protocol::registerPlayer(name, "127.0.0.1", 4242, comThread.getPort()))
    {
        return EXIT_FAILURE;
    }

	// Create window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Life After Earth III");

    // For test only
    sf::Vector2f position(0,0);

    // Create the World
    lae3::client::World world;

	// Main loop
	while (window.isOpen())
    {
        // Manage event
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                // Close window
                case sf::Event::Closed:
                    window.close();
                    break;

                // Key release
                case sf::Event::KeyReleased:
                    // If UP
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        sf::Packet packet;

                        packet << lae3::common::CodeCommande::MOVE_UP;

                        comThread.sendPacket(packet, sf::IpAddress("127.0.0.1"), 4242);
                    }
                    // If Down
                    if (event.key.code == sf::Keyboard::Down)
                    {
                        sf::Packet packet;

                        packet << lae3::common::CodeCommande::MOVE_DOWN;

                        comThread.sendPacket(packet, sf::IpAddress("127.0.0.1"), 4242);
                    }
                    // If Left
                    if (event.key.code == sf::Keyboard::Left)
                    {
                        sf::Packet packet;

                        packet << lae3::common::CodeCommande::MOVE_LEFT;

                        comThread.sendPacket(packet, sf::IpAddress("127.0.0.1"), 4242);
                    }
                    // If UP
                    if (event.key.code == sf::Keyboard::Right)
                    {
                        sf::Packet packet;

                        packet << lae3::common::CodeCommande::MOVE_RIGHT;

                        comThread.sendPacket(packet, sf::IpAddress("127.0.0.1"), 4242);
                    }
                    break;

                default:
                    break;
            }
        }

        // Update info with the server
        sf::Packet packet;
        while (comThread.receivePacket(packet))
        {
            lae3::common::UpdateData data;
            packet >> data;
            world.update(data);
        }

        window.clear(sf::Color::Black);

        world.render(window);

        window.display();
    }

	return EXIT_SUCCESS;
}

void help()
{
    std::cout << "USAGE:" << std::endl;
    std::cout << "\tlea3-client PLAYER_NAME" << std::endl;
}
