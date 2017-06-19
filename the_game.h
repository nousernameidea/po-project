#pragma once
#include "character_classes.h"
#ifndef the_game_h
#define the_game_h

class The_Game
{
	Player player;
	int current_location;
public:
	void after_fight_menu();
	The_Game(bool);
	void choose_path(int, int);
	void game_proceed(bool);
	void proceed_nochoice(int next);
	void game_save();
	bool room_fight(string, int, short);
	void found_item(string, int, int);
};

#endif