//#include "Game.h"
//#include"Zabezpieczenia.h"
#include <iostream>
#include <cstdio>
#include <ctime>
#include<cstdlib>
#include<Windows.h>
//#include "gracze.h"
//#include "funkcje.h"
#include "Logowanie.h"
#include "logowanie_metody.h"
#include"Totolotek.h"
#include "totolotek_metody.h"
#include"Kolko.h"
#include "kolko_metody.h"
#include "licznik_pkt.h"
#include "Papier.h"

using namespace std;



//void rozgrywka();
//void rundy();
//void tablica_wynikow();
//void wynik();



int N, x, y, m, n, o, p, suma, przeszkody = 0;


// Funkcja rysuje planszę gry w kółko i krzyżyk
//---------------------------------------------
void plansza(char t[])
{
    for (int i = 1; i <= 9; i++)
    {
        cout << " " << t[i] << " ";
        if (i % 3)
            cout << "|";
        else if (i != 9)
            cout << "\n---+---+---\n";
        else cout << endl;
    }
}

// Funkcja zwraca true, jeśli nastąpiła
// wygrana danego zawodnika
//-------------------------------------
bool wygrana(char t[], char g)
{
    bool test;
    int i;

    test = false;
    for (i = 1; i <= 7; i += 3)
        test |= ((t[i] == g) && (t[i + 1] == g) && (t[i + 2] == g));
    for (i = 1; i <= 3; i++)
        test |= ((t[i] == g) && (t[i + 3] == g) && (t[i + 6] == g));
    test |= ((t[1] == g) && (t[5] == g) && (t[9] == g));
    test |= ((t[3] == g) && (t[5] == g) && (t[7] == g));
    if (test)
    {
        plansza(t);
        cout << "\nGRACZ " << g << " WYGRYWA!!!\n\n";
        return true;
    }
    return false;
}

// Funkcja zwraca true, jeśli na planszy nie ma już
// żadnego wolnego pola na ruch.
//-------------------------------------------------
bool remis(char t[])
{
    for (int i = 1; i <= 9; i++)
        if (t[i] == ' ') return false;
    plansza(t);
    cout << "\nREMIS !!!\n\n";
    return true;
}

// Funkcja umożliwia ruch gracza
// Po ruchu następuje zamiana gracza
//------------------------------------
void ruch(char t[], char& gracz)
{
    int r;

    plansza(t);
    cout << "\nGRACZ " << gracz << " : Twoj ruch : ";
    cin >> r;
    cout << "-----------------------\n\n";
    if ((r >= 1) && (r <= 9) && (t[r] == ' ')) t[r] = gracz;
    gracz = (gracz == 'O') ? 'X' : 'O';
}

class User
{
public:
    User()
    {
        for (int i = 0; i < 3; i++) {
            statystyki[i][0] = rand() % 10 + 1;
            statystyki[i][1] = rand() % 10 + 1;
        }
    }
    string Imie;
    string plec;

    int statystyki[3][2]; //int[i][0] wygrane;     int[i][1] przegrane;


    void info()
    {

        cout << "______________________________________" << endl;
        cout << "Informacje o postaci: " << endl;
        cout << "Imie: " << Imie << endl;
        cout << "Plec: " << plec << endl;
        cout << "Statystyki: " << Imie << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Gra nr: " << i;
            cout << "\t Wygrane: " << statystyki[i][0];
            cout << "\t Przegrane: " << statystyki[i][1] << endl;
        }

        cout << "______________________________________" << endl << endl;

    }



};



void doplik(string imie, string plec, int statystyki[3][2]) {



}


void poziom(User& obiekt)
{
    int poz = 0;
    cout << "______________________________________" << endl;
    cout << "Poziom postaci: " << endl;
    for (int i = 0; i < 3; i++) {
        poz += (obiekt.statystyki[i][0] * 10) / (obiekt.statystyki[i][1] * 5 + 1);
    }
    cout << poz << endl;
    cout << "______________________________________" << endl << endl;

}

User zpliku() {
    User us1;

    //us1.Imie = 
    //us1.plec =
    //for
    //us1.statystyki[i][j] = 

    return us1;
}


void funkcjaZew(User& obiekt)
{
    cout << "______________________________________" << endl;

    cout << "Zmienne klasy w funkcji zewnetrznej: " << endl;
    //cout << obiekt.zmiennaInt << endl;
    //cout << obiekt.zmiennaDouble << endl;
    cout << "______________________________________" << endl;

}


