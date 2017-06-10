// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "items.h"
#include "character_classes.h"
#include "the_game.h"

/*DO ZROBIENIA POZOSTALO:
	zapis/wczytywanie gry
	fabula
	przebieg rozgrywki
*/

/*
The_Game game_load()
{
	//do zrobienia
}*/

int main()
{
	srand(time(NULL));

	draw_line();
	cout << "Student w Krainie Czarow"
		<< "\nMateusz Adamczyk, 235834"
		<< "\nProgramowanie Obiektowe -> Projekt\n";
	draw_line();
	Sleep(2000);
	/*
	short startchoice;
	bool validstart;

	do
	{
		cout << "\n\n1. Nowa gra"
			 << "\n2. Wczytaj gre"
			 << "\n3. Koniec gry\t\t";
		cin >> startchoice;
		switch (startchoice)
		{
		case 1:
			cout << "\n\nNowa gra\n";
			The_Game new_game();
			break;
		case 2:
			//game_load();
			break;
		case 3:
			entertocontinue("zakonczyc...");
			exit(0);
			break;
		default:
			cout << "\nNieprawidlowy wybor! Wybierz wartosc z przedzialu {1,2,3}";
			validstart = false;
			break;
		}
	} while (!validstart);
	*/

	return 0;
}

