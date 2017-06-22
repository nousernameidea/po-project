#include "stdafx.h"
#include "the_game.h"

void The_Game::after_fight_menu()
{
	draw_line();
	short choice;
	bool valid;
	this->player.print_stats();
	cout << "Chwila wytchnienia...";
	
	do
	{
	cout << "\n\nCo chcesz teraz zrobic?"
		 << "\n\n1. Pokaz ekwipunek"
		 << "\n2. Idziesz dalej bez zapisu"
		 << "\n3. Zapis i kontynuacja gry"
		 << "\n4. Wyjscie z gry\t\t\t";

		cin >> choice;
		switch (choice)
		{
		case 1:
			this->player.print_equipment();
			valid = false;
			break;
		case 2:
			Sleep(2000);
			this->game_proceed(false);
			valid = true;
			break;
		case 3:
			Sleep(1000);	
			this->game_proceed(true);
			Sleep(1000);
			entertocontinue("kontynuowac...");
			valid = true;
			break;
		case 4:
			entertocontinue("zakonczyc...");
			Sleep(2000);
			exit(0);
			break;

		default:
			cout << "\nNieprawidlowy wybor, wybierz wartosc ze zbioru {1,2,3,4,5}\t";
			valid = false;
			break;
		}
	} while (!valid);

	draw_line();
}

