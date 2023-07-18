#pragma once
#include <iostream>
#include "const.h"
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Resources
{
public:
	~Resources() = default;
	static Resources& instance();
	sf::Texture* getObjects(int);
	sf::Texture* getMenu(int index);
	sf::SoundBuffer* getSound(int index);
	sf::Font* getFont();
	char getChar(int level, int row, int col) const;
	int maxLevel() const;
	int maxRow(int level) const;
	int maxCol(int level) const;
	bool isMute() const;
	void mute();

private:
	Resources();
	Resources(const Resources&) = delete;
	Resources& operator=(const Resources&) = delete;
	void readingLevel();

	std::string m_imagesName[objects]{ "pacman.png", "RandomGhost.png", "door.png", "key.png", "cookie.png","Wall.png", "ExtraLifeGift.png"
		, "ExtraTimeGift.png", "FreezingGift.png", "SuperPacmanGift.png", "SuperPacman.png", "board.png","SmartGhost.png", "LessSmartGhost.png" };
	std::string m_menuImagesName[menuObjects]{ "play.png", "help.png", "exit.png", "mute.png", "opening screen.jpg", "help screen.png", "win.png", "Lose.png", "nextLevel.png", "collisions.png" };
	sf::Texture m_textureObjects[objects];
	sf::Texture m_textureMenu[menuObjects];
	sf::Music m_gameMusic;
	std::string m_SoundName[Sound] = { "doorVsSuper.wav" ,"GhostVsPacman.wav" ,"GhostVsSuperPacman.wav" ,"gift.wav" ,"key.wav" ,"Cookie.wav"};// ,"menu.wav" ,"game.wav"};
	sf::SoundBuffer m_SoundArr[Sound];
	sf::Font m_font;
	std::vector <std::vector<std::vector<char>>> m_vectorOfLevel;
	bool m_mute;
	int m_levels;
};
