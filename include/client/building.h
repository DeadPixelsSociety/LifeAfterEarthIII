#ifndef __BUILDING_H
#define __BUILDING_H

#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <client/ressourceLoader.h>

enum BuildingType
{
	BT_unknown,
	BT_city_center,

	BT_building_count
};

namespace lifeAfterEarth3
{

	class Building
	{
	public:

		Building(BuildingType buildingType = BT_unknown);

		virtual ~Building(void);

		virtual void LoadSprite(const char* sprite);

		virtual void LoadSprite(const sf::Sprite& sprite);

		virtual sf::Sprite* GetSprite(void);

		virtual float GetX(void) const;

		virtual float GetY(void) const;

		virtual void SetX(float x);

		virtual void SetY(float y);

		virtual void SetPosition(float x, float y);

		virtual void SetPosition(sf::Vector2f* position);

		virtual sf::Vector2f* GetPosition(void) const;

		virtual int GetLevel(void) const;

		virtual void SetLevel(unsigned int newLevel);

		virtual void SetIsPlaced(bool state);

		virtual bool IsPlaced(void) const;

	private:

	protected:

		sf::Sprite* m_sprite;

		BuildingType m_type;

		sf::Vector2f* m_position;

		unsigned int m_level;

		unsigned int m_maxLevel;

		bool m_placed;

	};
}

#endif // __BUILDING_H