The_Game::The_Game(bool loadgame)
{
	if (loadgame == true)
	{
		ifstream file;
		file.open("save.txt", ios::in);
		if (file.is_open())
		{
			string tempname;
			getline(file, tempname);
			Player player1(tempname);
			
			int tempLvl, tempXp, tempStr, tempFat, tempCurHp, tempMaxHp, tempDex, tempLuck;
			string loadItemName;
			int loadItemAttribute, loadItemModifier;
			size_t tempEqSize;
			short tempLoc;
			file >> tempLvl;
			player1.set_Level(tempLvl);
			file >> tempLoc;
			player1.set_placement(tempLoc);
			file >> tempXp;
			player1.set_Xp(tempXp);
			file >> tempStr;
			player1.set_Strength(tempStr);
			file >> tempDex;
			player1.set_Dexterity(tempDex);
			file >> tempFat;
			player1.set_Fatty(tempFat);
			file >> tempLuck;
			player1.set_Luck(tempLuck);
			file >> tempCurHp;
			player1.set_Current_Hp(tempCurHp);
			file >> tempMaxHp;
			player1.load_Max_Hp(tempMaxHp);
			file >> tempEqSize;
			file.ignore(100,'\n');
			for (size_t i = 0; i < tempEqSize; i++)
			{
				getline(file, loadItemName);
				player1.add_item_load(loadItemName);

			}
			file.close();
			cout << "\n\nWczytanie zakonczone sukcesem";
			this->player = player1;
			this->player.Set_Next_Lvl_Xp();
			this->player.print_stats();
			this->player.print_equipment();
		}
		else
		{
			cerr << "\n\nBlad przy otwarciu pliku";
			entertocontinue("zakonczyc");
			exit(0);
		}
	}
	else
	{
		Player player1(1);
		this->player = player1;
	}
	
	bool exit_game;
	do
	{
		short localization;
		do
		{
		localization = this->player.get_placement();
		if (localization != HELL)
		{
			switch (localization)
			{
			case ENTRANCE:
				waitsec(3);
				cout << "Budzisz sie. Otwierasz oczy, ale nie widzisz niczego poza ciemnoscia.";
				waitsec(2);
				cout << "Dopiero po chwili wzrok przyzwyczaja sie do znikomej ilosci swiatla."
					 << "\nNie poznajesz miejsca, w ktorym sie znajdujesz.";
				Sleep(2000);
				cout << "\nPomieszczenie wyglada jak loch, nie ma w nim niczego procz starych drzwi"
					<< "\nTo chyba niemozliwe, aby gdziekolwiek w twoim akademiku bylo az tak...";
				Sleep(2000);
				cout << "\nmrocznie, brudno i...";
				Sleep(2000);
				cout << "\n...i strasznie.";
				waitsec(2);
				cout << "Odwracasz sie i dostrzegasz tablice z napisem:"
					 << "\n\n\t\t\t\tLOCH DEFICYTUSA";
				waitsec(3);
				cout << "Decydujesz sie przejsc przez drzwi. Musisz wrocic do domu.";
				Sleep(1000);
				cout << "\nW koncu lada moment sesja.";
				entertocontinue("wyruszyc");
				this->game_proceed(false);
				exit_game = false;
				break;
			case C1:
				exit_game = false;
				waitsec(3);
				cout << "Przechodzisz przez drzwi. Oczom twym ukazuje sie mala puchata kulka";
				Sleep(2000);
				cout << "\nKulka okazuje sie byc malym, samotnym kotkiem.";
				entertocontinue("stanac do walki");
				if (this->room_fight("Slodki, puchaty, malutki kotek", 1, C1) == true)
				{
					waitsec(2);
					cout << "Przeszukujesz pozostalosci po przeciwniku...";
					waitsec(3);
					cout << "Lecz niczego nie znajdujesz. Szkoda.";
					entertocontinue("przejsc do menu");
					after_fight_menu();
					break;
				}
				else break;
			case C1_Choice:
				game_proceed(false);
				break;
			case CL1:
				exit_game = false;
				//#################################
				waitsec(1);
				cout << "Decydujesz sie wybrac lewe drzwi.";
				waitsec(3);
				cout << "Wchodzisz do pomieszczenia, w ktorym, o dziwo, tez jest ciemno."
					<< "\nRozni sie ono jednak od poprzedniego.";
				Sleep(2000);
				cout << "\nW tym ewidentnie smierdzi siarka.";
				waitsec(3);
				cout << "W jednej chwili podloga zaczyna sie palic";
				Sleep(2000);
				cout << "\nZ ziemi wynurza sie niezbyt pokojowo nastawiony demon.";
				entertocontinue("stanac do walki");
				//#################################
				if (this->room_fight("Milczacy Demon", 2, CL1) == true)
				{
					waitsec(2); 
					cout << "Przeszukujesz pozostalosci po przeciwniku...";
					waitsec(3);
					cout << "Lecz niczego nie znajdujesz. Szkoda.";
					entertocontinue("przejsc do menu");
					after_fight_menu();
					break;
				}
				else break;
			
			case CR1:
				exit_game = false;
				//##################################
				waitsec(1);
				cout << "Decydujesz sie wybrac prawe drzwi.";
				waitsec(3);
				cout << "Pomieszczenie jest slabo, ale przynajmniej jakkolwiek oswietlone.";
				Sleep(2000);
				cout << "\nZ konca sali dobiega ciche stukanie... "
					 << "\nZblizasz sie w kierunku zrodla dzwieku.";
				waitsec(3);
				cout << "O nie!, to wyjatkowo chudy szkielet!";
				entertocontinue("stanac do walki");
				//##################################
				if (this->room_fight("Chudy szkielet", 2, CR1) == true)
				{
					waitsec(2);
					cout << "Przeszukujesz pozostalosci po przeciwniku...";
					found_item("Adidaski wichury", Attribute_Dexterity, 2);
					after_fight_menu();
					break;
				}
				else break;
			case CL2:
				exit_game = false;
				//##################################
				waitsec(1);
				cout << "Demon zapowiadal sie na nieco silniejszego przeciwnika.";
				Sleep(1000);
				cout << "No coz, widocznie nie taki diabel straszny.";
				waitsec(3);
				cout << "Tymczasem przechodzisz do kolejnego pomieszczenia."
					 << "\nSiedzi w nim czlowiek, wyglada dosc groznie";
					waitsec(3);
				cout << "Zreszta, w tym miejscu kazdy wyglada groznie... ";
				Sleep(2000);
				cout << "\nOprocz tamtego malego kotka, nieprawdaz?";

				entertocontinue("stanac do walki z niebezpiecznym przybyszem ze Wschodu");
				//##################################
				if (this->room_fight("Turrorysta", 3, CL2) == true)
				{
					waitsec(2);
					cout << "Przeszukujesz pozostalosci po przeciwniku...";
					found_item("Kebab", Attribute_Fatty, 3);
					after_fight_menu();
					break;
				}
				else break;
			case CL2_Choice:
				game_proceed(false);
				break;
			case CR2:
				exit_game = false;
				//##################################
				waitsec(1);
				cout << "Na twojej drodze staje mroczny elf.";
				waitsec(2);
				cout << "Probujesz zapytac go gdzie jestescie i jak stad wyjsc";
				waitsec(2);
				cout << "Niestety, okazuje sie, ze elfy nie do konca znaja jezyk polski";
				Sleep(2000);
				cout << "\nDo tego mina elfa wskazuje na to,"
					 << " ze fraza 'Przepraszam, jak stad wyjsc?' w jego jezyku jest bardzo obrazliwa";
				Sleep(3000);
				cout << "\n...i powoduje natychmiastowy atak ze strony rozmowcy.";
				entertocontinue("stanac do walki");
				//##################################
				if (this->room_fight("Bardzo mroczny elf", 3, CR2) == true)
				{
					waitsec(2);
					cout << "Przeszukujesz pozostalosci po przeciwniku...";
					waitsec(3);
					cout << "Lecz niczego nie znajdujesz. Szkoda.";
					entertocontinue("przejsc do menu");
					after_fight_menu();
					break;
				}
				else break;
			case CR2_Choice:
				game_proceed(false);
				break;
			case CL3:
				exit_game = false;
				//##################################
				waitsec(1);
				cout << "Stajesz przed Rewolwerowcem";
				Sleep(2000);
				cout << "\nWyglada na dosyc wyrewolwerowanego.";
				waitsec(1);
				entertocontinue("stanac do walki");
				//##################################
				if (this->room_fight("Wyrewolwerowany Rewolwerowiec", 4, CL3) == true)
				{
					waitsec(2);
					cout << "Przeszukujesz pozostalosci po przeciwniku...";
					found_item("Wyrewolwerowany rewolwer", Attribute_Strength, 2);
					after_fight_menu();
					break;
				}
				else break;
			case CC1:
				exit_game = false;
				//##################################
				waitsec(1);
				cout << "W pomieszczeniu, do ktorego wlasnie wszedles, znajduje sie jedynie..";
				Sleep(2000);
				cout << "\n...doniczkowa roslinka...";
				Sleep(2000);
				cout << "\n...wielka";
				Sleep(2000);
				cout << "\n...i wyraznie glodna.";
				entertocontinue("stanac do walki");
				//##################################
				if (this->room_fight("Gustowna doniczkowa roslinka", 5, CC1) == true)
				{
					waitsec(2);
					cout << "Przeszukujesz pozostalosci po przeciwniku...";
					found_item("Konewka z kwasem", Attribute_Strength, 5);
					after_fight_menu();
					break;
				}
				else break;
			case CC1_Choice:
				game_proceed(false);
				break;
			case CR3:
				exit_game = false;
				//##################################
				waitsec(1);
				cout << " -Czesc! - slyszysz.";
				waitsec(2);
				cout << "Kierujesz wzrok w strone zrodla glosu.";
				Sleep(2000);
				cout << "\nCoz... Nie wyglada groznie.";
				waitsec(2);
				cout << " -Podoba ci sie moja gra? - pyta";
				waitsec(2);
				cout << "Zgodnie z prawda mowisz, ze jest beznadziejna";
				Sleep(2000);
				cout << "\nNie wyraziles zgody na zamkniecie cie w lochu.";
				Sleep(2000);
				cout << "\nI chcesz natychmiast wyjsc.";
				waitsec(3);
				cout << " -Taaaak? W takim razie NIGDY STAD NIE WYJDZIESZ BUHAHAHA!";
				waitsec(2);
				cout << "Decydujesz, ze zabicie tego smieszka nie zaszkodzi.";
				entertocontinue("stanac do walki");
				//##################################
				if (this->room_fight("Niesmieszny tworca tej gry", 4, CR3) == true)
				{
					waitsec(2);
					cout << "To byla wyjatkowo prosta walka.";
					Sleep(1000);
					cout << "\nAle czego innego mozna bylo sie spodziewac po tym gosciu?";
					Sleep(2000);
					cout << "\nMoze chociaz mial cos ciekawego?";
					found_item("Ogromny, ciezki, niepraktyczny miecz, typowy dla chinskich bajek i gier", Attribute_Strength, 4);
					after_fight_menu();
					break;
				}
				else break;
			case CR3_Choice:
				game_proceed(false);
				break;
			case CL4:
				exit_game = false;
				//##################################
				waitsec(1);
				cout << "Nieznana czarna magia sprawia, ze w tym pomieszczeniu...";
				Sleep(2000);
				cout << "...brudna woda stoi do kolan i nie wylewa sie za drzwi";
				waitsec(3);
				cout << "Po chwili juz wiesz, co, czy raczej kto jest zrodlem tej magii.";
				waitsec(2);
				cout << "To Cthulhu.";
				entertocontinue("stanac do walki");
				//##################################
				if (this->room_fight("Cthulhu", 5, CL4) == true)
				{
					waitsec(2);
					found_item("Lepkie macki potwora", Attribute_Dexterity, 3);
					after_fight_menu();
					break;
				}
				else break;
			case CCL1:
				exit_game = false;
				//##################################
				waitsec(3);
				cout << "Przechodzisz przez drzwi." 
					 << "\nOczom twym ukazuje sie ogromny talerz spaghetti z klopsikami";
				waitsec(2);
				cout << "Nagle zawartosc talerza... zaczyna sie poruszac?!";
				Sleep(2000);
				cout << "\nNie spodziewales sie, ze cokolwiek jeszcze cie tu zaskoczy.";
				Sleep(2000);
				cout << "\nA jednak. Przed toba unosi sie Latajacy Potwor Spaghetti";
				Sleep(2000);
				cout << "\nWyglada na to, ze zapowiada sie wyjatkowo trudny pojedynek."
					 << "\nNie walczyles przeciez jeszcze z bogiem.";
				waitsec(3);
				cout << "Potwor jednak... nie atakuje?";
				waitsec(2);
				cout << " -Daj spokoj, stary - mowi"
					 << "\n -Po co mielibysmy walczyc? Myslisz ze nie przepuszcze cie dalej?";
				Sleep(2000);
				cout << "\nZanosi sie poteznym lecz przyjaznym smiechem.";
				waitsec(2);
				cout << " -Tak w sumie to mam nawet cos, co mogloby ci sie przydac...";
				Sleep(2000);
				cout << "\nHmm, tak, nada sie. Sprawdz kieszenie. Powodzenia.";
				waitsec(2);
				cout << "Potwor znika.";
				Sleep(1000);
				cout << "\nTo milo z jego strony, ze jako jedyny w tym chorym miejscu nie chcial cie zabic.";
				Sleep(2000);
				entertocontinue("przeszukac kieszenie...");

				found_item("Ekskluzywny Amulet Wyznawcy Latajacego Potwora Spaghetti", Attribute_Luck, 5);
				after_fight_menu();
				break;
				//##################################
				
			case CCR1:
				exit_game = false;
				//##################################
				waitsec(1);
				cout << "Otwierasz kolejne drzwi";
				waitsec(2);
				cout << "Twoje oczy widza znajome ogrodniczki..";
				Sleep(2000);
				cout << "\nZnajoma czerwona czapke...";
				Sleep(2000);
				cout << "\n...i znajome wasy.";
				waitsec(3);
				cout << "Mario? Czy to ty? Czy to naprawde ty?";
				waitsec(3);
				cout << "Oczy Mario blyszcza... na czerwono.";
				Sleep(2000);
				cout << "\nTo nie jest juz ten sam przyjazny hydraulik.";
				Sleep(2000);
				cout << "\nTo Demoniczny Mario.";
				entertocontinue("stanac do walki");
				//##################################
				if (this->room_fight("Demoniczny Mario", 5, CCR1) == true)
				{
					waitsec(2);
					cout << "Przeszukujesz pozostalosci po przeciwniku...";
					waitsec(3);
					cout << "Lecz niczego nie znajdujesz. Szkoda.";
					entertocontinue("przejsc do menu");
					after_fight_menu();
					break;
				}
				else break;
			case CR4:
				exit_game = false;
				//##################################
				waitsec(3);
				cout << "Przechodzisz spokojnie przez pomieszczenie, gdy nagle...";
				waitsec(3);
				cout << " -Hej, czy wiesz ze mozesz osiagnac wszystko?";
				Sleep(2000);
				cout << "\nO nie... Nawet tutaj?";
				waitsec(2);
				cout << " -Moge wskazac ci droge!";
				waitsec(2);
				cout << "Niechetnie prosisz zatem o wskazanie drogi do wyjscia";
				waitsec(3);
				cout << " -Noo... Nie wiem w sumie jak stad wyjsc.";
				Sleep(2000);
				cout << "\n  Ale dzieki moim lekcjom sam wskazesz sobie droge!";
				Sleep(2000);
				cout << "\n  Dla ciebie w promocyjnej cenie 149.90!";
				waitsec(3);
				cout << "Nie potrzebujesz dodatkowej motywacji.";
				entertocontinue("stanac do walki");
				//##################################
				if (this->room_fight("Fanatyk coachingu", 5, CR4) == true)
				{
					waitsec(2);
					found_item("Calkowicie darmowy anulet rozwoju osobistego", Attribute_Luck, 1);
					after_fight_menu();
					break;
				}
				else break;
			case PRE_BOSS:
				exit_game = false;
				//##################################
				waitsec(1);
				cout << "Przechodzisz przez drzwi";
				waitsec(2);
				cout << "W pomieszczeniu wyczuwasz potezna magie.";
				Sleep(2000);
				cout << "\nPrzed toba stoi mroczny mag.";
				waitsec(2);
				cout << " -Czekalem na ciebie - mowi.";
				Sleep(2000);
				cout << "\n  Chcesz stad wyjsc, prawda?";
				waitsec(2);
				cout << "Niesmialo potwierdzasz.";
				waitsec(2);
				cout << " -W takim razie mam dla ciebie zle wiesci.";
				Sleep(2000);
				cout << "\n  Bedziesz mnie musial najpierw pokonac.";
				Sleep(2000);
				cout << "\n  A ja nie zamierzam sie poddac.";
				entertocontinue("stanac do walki");
				//##################################
				if (this->room_fight("Mroczny mag Deficytus", 10, PRE_BOSS) == true)
				{
					waitsec(2);
					cout << "Przeszukujesz pozostalosci po przeciwniku...";
					waitsec(3);
					cout << "Lecz niczego nie znajdujesz. Szkoda.";
					entertocontinue("przejsc do menu");
					after_fight_menu();
					break;
				}
				else break;
				break;
			case BOSS:
				exit_game = false;
				//##################################
				waitsec(1);
				cout << "Przed toba prawdopodobnie ostatnia prosta.";
				Sleep(2000);
				cout << "\nNiepewnie przechodzisz przez wielkie drzwi...";
				waitsec(3);
				cout << "To jakis zart?";
				Sleep(2000);
				cout << "\n Puszysty kroliczek?";
				waitsec(3);
				cout << "Ale po chwili juz wiesz, co to za kroliczek.";
				Sleep(2000);
				cout << "\nZ jego malutkich oczek wycieka nienawisc i mord.";
				Sleep(2000);
				cout << "\nWyglada na to, ze znali sie z kotkiem z pierwszego pomieszczenia.";
				waitsec(2);
				cout << "Musisz walczyc o zycie!";
				entertocontinue("stanac do walki");
				//##################################
				if (this->room_fight("MORDERCZY, SADYSTYCZNY, KRWAWY PUCHATY KROLICZEK", 15, BOSS) == true)
				{
					waitsec(2);
					cout << "Nareszcie... Juz po wszystkim.";
					entertocontinue("kontynuowac");
					this->game_proceed(false);
					break;
				}
				else break;
			case WIN:
				waitsec(2);
				cout << "\t\t\tGRATULACJE"
					 << "\n\nUdalo ci sie wydostac z Lochu Deficytusa";
				waitsec(3);
				cout << "A teraz szybko do nauki, wszak nadchodzi sesja!";
				entertocontinue("zakonczyc");
				exit_game = true;
				break;
			default:
				break;
			}
		}
		else
			{
				waitsec(2);
				clear_screen();
				cout << "\t\t\tGAME OVER.";
				waitsec(2);
				entertocontinue("zakonczyc");
				exit_game = true;
			}
		} while ((localization != HELL) && (localization != WIN));
	} while (exit_game = false);
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

void The_Game::game_proceed(bool save)
{
	if (save == true) game_save();
	int whereami = this->player.get_placement();
	switch (whereami)
	{
														///pomieszczenia bez wyboru
	case ENTRANCE:
		cout << "\nPrzed toba dluga droga...";
			Sleep(1000);
			if (save == true) game_save();
			this->player.move(C1);
		//draw_line();
		break;
	case CL1:
		Sleep(1000);
		draw_line();
		this->proceed_nochoice(CL2);
		if (save == true) game_save();
		//draw_line();
		break;
	case CR1:
		Sleep(1000);
		draw_line();
		this->proceed_nochoice(CR2);
		if (save == true) game_save();
		//draw_line();
		break;
	case CL3:
		Sleep(1000);
		draw_line();
		this->proceed_nochoice(CL4);
		if (save == true) game_save();
		//draw_line();
		break;
	case CL4:
		Sleep(1000);
		draw_line();
		this->proceed_nochoice(PRE_BOSS);
		if (save == true) game_save();
		//draw_line();
		break;
	case CCL1:
		Sleep(1000);
		draw_line();
		this->proceed_nochoice(PRE_BOSS);
		if (save == true) game_save();
		//draw_line();
		break;
	case CCR1:
		Sleep(1000);
		draw_line();
		this->proceed_nochoice(PRE_BOSS);
		if (save == true) game_save();
		//draw_line();
		break;
	case CR4:
		Sleep(1000);
		draw_line();
		this->proceed_nochoice(PRE_BOSS);
		if (save == true) game_save();
		//draw_line();
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
		if (save == true) game_save();
		break;
	case BOSS:
		this->player.move(WIN);
		break;
											///pomieszczenia z wyborem dalszej drogi
	case C1:
		this->player.move(C1_Choice);
	case C1_Choice:
		if (save == true) game_save();
		Sleep(1000);
		draw_line();
		this->choose_path(CL1, CR1);
		//draw_line();
		break;
	case CL2:
		this->player.move(CL2_Choice);
	case CL2_Choice:
		if (save == true) game_save();
		Sleep(1000);
		draw_line();
		this->choose_path(CL3, CC1);
		//draw_line();
		break;
	case CR2:
		this->player.move(CR2_Choice);
	case CR2_Choice:
		if (save == true) game_save();
		Sleep(1000);
		draw_line();
		this->choose_path(CC1, CR3);
		//draw_line();
		break;
	case CC1:
		this->player.move(CC1_Choice);
	case CC1_Choice:
		if (save == true) game_save();
		Sleep(1000);
		draw_line();
		this->choose_path(CCL1, CCR1);
		//draw_line();
		break;
	case CR3:
		this->player.move(CR3_Choice);
	case CR3_Choice:
		if (save == true) game_save();
		Sleep(1000);
		draw_line();
		this->choose_path(CCR1, CR4);
		//draw_line();
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
	ofstream file;
	file.open("save.txt", ios::out);

	if(file.is_open())
	{	
		file << this->player.get_Name() << "\n" << this->player.get_Level() << " " << this->player.get_placement() << " " << this->player.get_Exp() << " ";
		file << this->player.get_Strength() << " " << this->player.get_Dexterity() <<  " " << this->player.get_Fatty() << " " << this->player.get_Luck() << " ";
		file << this->player.get_Current_Hp() << " " << this->player.get_Max_Hp() << " " << this->player.get_eq_size() << "\n";
		for (size_t i = 0; i < this->player.get_eq_size(); i++)
		{
			file << this->player.get_eq_item_name(i) << "\n";
		}

		file.close();
	}
	else cout << "\n\nBlad przy otwarciu pliku!";

	//do zrobienia
}

bool The_Game::room_fight(string fullname, int lvl, short placement)
{
	Character enemy(fullname, lvl, placement);
	bool result = this->player.combat(enemy);
	return result;
}

void The_Game::found_item(string itemname, int modifier, int boost)
{
	Item item_(itemname, modifier, boost);
	this->player.add_item_to_eq(item_);
}