#include <SFML/Graphics.hpp>

#include <client/World.h>

lae3::client::World::World() :
    m_position(10.0f, 10.0f)
{
    //ctor
}

lae3::client::World::~World()
{
    //dtor
}

/* virtual */ void lae3::client::World::render(sf::RenderWindow &window) const
{
    // Drawn a circle
    sf::CircleShape circle(10);
    circle.setFillColor(sf::Color::White);
    circle.setPosition(m_position);
    window.draw(circle);
}

void lae3::client::World::update(lae3::common::UpdateData &data)
{
    m_position.x = data.x;
    m_position.y = data.y;
}
