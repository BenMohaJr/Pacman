

#include "Menu.h"

Menu::Menu() : m_window(sf::RenderWindow(sf::VideoMode(windowLength,
	windowWidth), "Pacman", sf::Style::Close | sf::Style::Titlebar))
{
	// Loading the backgrounds.
	m_background.setTexture(Resources::instance().getMenu(OPENING_SCREEN));
	m_background.setSize(sf::Vector2f(windowLength, windowWidth));
	m_helpScreen.setTexture(Resources::instance().getMenu(HELP_SCREEN));
	m_helpScreen.setSize(sf::Vector2f(windowLength, windowWidth));

	int tempRow = windowLength/3;
	int tempCol = windowWidth/6;
	
	// Loads the buttons.
	sf::Sprite tempSprite;
	tempSprite.setTexture(*Resources::instance().getMenu(PLAY));
	tempSprite.setScale(0.14, 0.14);
	tempSprite.setPosition(sf::Vector2f(tempRow, tempCol*4.5));
	m_menuList.push_back(tempSprite);
	
	tempSprite = sf::Sprite();
	tempSprite.setTexture(*Resources::instance().getMenu(HELP));
	tempSprite.setScale(1.40, 1.40);
	m_menuList.push_back(tempSprite);

	tempSprite = sf::Sprite();
	tempSprite.setTexture(*Resources::instance().getMenu(EXIT));
	tempSprite.setScale(1.40, 1.40);
	tempSprite.setPosition(sf::Vector2f(windowLength - 200, 20));
	m_menuList.push_back(tempSprite);

	tempSprite = sf::Sprite();
	tempSprite.setTexture(*Resources::instance().getMenu(MUTE));
	tempSprite.setPosition(sf::Vector2f(200, 20));
	m_menuList.push_back(tempSprite);
}

// Running in an infinite loop waiting for Event.
void Menu::runMenu()
{
	
	draw();
	while (m_window.isOpen())
	{
		if (auto event = sf::Event{}; m_window.waitEvent(event))
		{
			switch (event.type) {
			case sf::Event::Closed: {
				m_window.close();
				break;
			}
			case sf::Event::MouseButtonReleased: {
				clickLocation(event.mouseButton);
				draw();
				break;
			}
			}
		}
	}
}

// Checks whether the click was on one of the buttons.
void Menu::clickLocation(sf::Event::MouseButtonEvent buttonPressed)
{
	for (int i = 0; i < menuListSize; i++)
	{
		if (m_menuList[i].getGlobalBounds().contains(
			m_window.mapPixelToCoords({ buttonPressed.x, buttonPressed.y })))
		{
			switch (i)
			{
			case PLAY:
				m_window.clear();
				m_playGame.run(m_window);
				break;

			case HELP:
				drawHelp();
				break;

			case EXIT:
				m_window.close();
				break;

			case MUTE:
				Resources::instance().mute();
				break;

			default:
				break;
			}
		}
	}
}

// Draws the menu and the buttons.
void Menu::draw() {
	m_window.clear();

	m_window.draw(m_background);

	for (int i = 0; i < m_menuList.size(); i++) {
		m_window.draw(m_menuList[i]);
	}

	m_window.display();
}

// Draws the help and deletes to click the mouse.
void Menu::drawHelp() {
	m_window.clear();
	m_window.draw(m_helpScreen);
	m_window.display();

	auto event = sf::Event{};
	m_window.waitEvent(event);
	while (m_window.isOpen() && event.type != sf::Event::MouseButtonReleased)
	{
		if(event.type == sf::Event::Closed)
			m_window.close();
		m_window.waitEvent(event);
	}
}
