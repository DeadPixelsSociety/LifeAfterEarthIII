#include <client/View.h>
#include <client/Map.h>

constexpr static int MOVE_STEP = 5;

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

void lae3::client::View::updateMoveState(sf::Vector2i mousePosition)
{
    // Calcul the margins
    float xMargin = 0.10f * m_sizeWindow.x;
    float yMargin = 0.10f * m_sizeWindow.y;

    // New center
    sf::Vector2f newCenter = getCenter();

    // Check if it's left screen
    if (mousePosition.x <= xMargin)
    {
        newCenter.x -= MOVE_STEP;
    }
    // Check if it's right screen
    else if (mousePosition.x >= (m_sizeWindow.x - xMargin))
    {
        newCenter.x += MOVE_STEP;
    }

    // Check if it's top screen
    if (mousePosition.y <= yMargin)
    {
        newCenter.y -= MOVE_STEP;
    }
    // Check if it's right screen
    else if (mousePosition.y >= (m_sizeWindow.y - yMargin))
    {
        newCenter.y += MOVE_STEP;
    }

    // Update the new center
    setCenter(newCenter);
}
