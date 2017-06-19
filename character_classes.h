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

	string get_Name();
	void set_Name(string);
	
	void set_Level(int);
	int get_Level();
	
	short get_placement();
	void set_placement(short);

	int get_Strength();
	void set_Strength(int);
	void Strength_up(int change);

	int get_Fatty();
	void set_Fatty(int);
	void Fatty_up(int change);

	int get_Current_Hp();
	void set_Current_Hp(int);
	int get_Max_Hp();
	void set_Max_Hp();
	void load_Max_Hp(int);
	void print_hp();

	int get_Dexterity();
	void set_Dexterity(int);
	void Dexterity_up(int change);

	void print_stats();
	void attacked(int);

	void character_death();

};

class Player : public Character
{
protected:
	int Luck, Experience, Next_Level_Xp;
	vector <Item> Equipment;
public:
	const int rest_multiplier = 5;
	Player();
	Player(int lv);
	Player(string loadname);
	Player(const Player& object) 
	{
		this->operator=(object);
	}
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
	void print_stats();
	void Level_up();
	void Set_Next_Lvl_Xp();
	void move(int whereto);
	void Current_Hp_heal(int value);
	void Current_Hp_fullheal();
	void add_item_to_eq(Item&);
	void load_item_to_eq(Item&);
	void add_item_load(string);
	void print_equipment();
	size_t get_eq_size();
	string get_eq_item_name(int);
	int get_eq_item_attribute(int);
	int get_eq_item_modifier(int);
	int get_Luck();
	void set_Luck(int);
	int get_Exp();
	void set_Xp(int);
	int get_Next_Lvl_Exp();
	void Luck_up(int change);
	void Exp_Increase(int value);
	void player_death();
	void player_attack(Character&);
	void enemy_attack(Character&);
	void player_rest();
	bool combat(Character&);						///drobna zmiana
};

#endif
