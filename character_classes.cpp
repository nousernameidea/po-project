#include "stdafx.h"
#include "character_classes.h"
#include "items.h"

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
	cout << "\n";
	for (int i = 0; i < get_console_width(); i++)
	{
		cout << "#";
	}
	cout << "\n";
}

void clear_screen()
{
	cout << string(100, '\n');
}

	Character::Character()
	{
		this->Level = 1;
	}

	Character::Character(string name, int lvl, short placement)
	{
		this->room_placement = placement;
		int AttributePoints = 10 + lvl;				//punkty do wydania na cechy: dla lvl 1: 10 + 1
		this->Fatty = lvl + rand() % AttributePoints;									
		AttributePoints -= this->Fatty;
		this->Strength = lvl + rand() % AttributePoints;
		AttributePoints -= this->Strength;
		this->Dexterity = lvl + rand() % AttributePoints;
		AttributePoints -= this->Dexterity;

		this->Fatty += AttributePoints;				//jesli z losowania cos zostalo to reszta idzie w zdrowie
		this->set_Max_Hp();
		this->Current_Hp = this->Max_Hp;
	}

	string Character::get_Name() { return this->Name; }
	int Character::get_Level() { return this->Level; }
	short Character::get_placement() {return this->room_placement;}
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
	void Character::print_hp() { cout << "\nPoziom zdrowia " << get_Name() << ": " << get_Current_Hp() << "/" << get_Max_Hp(); }
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

	void Character::attacked(int damage_taken)
	{
		this->Current_Hp -= damage_taken;
	}

	void Character::character_death()
	{
		//this->room_placement = HELL;
		this->Current_Hp = 0;
		this->Max_Hp = 0;
		this->Strength = 0;
		this->Dexterity = 0;
		this->Fatty = 0;
		this->Name = "I'M DEAD. LEAVE ME ALONE.";
	}

	Player::Player()
	{
		this->Level = 1;
		this->room_placement = 1;
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
			<< "\n4. Fart: Wplywa na skutecznosc ataku, szanse na unik oraz na korzystne wylosowanie terminu zapisow";
		bool validchoice;
		do
		{
			cout << "\n\nIle punktow przeznaczysz na mase&rzezbe?	";
			cin >> tempStr;
				
			if (tempStr <= StartingAttributePoints)
			{
				this->Strength = 1 + tempStr;
				StartingAttributePoints -= (this->Strength) - 1;
				validchoice = true;
			}
			else 
			{
				cout << "\nTo troche za duzo. Przestan smieszkowac.";
				validchoice = false;
			}

		} while (!validchoice);
		cout << "Pozostalo " << StartingAttributePoints << " wolnych punktow";
			do
			{
				cout << "\nIle punktow przeznaczysz na tluszczyk?	";
				cin >> tempFat;

				if (tempFat <= StartingAttributePoints)
				{
					this->Fatty = 1 + tempFat;
					this->set_Max_Hp();
					this->Current_Hp_fullheal();
					StartingAttributePoints -= (this->Fatty) - 1;
					validchoice = true;
				}
				else
				{
					cout << "\nPozostalo za malo punktow atrybutow!";
					validchoice = false;
				}
			} while (!validchoice);

			cout << "Pozostalo " << StartingAttributePoints << " wolnych punktow";
			do
			{
				cout << "\nIle punktow przeznaczysz na spryt?	";
				cin >> tempDex;

				if (tempDex <= StartingAttributePoints)
				{
					this->Dexterity = 1 + tempDex;
					StartingAttributePoints -= (this->Dexterity) - 1;
					validchoice = true;
				}
				else
				{
					cout << "\nPozostalo za malo punktow atrybutow!";
					validchoice = false;
				}
			} while (!validchoice);

		cout << "\nNa farta pozostalo cale " << StartingAttributePoints << " punktow";
		this->Luck = 1 + StartingAttributePoints;
		StartingAttributePoints -= (this->Luck) - 1;

		draw_line();
		cout << "\nPostac stworzona:\n";
		print_stats();
		cout << "\n\nNacisnij Enter aby rozpoczac przygode!";
		cin.ignore();
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
		if (this->Current_Hp > this->Max_Hp) { this->Current_Hp = this->Max_Hp; }
	}

	void Player::Current_Hp_fullheal() { this->Current_Hp = this->Max_Hp; }

	void Player::add_item_to_eq(Item& added_item)
	{
		this->Equipment.push_back(added_item);
		int tempAttr = added_item.get_Item_Attribute();
		cout << "\n\nZnalazles " << added_item.get_item_Name() << "!\n";
			switch (tempAttr)
			{
			case Attribute_Strength:
				cout << "Masa&Rzezba +" << added_item.get_item_modifier << "\n";
				int tempMod = added_item.get_item_modifier;
				this->Strength_up(tempMod);
				break;
			case Attribute_Fatty:
				cout << "Tluszczyk +" << added_item.get_item_modifier << "\n";
				int tempMod = added_item.get_item_modifier;
				this->Fatty_up(tempMod);
				break;
			case Attribute_Dexterity:
				cout << "Spryt +" << added_item.get_item_modifier << "\n";
				int tempMod = added_item.get_item_modifier;
				this->Dexterity_up(tempMod);
				break;
			case Attribute_Luck:
				cout << "Fart +" << added_item.get_item_modifier << "\n";
				int tempMod = added_item.get_item_modifier;
				this->Luck_up(tempMod);
				break;
			}
	}

	void Player::print_equipment()
	{
		draw_line();
		int eq_size = this->Equipment.size;
		cout << "Twoj ekwipunek:\n";
			for(size_t i = 0;i<eq_size;i++)
			{ 
				cout << i + 1 << ". " << this->Equipment[i].get_item_Name;
			}
	}

	void Player::Level_up() 
	{ 
		this->Level++;
		this->Fatty_up(1);

		cout << "\n\nAwansowales na poziom " << get_Level() << "!"
			<< "\nWybierz atrybut (numer), ktory chcesz podniesc: "
			<< "\n1. Masa&Rzezba\n2. Spryt\n3. Fart";
		short choice;
		bool valid;
		
		do
		{
			cin >> choice;
			switch (choice)
			{
			case 1:
				this->Strength_up(1);
				cout << "Zwiekszono Mase&Rzezbe";
				valid = true;
				break;
			case 2:
				this->Dexterity_up(1);
				cout << "Zwiekszono Spryt";
				valid = true;
				break;
			case 3:
				this->Luck_up(1);
				cout << "Zwiekszono Fart";
				valid = true;
				break;
			default:
				cout << "Niepoprawny wybor! Wybierz wartosc z przedzialu {1,2,3}";
				valid = false;
				break;
			}
		} while (!valid);
	}
	void Player::move(short whereto) { this->room_placement = whereto; }
	int Player::get_Luck() { return this->get_Luck; }
	void Player::Luck_up(int change) { this->Luck += change; }
	void Player::Exp_Increase(int value) { this->Experience += value; }
	void Player::player_death()
	{
		//this->move(HELL);
	}
	void Player::player_attack(Character& enemy)
	{
		int enemy_dodge_success, critical_success, damage;
		int tempLuck = this->get_Luck();
		int tempStr = this->get_Strength();
		int tempEnemyDex = enemy.get_Dexterity();

		enemy_dodge_success = rand() % 100 + 1 + tempEnemyDex;
		critical_success = rand() % 100 + 1 + tempLuck;

		cout << "\n\nAtakujesz wroga!";
		Sleep(1000);
		if (enemy_dodge_success < 70)										// kryterium uniku przeciwnika
		{
			if (critical_success >= 80)										//kryterium zadania krytyka
			{
				damage = tempStr * 10;
				cout << "\nTrafienie krytyczne!"
					<< "\nZadales " << damage << "obrazen"
					<< "\nTo musialo zabolec...";
			}
			else
			{
				damage = (rand() % tempStr + 1)*damage_multiplier;
				cout << "\nZadales " << damage << "obrazen";
			}
		}
		else
		{
			cout << "\nPrzeciwnik uniknal ataku!";
			damage = 0;
		}
		enemy.attacked(damage);												//odjecie zadanych obrazen
	}

	void Player::enemy_attack(Character &enemy)
	{
		int player_dodge_success, damage;
		int tempLuck = this->get_Luck();
		int tempStr = enemy.get_Strength();
		int tempDex = this->get_Dexterity();

		player_dodge_success = rand() % 100 + 1 + tempDex + tempLuck;

		cout << "\n\n" << enemy.get_Name << " atakuje!";
		Sleep(1000);
		if (player_dodge_success < 70)										// kryterium uniku gracza
		{
			damage = (rand() % tempStr + 1)*damage_multiplier;
			cout << "\nOtrzymales " << damage << "obrazen";
		}
		else cout << "\nUdalo ci sie uniknac ataku!";
		this->attacked(damage);
	}

	void Player::player_rest()
	{
		int tempFat = this->get_Fatty();
		int Hp_Max = this->get_Max_Hp();
		int Max_Heal = ((Hp_Max / 2) - 5 * tempFat);
		int Hp_heal;
		cout << "\nRobisz krok w tyl aby na ulamek sekundy odpoczac od trudnej walki";
		Sleep(2000);
		Hp_heal = (rand() % Max_Heal + 1) + 5 * tempFat;
		this->Current_Hp_heal(Hp_heal);
	}

	void Player::combat(Character &enemy)
	{
		draw_line();
		cout << "\nRozpoczyna sie walka z "<< enemy.get_Name() <<"!";
		Sleep(1000);
		do
		{
			draw_line();
			cout << "\nZdrowie przeciwnika: " << enemy.get_Current_Hp();
			cout << "\nTwoje zdrowie: " << this->get_Current_Hp() << "\n\n"
				<< "Co robisz?\n"
				<< "1. Atak\n"
				<< "2. Odpoczynek\n";
			short decision;
			bool valid;											//to samo rozwiazanie co przy level up
			do
			{
				cin >> decision;
				switch (decision)
				{
				case 1:
					Sleep(1000);
					this->player_attack(enemy);
					valid = true;
					break;
				case 2:
					Sleep(1000);
					this->player_rest();
					valid = true;
					break;
				default:
					cout << "Niepoprawny wybor! Wybierz wartosc z przedzialu {1,2}";
					valid = false;
					break;
				}
			} while (!valid);

			this->enemy_attack(enemy);										//przeciwnik atakuje zawsze, po graczu

		} while ( (this->get_Current_Hp()>1) || (enemy.get_Current_Hp()>1) );
		
		if (enemy.get_Current_Hp() < 1)
		{
			enemy.character_death();
			//proceed...
		}
		else if (this->get_Current_Hp() < 1)
		{
			this->player_death();
		}
	}


