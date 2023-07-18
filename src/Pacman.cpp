#include "ObjectsInc/Pacman.h"

Pacman::Pacman(double sizeScale, sf::Vector2f position, std::function<void()> func)
	: MovingObject(PACMAN, sizeScale, position), m_resetMovingObj(func)
	, m_PacmanState(std::make_unique<NormalPacman>()) {
	m_object.setOrigin(sf::Vector2f(m_object.getTexture()->getSize() / 2u));
	m_giftSound.setBuffer(*Resources::instance().getSound(GIFT));
	m_keySound.setBuffer(*Resources::instance().getSound(KEY_S));
	m_cookieSound.setBuffer(*Resources::instance().getSound(COOKIE_S));
}

// Pacman's motion function.
void Pacman::move(sf::Vector2f pacmanLocation, std::vector<std::unique_ptr<StaticObject>> &StaticObject, sf::Time deltaTime)
{
	m_PacmanState->ChangeOfState(*this); // Checks if state needs to be changed and if so it changes.
	sf::Vector2f direction;

	// Checks which direction the user wants to go and updates the data accordingly.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if(m_object.getScale().x > 0)
			m_object.scale(-1, 1);
		m_object.setRotation(0);
		direction = sf::Vector2f(-1, 0);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (m_object.getScale().x < 0)
			m_object.scale(-1, 1);
		m_object.setRotation(0);
		direction = sf::Vector2f(1, 0);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (m_object.getScale().x > 0)
			m_object.setRotation(90);
		else
			m_object.setRotation(270);
		direction = sf::Vector2f(0, 1);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (m_object.getScale().x > 0)
			m_object.setRotation(270);
		else
			m_object.setRotation(90);
		direction = sf::Vector2f(0, -1);
	}

	relocate(direction, deltaTime);
}

// The function moves the pacman and makes sure it goes between the sides of the board.
void Pacman::relocate(sf::Vector2f direction, sf::Time deltaTime)
{
	m_lastLocation = m_object.getPosition();
	
	// Updating the location.
	m_object.move(direction * speedPerSecond * deltaTime.asSeconds());
	
	// Checks if the new location does not exceed the board and handles if so.

	auto row = m_object.getPosition().x;
	auto col = m_object.getPosition().y;

	if (row > distance + boardWidth - ((sizeObject * m_object.getScale().y) / 2))
		row = distance + ((sizeObject * m_object.getScale().y) / 2);
	else if (row < distance + ((sizeObject * m_object.getScale().y) / 2))
		row = boardWidth + distance - ((sizeObject * m_object.getScale().y) / 2);
	if (col > distance + boardLength - ((sizeObject * m_object.getScale().y) / 2))
		col = distance + ((sizeObject * m_object.getScale().y) / 2);
	else if (col < distance + ((sizeObject * m_object.getScale().y) / 2))
		col = boardLength + distance - ((sizeObject * m_object.getScale().y) / 2);

	m_object.setPosition(sf::Vector2f(row, col));
}

// Updating the state for Super Pacman.
void Pacman::upgradeToSuper() 
{
	m_object.setTexture(*Resources::instance().getObjects(SUPER_PACMAN));
	m_PacmanState.reset(new SuperPacman());
}
// Updating the state for Pacman.
void Pacman::downgradeToNormal() 
{
	m_object.setTexture(*Resources::instance().getObjects(PACMAN));
	m_PacmanState.reset(new NormalPacman());
}
// Updates the Pacman's position to the last position.
void Pacman::dontMove()
{
	m_object.setPosition(m_lastLocation);
}

//Double Dispatch.
void Pacman::handleCollision(Object& gameObject)
{
	gameObject.handleCollision(*this);
}
void Pacman::handleCollision(Wall& gameObject)
{
	dontMove();
}
void Pacman::handleCollision(Cookie& gameObject)
{
	if (GameData::instance().collisionseIsMute())
		m_cookieSound.play();
	GameData::instance().setCookie(-1);
	gameObject.Dispose();
	GameData::instance().setPoints(2);
}
void Pacman::handleCollision(Key& gameObject)
{
	if (GameData::instance().collisionseIsMute())
		m_keySound.play();
	gameObject.Dispose();
	GameData::instance().setPoints(7);
}
void Pacman::handleCollision(ExtraLifeGift& gameObject)
{
	if (GameData::instance().collisionseIsMute())
		m_giftSound.play();
	gameObject.Dispose();
	GameData::instance().setPoints(5);
	GameData::instance().setLife(1);
}
void Pacman::handleCollision(ExtraTimeGift& gameObject)
{
	if (GameData::instance().collisionseIsMute())
		m_giftSound.play();
	gameObject.Dispose();
	GameData::instance().setPoints(5);
	GameData::instance().setTime(20);
}
void Pacman::handleCollision(FreezingGift& gameObject)
{
	if (GameData::instance().collisionseIsMute())
		m_giftSound.play();
	gameObject.Dispose();
	GameData::instance().setPoints(5);
	GameData::instance().setFreez(20);
}
void Pacman::handleCollision(SuperPacmanGift& gameObject)
{
	if(GameData::instance().collisionseIsMute())
		m_giftSound.play();
	gameObject.Dispose();
	GameData::instance().setPoints(5);
	GameData::instance().setSuper(20);
}

//Double Dispatch that depends on the state of the player.
void Pacman::handleCollision(Door& gameObject)
{
	m_PacmanState->handleDoorCollision(*this, gameObject);
}
void Pacman::handleCollision(Ghost& gameObject)
{
	m_PacmanState->handleGhostCollision(gameObject, m_resetMovingObj);
}

