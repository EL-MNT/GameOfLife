/*
Eine tote Zelle mit genau drei lebenden Nachbarn wird neu geboren.
Lebende Zellen mit weniger als zwei lebenden Nachbarn sterben.
Eine lebende Zelle mit zwei oder drei lebenden Nachbarn bleibt Leben.
Lebende Zellen mit mehr als drei lebenden Nachbarn sterben.

2D Array- Boolean				//Spielfeld 1-1 = True = belegt

1.Anfangen Felder zu initalisieren. // Array wird bereitgestellt (Alle felder auf false)
2.Erzeuge Anfangsgeneration.
3.Zeige aktuelle Generation.	//Stelle die Generation dar. (Wird aus dem initialisieren Speicher gelesen)
4.Solange nicht fertig.         //3-5 Regeln anwenden.
5.Zelle Nachbarn? 
6.Erzeuge neue Generation.
7.Zeige aktuelle Generation.
*/
#include "pch.h"
#include <iostream>
#include "windows.h"
#include "time.h"
#include <stdlib.h>
#include <Bits.h>

using namespace std;

int const breite = 55, hoehe = 50;
bool spielfeld[breite][hoehe];
int zaehlfeld[breite][hoehe];

void initfield()
{
	for (int zeile = 0; zeile < hoehe; zeile++)
		for (int spalte = 0; spalte < breite;spalte++)
		{
			spielfeld[zeile][spalte] = false;
			zaehlfeld[zeile][spalte] = 0;
		}
}
void buildstart()
{
	int num;

	system("Color 02");
	cout << "Wählen Sie eine Startgeneration aus" << endl << "[1] 34. Generation" << endl << "[2] Irgendwas" << endl << "[3] Random" << endl;
	cin >> num;

	switch (num)
	{
	case 1:
		spielfeld[22][22] = true;
		spielfeld[22][23] = true;
		spielfeld[22][24] = true;
		spielfeld[23][22] = true;
		spielfeld[23][24] = true;
		spielfeld[24][22] = true;
		spielfeld[24][24] = true;
		spielfeld[26][22] = true;
		spielfeld[26][24] = true;
		spielfeld[27][22] = true;
		spielfeld[27][24] = true;
		spielfeld[28][22] = true;
		spielfeld[28][23] = true;
		spielfeld[28][24] = true;
		break;

	case 2:
		spielfeld[22][23] = true;
		spielfeld[23][23] = true;
		spielfeld[24][23] = true;
		spielfeld[28][26] = true;
		spielfeld[25][22] = true;
		spielfeld[21][23] = true;
		spielfeld[28][27] = true;
		spielfeld[27][25] = true;
		spielfeld[22][21] = true;
		break;
		
	case 3:
		srand(time(NULL));
		for (int zeile = 0; zeile < hoehe; zeile++)
			for (int spalte = 0; spalte < breite; spalte++)
			{
				int zufall = rand() % 100;
				spielfeld[zeile][spalte] = (zufall < 30);
			}
		break;
	}
}
void showGen()											//Zeige Generation 
{
	system("cls");
	for (int zeile = 0; zeile < hoehe; zeile++)
	{
		for (int spalte = 0; spalte < breite; spalte++)
		{
			if (spielfeld[zeile][spalte] == true)
				cout << '+';
			else
				cout << ' ';
		}
		cout << endl;
	}
}
int countneigh(int zeile, int spalte)						//Check den nachbarn
{
	int c = 0;

			if (spielfeld[zeile - 1][spalte - 1] == true)
				c += 1;

			if (spielfeld[zeile][spalte - 1] == true)
				c += 1;

			if (spielfeld[zeile + 1][spalte - 1] == true)
				c += 1;

			if (spielfeld[zeile - 1][spalte] == true)
				c += 1;

			if (spielfeld[zeile + 1][spalte] == true)
				c += 1;
			
			if (spielfeld[zeile - 1][spalte + 1] == true)
				c += 1;

			if (spielfeld[zeile][spalte + 1] == true)
				c += 1;

			if (spielfeld[zeile + 1][spalte + 1] == true)
				c += 1;
	return c;
}
void count()															//check zelle
	{
		for (int zeile = 1; zeile < hoehe - 1; zeile++)
			for (int spalte = 1; spalte < breite - 1; spalte++)
				zaehlfeld[zeile][spalte] = countneigh(zeile, spalte);
	}
void newGen()															// new generation - Logik
{
for (int zeile = 1; zeile < hoehe - 1; zeile++)
	for (int spalte = 1; spalte < breite - 1; spalte++)

	switch (zaehlfeld[zeile][spalte])
	{
	case 2:
			break;
	case 3:
		spielfeld[zeile][spalte] = true;
			break;
	default:
		spielfeld[zeile][spalte] = false;
	}
}

int main()
{ 
	initfield();
	buildstart();
	showGen();
	while (true)
	{
		count();			//zähle Nachbarn greift schreibend auf das Zählfeld (X und Y Koordinaten)
		newGen();			//neue generation
		//system("pause");	
		showGen();
	}
	return 0;
}