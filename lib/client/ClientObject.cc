#include <client/ClientObject.h>

/* explicit */ lae3::client::ClientObject::ClientObject()
{
    //ctor
}

/* virtual */ lae3::client::ClientObject::~ClientObject()
{
    //dtor
}

/* virtual */ void lae3::client::ClientObject::render(sf::RenderWindow &window) const
{
    // Empty
}

/* virtual */ void lae3::client::ClientObject::update(const float dt)
{
    // Empty
}
