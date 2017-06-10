#include "stdafx.h"
#include "the_game.h"

void The_Game::after_fight_menu(int pathsafter)
{
	draw_line();
	short choice;
	bool valid;
	cout << "Kolejna meczaca walka za toba."
		 << "\nCo chcesz teraz zrobic?"
		 << "\n\n1. Idziesz dalej"
		 << "\n2. Zapis i kontynuacja gry"
		 << "\n3. Zapis i wyjscie z gry"
		 << "\n4. Wyjscie bez zapisu\t\t\t";
	do
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
			Sleep(2000);
			this->game_proceed();
			break;
		case 2:
			Sleep(1000);
			this->game_save();
			entertocontinue("kontynuowac...");
			Sleep(1000);
			this->game_proceed();
			break;
		case 3:
			Sleep(1000);
			this->game_save();
			entertocontinue("zakonczyc...");
			exit(0);
			break;

		case 4:
			entertocontinue("zakonczyc...");
			Sleep(2000);
			exit(0);
			break;

		default:
			cout << "\nNieprawidlowy wybor, wybierz wartosc z przedzialu {1,2,3,4,}\t";
			valid = false;
			break;
		}
	} while (!valid);

	draw_line();
}

The_Game::The_Game()
{
	Player player1(1);
	this->player = player1;
	/*
	if (this->player.get_placement() != HELL)
	{
		
	}*/
}

void The_Game::choose_path(int left, int right)
{
	char choice;
	bool validchoice;
	cout << "\n\nPrzed toba dwa przejscia"
		<< "\n Ktore z nich wybierzesz?";
	
	do
	{
		cout << "\nWpisz 'L' zeby pojsc w lewo lub 'P' aby wybrac prawe przejscie\n";
		cin >> choice;
		switch (choice)
		{
		case 'L':
		case 'l':
			cout << "\nWybierasz sciezke w lewo. Oby byla wlasciwa.";
			Sleep(1000);
			this->player.move(left);
			validchoice = true;
			break;
		
		case 'P':
		case 'p':
			cout << "\nWybierasz sciezke w prawo. Oby byla wlasciwa.";
			Sleep(1000);
			this->player.move(right);
			validchoice = true;
			break;

		default:
			cout << "\nNiepoprawny wybor!";
			validchoice = false;
			break;
		}
	} while (!validchoice);
}

void The_Game::game_proceed()
{
	int whereami = this->player.get_placement();
	switch (whereami)
	{
														///pomieszczenia bez wyboru
	case ENTRANCE:
		draw_line();
		cout << "Przed toba dluga droga...";
			Sleep(1000);
			this->player.move(C1);
		draw_line();
		break;
	case CL1:
		Sleep(1000);
		draw_line();
		this->proceed_nochoice(CL2);
		draw_line();
		break;
	case CR1:
		Sleep(1000);
		draw_line();
		this->proceed_nochoice(CR2);
		draw_line();
		break;
	case CL3:
		Sleep(1000);
		draw_line();
		this->proceed_nochoice(CL4);
		draw_line();
		break;
	case CL4:
	case CCL1:
	case CCR1:
	case CR4:
		Sleep(1000);
		draw_line();
		this->proceed_nochoice(PRE_BOSS);
		draw_line();
		break;
	case PRE_BOSS:
		Sleep(1000);
		draw_line();
		cout << "Idziesz przed siebie, przetrwales juz zbyt wiele by teraz sie poddac";
		Sleep(1000);
		cout << "\nCzujesz unoszace sie w powietrzu strach i zimno";
		Sleep(1000);
		cout << "\nPrzed toba koniec drogi. Pora na ostatni wysilek...";
		Sleep(500);
		draw_line();
		this->player.move(BOSS);
		break;
													///pomieszczenia z wyborem dalszej drogi
	case C1:
		Sleep(1000);
		draw_line();
		this->choose_path(CL1, CL2);
		draw_line();
		break;
	case CL2:
		Sleep(1000);
		draw_line();
		this->choose_path(CL3, CC1);
		draw_line();
		break;
	case CR2:
		Sleep(1000);
		draw_line();
		this->choose_path(CC1, CR3);
		draw_line();
		break;
	case CC1:
		Sleep(1000);
		draw_line();
		this->choose_path(CCL1, CCR1);
		draw_line();
		break;
	case CR3:
		Sleep(1000);
		draw_line();
		this->choose_path(CCR1, CR4);
		draw_line();
		break;
	}
}

void The_Game::proceed_nochoice(int next)
{
	cout << "\nPrzed toba kolejny tunel. Kiedy ten koszmar sie skonczy?";
	this->player.move(next);
	Sleep(500);
}

void The_Game::game_save()
{
	//do zrobienia
}
