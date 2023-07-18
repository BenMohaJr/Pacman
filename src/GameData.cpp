#include "GameData.h"
#include <string>
#include <iostream>
#include <sstream>

GameData::GameData() : m_level(1), m_life(3), m_points(0), m_time(120), m_freez(0), m_super(0), m_cookie(0), m_collisionseSound(true)
{
    // Loads the locations and the Font of the data.
    for (int i = 0; i < Data; i++)
    {
        auto result = sf::Text(m_text[i], *(Resources::instance().getFont()));
        result.setPosition(sf::Vector2f(boardLength + distance *1.5 , distance * (i*2 + 1)));
        result.setCharacterSize(90);
        result.setFillColor(sf::Color(218, 112, 214));
        result.setOutlineColor(sf::Color(150, 70, 150));
        result.setOutlineThickness(3);
        result.setStyle(sf::Text::Bold);
        m_textVector.push_back(result);
    }
}

GameData& GameData::instance()
{
	static GameData gameData;
	return gameData;
}
// Updates the data and draws it to the player.
void GameData::draw(sf::RenderWindow& window)
{
    if (m_timer.getElapsedTime().asSeconds() > 1)
    {
        m_time--;
        m_timer.restart();
        if (m_freez > 0)
            m_freez--;
        if (m_super > 0)
            m_super--;
    }
    std::stringstream temp;
    temp << m_text[LEVEL];
    temp << m_level;
    m_textVector[LEVEL].setString(temp.str().c_str());
    window.draw(m_textVector[LEVEL]);

    temp = std::stringstream("");
    temp << m_text[LIFE];
    temp << m_life;
    m_textVector[LIFE].setString(temp.str().c_str());
    window.draw(m_textVector[LIFE]);

    temp = std::stringstream("");
    temp << m_text[POINTS];
    temp << m_points;
    m_textVector[POINTS].setString(temp.str().c_str());
    window.draw(m_textVector[POINTS]);

    temp = std::stringstream("");
    temp << m_text[TIME];
    if(m_time / 60 < 10)
        temp << 0;
    temp << m_time / 60 << ":";
    if (m_time % 60 < 10)
        temp << 0;
    temp << m_time % 60;
    m_textVector[TIME].setString(temp.str().c_str());
    window.draw(m_textVector[TIME]);
}

// Mutes and unmutes the collisions.
void GameData::collisionseMute()
{
    if (m_collisionseSound)
        m_collisionseSound = false;
    else
        m_collisionseSound = true;
}

// Returns if the collisions are muted.
bool GameData::collisionseIsMute()
{
    return m_collisionseSound;
}

// Handles level crossing.
void GameData::nextLevel() {
    m_level++;
    m_time += 60;
}

// Handles the player's timeout disqualification.
void GameData::endOfTime()
{
    int temp;
    temp = (-1 * m_cookie);
    m_cookie += temp;
    temp = (-1 * m_life) + 3;
    m_life += temp;
    temp = (-1 * m_points);
    m_points += temp;
    temp = (-1 * m_time) + 120;
    m_time += temp;
    temp = (-1 * m_super);
    m_super += temp;
}
// Handles the player's life-ending disqualification.
void GameData::endOfLife()
{
    int temp;
    temp = (-1 * m_level) + 1;
    m_level += temp;
    temp = (-1 * m_cookie);
    m_cookie += temp;
    temp = (-1 * m_life) + 3;
    m_life += temp;
    temp = (-1 * m_points);
    m_points += temp;
    temp = (-1 * m_time) + 120;
    m_time += temp;
    temp = (-1 * m_freez);
    m_freez += temp;
}

// sets and getters for the data stored in dataGame.
int GameData::getLevel() const {
    return m_level;
}
int GameData::getCookie() const {
    return m_cookie;
}
int GameData::getLife() const{
    return m_life;
}
int GameData::getPoints() const {
    return m_points;
}
int GameData::getTime() const {
    return m_time;
}
int GameData::getFreez() const {
    return m_freez;
}
int GameData::getSuper() const {
    return m_super;
}
void GameData::setCookie(int num) {
    m_cookie += num;
}
void GameData::setLife(int num) {
    m_life += num;
}
void GameData::setPoints(int num) {
   m_points += num;
}
void GameData::setTime(int num) {
   m_time += num;
}
void GameData::setFreez(int num) {
   m_freez += num;
}
void GameData::setSuper(int num) {
   m_super += num;
}

// resets the clock.
void GameData::restart()
{
    m_timer.restart();
}
