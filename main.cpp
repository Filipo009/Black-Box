#include <iostream>
#include <chrono>
#include <thread>


void generowanie_planszy(int plansza, int obiekty[20][20], bool kursor[20][20], bool Atom[20][20]) {

	std::cout << "     " << char(201) << char(205) << char(205) << char(205) << char(203);

	for (int i = 0; i < plansza - 2; i++) {
		std::cout << char(203) << char(205) << char(205) << char(205) << char(203);
	}
	std::cout << char(203) << char(205) << char(205) << char(205) << char(187) << std::endl;

	//--------------------

	std::cout << "     ";
	for (int i = 1; i <= plansza; i++) {
		bool narysowane = false;


		if (kursor[0][i] == true) {
			std::cout << "| + |";
			narysowane = true;
		}

		if (narysowane == false) {
			if (obiekty[0][i] == 101) {
				std::cout << "| H |";
				narysowane = true;
			}
		}

		if (narysowane == false) {
			if (obiekty[0][i] == 102) {
				std::cout << "| R |";
				narysowane = true;
			}
		}

		if (narysowane == false) {
			if (obiekty[0][i] != 100) {
				if (obiekty[0][i] < 10) {
					std::cout << "| " << obiekty[0][i] << " |";
				}
				else {
					std::cout << "| " << obiekty[0][i] << '|';
				}
				narysowane = true;
			}
		}

		if (narysowane == false) {
			std::cout << "|   |";
		}
	}
	std::cout << std::endl;

	//----------------------

	std::cout << char(201) << char(205) << char(205) << char(205) << char(203);

	for (int i = 0; i < plansza; i++) {
		std::cout << char(206) << char(205) << char(205) << char(205) << char(206);
	}
	std::cout << char(203) << char(205) << char(205) << char(205) << char(187) << std::endl;

	//---------------------

	for (int i = 1; i <= plansza; i++) {

		for (int j = 0; j <= plansza + 1; j++) {
			bool narysowane = false;

			if (kursor[i][j] == true) {
				std::cout << "| + |";
				narysowane = true;
			}

			if (narysowane == false) {
				if (obiekty[i][j] == 101) {
					std::cout << "| H |";
					narysowane = true;
				}
			}

			if (narysowane == false) {
				if (obiekty[i][j] == 102) {
					std::cout << "| R |";
					narysowane = true;
				}
			}

			if (narysowane == false) {
				if (obiekty[i][j] == 103) {
					std::cout << "| o |";
					narysowane = true;
				}
			}

			if (narysowane == false) {
				if (obiekty[i][j] != 100) {
					if (obiekty[i][j] < 10) {
						std::cout << "| " << obiekty[i][j] << " |";
					}
					else {
						std::cout << "| " << obiekty[i][j] << '|';
					}
					narysowane = true;
				}
			}

			if (narysowane == false) {
				std::cout << "|   |";
			}
		}

		std::cout << std::endl;

		if (i == plansza) {
			std::cout << char(200) << char(205) << char(205) << char(205) << char(202);

			for (int i = 0; i < plansza; i++) {
				std::cout << char(206) << char(205) << char(205) << char(205) << char(206);
			}
			std::cout << char(202) << char(205) << char(205) << char(205) << char(188) << std::endl;
		}
		else {
			std::cout << char(204) << char(205) << char(205) << char(205) << char(206);

			for (int i = 0; i < plansza; i++) {
				std::cout << char(206) << char(205) << char(205) << char(205) << char(206);
			}
			std::cout << char(206) << char(205) << char(205) << char(205) << char(185) << std::endl;
		}
	}

	//-------------------------



	//-------------------------

	std::cout << "     ";
	for (int i = 1; i <= plansza; i++) {
		bool narysowane = false;

		if (kursor[plansza + 1][i] == true) {
			std::cout << "| + |";
			narysowane = true;
		}

		if (narysowane == false) {
			if (obiekty[plansza + 1][i] == 101) {
				std::cout << "| H |";
				narysowane = true;
			}
		}

		if (narysowane == false) {
			if (obiekty[plansza + 1][i] == 102) {
				std::cout << "| R |";
				narysowane = true;
			}
		}

		if (narysowane == false) {
			if (obiekty[plansza + 1][i] != 100) {
				if (obiekty[plansza + 1][i] < 10) {
					std::cout << "| " << obiekty[plansza + 1][i] << " |";
				}
				else {
					std::cout << "| " << obiekty[plansza + 1][i] << '|';
				}
				narysowane = true;
			}
		}

		if (narysowane == false) {
			std::cout << "|   |";
		}
	}
	std::cout << std::endl;


	std::cout << "     " << char(200) << char(205) << char(205) << char(205) << char(202);

	for (int i = 0; i < plansza - 2; i++) {
		std::cout << char(202) << char(205) << char(205) << char(205) << char(202);
	}
	std::cout << char(202) << char(205) << char(205) << char(205) << char(188) << std::endl;
}

void wypelnianie_tablic(int obiekty[20][20], bool kursor[20][20], bool Atom[20][20]) {

	// 100 - puste pole
	// 101 - trafienie
	// 102 - R (dobicie)

	// wrzucanie pustych pol do tablicy
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			obiekty[i][j] = 100;
		}
	}

	// # - puste pole w tablicy kursora
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			kursor[i][j] = false;
		}
	}

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			Atom[i][j] = false;
		}
	}

	kursor[1][1] = true;
}

