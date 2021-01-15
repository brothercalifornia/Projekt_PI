#pragma once
#pragma once
#include<iostream>
#include "licznik_pkt.h"

using namespace std;

int komp = 0, gracz = 0;


void rundy();

void tablica_wynikow(int& gracz, int& komp)
{
	cout << "gracz:" << gracz << " troll:" << komp << endl;
	if (gracz > komp) {
		licznik();
		cout << "WYGRYWASZ!" << endl;
	}
	if (komp > gracz) {
		cout << "PRZEGRYWASZ!" << endl;
		przegrana();
	}
	if (komp == gracz) cout << "REMIS!" << endl;

	string odpowiedz;
	cout << "Czy chcesz zwiekszyc ilosc rund?" << endl; cin >> odpowiedz;
	if (odpowiedz == "tak")
		rundy();
	else cout << "koniec gry" << endl;

}

void wynik(int n, int m, int& i, int& X)
{

	switch (n)
	{
	case 1:
		if (m == 1) {
			cout << "remis" << endl; Sleep(2000);
			gracz++; komp++;
		}
		if (m == 2) {
			cout << "przegrana" << endl; Sleep(2000);
			komp++;
		}
		if (m == 3) {
			cout << "wygrana" << endl; Sleep(2000);
			gracz++;
		}
		if (i == X - 1)
			tablica_wynikow(gracz, komp);
		break;
	case 2:
		if (m == 2) {
			cout << "remis" << endl; Sleep(2000);
			gracz++; komp++;
		}
		if (m == 3) {
			cout << "przegrana" << endl; Sleep(2000);
			komp++;
		}
		if (m == 1) {
			cout << "wygrana" << endl; Sleep(2000);
			gracz++;
		}
		if (i == X - 1)
			tablica_wynikow(gracz, komp);
		break;
	case 3:
		if (m == 3) {
			cout << "remis" << endl; Sleep(2000);
			gracz++; komp++;
		}
		if (m == 1) {
			cout << "przegrana" << endl; Sleep(2000);
			komp++;
		}
		if (m == 2) {
			cout << "wygrana" << endl; Sleep(2000);
			gracz++;
		}
		if (i == X - 1)
			tablica_wynikow(gracz, komp);
		break;
	}

}
void rozgrywka(int& i, int& X)
{
	int n;
	system("cls");
	cout << "1-kamien" << endl;
	cout << "2-papier" << endl;
	cout << "3-nozyczki" << endl;
	cout << "podaj cyfre: "; cin >> n;

	int m = (rand() % 3) + 1;
	cout << "troll wybral: " << m << endl;
	wynik(n, m, i, X);


}

void rundy()
{
	int X, i;
	cout << "Podaj ilosc rund: "; cin >> X;

	for (i = 0; i < X; i++)
		rozgrywka(i, X);
}