void tworzeniehasla(char haslo[9], char znaki[9], int iloscznakow[3]) {
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


int main()

{
    setlocale(LC_CTYPE, "Polish");

    Logowanie a;
    a.log();

   // Zabezpieczenia b;
    //b.zabezpieczenia();

    //Game g;
    //g.menu();

    //Totolotek z;
    //z.losowanie();
 
    
   



    int stan = 1;
    while (stan != 0)
    {
        cout << "Podaj liczbe od 0 do 2:" << endl << "0-wyjście" << endl << "1-losowanie statystyk i posatci" << endl << "2-gra" << endl;

        cout << endl;
        cin >> stan;
        if (stan == 1) {
          /*  User Paulina;
            User Jan;
            cout << "Losowanie postaci: " << endl << "Proszę wybrać dwie dowolne liczby" << endl;
            string imie;
            cin >> imie;
            Paulina.Imie = imie;
            cin >> imie;
            Jan.Imie = imie;
            Paulina.info();
            Jan.info();
            poziom(Paulina);
            poziom(Jan);

            doplik(Paulina.Imie, Paulina.plec, Paulina.statystyki);
            // cout << "Wywolanie funkcji zewnetrznej:5: " << endl;

            Paulina = zpliku();

*/
        }
        string odp;
        if (stan == 2) {
            cout << "Niech rozpocznie się gra!" << endl;
            cout << endl;

            cout << "Drogi studencie! " << endl << "Nadeszły trudne czasy, sesja coraz bliżej. To już nie przelewki. Trafiłeś do mrocznego świata strachu i paniki. Zegar nieubłagalnie tyka. Jeżeli chcesz przeżyć musisz wykonać pewne zadania."<<endl<<"Mogą cię uratować albo jeszcze bardziej pogrążyć. Czy jesteś pewny, że chcesz zaryzykować ? " << endl;
            
            cin >> odp;
            if (odp == "nie") break;
           
            cout << "Oto twoje pierwsze zadanie. Spotkałeś na swojej drodze surowego profesora. Przygotowane przez niego pytania na egzamin są chyba z kosmosu. Dostajesz jednak szansę."<<endl<<"Jeżeli wygrasz z nim w „kółko i krzyżyk” unikniesz pisania egzaminu, a twoja ocena wyniesie 5.0. Czy jesteś gotowy? Ta misja będzie wymagać od Ciebie sprytu i szczęścia. Niech moc będzie z Tobą! Powodzenia!" << endl;
            cout << endl;

            Kolko f;
            f.kolko();

            system("cls");
            if (porażka == 0) {
                cout << "Bardzo się starałeś, lecz z gry wyleciałeś :C Cóż, powodzenia na egzaminie. Lepiej przyłóż się do nauki. Żegnaj studencie." << endl;
                break;
            }
            else
            cout << "Udało się!!! Pierwsza misja za Tobą. Tym razem na Twojej drodze pojawił się dziwny stwór. To wszechwiedzący troll. Proponuje ci grę w „Papier, kamień, nożyce”."<<endl<<"Jeśli wygrasz pomoże Ci w na wybranym egzaminie, jeśli jednak przegrasz do końca życia będziesz musiał mu usługiwać. Ryzykujesz? Chyba warto. Obyś przechytrzył sprytnego trolla." << endl;
            cout << endl;

            porażka = 1;
            pocz_papier();
            system("cls");
            if (porażka == 0) {
                cout << "Niestety nie tym razem :( Musisz teraz być na każde zawołanie trolla. Czeka Cię ciężki żywot. Żegnaj studencie." << endl;
                break;
            }
            else
                cout << "4.	WOW :O Gratulacje! Kolejną misją jest gra w „memory”. Twój przeciwnik to starożytny myśliciel. Może da Ci fory. Jeśli nie… - (x_x)-> Ale trzeba być dobrej myśli.Wygrana to dodatkowy czas na naukę.Otrzymasz zmieniacz czasu, będziesz mógł go jednak wykorzystać tylko raz.Powodzenia przyjacielu." << endl;
            cout << endl;
        
        
        }
        if (stan == 0) {

            cout << "Wyjście z programu";

        }
            return 0;

        }





    }
