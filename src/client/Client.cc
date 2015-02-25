#include <iostream>
#include <unistd.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include <common/CommunicationThread.h>
#include <common/Protocol.h>
#include <client/World.h>
#include <client/View.h>

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
    int seed = lae3::common::Protocol::registerPlayer(name, "127.0.0.1", 4242, comThread.getPort());
    if (-1 == seed)
    {
        return EXIT_FAILURE;
    }

    std::cout << "seed = " << seed << std::endl;

    // Create random generator
    lae3::common::Random random(seed);

	// Create window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Life After Earth III");

    // Create the World
    lae3::client::World world(random);

    // Setting view
    sf::View view({ 128.0f * lae3::client::Map::MAP_WIDTH, 128.0f * lae3::client::Map::MAP_HEIGHT }, { lae3::client::View::VIEW_WIDTH, lae3::client::View::VIEW_HEIGHT });
    view.setViewport(lae3::client::View::computeViewport(800, 600));

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

                /// TODO Manage mouse event

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

        //window.setView(view);
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
