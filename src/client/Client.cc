#include <iostream>
#include <unistd.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include <common/CommunicationThread.h>
#include <common/Protocol.h>

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

	// Main loop
	while (window.isOpen())
    {
        // Manage event
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update info with the server
        sf::Packet packet;
        while (comThread.receivePacket(packet))
        {
            packet >> position.x >> position.y;
        }

        window.clear(sf::Color::Black);

        // Drawn a circle
        sf::CircleShape circle(10);
        circle.setFillColor(sf::Color::White);
        circle.setPosition(position);
        window.draw(circle);

        window.display();
    }

	return EXIT_SUCCESS;
}

void help()
{
    std::cout << "USAGE:" << std::endl;
    std::cout << "\tlea3-client PLAYER_NAME" << std::endl;
}
