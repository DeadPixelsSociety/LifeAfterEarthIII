#include <client/building.h>

namespace lifeAfterEarth3
{

	Building::Building(BuildingType buildingType)
	: m_sprite(NULL)
	, m_type(buildingType)
	, m_position(new sf::Vector2f())
	, m_level(1)
	, m_placed(false)
	{

	}

	/*virtual*/ Building::~Building()
	{
		if(m_position)
			delete m_position;
		if(m_sprite)
			delete m_sprite;
	}

	/*virtual*/ void Building::LoadSprite(const char* sprite)
	{
		if(m_sprite)
		{
			delete m_sprite;
		}
		m_sprite = new sf::Sprite();
		m_sprite->setTexture(*RessourceLoader::GetTexture(std::string(sprite)));
	}

	/*virtual*/ void Building::LoadSprite(const sf::Sprite& sprite)
	{
		if(m_sprite)
		{
			delete m_sprite;
		}
		m_sprite = new sf::Sprite();
		m_sprite->setTexture(*(sprite.getTexture()));
	}

	/*virtual*/ sf::Sprite* Building::GetSprite()
	{
		return m_sprite;
	}

	/*virtual*/ float Building::GetX() const
	{
		return m_position->x;
	}

	/*virtual*/ float Building::GetY() const
	{
		return m_position->y;
	}

	/*virtual*/ void Building::SetX(float x)
	{
		m_position->x = x;
		m_sprite->setPosition(x, m_position->y);
	}

	/*virtual*/ void Building::SetY(float y)
	{
		m_position->y = y;
		m_sprite->setPosition(m_position->x, y);
	}

	/*virtual*/ void Building::SetPosition(float x, float y)
	{
		m_position->x = x;
		m_position->y = y;
		m_sprite->setPosition(x, y);
	}

	/*virtual*/ void Building::SetPosition(sf::Vector2f* position)
	{
		m_position->x = position->x;
		m_position->y = position->y;
		m_sprite->setPosition(position->x, position->y);
	}

	/*virtual*/ sf::Vector2f* Building::GetPosition() const
	{
		return m_position;
	}

	/*virtual*/ int Building::GetLevel() const
	{
		return m_level;
	}

	/*virtual*/ void Building::SetLevel(unsigned int newLevel)
	{
		m_level = newLevel;
		if(m_level > m_maxLevel)
			m_level = m_maxLevel;
	}

	/*virtual*/ void Building::SetIsPlaced(bool state)
	{
		m_placed = state;
	}

	/*virtual*/ bool Building::IsPlaced() const
	{
		return m_placed;
	}

}
