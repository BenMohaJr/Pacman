#pragma once

#include <iostream>
#include "const.h"
#include <string>
#include <SFML/Graphics.hpp>
#include "Resources.h"


class GameData
{
public:
	~GameData() = default;
	static GameData& instance();
	void draw(sf::RenderWindow& window);
	void collisionseMute();
	bool collisionseIsMute();
	void nextLevel();
	void endOfTime();
	void endOfLife();
	int getLevel() const;
	int getCookie() const;
	int getLife() const;
	int getPoints() const;
	int getTime() const;
	int getFreez() const;
	int getSuper() const;
	void setCookie(int num);
	void setLife(int num);
	void setPoints(int num);
	void setTime(int num);
	void setFreez(int num);
	void setSuper(int num);
	void restart();

private:
	GameData();
	GameData(const GameData&) = delete;
	GameData& operator=(const GameData&) = delete;

	std::string m_text[4] = { "LEVEL: " , "LIFE: " , "POINTS: " , "TIME: " };
	int m_level;
	int m_life;
	int m_points;
	int m_time;
	int m_freez;
	int m_super;
	int m_cookie;
	bool m_collisionseSound;
	std::vector<sf::Text> m_textVector;
	sf::Clock m_timer;
};
