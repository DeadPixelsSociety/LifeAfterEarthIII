#include <common/common.h>
#include <client/ressourceLoader.h>
#include <client/building.h>
#include <iostream>
#include <SFML/Graphics.hpp>

enum
{
    none,
    place,
    move,
    evolve
};

int main(int argc, char *argv[])
{
    lifeAfterEarth3::common::Common::printMessage("Client started.");
    sf::RenderWindow win(sf::VideoMode(1280, 768), "Life After Earth III");
    sf::Clock frameTime;
    win.setVerticalSyncEnabled(true);
    lifeAfterEarth3::RessourceLoader::LoadTextures("../data/textures.tlf");

    lifeAfterEarth3::Building cityCenter(BT_city_center);
    cityCenter.LoadSprite("Building City Center");
    cityCenter.GetSprite()->setTextureRect(sf::IntRect(0, 0, cityCenter.GetSprite()->getTexture()->getSize().x / 10.f, cityCenter.GetSprite()->getTexture()->getSize().y));

    int placement = none;
    bool mouseTriggered = false, mousePressed = false;

    while(win.isOpen())
    {
        sf::Event event;
        while(win.pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::Closed:
                win.close();
                break;
            default:
                break;
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
            placement = place;
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
            placement = move;
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            placement = evolve;
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            placement = none;
        // Update
        frameTime.restart();

        //Display
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !mousePressed)
        {
            mouseTriggered = true;
            mousePressed = true;
        }
        if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            mousePressed = false;
        }

        switch(placement)
        {
        case place:
            if(!cityCenter.IsPlaced())
            {
                if(mouseTriggered)
                {
                    lifeAfterEarth3::common::Common::printMessage("City Center Placed\n");
                    cityCenter.SetPosition(sf::Mouse::getPosition(win).x-cityCenter.GetSprite()->getGlobalBounds().width/2.f,
                    sf::Mouse::getPosition(win).y-cityCenter.GetSprite()->getGlobalBounds().height/2.f);
                    cityCenter.SetIsPlaced(true);
                }
            }
            win.clear(sf::Color::Red);
            break;
        case move:
            if(cityCenter.IsPlaced())
            {
                if(mouseTriggered)
                {
                    lifeAfterEarth3::common::Common::printMessage("City Center Moved\n");
                    cityCenter.SetPosition(sf::Mouse::getPosition(win).x-cityCenter.GetSprite()->getGlobalBounds().width/2.f,
                    sf::Mouse::getPosition(win).y-cityCenter.GetSprite()->getGlobalBounds().height/2.f);
                }
            }
            win.clear(sf::Color::Green);
            break;
        case evolve:
            if(cityCenter.IsPlaced())
            {
                if(mouseTriggered)
                {
                    if(cityCenter.GetSprite()->getGlobalBounds().contains(sf::Mouse::getPosition(win).x, sf::Mouse::getPosition(win).y))
                    {
                        lifeAfterEarth3::common::Common::printMessage("City Center Evolved\n");
                        cityCenter.SetLevel(cityCenter.GetLevel()+1);
                        sf::IntRect rect = cityCenter.GetSprite()->getTextureRect();
                        cityCenter.GetSprite()->setTextureRect(sf::IntRect(rect.left+rect.width, 0, rect.width, rect.height));
                    }
                }
            }
            win.clear(sf::Color::Cyan);
            break;
        default:
            win.clear(sf::Color::Black);
            break;
        }
        mouseTriggered = false;

        if(cityCenter.IsPlaced())
        {
            win.draw(*(cityCenter.GetSprite()));
        }

        win.display();
    }
    return EXIT_SUCCESS;
}