void losowanie_kordow_atomow(int AtomX[], int AtomY[], int plansza, bool Atom[20][20], int &ilosc_atomow, int &atomy_backup) {
	srand(time(0));

	if (plansza == 5) {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "| Wybierz poziom trudnosci:                     |" << std::endl;
		std::cout << "| Domyslny  -  (3 atomy)   - wpisz '3'          |" << std::endl;
		std::cout << "| Sredni    -  (4 atomy)   - wpisz '4'          |" << std::endl;
		std::cout << "| Trudny    -  (5 atomow)  - wpisz '5'          |" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;

		std::cout << "Wybierz ilosc atomow: ";
		std::cin >> ilosc_atomow;

		if (ilosc_atomow != 3 && ilosc_atomow != 4 && ilosc_atomow != 5) {
			while (ilosc_atomow != 3 && ilosc_atomow != 4 && ilosc_atomow != 5) {
				std::cout << "Niepoprawna ilosc atomow, podaj prawidlowe dane: ";
				std::cin >> ilosc_atomow;
			}
		}
	}


	else if (plansza == 8) {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "| Wybierz poziom trudnosci:                     |" << std::endl;
		std::cout << "| Domyslny  -  (4 atomy)   - wpisz '4'          |" << std::endl;
		std::cout << "| Sredni    -  (5 atomow)  - wpisz '5'          |" << std::endl;
		std::cout << "| Trudny    -  (6 atomow)  - wpisz '6'          |" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;

		std::cout << "Wybierz ilosc atomow: ";
		std::cin >> ilosc_atomow;

		if (ilosc_atomow != 5 && ilosc_atomow != 6 && ilosc_atomow != 4) {
			while (ilosc_atomow != 5 && ilosc_atomow != 6 && ilosc_atomow != 4) {
				std::cout << "Niepoprawna ilosc atomow, podaj prawidlowe dane: ";
				std::cin >> ilosc_atomow;
			}
		}
	}
	else {
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "| Wybierz poziom trudnosci:                     |" << std::endl;
		std::cout << "| Domyslny  -  (6 atomy)   - wpisz '6'          |" << std::endl;
		std::cout << "| Sredni    -  (7 atomow)  - wpisz '7'          |" << std::endl;
		std::cout << "| Trudny    -  (8 atomow)  - wpisz '8'          |" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;

		std::cout << "Wybierz ilosc atomow: ";
		std::cin >> ilosc_atomow;

		if (ilosc_atomow != 8 && ilosc_atomow != 7 && ilosc_atomow != 6) {
			while (ilosc_atomow != 8 && ilosc_atomow != 7 && ilosc_atomow != 6) {
				std::cout << "Niepoprawna ilosc atomow, podaj prawidlowe dane: ";
				std::cin >> ilosc_atomow;
			}
		}
	}

	system("cls");

	atomy_backup = ilosc_atomow;

	for (int i = 0; i < ilosc_atomow; i++) {
		AtomX[i] = rand() % plansza + 1;
		AtomY[i] = rand() % plansza + 1;
	}

	while (true) {

		bool proba_kontrolna = false;
		for (int i = 0; i < ilosc_atomow; i++) {

			for (int j = 0; j < ilosc_atomow; j++) {

				if (i != j) {

					if (AtomX[i] == AtomX[j] && AtomY[i] == AtomY[j]) {
						AtomY[i] = rand() % plansza + 1;
						proba_kontrolna = true;
					}
				}
			}
		}

		if (proba_kontrolna == false) {

			for (int i = 0; i < ilosc_atomow; i++) {
				Atom[AtomX[i]][AtomY[i]] = true;
			}

			break;
		}
	}
}

void rozwiazanie(int plansza, bool Atom[20][20], bool ostatnia_plansza, int obiekty[20][20], bool wygrana, int punkty) {

	if (wygrana == true && ostatnia_plansza == true) {
		std::cout << "Gratulacje!!! Udalo Ci sie wygrac :)" << std::endl;
		std::cout << "Otrzumujesz " << punkty << " punktow" << std::endl;
	}
	else if (ostatnia_plansza == true) {
		std::cout << "Niewiele brakowalo, powodzenia nastepnym razem ;)" << std::endl;
		std::cout << "Otrzumujesz " <<punkty << " punktow" << std::endl;
	}


	std::cout << std::endl;

	std::cout << "     " << char(201) << char(205) << char(205) << char(205) << char(203);

	for (int i = 0; i < plansza - 2; i++) {
		std::cout << char(203) << char(205) << char(205) << char(205) << char(203);
	}
	std::cout << char(203) << char(205) << char(205) << char(205) << char(187) << std::endl;

	for (int i = 1; i <= plansza; i++) {

		std::cout << "     ";

		for (int j = 1; j <= plansza; j++) {
			bool narysowane = false;

			if (Atom[i][j] == true) {
				std::cout << "| O |";
				narysowane = true;
			}

			else if (narysowane == false && ostatnia_plansza == true && obiekty[i][j] == 103) {
				std::cout << "| X |";
				narysowane = true;
			}

			if (narysowane == false) {
				std::cout << "|   |";
			}

		}
		std::cout << std::endl;

		if (i == plansza) {
			std::cout << "     " << char(200) << char(205) << char(205) << char(205) << char(202);

			for (int i = 0; i < plansza - 2; i++) {
				std::cout << char(202) << char(205) << char(205) << char(205) << char(202);
			}
			std::cout << char(202) << char(205) << char(205) << char(205) << char(188) << std::endl;
		}
		else {
			std::cout << "     " << char(204) << char(205) << char(205) << char(205) << char(206);

			for (int i = 0; i < plansza - 2; i++) {
				std::cout << char(206) << char(205) << char(205) << char(205) << char(206);
			}
			std::cout << char(206) << char(205) << char(205) << char(205) << char(185) << std::endl;
		}
	}
}

