#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>

#include "character_classes.h"

using namespace std;

int get_console_width() 
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	return columns;
}
void draw_line()
{
	for (int i = 0; i < get_console_width(); i++)
	{
		cout << "#";
	}
}

	Character::Character()
	{
		this->Level = 1;
	}

	Character::Character(string name, int lvl)
	{
		int AttributePoints = 10 + lvl;				//punkty do wydania na cechy: dla lvl 1: 10 + 1
		this->Fatty = rand() % AttributePoints;									
		AttributePoints -= this->Fatty;
		this->Strength = rand() % AttributePoints;
		AttributePoints -= this->Strength;
		this->Dexterity = rand() % AttributePoints;
		AttributePoints -= this->Dexterity;

		this->Fatty += AttributePoints;				//jesli z losowania cos zostalo to reszta idzie w zdrowie
		this->set_Max_Hp();
	}

	string Character::get_Name() { return this->Name; }
	int Character::get_Level() { return this->Level; }
	int Character::get_Strength() { return this->Strength; }
	void Character::Strength_up(int change) { this->Strength += change; }
	int Character::get_Fatty() { return this->Fatty; }
	void Character::Fatty_up(int change) 
	{
		this->Fatty += change;
		set_Max_Hp();
	}
	int Character::get_Current_Hp() { return this->Current_Hp; }
	int Character::get_Max_Hp() { return this->Max_Hp; }
	void Character::set_Max_Hp() { this->Max_Hp = 100 + ((this->Fatty) * 10); }
	int Character::get_Dexterity() { return this->Dexterity; }
	void Character::Dexterity_up(int change) { this->Dexterity += change; }

	void Character::print_stats()
	{
		cout << "\n" << get_Name();
		cout << "\nPoziom = " << get_Level();
		cout << "\nMasa&Rzezba = " << get_Strength();
		cout << "\nTluszczyk = " << get_Fatty();
		cout << "\nZdrowie = " << get_Current_Hp()<<"/"<< get_Max_Hp();
		cout << "\nSpryt = " << get_Dexterity();
		draw_line();
	}

	Player::Player()
	{
		int StartingAttributePoints = 10 + this->Level;
		int tempFat, tempStr, tempDex, tempLuck;

		cout << endl;
		draw_line();
		cout << "\nWitaj w kreatorze postaci!"
			<< "\n\nPodaj imie swojego bohatera:		";
		cin >> this->Name;
		cout << "Masz dokladnie " << StartingAttributePoints << " wolnych punktow cech. Wydaj je madrze!"
			<< "\nDostepne cechy to:\n1.Masa&Rzezba: Okresla stopien napakowania studenciaka, a co za tym idzie - sile"
			<< "\n2. Tluszczyk: Jak wszyscy wiedza, im wiecej kochanego cialka tym mniej bolu zadaja ciosy. Wplywa na maksymalna zywotnosc bohatera\n3. Spryt: W zyciu trzeba byc cwanym, spryt zwieksza szanse na unikniecie ciosu"
			<< "\n4. Fart: Wplywa na skutecznosc ataku, szanse na unik oraz na korzystne wylosowanie terminu zapisow"
			<< "\n\nIle punktow przeznaczysz na mase&rzezbe?	";
		cin >> tempStr;
		this->Strength = 1 + tempStr;
		StartingAttributePoints -= (this->Strength) - 1;
		cout << "Pozostalo " << StartingAttributePoints << " wolnych punktow"
			<< "\nIle punktow przeznaczysz na tluszczyk?	";
		cin >> tempFat;
		this->Fatty = 1 + tempFat;
		this->set_Max_Hp();
		StartingAttributePoints -= (this->Fatty) - 1;
		cout << "Pozostalo " << StartingAttributePoints << " wolnych punktow"
			<< "\nIle punktow przeznaczysz na spryt?	";
		cin >> tempDex;
		this->Dexterity = 1 + tempDex;
		StartingAttributePoints -= (this->Strength) - 1;
		cout << "Pozostalo " << StartingAttributePoints << " wolnych punktow"
			<< "\nNa farta pozostalo cale " << StartingAttributePoints << " punktow";
		this->Luck = 1 + StartingAttributePoints;
		StartingAttributePoints -= (this->Luck) - 1;

		draw_line();
		cout << "\nPostac stworzona:\n";
		print_stats();
	}

	void Player::print_stats()
	{
		cout << "\n" << get_Name() << ":";
		cout << "\nPoziom = " << get_Level();
		cout << "\nMasa&Rzezba = " << get_Strength();
		cout << "\nTluszczyk = " << get_Fatty();
		cout << "\nZdrowie = " << get_Current_Hp() << "/" << get_Max_Hp();
		cout << "\nSpryt = " << get_Dexterity();
		cout << "\nFart = " << get_Luck();
		draw_line();
	}

	void Player::Current_Hp_heal(int value)
	{
		this->Current_Hp += value;
	}

	void Player::Current_Hp_fullheal() { this->Current_Hp = this->Max_Hp; }

	void Player::Level_up() 
	{ 
		this->Level++;
		this->Strength_up(1);
		this->Fatty_up(1);
		this->Dexterity_up(1);
		this->Luck_up(1);
	}
	int Player::get_Luck() { return this->get_Luck; }
	void Player::Luck_up(int change) { this->Luck += change; }
	void Player::Exp_Increase(int value) { this->Experience += value; }
