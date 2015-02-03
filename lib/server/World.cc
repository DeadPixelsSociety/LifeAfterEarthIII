#include <iostream>
#include <cassert>
#include <server/World.h>

/* explicit */ lae3::server::World::World() :
    m_position(10, 10)
{
    //ctor
}

/* virtual */ lae3::server::World::~World()
{
    //dtor
}

lae3::common::UpdateData lae3::server::World::getUpdateData() const
{
    lae3::common::UpdateData data;
    data.x = m_position.x;
    data.y = m_position.y;

    return data;
}

void lae3::server::World::update(lae3::common::CodeCommande codeCommande)
{
    // Apply the right update
    switch (codeCommande)
    {
    case lae3::common::CodeCommande::MOVE_UP:
        m_position.y -= 10;
        break;

    case lae3::common::CodeCommande::MOVE_DOWN:
        m_position.y += 10;
        break;

    case lae3::common::CodeCommande::MOVE_LEFT:
        m_position.x -= 10;
        break;

    case lae3::common::CodeCommande::MOVE_RIGHT:
        m_position.x += 10;
        break;

    default:
        assert(false);
    }
}