void wielokrotne_odbicia(int obiekty[20][20], bool Atom[20][20], char& kierunek_wiazki, int& startowyX, int& startowyY, int plansza, int Kursorx, int Kursory, bool& zakoncz, int& numer_wiazki) {

	bool odbicie = false;

	if (kierunek_wiazki == 'R') {
		for (int i = startowyY; i <= plansza; i++) {

			if (Atom[startowyX][i] == true) {
				obiekty[Kursorx][Kursory] = 101;
				zakoncz = true;
				break;
			}

			else if (Atom[startowyX - 1][i] == true && Atom[startowyX + 1][i] == true) {
				obiekty[Kursorx][Kursory] = 102;
				zakoncz = true;
				break;
			}

			else {
				if (Atom[startowyX - 1][i] == true) {
					kierunek_wiazki = 'D';
					startowyY = i - 1;
					odbicie = true;
					break;
				}
				else if (Atom[startowyX + 1][i] == true) {
					kierunek_wiazki = 'U';
					startowyY = i - 1;
					odbicie = true;
					break;
				}
			}
		}

		if (odbicie == false && zakoncz == false) {
			obiekty[Kursorx][Kursory] = numer_wiazki;
			obiekty[startowyX][plansza + 1] = numer_wiazki;
			numer_wiazki += 1;
			zakoncz = true;
		}
	}

	if (kierunek_wiazki == 'L') {
		for (int i = startowyY; i > 0; i--) {

			if (Atom[startowyX][i] == true) {
				obiekty[Kursorx][Kursory] = 101;
				zakoncz = true;
				break;
			}

			else if (Atom[startowyX - 1][i] == true && Atom[startowyX + 1][i] == true) {
				obiekty[Kursorx][Kursory] = 102;
				zakoncz = true;
				break;
			}

			else {
				if (Atom[startowyX - 1][i] == true) {
					kierunek_wiazki = 'D';
					startowyY = i + 1;
					odbicie = true;
					break;
				}
				else if (Atom[startowyX + 1][i] == true) {
					kierunek_wiazki = 'U';
					startowyY = i + 1;
					odbicie = true;
					break;
				}
			}
		}

		if (odbicie == false && zakoncz == false) {
			obiekty[Kursorx][Kursory] = numer_wiazki;
			obiekty[startowyX][0] = numer_wiazki;
			numer_wiazki += 1;
			zakoncz = true;
		}
	}

	if (kierunek_wiazki == 'D') {
		for (int i = startowyX; i <= plansza; i++) {

			if (Atom[i][startowyY] == true) {
				obiekty[Kursorx][Kursory] = 101;
				zakoncz = true;
				break;
			}

			else if (Atom[i][startowyY - 1] == 1 && Atom[i][startowyY + 1] == true) {
				obiekty[Kursorx][Kursory] = 102;
				zakoncz = true;
				break;
			}

			else {
				if (Atom[i][startowyY + 1] == true) {
					kierunek_wiazki = 'L';
					startowyX = i - 1;
					odbicie = true;
					break;
				}
				else if (Atom[i][startowyY - 1] == true) {
					kierunek_wiazki = 'R';
					startowyX = i - 1;
					odbicie = true;
					break;
				}
			}
		}

		if (odbicie == false && zakoncz == false) {
			obiekty[Kursorx][Kursory] = numer_wiazki;
			obiekty[plansza + 1][startowyY] = numer_wiazki;
			numer_wiazki += 1;
			zakoncz = true;
		}
	}

	if (kierunek_wiazki == 'U') {
		int ostatniX;
		for (int i = startowyX; i > 0; i--) {

			if (Atom[i][startowyY] == true) {
				obiekty[Kursorx][Kursory] = 101;
				zakoncz = true;
				break;
			}

			else if (Atom[i][startowyY - 1] == true && Atom[i][startowyY + 1] == true) {
				obiekty[Kursorx][Kursory] = 102;
				zakoncz = true;
				break;
			}

			else {
				if (Atom[i][startowyY + 1] == true) {
					kierunek_wiazki = 'L';
					startowyX = i + 1;
					ostatniX = startowyX;
					odbicie = true;
					break;
				}
				else if (Atom[i][startowyY - 1] == true) {
					kierunek_wiazki = 'R';
					startowyX = i + 1;
					ostatniX = startowyX;
					odbicie = true;
					break;
				}
			}
		}

		if (odbicie == false && zakoncz == false) {
			obiekty[Kursorx][Kursory] = numer_wiazki;
			obiekty[0][startowyY] = numer_wiazki;
			numer_wiazki += 1;
			zakoncz = true;
		}
	}
}


