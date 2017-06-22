#pragma once
#include "character_classes.h"
#ifndef the_game_h
#define the_game_h


class The_Game
{
	Player player;
	int current_location;
public:

	/// <summary>
	/// Menu after every fight, where player can save the game, proceed without saving or exit.
	/// </summary>
	void after_fight_menu();
	
	/// <summary>
	/// Initializes a new instance of the <see cref="The_Game"/> class.
	/// </summary>
	/// <param name="">if set to <c>true</c> loads the game from .txt file.</param>
	The_Game(bool);

	/// <summary>
	/// Choosing whether to go left or right.
	/// </summary>
	/// <param name="">Left door.</param>
	/// <param name="">Right door.</param>
	void choose_path(int, int);
	
	/// <summary>
	/// After getting through room, proceed to next one.
	/// </summary>
	/// <param name="savegame">if set to <c>true</c>[game saves].</param>
	void game_proceed(bool);
	
	/// <summary>
	/// Proceeding in game without choice of next path.
	/// </summary>
	/// <param name="next">next room.</param>
	void proceed_nochoice(int next);
	
	/// <summary>
	/// Saves the game.
	/// </summary>
	void game_save();
	
	/// <summary>
	/// Basically, it's the fight which takes place in a particular room.
	/// It generates an enemy the player is going to fight. 
	/// </summary>
	/// <param name="">Enemy name</param>
	/// <param name="">Enemy level.</param>
	/// <param name="">Enemy localization.</param>
	/// <returns> returns true when player wins the combat</returns>
	bool room_fight(string, int, short);

	/// <summary>
	/// Generates an item and adds it to player's equipment.
	/// </summary>
	/// <param name="">Item name.</param>
	/// <param name="">Attribute boosted by item (I use const ints).</param>
	/// <param name="">Boost value.</param>
	void found_item(string, int, int);
};

#endif