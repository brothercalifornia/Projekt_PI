#pragma once
#include<Windows.h>
#include "papier_funkcje.h"

using namespace std;

void rozgrywka();
void rundy();
void tablica_wynikow();
void wynik();

void pocz_papier()
{
	srand(time(NULL));
	rundy();

}
