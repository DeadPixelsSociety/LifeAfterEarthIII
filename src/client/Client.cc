#include <iostream>
#include <unistd.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include <common/CommunicationThread.h>
#include <common/Protocol.h>
#include <common/Map.h>
#include <client/World.h>
#include <client/View.h>
#include <client/Resource.h>

#include "config.h"

void help();

int main(int argc, char *argv[])
{
    // Check parameters
  std::string name("unkownplayer");
  std::string address = "127.0.0.1";
  int port = 4242;

  if (argc == 1)
    {
      help();
      return EXIT_FAILURE;
    }
  else
    {
      std::string arg;
      //for each args
      for(int i = 0; i<argc; i++)
	{
	  arg = argv[i];
	  bool error = false;

	  //check those who begin by -
	  if( arg[0] == '-' )
	    {
	      if( i+1 < argc )
		{
		  // n for the name
		  if( arg[1] == 'n' )
		    {
		      name = argv[i+1];
		    }
		  // p for the port
		  else if( arg[1] == 'p' )
		    {
		      port = std::stoi(argv[i+1]);
		    }
		  // a for the address
		  else if( arg[1] == 'a' )
		    {
		      address = argv[i+1];
		    }
		  // else there is an error
		  else
		    {
		      error = true;
		    }

		}
	      //if there isn't '-' in arguments it is an error too
	      else
		{
		  error = true;
		}

	      //display the error
	      if(error)
		{
		  help();
		  std::cerr<<"E: bad arguments "<<arg<<" \n";
		  return EXIT_FAILURE;
		}
	    }


	}

    }

  std::cout<<"\tPlayer: "<<name<<" port: "<<port<<" address: "<<address<<std::endl;//debug

    // Create the communication thread
    lae3::common::CommunicationThread comThread;
    comThread.start();

    // Wait to get the port of UDP
    while (comThread.getPort() == 0)
    {
        sleep(1);
    }

    // Register the player
    int seed = lae3::common::Protocol::registerPlayer(name, address, port, comThread.getPort());
    if (-1 == seed)
    {
        return EXIT_FAILURE;
    }

    std::cout << "seed = " << seed << std::endl;

    // Create the resources manager
    lae3::client::ResourceManager resources;
    resources.addSearchDir(GAME_DATADIR);

    // Create random generator
    lae3::common::Random random(seed);

	// Create window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Life After Earth III");

    // Create the World
    lae3::client::World world(random, resources);

    // Setting view
    sf::View view({ lae3::client::Map::MAP_WIDTH * lae3::client::Map::TILE_WIDTH / 2.0f, lae3::client::Map::MAP_HEIGHT * lae3::client::Map::TILE_HEIGHT / 2.0f }, { 7.0f * lae3::client::Map::TILE_WIDTH, 7.0f * lae3::client::Map::TILE_HEIGHT });

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

        window.setView(view);

        window.clear(sf::Color::Black);

        world.render(window);

        window.display();
    }

	return EXIT_SUCCESS;
}

void help()
{
    std::cout << "USAGE:" << std::endl;
    std::cout << "\tlea3-client -n PLAYER_NAME" << std::endl;
    std::cout << "\tlea3-client -p PORT" << std::endl;
    std::cout << "\tlea3-client -a ADR" << std::endl;
}
