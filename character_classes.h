#pragma once
#include "items.h"
#ifndef character_classes.h
#define character_classes.h

using namespace std;

int get_console_width();
void draw_line();


class Character	//postac i przeciwnicy
{
protected:
	string Name;
	int Level, Strength, Max_Hp, Current_Hp, Fatty, Dexterity;
	short room_placement;

public:
	const int damage_multiplier = 5;

	Character();

	Character(string name, int lvl, short placement);

	string get_Name() { return this->Name; }

	int get_Level();
	short get_placement();

	int get_Strength();
	void Strength_up(int change);

	int get_Fatty();
	void Fatty_up(int change);

	int get_Current_Hp();
	int get_Max_Hp();
	void set_Max_Hp();
	void print_hp();

	int get_Dexterity();
	void Dexterity_up(int change);

	void print_stats();
	void attacked(int);

	void character_death();

};

class Player : public Character
{
protected:
	int Luck, Experience;
	vector <Item> Equipment;
public:
	const int rest_multiplier = 5;
	Player();
	void print_stats();
	void Level_up();
	void move(short whereto);
	void Current_Hp_heal(int value);
	void Current_Hp_fullheal();
	void add_item_to_eq(Item&);
	void print_equipment();
	int get_Luck();
	void Luck_up(int change);
	void Exp_Increase(int value);
	void player_death();
	void player_attack(Character&);
	void enemy_attack(Character&);
	void player_rest();
	void combat(Character&);
};

#endif character_classes.h
