#include "GameControl.h"
#include "GameData.h"

GameControl::GameControl()
{
	// Loads the backgrounds and the mute button.
	m_mute.setTexture(*Resources::instance().getMenu(MUTE));
	m_mute.setPosition(sf::Vector2f(windowLength - 150, 20));
	m_collisionse.setTexture(*Resources::instance().getMenu(COLLISIONS));
	m_collisionse.setScale(0.15, 0.15);
	m_collisionse.setPosition(sf::Vector2f(windowLength - 250, 20));
	m_background.setTexture(Resources::instance().getObjects(WALL));
	m_background.setSize(sf::Vector2f(windowLength, windowWidth));
	m_backgroundWin.setTexture(Resources::instance().getMenu(WIN));
	m_backgroundWin.setSize(sf::Vector2f(windowLength, windowWidth));
	m_backgroundLose.setTexture(Resources::instance().getMenu(LOSE));
	m_backgroundLose.setSize(sf::Vector2f(windowLength, windowWidth));
	m_nextLevel.setTexture(Resources::instance().getMenu(NEXT_LEVEL));
	m_nextLevel.setSize(sf::Vector2f(windowLength, windowWidth));
}

// Runs in a loop and checks if the game won or lost and checks events.
void GameControl::run(sf::RenderWindow& window)
{
	window.setFramerateLimit(60);
	bool isEsc = false;
	GameData::instance().restart();
	sf::Clock clock;

    while (window.isOpen() && !isEsc)
    {
		draw(window);
		if (GameData::instance().getCookie() == 0){// Level crossing.
			
			if (Resources::instance().maxLevel() == GameData::instance().getLevel()) {
				loseOrWin(window, isEsc, true);
				m_board.endOfLife();
			}
			else
				nextLevel(window);
		}
		if (!GameData::instance().getLife()) {// Disqualification of life.
			m_board.endOfLife();
			loseOrWin(window, isEsc, false);
			clock.restart();
		}
		if (!GameData::instance().getTime()) {// disqualification of time.
			m_board.endOfTime();
			loseOrWin(window, isEsc, false);
			clock.restart();
		}
		for (auto event = sf::Event(); window.pollEvent(event);) // checks events.
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonReleased: {
				if (m_mute.getGlobalBounds().contains(
					window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y })))
					Resources::instance().mute();
				else if (m_collisionse.getGlobalBounds().contains(
					window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y })))
					GameData::instance().collisionseMute();
				break;
			}

			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
				{
					isEsc = true;
				}
				break;
			}
		}
		const auto deltaTime = clock.restart();		
		m_board.move(deltaTime);// Move the moving objects.
    }
}
// Handles a level crossing board.
void GameControl::nextLevel(sf::RenderWindow& window)
{
	GameData::instance().nextLevel();
	window.clear();
	window.draw(m_nextLevel);
	window.display();
	m_board.nextLevel();

	auto event = sf::Event{};
	window.waitEvent(event);
	while (window.isOpen() && event.type != sf::Event::MouseButtonReleased)
	{
		window.waitEvent(event);
		if (event.type == sf::Event::Closed)
			window.close();
	}
}
// Handles the board of disqualification.
void GameControl::loseOrWin(sf::RenderWindow& window, bool &isEsc, bool win)
{
	window.clear();
	if (win)
		window.draw(m_backgroundWin);
	else
		window.draw(m_backgroundLose);
	window.display();
	bool stop = false;
	while (window.isOpen() && !isEsc && !stop)
	{
		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed: {
				window.close();
				break;
				}
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					isEsc = true;
				else if (event.key.code == sf::Keyboard::Enter)
					stop = true;
				break;
			}
		}
	}
}

// Draws the background and the mute button and the board and the dadaGame.
void GameControl::draw(sf::RenderWindow& window)
{
	window.clear();
	window.draw(m_background);
	window.draw(m_mute);
	window.draw(m_collisionse);
	m_board.drawBoard(window);
	GameData::instance().draw(window);
	window.display();
}