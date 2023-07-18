#pragma once
#include "PacmanState.h"

class Pacman;
class Door;
class Ghost;

class SuperPacman : public PacmanState
{
public:
	SuperPacman();
	~SuperPacman() = default;

	void ChangeOfState(Pacman& pacman);
	void handleDoorCollision(Pacman& pacman, Door& door);
	void handleGhostCollision(Ghost& ghost, std::function<void()> resetMovingObj);

private:
	sf::Sound m_doorSound;
};
