#include <cstdlib>
#include <SFML/Network.hpp>

#include <client/Socket.h>

int main(int argc, char *argv[])
{
	lae3::client::Socket socket;

	socket.connect(sf::IpAddress::LocalHost);

	for(;;)
    {

    }

	return EXIT_SUCCESS;
}
