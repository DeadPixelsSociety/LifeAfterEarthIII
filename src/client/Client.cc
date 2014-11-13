#include <iostream>
#include <SFML/Network.hpp>

void help();

int main(int argc, char *argv[])
{
    // Check parameters
    if (argc != 2)
    {
        help();
        return EXIT_FAILURE;
    }

	sf::TcpSocket socket;
	sf::Packet packet;
	std::string name(argv[1]);

    // Sent player name
	socket.connect(sf::IpAddress::LocalHost, 4242);
	packet << name;
	socket.send(packet);

	for (;;)
    {
        //
    }

	return EXIT_SUCCESS;
}

void help()
{
    std::cout << "USAGE:" << std::endl;
    std::cout << "\tlea3-client PLAYER_NAME" << std::endl;
}
