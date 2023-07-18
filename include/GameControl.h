#pragma once
#include "const.h"
#include "Board.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


class GameControl
{
public:
    GameControl();
	~GameControl() {}
    void run(sf::RenderWindow& window);
    void nextLevel(sf::RenderWindow& window);
    void loseOrWin(sf::RenderWindow& window, bool& isEsc, bool win);
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape m_background;
    sf::RectangleShape m_backgroundWin;
    sf::RectangleShape m_backgroundLose;
    sf::RectangleShape m_nextLevel;
    sf::Sprite m_mute;
    sf::Sprite m_collisionse;
    Board m_board;
};