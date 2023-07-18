#pragma once


enum OBJECTS {
	PACMAN, RANDOM_GHOST, DOOR, KEY, COOKIE, WALL, EXTRA_LIFE, EXTRA_TIME, FREEZING,
	SUPER_PACMAN_GIFT, SUPER_PACMAN, BOARD, SMART_GHOST, LESS_SMART_GHOST
};

enum MENU {
	 PLAY, HELP, EXIT, MUTE, OPENING_SCREEN, HELP_SCREEN, WIN, LOSE, NEXT_LEVEL, COLLISIONS
};

enum DATA {
	LEVEL, LIFE, POINTS, TIME
};

enum SOUND {
	DOOR_SUPER, GHOST_PACMAN, GHOST_SUPER, GIFT, KEY_S, COOKIE_S
};

const int Sound = 6;
const auto speedPerSecond = 100.f;
const int Data = 4;
const int distance = 100;
const int sizeObject = 512;
const int boardLength = 850;
const int boardWidth = 850;
const int windowLength = 1400;
const int windowWidth = 1050;
const int menuListSize = 4;
const int objects = 14;
const int menuObjects = 10;
const char font[50] = "C:/Windows/Fonts/HARLOWSI.ttf";


