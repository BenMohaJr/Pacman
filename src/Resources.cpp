#include "Resources.h"

// The Resources class that handles all the objects that we want to load only once

Resources::Resources()
{
	char font[50] = "C:/Windows/Fonts/FREESCPT.TTF";
	m_font.loadFromFile(font);

	for (int i = 0; i < objects; i++)
		m_textureObjects[i].loadFromFile(m_imagesName[i]);

	for (int i = 0; i < menuObjects; i++)
		m_textureMenu[i].loadFromFile(m_menuImagesName[i]);

	for (int i = 0; i < Sound; i++)
		m_SoundArr[i].loadFromFile(m_SoundName[i]);

	readingLevel();

	m_gameMusic.openFromFile("game.wav");
	m_gameMusic.play();
}

// Returns a pointer to the variable we want to initialize.
Resources& Resources::instance()
{
	static Resources resources;
	return resources;
}

// Returns a pointer to the texture of an object.
sf::Texture* Resources::getObjects(int index)
{
	return &(m_textureObjects[index]);
}

// Returns a pointer to the texture of an Menu object.
sf::Texture* Resources::getMenu(int index)
{
	return &(m_textureMenu[index]);
}

// Returns a pointer to the Buffer of an Sound.
sf::SoundBuffer* Resources::getSound(int index)
{
	return &(m_SoundArr[index]);
}

// // Returns a pointer to the Font of an text.
sf::Font* Resources::getFont()
{
	return &m_font;
}

// Opens the file that contains the levels and reads all the steps into a vector of levels.
void Resources::readingLevel()
{
	auto my_file = std::ifstream ("levels.txt");
	if (!my_file.is_open()) {
		exit(EXIT_FAILURE);
	}
	int row, col;
	char tempChar;

	my_file >> m_levels;
	for (int level = 0; level < m_levels; level++)
	{
		std::vector<std::vector<char>> tempLevel; // A temporary step that will enter the vector.
		my_file >> row >> col;
		my_file.get();
		for (int i = 0; i < row; i++)
		{
			std::vector<char> tempRow; // A temporary line that will enter the tempLevel
			for (int j = 0; j < col; j++)
			{
				my_file.get(tempChar);
				tempRow.push_back(tempChar);
			}
			tempLevel.push_back(tempRow);
			my_file.get();
		}
		m_vectorOfLevel.push_back(tempLevel);
	}
	my_file.close();
}

// Returns a char that is in the level in the row and col that you received.
char Resources::getChar(int level, int row, int col) const
{
	return m_vectorOfLevel[level][row][col];
}

// Returns the last Level.
int Resources::maxLevel() const
{
	return m_levels;
}

// Returns the max row in the level.
int Resources::maxRow(int level) const
{
	return m_vectorOfLevel[level].size();
}

// Returns the max col in the level.
int Resources::maxCol(int level) const
{
	return m_vectorOfLevel[level][1].size();
}

// Returns whether the user muted the music.
bool Resources::isMute() const {
	return m_mute;
}

// Mute or unmute the music.
void Resources::mute() {
	if (m_mute) {
		m_mute = false;
		m_gameMusic.play();
	}
	else {
		m_mute = true;
		m_gameMusic.pause();
	}
}