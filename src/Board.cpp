#include "Board.h"
#include <functional>
#include <memory>


Board::Board()
{
	m_background.setSize(sf::Vector2f(boardLength, boardWidth));
	m_background.setTexture(Resources::instance().getObjects(BOARD));
	m_background.setPosition(distance, distance);
	m_background.setOutlineThickness(3.5);
	m_background.setOutlineColor(sf::Color(55, 53, 8));
	levelLoading();
}

// Loads a new stage to the board.
void Board::levelLoading()
{
	double sizeSfr; // Calculates the size of each object based on the size of the board.
	double tempRow = boardLength / Resources::instance().maxRow(GameData::instance().getLevel() - 1);
	double tempCol = boardWidth / Resources::instance().maxCol(GameData::instance().getLevel() - 1);
	(tempRow <= tempCol) ? sizeSfr = tempRow : sizeSfr = tempCol;
	double sizeScale = (double)sizeSfr / sizeObject; // Calculates the Scale of each object according to the size.

	// Clears the object vectors.
	m_MovingObject.clear();
	m_StaticObject.clear();
	// Vectors that will hold the positions of the doors and keys to connect them.
	std::vector<int> keyVec;
	std::vector<int> doorVec;
	
	// Goes character by character and translates it into objects.
	int level = GameData::instance().getLevel() - 1;
	for (int i = 0; i < Resources::instance().maxRow(level); i++)
		for (int j = 0; j < Resources::instance().maxCol(level); j++)
			loadingObject(Resources::instance().getChar(level, i, j), i, j, sizeSfr, sizeScale, keyVec, doorVec);

	// A connector between the doors and the keys.
	for (int i = 0; i < keyVec.size(); i++) {
		static_cast<Key*>(m_StaticObject[keyVec[i]].get())->setDoor(static_cast<Door*>(m_StaticObject[doorVec[i]].get()));
		static_cast<Door*>(m_StaticObject[doorVec[i]].get())->setKey(static_cast<Key*>(m_StaticObject[keyVec[i]].get()));
	}
}

// switch case that translates characters into objects.
void Board::loadingObject(char currentType, double row, double col, double sizeSfr, double sizeScale,
	std::vector<int>& keyVec, std::vector<int>& doorVec)
{
	switch (currentType)
	{
	case '*':
		GameData::instance().setCookie(1);
		m_StaticObject.push_back(std::make_unique<Cookie>(sizeScale,
			sf::Vector2f(distance + sizeSfr * row, distance + sizeSfr * col)));
		break;

	case 'A':
		m_MovingObject.push_back(std::make_unique<SmartGhost>(sizeScale * 0.80,
			sf::Vector2f(distance + sizeSfr * row, distance + sizeSfr * col)));
		break;

	case 'B':
		m_MovingObject.push_back(std::make_unique<LessSmartGhost>(sizeScale * 0.80,
			sf::Vector2f(distance + sizeSfr * row, distance + sizeSfr * col)));
		break;

	case 'C':
		m_MovingObject.push_back(std::make_unique<RandomGhost>(sizeScale * 0.80,
			sf::Vector2f(distance + sizeSfr * row, distance + sizeSfr * col)));
		break;

	case 'D':
		doorVec.push_back(m_StaticObject.size());
		m_StaticObject.push_back(std::make_unique<Door>(sizeScale,
			sf::Vector2f(distance + sizeSfr * row, distance + sizeSfr * col)));
		break;

	case '%':
		keyVec.push_back(m_StaticObject.size());
		m_StaticObject.push_back(std::make_unique<Key>(sizeScale,
			sf::Vector2f(distance + sizeSfr * row, distance + sizeSfr * col)));
		break;

	case '@':
		m_pacman_index = m_MovingObject.size();
		m_MovingObject.push_back(std::make_unique<Pacman>(sizeScale * 0.85,
			sf::Vector2f(distance + sizeSfr * row, distance + sizeSfr * col), std::bind(&Board::reset,this)));
		break;

	case '#':
		m_StaticObject.push_back(std::make_unique<Wall>(sizeScale,
			sf::Vector2f(distance + sizeSfr * row, distance + sizeSfr * col)));
		break;

	case '1':
		m_StaticObject.push_back(std::make_unique<ExtraLifeGift>(sizeScale,
			sf::Vector2f(distance + sizeSfr * row, distance + sizeSfr * col)));
		break;

	case '2':
		m_StaticObject.push_back(std::make_unique<ExtraTimeGift>(sizeScale,
			sf::Vector2f(distance + sizeSfr * row, distance + sizeSfr * col)));
		break;

	case '3':
		m_StaticObject.push_back(std::make_unique<FreezingGift>(sizeScale,
			sf::Vector2f(distance + sizeSfr * row, distance + sizeSfr * col)));
		break;

	case '4':
		m_StaticObject.push_back(std::make_unique<SuperPacmanGift>(sizeScale,
			sf::Vector2f(distance + sizeSfr * row, distance + sizeSfr * col)));
		break;

	default:
		break;
	}
}

// Draws the background of the board and the moving and static objects.
void Board::drawBoard(sf::RenderWindow& window) const
{
	window.draw(m_background);
	for (int i = 0; i < m_StaticObject.size(); i++)
		m_StaticObject[i]->drawObject(window);

	for (int i = 0; i < m_MovingObject.size(); i++)
		m_MovingObject[i]->drawObject(window);
}

// Moves the objects and checks for collisions.
void Board::move(sf::Time deltaTime)
{
	if(!GameData::instance().getFreez()) // Checks if the ghosts are frozen and moves them if not.
		for (int i = 0; i < m_MovingObject.size(); i++)
			m_MovingObject[i]->move(m_MovingObject[m_pacman_index]->getPosition(), m_StaticObject, deltaTime);

	else // Otherwise only moves the pacman.
		m_MovingObject[m_pacman_index]->move(m_MovingObject[m_pacman_index]->getPosition(), m_StaticObject, deltaTime);

	// Checks if there is a collision between moving and static objects using handleCollision.
	for (int i = 0; i < m_MovingObject.size(); i++)
		for (int j = 0; j < m_StaticObject.size(); j++)
			if(m_MovingObject[i]->getGlobalBounds().intersects(m_StaticObject[j]->getGlobalBounds()))
				m_StaticObject[j]->handleCollision(*m_MovingObject[i]);

	// Checks for a collision between moving objects using handleCollision.
	for (int i = 0; i < m_MovingObject.size(); i++)
		for (int j = 0; j < m_MovingObject.size(); j++)
			if (m_MovingObject[i]->getGlobalBounds().intersects(m_MovingObject[j]->getGlobalBounds()))
				m_MovingObject[j]->handleCollision(*m_MovingObject[i]);
	// Checks if there is an object that needs to be deleted and deletes it.
	for (int i = 0; i < m_StaticObject.size(); i++)
		if (m_StaticObject[i]->isDisposed())
			m_StaticObject.erase(m_StaticObject.begin() + i);
}
// Level crossing.
void Board::nextLevel()
{
	levelLoading();
}
// End of life disqualification.
void Board::endOfTime()
{
	GameData::instance().endOfTime();
	levelLoading();
}
// Disqualification of end of time.
void Board::endOfLife()
{
	GameData::instance().endOfLife();
	levelLoading();
}
// Returns all objects to their initial position.
void Board::reset()
{
	for (auto& movingObject : m_MovingObject)
	{
		movingObject->reset();
	}
}
