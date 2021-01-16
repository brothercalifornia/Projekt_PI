#pragma once
#include "Logowanie.h"
#include <iostream>
#include<cstring>
#include<fstream>

using namespace std;

int wymiar(int d)
{

	int n = 0;
	while (n * n < d)
	{
		n++;
	}

	return n;
}

string deszyfrowanie(string tekst)
{
	int d = tekst.size();
	int k = wymiar(d);
	string szyfr, haslo;

	//odczytywanie w pionie
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
			szyfr = szyfr + tekst[i + j * k];

	for (int i = 0; i < d; i++) {
		if (szyfr[i] == '_') break;
		haslo += szyfr[i];

	}

	return haslo;

}

string LogIHas_p(string nazwaPliku, string login) {
	string login_plik, haslo_plik, odszyfrowane_haslo = "";
	ifstream plik_1;
	plik_1.open(nazwaPliku.c_str());

	if (!plik_1.good())
		cout << "problem z plikiem " << endl;
	
	for (int i = 0; i < 4; i++) {
		plik_1 >> login_plik >> haslo_plik;
		if (login == login_plik) {
			odszyfrowane_haslo = deszyfrowanie(haslo_plik);

		}
		

	}return odszyfrowane_haslo;

}

void Logowanie::log()
{
    string LoginStr, PasswordStr;
    cout << "Podaj login: " << endl;

    cin >> LoginStr;
    cout << "Podaj haslo:" << endl;
    cin >> PasswordStr;
    if (LogIHas_p("loginy_hasla.txt", LoginStr) == PasswordStr) {
		cout << "POPRAWNE LOGOWANIE" << endl;
        cout << "Wpisano login : " << LoginStr << "; oraz haslo : " << PasswordStr << endl << endl;
		system("pause");
    }
    else {
        cout << "BAD LOGIN OR PASSWORD - SELFDESTRUCTION PROCEDURE STARTED" << endl << "HAVE A NICE DAY ..." << endl << endl;
		log();
    }
    
}
