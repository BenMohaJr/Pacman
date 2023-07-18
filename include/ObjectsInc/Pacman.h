#pragma once

#include <SFML/Audio.hpp>
#include "ObjectsInc/MovingObject.h"
#include "GameData.h"
#include "ObjectsInc/Ghost.h"
#include "PacmanState.h"
#include "NormalPacman.h"
#include "SuperPacman.h"
#include <functional>
#include <memory>

class Pacman : public MovingObject
{
public:
	Pacman(double sizeScale, sf::Vector2f position, std::function<void()> func);
	~Pacman() {}

	void move(sf::Vector2f pacmanLocation, std::vector<std::unique_ptr<StaticObject>> &StaticObject, sf::Time deltaTime);
	void relocate(sf::Vector2f direction, sf::Time deltaTime);
	void upgradeToSuper();
	void downgradeToNormal();
	void dontMove();

	virtual void handleCollision(Object& gameObject);
	virtual void handleCollision(Cookie& gameObject);
	virtual void handleCollision(Door& gameObject);
	virtual void handleCollision(Key& gameObject);
	virtual void handleCollision(Wall& gameObject);
	virtual void handleCollision(Ghost& gameObject);
	virtual void handleCollision(ExtraLifeGift& gameObject);
	virtual void handleCollision(ExtraTimeGift& gameObject);
	virtual void handleCollision(FreezingGift& gameObject);
	virtual void handleCollision(SuperPacmanGift& gameObject);
	virtual void handleCollision(Pacman& gameObject) {}

private://DOOR_SUPER, GHOST_PACMAN, GHOST_SUPER, GIFT, KEY_V
	std::unique_ptr<PacmanState> m_PacmanState;
	sf::Sound m_giftSound;
	sf::Sound m_keySound;
	sf::Sound m_cookieSound;
	std::function<void()> m_resetMovingObj;
};

