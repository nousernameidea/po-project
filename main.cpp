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
				validstart = true;
				break; 
			}
			case 2:
			{
				cout << "\n\n\t\t\t\tWczytywanie...";
				waitsec(3);
				The_Game load_game(true);
				validstart = true;
				break;
			}
		case 3:
		{
			entertocontinue("zakonczyc...");
			exit(0);
			validstart = true;
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
	
	return 0;
}