void archiwizacja(bool kursor[20][20], int archiwum_obiekty[100][20][20], int obiekty[20][20], int& Kursorx, int& Kursory, int archiwum_Kursorx[100], int archiwum_Kursory[100], int& numer_ruchu, int& najwyzszy_zapisany_numer_ruchu, int archiwum_ilosc_atomow[100], int ilosc_atomow) {

	numer_ruchu += 1;

	archiwum_ilosc_atomow[numer_ruchu] = ilosc_atomow;
	archiwum_Kursorx[numer_ruchu] = Kursorx;
	archiwum_Kursory[numer_ruchu] = Kursory;

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			archiwum_obiekty[numer_ruchu][i][j] = obiekty[i][j];
		}
	}

	if (numer_ruchu > najwyzszy_zapisany_numer_ruchu) {
		najwyzszy_zapisany_numer_ruchu = numer_ruchu;
	}
}

void wyswietlanie_dla_case_p(bool &ostatnia_plansza, int plansza,bool Atom[20][20], int obiekty[20][20], char &ruch_gracza, bool koniec, bool &wygrana, bool &nowa_gra, int &punkty) {
	system("cls");
	ostatnia_plansza = true;

	for (int i = 1; i <= plansza; i++) {
		for (int j = 1; j <= plansza; j++) {
			if (obiekty[i][j] == 103 && Atom[i][j] != true) {
				wygrana = false;
				punkty += 1;
			}
		}
	}

	rozwiazanie(plansza, Atom, ostatnia_plansza, obiekty, wygrana, punkty);
	koniec = true;

	std::cout << std::endl;
	std::cout << "by zakonczyc rozgrywke wcisnij 'k': ";
	ruch_gracza = std::cin.get();
	ruch_gracza = std::cin.get();
	std::cout << std::endl;

	while (ruch_gracza != 'k') {
		std::cout << "by zakonczyc rozgrywke wcisnij 'k': ";
		ruch_gracza = std::cin.get();
		ruch_gracza = std::cin.get();
		std::cout << std::endl;
	}
	nowa_gra = false;
}

void instrukcja() {
	char kontynuacja;

	system("cls");
	std::cout << "Rozpiska przyciskow: " << std::endl;
	std::cout << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "|  (W, S, A, D) - poruszanie sie po planszy odpowiednio: w gore, w dol, w lewo i prawo                                               |" << std::endl;
	std::cout << "|   w, s, a, d  - poruszanie sie po planszy odpowiednio: w gore, w dol, w lewo i prawo                                               |" << std::endl;
	std::cout << "|      q, Q     - wyjscie do menu glownego                                                                                           |" << std::endl;
	std::cout << "|      r, R     - redo (powtorz cofniety ruch)                                                                                       |" << std::endl;
	std::cout << "|     spacja    - oddanie strzalu (gdy kursor jest na dowolnej scianie)                                                              |" << std::endl;
	std::cout << "|       o       - na planszy umozliwia zaznaczenie przypuszczalnego polozenia atomu                                                  |" << std::endl;
	std::cout << "|       k       - konczy rozgrywke i umozliwia wyswietlenie rozwiazania i liczby uzyskanych punktow (poprawnie znalezionych atomow)  |" << std::endl;
	std::cout << "|       p       - umozliwia wyswietlenie rozwiazania (przerywa etap gry, brak mozliwosci kontynuowania tego etapu gry)               |" << std::endl;
	std::cout << "|       H       - Help/Pomoc - pokazuje na chwile umieszczenie atomow na planszy                                                     |" << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "By wyjsc z instrukcji wcisnij dowolny przycisk... " << std::endl;
	kontynuacja = std::cin.get();
	kontynuacja = std::cin.get();
	system("cls");
}

void menu(char& ruch_gracza, bool &nowa_gra) {
	system("cls");

	char wybor_gracza;


	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "| Menu:                                                        |" << std::endl;
	std::cout << "| By zakonczyc rozgrywke wcisnij 'K'.                          |" << std::endl;
	std::cout << "| By rozpoczac rozgrywke od nowa wcisnij 'N'.                  |" << std::endl;
	std::cout << "| By powrocic do rozgrywki wcisjnij dowolny inny przycisk      |" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "Ruch Gracza: " << std::endl;
	wybor_gracza = std::cin.get();
	wybor_gracza = std::cin.get();

	if (wybor_gracza == 'k' || wybor_gracza == 'K') {
		ruch_gracza = 'k';
		nowa_gra = false;
	}
	else if (wybor_gracza == 'n' || wybor_gracza == 'N') {
		ruch_gracza = 'k';
	}
	
	system("cls");
}



