#pragma once
#include <functional>
#include <SFML/Audio.hpp>
#include "Resources.h"

class Pacman;
class Door;
class Ghost;

class PacmanState
{
public:
	PacmanState() = default;
	virtual ~PacmanState() = default;
	virtual void ChangeOfState(Pacman& pacman) = 0;
	virtual void handleDoorCollision(Pacman& pacman, Door& door) = 0;
	virtual void handleGhostCollision(Ghost& ghost, std::function<void()> resetMovingObj) = 0;

protected:
	sf::Sound m_ghostSound;
};
