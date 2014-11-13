#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include <common/CommunicationThread.h>

void help();

int main(int argc, char *argv[])
{
    // Check parameters
    if (argc != 2)
    {
        help();
        return EXIT_FAILURE;
    }

    // Create packet
	sf::TcpSocket socket;
	sf::Packet packet;
	std::string name(argv[1]);

    // Sent player name
	socket.connect(sf::IpAddress::LocalHost, 4242);
	packet << name;
	socket.send(packet);

	// Create window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Life After Earth III");

	// Create the communication thread
    lae3::common::CommunicationThread comThread;
    comThread.start();

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

        window.clear(sf::Color::Black);

        // Drawn a circle
        sf::CircleShape circle(10);
        circle.setFillColor(sf::Color::White);
        circle.setPosition(5, 5);
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
