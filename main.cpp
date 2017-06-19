// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "items.h"
#include "character_classes.h"
#include "the_game.h"


int main()
{
	srand(time(NULL));

	draw_line();
	cout << "Student w Krainie Czarow"
		<< "\nMateusz Adamczyk, 235834"
		<< "\nProgramowanie Obiektowe -> Projekt\n";
	draw_line();
	
	short startchoice;
	bool validstart;

	do
	{
		cout << "\t\t\t\tMenu glowne";
		cout << "\n\n1. Nowa gra"
			 << "\n2. Wczytaj gre"
			 << "\n3. Koniec gry\t\t";
		cin >> startchoice;
		switch (startchoice)
		{
			case 1:
			{
				cout << "\n\n\t\t\t\tNowa gra\n";
				waitsec(3);
				The_Game new_game(false);
				break; 
			}
			case 2:
			{
				cout << "\n\n\t\t\t\tWczytywanie...";
				waitsec(3);
				The_Game load_game(true);
				break;
			}
		case 3:
		{
			entertocontinue("zakonczyc...");
			exit(0);
			break;
		}
		default:
		{
			cout << "\nNieprawidlowy wybor! Wybierz wartosc z przedzialu {1,2,3}";
			validstart = false;
			break;
		}
		}
	} while (!validstart);
	
	
	/*
	Player test1(1);
	Character enemy1("maly pedal", 1, ENTRANCE);
	enemy1.print_stats();
	bool testinio = test1.combat(enemy1);
	test1.print_stats();
	enemy1.print_stats();

	Character enemy2("ciota", 2, ENTRANCE);
	test1.combat(enemy2);
	test1.print_stats();
	entertocontinue("kontynuowac");
	*/

	entertocontinue("zakonczyc dzialanie gry");
	return 0;
}

