#include <iostream>
#include <SFML/Network.hpp>

#include <common/Protocol.h>

/* static */ int lae3::common::Protocol::registerPlayer(const std::string &name, const std::string &ip, const unsigned short &port, const sf::Uint16 &portUDP)
{
    // Create packet
	sf::TcpSocket socket;
	sf::Packet packet;

    // Sent player name
	socket.connect(sf::IpAddress(ip), port);
	packet << name;
	packet << portUDP;
	std::cout << "portUDP = " << portUDP << std::endl;
	if (socket.send(packet) != sf::Socket::Done)
    {
        std::cerr << "Error during send packet" << std::endl;
        return -1;
    }

	// Get seed
	sf::Int64 seed;

	packet.clear();
	if (socket.receive(packet) != sf::Socket::Done)
    {
        std::cerr << "Error during receive packet" << std::endl;
        return -1;
    }
    packet >> seed;

    // Waiting the other player
    do
    {
        std::cout << "Waiting other players" << std::endl;
    }
    while (sf::Socket::Disconnected != socket.receive(packet));

    return (unsigned int)seed;
}
