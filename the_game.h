#pragma once
#include "character_classes.h"
#ifndef the_game_h
#define the_game_h

class The_Game
{
	Player player;
	int current_location;
public:
	void after_fight_menu(int);
	The_Game();
	void choose_path(int, int);
	void game_proceed();
	void proceed_nochoice(int next);
	void game_save();
};

#endif