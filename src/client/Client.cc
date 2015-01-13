#include <iostream>
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

    // Register the player
    std::string name(argv[1]);
    unsigned short port = 0;
    if (!lae3::common::Protocol::registerPlayer(name, port))
    {
        return EXIT_FAILURE;
    }

	// Create window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Life After Earth III");

	// Create the communication thread
    lae3::common::CommunicationThread comThread;
    comThread.setPort(port);
    comThread.start();

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
