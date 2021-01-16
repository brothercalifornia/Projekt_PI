#include <iostream>
#include <time.h>
#include "Zabezpieczenia.h"

using namespace std;



void Zabezpieczenia::wypisz(char tablica[9])
{
	for (int i = 0; i < 9; i++) {
		cout << tablica[i];
	}
}

void Zabezpieczenia::jakieznaki(char haslo[9])
{
	int tempiloscznakow[3] = { 0 };
	cout << endl << "jakie znaki: ";
	for (int j = 0; j < 9; j++) {
		if (haslo[j] < 122 && haslo[j] > 97) {
			tempiloscznakow[0]++;
		}
		else if (haslo[j] < 90 && haslo[j] > 65) {
			tempiloscznakow[1]++;
		}
		else {
			tempiloscznakow[2]++;
		}
	}
	cout << " M: " << tempiloscznakow[0] << " D: " << tempiloscznakow[1] << " Z: " << tempiloscznakow[2] << endl;
}


void Zabezpieczenia::tworzeniehasla(char haslo[9], char znaki[9], int iloscznakow[3])
{
	int x;
	//x = (a + (rand() % (b - a)))
	for (int i = 0; i < 9; i++) {
		while (true) {
			x = (rand() % 3);
			if (iloscznakow[x] > 0) {
				iloscznakow[x]--;
				switch (x)
				{
				case 0: //małe litery
					haslo[i] = (97 + (rand() % (122 - 97)));
					break;
				case 1: //duże litery
					haslo[i] = (65 + (rand() % (90 - 65)));
					break;
				case 2: //znaki
					haslo[i] = znaki[(rand() % 8)];
					break;
				default:
					cout << "ERROR!!!";
					break;
				}
				break; //break do while
			}
		}
	}
}

void Zabezpieczenia::szyfr(char haslo[9], char cezar[9], int lenskok)
{
	for (int i = 0; i < 9; i++) {
		cezar[i] = haslo[i] + lenskok;
		while (cezar[i] > 126) {
			cezar[i] = cezar[i] - 93;
		}
	}
}

void Zabezpieczenia::deszyfr(char cezar[9], char decezar[9], int lenskok)
{
	for (int i = 0; i < 9; i++) {
		decezar[i] = cezar[i] - lenskok;
		while (cezar[i] < 33) {
			decezar[i] = cezar[i] + 93;
		}
	}

}



void Zabezpieczenia::zabezpieczenia()
{
	srand(time(NULL));
	char haslo[9], cezar[9], decezar[9], znaki[8] = { '!','@','#','$','%','^','&','*' };
	int iloscznakow[3] = { 4,3,2 };//{x,y,z}; (MIN) x-małe litery, y-duże ltery, z-znaki specjalne

	//---TWORZENIE HASŁA---
	tworzeniehasla(haslo, znaki, iloscznakow); // wywołanie
	cout << "Wylosowane zaszyfowane hasło wstępu to: ";
	wypisz(haslo);

	//---SZYFR CEZARA---
	int lenskok = 3; //Klucz do cezara
	szyfr(haslo, cezar, lenskok); // wywołanie

	cout << endl << "po szyfrowaniu: ";
	wypisz(cezar);

	//---DESZYFRACJA---
	deszyfr(cezar, decezar, lenskok);
	cout << endl << "po rozszyfrowaniu: ";
	wypisz(decezar);

	//--ILE JAKICH ZNAKÓW--
	jakieznaki(haslo);
	cout << endl << endl;
	system("pause");
}


