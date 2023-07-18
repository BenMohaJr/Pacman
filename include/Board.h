#pragma once
#include "ObjectsInc/MovingObject.h"
#include "ObjectsInc/Pacman.h"
#include "ObjectsInc/Ghost.h"
#include "ObjectsInc/StaticObject.h"
#include "ObjectsInc/Cookie.h"
#include "ObjectsInc/Door.h"
#include "ObjectsInc/Key.h"
#include "ObjectsInc/Wall.h"
#include "ObjectsInc/ExtraLifeGift.h"
#include "ObjectsInc/ExtraTimeGift.h"
#include "ObjectsInc/FreezingGift.h"
#include "ObjectsInc/SuperPacmanGift.h"
#include "ObjectsInc/SmartGhost.h"
#include "ObjectsInc/RandomGhost.h"
#include "ObjectsInc/LessSmartGhost.h"




class Board
{
public:
	Board();
	~Board() {}
	void levelLoading();
	void loadingObject(char currentType, double row, double col, double sizeSfr,
		double sizeScale, std::vector<int>& keyVec, std::vector<int>& doorVec);
	void drawBoard(sf::RenderWindow& window) const;
	void move(sf::Time deltaTime);
	void nextLevel();
	void endOfTime();
	void endOfLife();
	void reset();

private:
	int m_pacman_index;
	sf::RectangleShape m_background;
	std::vector<std::unique_ptr<StaticObject>> m_StaticObject;
	std::vector<std::unique_ptr<MovingObject>> m_MovingObject;

};
