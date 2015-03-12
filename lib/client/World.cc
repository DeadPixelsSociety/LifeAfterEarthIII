#include <SFML/Graphics.hpp>

#include <client/World.h>

lae3::client::World::World(const lae3::common::Random &random, ResourceManager &resources) :
    m_map(random, resources)
{
    //ctor
}

lae3::client::World::~World()
{
    //dtor
}

/* virtual */ void lae3::client::World::render(sf::RenderWindow &window) const
{
    // Drawn the map
    m_map.render(window);
}

void lae3::client::World::update(lae3::common::UpdateData &data)
{
    // Nothing
}
