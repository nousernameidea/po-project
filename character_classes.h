#pragma once
#include "items.h"
#ifndef character_classes_h
#define character_classes_h

using namespace std;

int get_console_width();
void draw_line();
void clear_screen();
void entertocontinue(string aby);
void waitsec(short);


class Character
{
protected:
	string Name;
	int Level, Strength, Max_Hp, Current_Hp, Fatty, Dexterity;
	short room_placement;

public:
	/// <summary>
	/// Damage multiplier
	/// </summary>
	const int damage_multiplier = 5;

	Character();

	/// <summary>
	/// Initializes a new instance of the <see cref="Character"/> class.
	/// </summary>
	/// <param name="name">The name.</param>
	/// <param name="lvl">The level</param>
	/// <param name="placement">The placement.</param>
	/// /konstruktor przeciwnika
	Character(string name, int lvl, short placement);


	/// <summary>
	/// Returns character's name.
	/// </summary>
	/// <returns></returns>
	string get_Name();


	/// <summary>
	/// Sets character's name
	/// </summary>
	/// <param name="">The name.</param>
	void set_Name(string);
	
	/// <summary>
	/// Used when loading the game.
	/// </summary>
	/// <param name="value">The level.</param>
	void set_Level(int);
	
	/// <summary>
	/// Returns character's level.
	/// </summary>
	/// <returns></returns>
	int get_Level();
	
	/// <summary>
	/// Returns character's current localization.
	/// </summary>
	/// <returns></returns>
	short get_placement();
	
	/// <summary>
	/// Sets player placement when loading the game.
	/// </summary>
	/// <param name="dest">The dest.</param>
	void set_placement(short);

	/// <summary>
	/// Returns character's Strength attribute value.
	/// </summary>
	/// <returns></returns>
	int get_Strength();
	
	/// <summary>
	/// Used when loading the game.
	/// </summary>
	/// <param name="value">The value.</param>
	void set_Strength(int);
	
	/// <summary>
	/// Increases character's Strength by given value.
	/// </summary>
	/// <param name="change">The value.</param>
	void Strength_up(int change);

	/// <summary>
	/// Returns character's Fatty attribute value.
	/// </summary>
	/// <returns></returns>
	int get_Fatty();
	
	/// <summary>
	/// Used when loading the game.
	/// </summary>
	/// <param name="value">The value.</param>
	void set_Fatty(int);
	
	/// <summary>
	/// Increases character's Fatty by given value.
	/// </summary>
	/// <param name="change">The value.</param>
	void Fatty_up(int change);

	/// <summary>
	/// Returns character's current HP points.
	/// </summary>
	/// <returns></returns>
	int get_Current_Hp();
	
	/// <summary>
	/// Used when loading the game.
	/// </summary>
	/// <param name="value">The value.</param>
	void set_Current_Hp(int);
	
	/// <summary>
	/// Returns character's maximum HP value.
	/// </summary>
	/// <returns></returns>
	int get_Max_Hp();
	
	/// <summary>
	/// Sets the maximum HP according to character's Fatty.
	/// </summary>
	void set_Max_Hp();

	/// <summary>
	/// Used when loading the game.
	/// </summary>
	/// <param name="value">The value.</param>
	void load_Max_Hp(int);
	
	/// <summary>
	/// Prints character's Current HP / Maximum HP.
	/// </summary>
	void print_hp();

	/// <summary>
	/// Returns character's Dexterity attribute value.
	/// </summary>
	/// <returns></returns>
	int get_Dexterity();
	
	/// <summary>
	/// Used when loading the game.
	/// </summary>
	/// <param name="value">The value.</param>
	void set_Dexterity(int);
	
	/// <summary>
	/// Increases character's Dexterity by given value.
	/// </summary>
	/// <param name="change">The value.</param>
	void Dexterity_up(int change);

	void print_stats();

	/// <summary>
	/// Subtracts amount of taken damage from the specified .
	/// </summary>
	/// <param name="">Damage taken .</param>
	/// /odejmuje ustalona w walce ilosc zdrowia
	void attacked(int);


	/// <summary>
	/// Moves the enemy to 'death' localization
	/// </summary>
	void character_death();

};


class Player : public Character
{
protected:
	int Luck, Experience, Next_Level_Xp;
	vector <Item> Equipment;
public:
	
	/// <summary>
	/// Player resting multiplier
	/// </summary>
	const int rest_multiplier = 5;
	Player();

	/// <summary>
	/// Initializes a new instance of the <see cref="Player"/> class.
	/// </summary>
	/// <param name="lv">starting level.</param>
	/// 'Podstawowy' konstruktor postaci gracza, wywolywany przy nowej grze
	Player(int lv);
	
