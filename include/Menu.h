#pragma once
#include "const.h"
#include "GameControl.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Resources.h"

class Menu
{
public:
	Menu();
	void runMenu();
	void draw();
	void drawHelp();
	void clickLocation(sf::Event::MouseButtonEvent buttonPressed);

private:
	sf::RenderWindow m_window;

	sf::RectangleShape m_background;
	sf::RectangleShape m_helpScreen;

	std::vector <sf::Sprite> m_menuList;
	GameControl m_playGame;

};