void movement(char &ruch_gracza, int& Kursorx, int& Kursory, int plansza, bool& koniec, int obiekty[20][20], bool kursor[20][20], int& numer_wiazki, bool Atom[20][20], int archiwum_Kursorx[100], int archiwum_Kursory[100], int& numer_ruchu, int& najwyzszy_zapisany_ruch, int archiwum_obiekty[100][20][20], int &ilosc_atomow, int archiwum_ilosc_atomow[100], bool &nowa_gra, bool &wygrana, int &punkty, int atomy_backup) {

	bool zakoncz = false;
	int startowyX, startowyY;
	char kierunek_wiazki;
	bool ostatnia_plansza;

	if (koniec == false) {
		std::cout << std::endl;
		std::cout << "-------------------------------------------------------------" << std::endl;
		std::cout << " |  Liczba atomow ukrytych na planszy:                    " << atomy_backup << '|' << std::endl;
		std::cout << " |  Pozostala ilosc atomow:                               " << ilosc_atomow << '|' << std::endl;
		std::cout << "-------------------------------------------------------------" << std::endl;
		std::cout << "Ruch Gracza: ";
		ruch_gracza = std::cin.get();
		ruch_gracza = std::cin.get();


		switch (ruch_gracza) {

		case 'W': case 'w':
			kursor[Kursorx][Kursory] = false;
			Kursorx -= 1;

			if (Kursorx < 0) {
				Kursorx = plansza + 1;
			}

			kursor[Kursorx][Kursory] = true;
			archiwizacja(kursor,archiwum_obiekty, obiekty, Kursorx, Kursory, archiwum_Kursorx, archiwum_Kursory, numer_ruchu, najwyzszy_zapisany_ruch, archiwum_ilosc_atomow, ilosc_atomow);
			break;

		case 'S': case 's':
			kursor[Kursorx][Kursory] = false;
			Kursorx += 1;

			if (Kursorx > plansza + 1) {
				Kursorx = 0;
			}

			kursor[Kursorx][Kursory] = true;

		archiwizacja(kursor, archiwum_obiekty, obiekty, Kursorx, Kursory, archiwum_Kursorx, archiwum_Kursory, numer_ruchu, najwyzszy_zapisany_ruch, archiwum_ilosc_atomow, ilosc_atomow);
		break;

		case 'A': case 'a':
			kursor[Kursorx][Kursory] = false;
			Kursory -= 1;

			if (Kursory < 0) {
				Kursory = plansza + 1;
			}

			kursor[Kursorx][Kursory] = true;
			archiwizacja(kursor, archiwum_obiekty, obiekty, Kursorx, Kursory, archiwum_Kursorx, archiwum_Kursory, numer_ruchu, najwyzszy_zapisany_ruch, archiwum_ilosc_atomow, ilosc_atomow);
			break;

		case 'D': case 'd':
			kursor[Kursorx][Kursory] = false;
			Kursory += 1;

			if (Kursory > plansza + 1) {
				Kursory = 0;
			}

			kursor[Kursorx][Kursory] = true;
			archiwizacja(kursor, archiwum_obiekty, obiekty, Kursorx, Kursory, archiwum_Kursorx, archiwum_Kursory, numer_ruchu, najwyzszy_zapisany_ruch, archiwum_ilosc_atomow, ilosc_atomow);
			break;

		case 'Q': case 'q':
			menu(ruch_gracza, nowa_gra);
			break;

		case 'k':
			nowa_gra = false;
			ostatnia_plansza = true;

			for (int i = 1; i <= plansza; i++) {
				for (int j = 1; j <= plansza; j++) {
					if (obiekty[i][j] == 103 && Atom[i][j] != true) {
						wygrana = false;
					}
					else if (obiekty[i][j] == 103 && Atom[i][j] == true) {
						punkty += 1;
					}
				}
			}
			break;

		case 'H':
			ostatnia_plansza = false;
			system("cls");
			rozwiazanie(plansza, Atom, ostatnia_plansza, obiekty, wygrana, punkty);
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "Czas: " << std::endl;
			std::cout << "--------------------" << std::endl;
			std::cout << "|***/              |" << std::endl;
			std::cout << "--------------------" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(400));
			system("cls");

			rozwiazanie(plansza, Atom, ostatnia_plansza, obiekty, wygrana, punkty);
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "Czas: " << std::endl;
			std::cout << "--------------------" << std::endl;
			std::cout << "|******/           |" << std::endl;
			std::cout << "--------------------" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(400));
			system("cls");

			system("cls");
			rozwiazanie(plansza, Atom, ostatnia_plansza, obiekty, wygrana, punkty);
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "Czas: " << std::endl;
			std::cout << "--------------------" << std::endl;
			std::cout << "|*********/        |" << std::endl;
			std::cout << "--------------------" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(400));
			system("cls");

			system("cls");
			rozwiazanie(plansza, Atom, ostatnia_plansza, obiekty, wygrana, punkty);
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "Czas: " << std::endl;
			std::cout << "--------------------" << std::endl;
			std::cout << "|************/     |" << std::endl;
			std::cout << "--------------------" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(400));
			system("cls");

			system("cls");
			rozwiazanie(plansza, Atom, ostatnia_plansza, obiekty, wygrana, punkty);
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "Czas: " << std::endl;
			std::cout << "--------------------" << std::endl;
			std::cout << "|***************/  |" << std::endl;
			std::cout << "--------------------" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(400));
			system("cls");


			system("cls");
			rozwiazanie(plansza, Atom, ostatnia_plansza, obiekty, wygrana, punkty);
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "Czas: " << std::endl;
			std::cout << "--------------------" << std::endl;
			std::cout << "|******************|" << std::endl;
			std::cout << "--------------------" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(400));
			system("cls");
			break;

		case 'p':
			if (ilosc_atomow != 0) {
				if (ilosc_atomow < 0) {
					std::cout << "Przekroczono liczbe atomow na planszy o " << ilosc_atomow * (-1);
				}
				else{
					std::cout << "Na planszy brakuje " << ilosc_atomow << " atomow";
				}

				std::cout << std::endl;
				std::cout << "Czy chcesz kontynuowac? (Bedzie to oznaczalo koniec rozgrywki)" << std::endl;
				std::cout << "Jezeli chesz kontynowac wcisnij 'Y'" << std::endl;
				std::cout << "Jezeli chcesz wrocic do rozgrywki wcisnij przycisk inny niz 'Y'" << std::endl;
				std::cout << "Ruch Gracza: ";

				ruch_gracza = std::cin.get();
				ruch_gracza = std::cin.get();

				if (ruch_gracza == 'Y' || ruch_gracza == 'y') {
					wygrana = false;
					wyswietlanie_dla_case_p(ostatnia_plansza, plansza, Atom, obiekty, ruch_gracza, koniec, wygrana, nowa_gra, punkty);
				}
			}
			else {
				for (int i = 1; i <= plansza; i++) {
					for (int j = 1; j <= plansza; j++) {
						if (obiekty[i][j] == 103 && Atom[i][j] != true) {
							wygrana = false;
						}
						else if (obiekty[i][j] == 103 && Atom[i][j] == true) {
							punkty += 1;
						}
					}
				}

				wyswietlanie_dla_case_p(ostatnia_plansza, plansza, Atom, obiekty, ruch_gracza, koniec, wygrana, nowa_gra, punkty);
			}
			break;

		case 'o':
			if (Kursorx != 0 && Kursorx != plansza + 1 && Kursory != 0 && Kursory != plansza + 1) {
				if (obiekty[Kursorx][Kursory] == 103) {
					obiekty[Kursorx][Kursory] = 100;
					ilosc_atomow += 1;
				}
				else {
					if (Kursory != 0 && Kursory != plansza + 1) {
						obiekty[Kursorx][Kursory] = 103;
						ilosc_atomow -= 1;
					}
				}
			}
			break;

		case 'I': case 'i':
			instrukcja();
			break;


		case 'U': case 'u':
			numer_ruchu -= 1;
			if (numer_ruchu > 0 && numer_ruchu <= najwyzszy_zapisany_ruch) {
				kursor[Kursorx][Kursory] = false;
				Kursorx = archiwum_Kursorx[numer_ruchu];
				Kursory = archiwum_Kursory[numer_ruchu];
				ilosc_atomow = archiwum_ilosc_atomow[numer_ruchu];
				kursor[Kursorx][Kursory] = true;

				for (int i = 0; i < 20; i++) {
					for (int j = 0; j < 20; j++) {
						obiekty[i][j] = archiwum_obiekty[numer_ruchu][i][j];
					}
				}
			}
			else {
				numer_ruchu += 1;
			}
			break;


		case 'R': case 'r':
			numer_ruchu += 1;
			if (numer_ruchu > 0 && numer_ruchu <= najwyzszy_zapisany_ruch) {
				kursor[Kursorx][Kursory] = false;
				Kursorx = archiwum_Kursorx[numer_ruchu];
				Kursory = archiwum_Kursory[numer_ruchu];
				ilosc_atomow = archiwum_ilosc_atomow[numer_ruchu];
				kursor[Kursorx][Kursory] = true;

				for (int i = 0; i < 20; i++) {
					for (int j = 0; j < 20; j++) {
						obiekty[i][j] = archiwum_obiekty[numer_ruchu][i][j];
					}
				}
			}
			else {
				numer_ruchu -= 1;
			}
			break;


		case ' ':

			if (obiekty[Kursorx][Kursory] == 100) {
				if (Kursorx == 0) {

					if (Atom[1][Kursory] == true) {
						obiekty[Kursorx][Kursory] = 101;
					}

					else if (Atom[1][Kursory - 1] == true || Atom[1][Kursory + 1] == true) {
						obiekty[Kursorx][Kursory] = 102;
					}

					else {

						startowyX = 2;
						startowyY = Kursory;
						kierunek_wiazki = 'D';

						while (zakoncz == false) {
							wielokrotne_odbicia(obiekty, Atom, kierunek_wiazki, startowyX, startowyY, plansza, Kursorx, Kursory, zakoncz, numer_wiazki);
						}
					}
				}


				else if (Kursorx == plansza + 1) {

					if (Atom[plansza][Kursory] == true) {
						obiekty[Kursorx][Kursory] = 101;
					}

					else if (Atom[plansza][Kursory - 1] == true || Atom[plansza][Kursory + 1] == true) {
						obiekty[Kursorx][Kursory] = 102;
					}

					else {

						startowyX = plansza - 1;
						startowyY = Kursory;
						kierunek_wiazki = 'U';

						while (zakoncz == false) {
							wielokrotne_odbicia(obiekty, Atom, kierunek_wiazki, startowyX, startowyY, plansza, Kursorx, Kursory, zakoncz, numer_wiazki);
						}
					}
				}


				else if (Kursory == 0) {

					if (Atom[Kursorx][1] == true) {
						obiekty[Kursorx][Kursory] = 101;
					}

					else if (Atom[Kursorx - 1][1] == true || Atom[Kursorx + 1][1] == true) {
						obiekty[Kursorx][Kursory] = 102;
					}

					else {

						startowyX = Kursorx;
						startowyY = 2;
						kierunek_wiazki = 'R';

						while (zakoncz == false) {
							wielokrotne_odbicia(obiekty, Atom, kierunek_wiazki, startowyX, startowyY, plansza, Kursorx, Kursory, zakoncz, numer_wiazki);
						}
					}
				}


				else if (Kursory == plansza + 1) {

					if (Atom[Kursorx][plansza] == true) {
						obiekty[Kursorx][Kursory] = 101;
					}

					else if (Atom[Kursorx - 1][plansza] == true || Atom[Kursorx + 1][plansza] == true) {
						obiekty[Kursorx][Kursory] = 102;
					}

					else {

						startowyX = Kursorx;
						startowyY = plansza - 1;
						kierunek_wiazki = 'L';

						while (zakoncz == false) {
							wielokrotne_odbicia(obiekty, Atom, kierunek_wiazki, startowyX, startowyY, plansza, Kursorx, Kursory, zakoncz, numer_wiazki);
						}
					}
				}
			}
			break;

		}
	}

	else {
			std::cout << "wcisnieto klawisz 'p' dalsza rozgrywka nie jest mozliwa, wcisnij 'k' aby wyjsc z gry: ";
			std::cin >> ruch_gracza;
	}

	if (Kursorx == 0 && Kursory == 0) {
		if (archiwum_Kursorx[numer_ruchu - 1] == 0) {
			Kursory = plansza;
		}
		else {
			Kursorx = plansza;
		}

		kursor[Kursorx][Kursory] = true;
		numer_ruchu -= 1;
		archiwizacja(kursor, archiwum_obiekty, obiekty, Kursorx, Kursory, archiwum_Kursorx, archiwum_Kursory, numer_ruchu, najwyzszy_zapisany_ruch, archiwum_ilosc_atomow, ilosc_atomow);
	}
	if (Kursorx == 0 && Kursory == plansza + 1) {
		if (archiwum_Kursorx[numer_ruchu - 1] == 0) {
			Kursory = 1;
		}
		else {
			Kursorx = plansza;
		}

		kursor[Kursorx][Kursory] = true;
		numer_ruchu -= 1;
		archiwizacja(kursor, archiwum_obiekty, obiekty, Kursorx, Kursory, archiwum_Kursorx, archiwum_Kursory, numer_ruchu, najwyzszy_zapisany_ruch, archiwum_ilosc_atomow, ilosc_atomow);
	}
	if (Kursorx == plansza + 1 && Kursory == plansza + 1) {
		if (archiwum_Kursorx[numer_ruchu - 1] == plansza + 1) {
			Kursory = 1;
		}
		else {
			Kursorx = 1;
		}

		kursor[Kursorx][Kursory] = true;
		numer_ruchu -= 1;
		archiwizacja(kursor, archiwum_obiekty, obiekty, Kursorx, Kursory, archiwum_Kursorx, archiwum_Kursory, numer_ruchu, najwyzszy_zapisany_ruch, archiwum_ilosc_atomow, ilosc_atomow);
	}
	if (Kursorx == plansza + 1 && Kursory == 0) {
		if (archiwum_Kursorx[numer_ruchu - 1] == plansza) {
			Kursorx = 1;
		}
		else {
			Kursory = plansza;
		}

		kursor[Kursorx][Kursory] = true;
		numer_ruchu -= 1;
		archiwizacja(kursor, archiwum_obiekty, obiekty, Kursorx, Kursory, archiwum_Kursorx, archiwum_Kursory, numer_ruchu, najwyzszy_zapisany_ruch, archiwum_ilosc_atomow, ilosc_atomow);
	}
}


