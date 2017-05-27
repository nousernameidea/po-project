#pragma once
#ifndef character_classes.h
#define character_classes.h

using namespace std;

class Character	//postac i przeciwnicy
{
protected:
	string Name;
	int Level, Strength, Max_Hp, Current_Hp, Fatty, Dexterity;

public:
	Character();

	Character(string name, int lvl);

	string get_Name() { return this->Name; }

	int get_Level();

	int get_Strength();
	void Strength_up(int change);

	int get_Fatty();
	void Fatty_up(int change);

	int get_Current_Hp();
	int get_Max_Hp();
	void set_Max_Hp();

	int get_Dexterity();
	void Dexterity_up(int change);

	void print_stats();

};

class Player : public Character
{
protected:
	int Luck, Experience;
public:
	Player();
	void print_stats();
	void Level_up();
	void Current_Hp_heal(int value);
	void Current_Hp_fullheal();
	int get_Luck();
	void Luck_up(int change);
	void Exp_Increase(int value);
};

#endif character_classes.h