	/// <summary>
	/// Used only when loading the game/> class.
	/// </summary>
	/// <param name="loadname">The loadname.</param>	
	Player(string loadname);
	
	
	/// <summary>
	/// Copying constructor
	/// </summary>
	/// <param name="object">Player object.</param>
	Player(const Player& object)
	{
		this->operator=(object);
	}
	
	/// <summary>
	/// Operator =.
	/// </summary>
	/// <param name="object">The object.</param>
	/// <returns></returns>
	Player& operator=(const Player& object)
	{
		this->Name = object.Name;
		this->Level = object.Level;
		this->Experience = object.Experience;
		this->Equipment = object.Equipment;
		this->Next_Level_Xp = object.Next_Level_Xp;
		this->Strength = object.Strength;
		this->Fatty = object.Fatty;
		this->Max_Hp = object.Max_Hp;
		this->Current_Hp = object.Current_Hp;
		this->Dexterity = object.Dexterity;
		this->Luck = object.Luck;
		this->room_placement = object.room_placement;
		return *this;
	}

	/// <summary>
	/// Prints player statistics.
	/// </summary>
	void print_stats();
	
	
	/// <summary>
	/// Level +1, Fatty + 1 and add 1 attribute point to spend.
	/// </summary>
	void Level_up();
	
	/// <summary>
	/// Sets the next level xp.
	/// </summary>
	void Set_Next_Lvl_Xp();
	
	/// <summary>
	/// Moves the player to another localization.
	/// </summary>
	/// <param name="whereto">Where the player moves.</param>
	void move(int whereto);
	
	/// <summary>
	/// Heals Current HP by given value.
	/// </summary>
	/// <param name="value">The value.</param>
	void Current_Hp_heal(int value);
	
	/// <summary>
	/// Fully heals current HP.
	/// </summary>
	void Current_Hp_fullheal();
	
	/// <summary>
	/// Adds the item to equipment.
	/// </summary>
	/// <param name="">The item.</param>
	void add_item_to_eq(Item&);
	

	/// <summary>
	/// Used when loading the game.
	/// </summary>
	/// <param name="">Loaded item</param>
	void load_item_to_eq(Item&);
	
	/// <summary>
	/// Used when loading the game.
	/// </summary>
	/// <param name="">Item name</param>
	void add_item_load(string);
	
	/// <summary>
	/// Prints player's equipment.
	/// </summary>
	void print_equipment();

	/// <summary>
	/// Returns size of the equipment. Used to save the game.
	/// </summary>
	/// <returns></returns>
	size_t get_eq_size();

	/// <summary>
	/// Returns name of an item in equipment. Used to save the game.
	/// </summary>
	/// <param name="">Position of selected item in equipment.</param>
	/// <returns></returns>
	string get_eq_item_name(int);
	
	/// <summary>
	/// Returns ID of attribute boosted by selected item.
	/// </summary>
	/// <param name="">Position of selected item in equipment.</param>
	/// <returns></returns>
	int get_eq_item_attribute(int);

	/// <summary>
	/// Returns boost value of selected item.
	/// </summary>
	/// <param name="">Position of selected item in equipment.</param>
	/// <returns></returns>
	int get_eq_item_modifier(int);

	/// <summary>
	/// Returns value of Luck Attribute.
	/// </summary>
	/// <returns></returns>
	int get_Luck();
	
	/// <summary>
	/// Used when loading the game.
	/// </summary>
	/// <param name="value">The value.</param>
	void set_Luck(int);
	
	/// <summary>
	/// Returns amount of experience points.
	/// </summary>
	/// <returns></returns>
	int get_Exp();
	
	/// <summary>
	/// Used when loading the game.
	/// </summary>
	/// <param name="value">The value.</param>
	void set_Xp(int);
	
	/// <summary>
	/// Returns amount of experience points needed to reach next level.
	/// </summary>
	/// <returns></returns>
	int get_Next_Lvl_Exp();
	
	/// <summary>
	/// Increases Luck by given value.
	/// </summary>
	/// <param name="change">The change.</param>
	void Luck_up(int change);
	
	/// <summary>
	/// Increases experience points by given value.
	/// </summary>
	/// <param name="value">The value.</param>
	void Exp_Increase(int value);

	/// <summary>
	/// Moves player to "death" localization
	/// </summary>
	void player_death();

	/// <summary>
	/// Player attack method.
	/// </summary>
	/// <param name="">Attacked enemy.</param>
	void player_attack(Character&);

	/// <summary>
	/// Enemy attack method.
	/// </summary>
	/// <param name="">Attacking enemy.</param>
	void enemy_attack(Character&);

	/// <summary>
	/// Rest in combat, heals part of player's health
	/// </summary>
	/// /odpoczynek odnawia czesc zdrowia
	void player_rest();
	
	/// <summary>
	/// Combat method
	/// </summary>
	/// <param name="">The enemy.</param>
	/// <returns>Returns true if combat was won by player</returns>
	/// /drobna zmiana
	bool combat(Character&);
};

#endif