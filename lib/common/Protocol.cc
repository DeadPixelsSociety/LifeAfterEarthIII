#include <iostream>
#include <SFML/Network.hpp>

#include <common/Protocol.h>

/* static */ bool lae3::common::Protocol::registerPlayer(const std::string &name, unsigned short &port)
{
    // Create packet
	sf::TcpSocket socket;
	sf::Packet packet;

    // Sent player name
	socket.connect(sf::IpAddress::LocalHost, 4242);
	packet << name;
	if (socket.send(packet) != sf::Socket::Done)
    {
        std::cerr << "Error during send packet" << std::endl;
        return false;
    }

	// Get UDP port
	packet.clear();
	if (socket.receive(packet) != sf::Socket::Done)
    {
        std::cerr << "Error during receive packet" << std::endl;
        return false;
    }
    packet >> port;

    // Waiting the other player
    do
    {
        std::cout << "Waiting other players" << std::endl;
    }
    while (sf::Socket::Disconnected != socket.receive(packet));

    return true;
}