void wstep(int &plansza) {
	const int limit_znakow = 50;
	char kontynuacja[limit_znakow];
	std::cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "|BBBBBBBBBBBBBBBBB   lllllll                                      kkkkkkkk                BBBBBBBBBBBBBBBBB                                      |" << std::endl;
	std::cout << "|B::::::::::::::::B  l:::::l                                      k::::::k                B::::::::::::::::B                                     |" << std::endl;
	std::cout << "|B::::::BBBBBB:::::B l:::::l                                      k::::::k                B::::::BBBBBB:::::B                                    |" << std::endl;
	std::cout << "|BB:::::B     B:::::Bl:::::l                                      k::::::k                BB:::::B     B:::::B                                   |" << std::endl;
	std::cout << "|  B::::B     B:::::B l::::l   aaaaaaaaaaaaa      cccccccccccccccc k:::::k    kkkkkkk       B::::B     B:::::B   ooooooooooo xxxxxxx      xxxxxxx|" << std::endl;
	std::cout << "|  B::::B     B:::::B l::::l   a::::::::::::a   cc:::::::::::::::c k:::::k   k:::::k        B::::B     B:::::B oo:::::::::::oox:::::x    x:::::x |" << std::endl;
	std::cout << "|  B::::BBBBBB:::::B  l::::l   aaaaaaaaa:::::a c:::::::::::::::::c k:::::k  k:::::k         B::::BBBBBB:::::B o:::::::::::::::ox:::::x  x:::::x  |" << std::endl;
	std::cout << "|  B:::::::::::::BB   l::::l            a::::ac:::::::cccccc:::::c k:::::k k:::::k          B:::::::::::::BB  o:::::ooooo:::::o x:::::xx:::::x   |" << std::endl;
	std::cout << "|  B::::BBBBBB:::::B  l::::l     aaaaaaa:::::ac::::::c     ccccccc k::::::k:::::k           B::::BBBBBB:::::B o::::o     o::::o  x::::::::::x    |" << std::endl;
	std::cout << "|  B::::B     B:::::B l::::l   aa::::::::::::ac:::::c              k:::::::::::k            B::::B     B:::::Bo::::o     o::::o   x::::::::x     |" << std::endl;
	std::cout << "|  B::::B     B:::::B l::::l  a::::aaaa::::::ac:::::c              k:::::::::::k            B::::B     B:::::Bo::::o     o::::o   x::::::::x     |" << std::endl;
	std::cout << "|  B::::B     B:::::B l::::l a::::a    a:::::ac::::::c     ccccccc k::::::k:::::k           B::::B     B:::::Bo::::o     o::::o  x::::::::::x    |" << std::endl;
	std::cout << "|BB:::::BBBBBB::::::Bl::::::la::::a    a:::::ac:::::::cccccc:::::ck::::::k k:::::k        BB:::::BBBBBB::::::Bo:::::ooooo:::::o x:::::xx:::::x   |" << std::endl;
	std::cout << "|B:::::::::::::::::B l::::::la:::::aaaa::::::a c:::::::::::::::::ck::::::k  k:::::k       B:::::::::::::::::B o:::::::::::::::ox:::::x  x:::::x  |" << std::endl;
	std::cout << "|B::::::::::::::::B  l::::::l a::::::::::aa:::a cc:::::::::::::::ck::::::k   k:::::k      B::::::::::::::::B   oo:::::::::::oox:::::x    x:::::x |" << std::endl;
	std::cout << "|BBBBBBBBBBBBBBBBB   llllllll  aaaaaaaaaa  aaaa   cccccccccccccccckkkkkkkk    kkkkkkk     BBBBBBBBBBBBBBBBB      ooooooooooo xxxxxxx      xxxxxxx|" << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "                                                         |autorstwa Filipa Jakubowskiego|" << std::endl;
	std::cout << "                                                         --------------------------------" << std::endl << std::endl;
	std::cout << "                                                     By kontynowac wcisnij dowolny przycisk..." << std::endl;
	std::cin.getline(kontynuacja, limit_znakow);
	system("cls");

	std::cout << "Wybierz wielkosc boku planszy (5/ 8/ 10): ";
	std::cin >> plansza;

	if (plansza != 5 && plansza != 8 && plansza != 10) {
		while (plansza != 5 && plansza != 8 && plansza != 10) {
			std::cout << "Niepoprawny rozmiar planszy, wpisz prawidlowa wartosc: ";
			std::cin >> plansza;
		}
	}


	system("cls");
	std::cout << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "| Bugi:                                                                                                         |" << std::endl;
	std::cout << "| 1. Wszystkie ruchy prosze koniecznie wykonywac poprzes wcisniecie JEDNEGO klawisza i zatwierdzenie go enterem |" << std::endl;
	std::cout << "| 2. Jezeli kursor sie zatnie przed wpisaniem swojego ruchu wcisnij jeszcze jeden enter.                        |" << std::endl;
	std::cout << "| 3. W celu unikniecia bugow zwiazanych z generowaniem planszy zaleca sie granie na pelnym ekranie              |" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "| Instrukcja:                                                                                                   |" << std::endl;
	std::cout << "| BY otworzyc instrukcje obslugi wcisnij klawisz 'I' oraz 'i'                                                   |" << std::endl;
	std::cout << "| By otworzyc menu wcisnij 'M' lub 'm'                                                                          |" << std::endl;
	std::cout << "| (Gracz bedzie mial dostep do tych funkcji po rozpoczeciu rogrywki)                                            |" << std::endl;
	std::cout << "| Zycze dobrej zabawy ;)                                                                                        |" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cin.getline(kontynuacja, limit_znakow);
}


