#include <cstdlib>
#include <SFML/Network.hpp>

int main(int argc, char *argv[])
{
	sf::TcpSocket socket;
	sf::Packet packet;
	std::string message = "The cake is a lie!";

	socket.connect(sf::IpAddress::LocalHost, 4242);
	packet << message;
	socket.send(packet);

	for (;;)
    {
        //
    }

	return EXIT_SUCCESS;
}
