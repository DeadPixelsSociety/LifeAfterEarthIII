#include <iostream>
#include <SFML/Graphics.hpp>
#include <Map.h>
using namespace std;
using namespace sf;

int main(int argc, char *argv[])
{
  sf::Texture t;
  t.loadFromFile("tileset.png");
  client::Map m(t);;
  
  RenderWindow window(VideoMode(MAP_WIDTH * TILE_WIDTH,MAP_HEIGHT * TILE_HEIGHT,32),"TEST");
  Event event;
  
  m.generateWall(0.1);


  while(window.isOpen())
    {

      while(window.pollEvent(event))
	{

	  switch(event.type)
	    {
	    case Event::Closed:
	      window.close();
	      break;
	      
	    case Event::KeyPressed:
	      
	      switch(event.key.code)
		{
		case Keyboard::Escape:
		  window.close();
		  break;

		  //pour tester
		case Keyboard::Space:
		  m.init();
		  m.generateWall();
		  m.generateWall(0.1);
		  break;

		default:break;
		}

	      break;

	    default:break;

	    }

	  
	}
     
      m.update();
      window.clear(Color(4,139,154));
      m.display(&window);
      window.display();
    }
  

  
  
  
}
