#include <client/View.h>
#include <client/Map.h>

/* explicit */ lae3::client::View::View(sf::Vector2u sizeWindow) :
    m_sizeWindow(sizeWindow)
{
    // Set center
    sf::Vector2f cameraPosition;
    cameraPosition.x = lae3::client::Map::MAP_WIDTH * lae3::client::Map::TILE_WIDTH / 2.0f;
    cameraPosition.y = lae3::client::Map::MAP_HEIGHT * lae3::client::Map::TILE_HEIGHT / 2.0f;
    setCenter(cameraPosition);

    // Set view size
    sf::Vector2f sizeView;
    sizeView.x = sizeWindow.x;
    sizeView.y = sizeWindow.y;
    setSize(sizeView);
}

/* virtual */ lae3::client::View::~View()
{
    //dtor
}
