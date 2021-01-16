#pragma once
#include "Kolko.h"
#include "licznik_pkt.h"

// Funkcja rysuje planszê gry w kó³ko i krzy¿yk
//---------------------------------------------

void Kolko::plansza(char t[])
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

// Funkcja zwraca true, jeœli nast¹pi³a
// wygrana danego zawodnika
//-------------------------------------

bool Kolko::wygrana(char t[], char g)
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
        if (g == 'O') {
            punkty = 0;
            licznik_fun();
        }
        else przegrana();
        cout << "\nGRACZ " << g << " WYGRYWA!!!\n\n";
        return true;
    }
    return false;
}

// Funkcja zwraca true, jeœli na planszy nie ma ju¿
// ¿adnego wolnego pola na ruch.
//-------------------------------------------------


bool Kolko::remis(char t[])
{
    for (int i = 1; i <= 9; i++)
        if (t[i] == ' ') return false;
    plansza(t);
    cout << "\nREMIS !!!\n\n";
    return true;
}

// Funkcja umo¿liwia ruch gracza
// Po ruchu nastêpuje zamiana gracza
//------------------------------------

void Kolko::ruch_komp(char t[], char komp)
{
    int r;
    srand(time(NULL));
    plansza(t);
    cout << "\nGRACZ " << komp << " : Twoj ruch : ";
    do {
        r = (1 + (rand() % (9 - 1 + 1)));
    } while (t[r] != ' ');
    cout << r << endl;
    cout << "-----------------------\n\n";
    if ((r >= 1) && (r <= 9) && (t[r] == ' ')) t[r] = komp;
   char gracz = 'O';
    for (int i = 1; i <= 9; i++)
        if (!wygrana(t, 'X') && !wygrana(t, 'O') && !remis(t))
            ruch(t, gracz);
        else system("cls");
}

void Kolko::ruch(char t[], char gracz)
{
    int r;

    plansza(t);
    cout << "\nGRACZ " << gracz << " : Twoj ruch : ";
    cin >> r;
    cout << "-----------------------\n\n";
    if ((r >= 1) && (r <= 9) && (t[r] == ' ')) t[r] = gracz;
    char komp = 'X';
    for (int i = 1; i <= 9; i++)
        if (!wygrana(t, 'X') && !wygrana(t, 'O') && !remis(t))
            ruch_komp(t, komp);
        else system("cls");
}

void Kolko::kolko()
{
    // kolko i krzyzyk operacja na cyferkach
    char p[10], g, w = 0;

    do
    {
        cout << "Gra w Kolko i Krzyzyk dla dwoch graczy, operujemy na liczbach od 1 do 9, gracz, który w poziomie,pionie albo po ukosie zbierze swoje figury wygrywa\n"
            "======================================\n\n";
        for (int i = 1; i <= 9; i++) p[i] = ' ';
        g = 'O';
        while (!wygrana(p, 'X') && !wygrana(p, 'O') && !remis(p)) ruch(p, g);
        cout << "Jeszcze raz ? (T = TAK) : ";
        cin >> w;
        cout << "\n\n\n";
    } while ((w == 'T') || (w == 't'));
}
