#pragma once
#include<iostream>

using namespace std;
int punkty = 0;
int pora¿ka=1;

int licznik_fun() {

	punkty += 5;
	pora¿ka = 1;
	return punkty;
}


int przegrana() {
	pora¿ka = 0;
	return pora¿ka;
}