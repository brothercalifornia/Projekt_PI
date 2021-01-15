#pragma once
#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

class Kolko {
public:
	void plansza(char t[]);
	bool wygrana(char t[], char g);
	bool remis(char t[]);
	void ruch(char t[], char gracz);
	void ruch_komp(char t[], char gracz);
	void kolko();
};
