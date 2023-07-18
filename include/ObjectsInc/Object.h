#pragma once
#include "Resources.h"
#include <SFML/Graphics.hpp>

class Cookie;
class Door;
class Key;
class Wall;
class Pacman;
class Ghost;
class ExtraLifeGift;
class ExtraTimeGift;
class FreezingGift;
class SuperPacmanGift;

class Object
{
public:
	Object(OBJECTS object, double sizeScale, sf::Vector2f position);
	virtual ~Object() {}
	void drawObject(sf::RenderWindow& window) const;
	sf::FloatRect getGlobalBounds() const;

	virtual void handleCollision(Object& gameObject) = 0;
	virtual void handleCollision(Cookie& gameObject) = 0;
	virtual void handleCollision(Door& gameObject) = 0;
	virtual void handleCollision(Key& gameObject) = 0;
	virtual void handleCollision(Wall& gameObject) = 0;
	virtual void handleCollision(Pacman& gameObject) = 0;
	virtual void handleCollision(Ghost& gameObject) = 0;
	virtual void handleCollision(ExtraLifeGift& gameObject) = 0;
	virtual void handleCollision(ExtraTimeGift& gameObject) = 0;
	virtual void handleCollision(FreezingGift& gameObject) = 0;
	virtual void handleCollision(SuperPacmanGift& gameObject) = 0;

protected:
	sf::Sprite m_object;
};