void rozgrywka(bool &nowa_gra) {
	char kontynuacja;

	bool koniec = false;
	char ruch_gracza = 0;
	int plansza;
	int AtomX[20], AtomY[20];
	int Kursorx = 1, Kursory = 1;
	int numer_wiazki = 0;
	bool kursor[20][20];
	int obiekty[20][20];
	bool Atom[20][20];
	int ilosc_atomow;
	int atomy_backup, punkty = 0;
	bool ostatnia_plansza = true;
	bool wygrana = true;


	int najwyzszy_zapisany_ruch;
	int numer_ruchu = 0;
	int archiwum_Kursorx[100];
	int archiwum_Kursory[100];
	int archiwum_ilosc_atomow[100];
	int archiwum_obiekty[100][20][20];

	wstep(plansza);

	wypelnianie_tablic(obiekty, kursor, Atom);
	losowanie_kordow_atomow(AtomX, AtomY, plansza, Atom, ilosc_atomow, atomy_backup);

	system("cls");

	while (ruch_gracza != 'k') {
		generowanie_planszy(plansza, obiekty, kursor, Atom);
		movement(ruch_gracza, Kursorx, Kursory, plansza, koniec, obiekty, kursor, numer_wiazki, Atom, archiwum_Kursorx, archiwum_Kursory, numer_ruchu, najwyzszy_zapisany_ruch, archiwum_obiekty, ilosc_atomow, archiwum_ilosc_atomow, nowa_gra, wygrana, punkty, atomy_backup);
		system("cls");
	}

	if (ilosc_atomow != 0) {
		wygrana = false;
	}
	rozwiazanie(plansza, Atom, ostatnia_plansza, obiekty, wygrana, punkty);
}


int main()
{	
	bool nowa_gra = true;

	while (nowa_gra == true) {
		rozgrywka(nowa_gra);
	}
}
