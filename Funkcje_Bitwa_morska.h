#pragma once
#include<iostream>
#include"plansza.h"
#include"Statek.h"
using namespace std;


void wystawa(plansza &gracz, plansza& wrog)
{
	srand(time(NULL));
	int poziom, x, y;
	for (int i = 1; i <= 5; i += 2)
	{
		cout << "wybierz czy statek " << i << "-masztowy ma byc w pionie czy poziomie:\n 1-pion\n0-poziom\n";
		cin >> poziom;
		while (poziom > 1 || poziom < 0)
		{

			if (poziom > 1 || poziom < 0)cout << "zla wartosc\n podaj znowu\n";
			cin >> poziom;
		}
		cout << "Podaj wspolrzedne x,y\n";
		cin >> x >> y;
		new Statek(poziom, i, x, y, gracz.tab);
		new Statek((rand() % 2), i, wrog.tab);
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Rozgrywka

int start()
{

	int rozgrywka=0;

	while (rozgrywka != 1 && rozgrywka != 2)
	{
		cout << "\nPodaj rodzaj rozgrywki:\n 1-soba vs komputer\n 2-osoba vs osoba";
		cin >> rozgrywka;
	}
	return rozgrywka;
}
int komputer_trafienie(int x, int y)
{
	if (x == 0 && y == 0)
		return 0;
}

void strzal_osoba(plansza &wrog,plansza &podglad,int x,int y)
{
	if (wrog.tab[x][y] == 3 || wrog.tab[x][y] == 1 || wrog.tab[x][y] == 5)
		podglad.tab[x][y]= wrog.tab[x][y];
	else
	podglad.tab[x][y]=20;
}

void strzal_komputer(plansza &gracz)
{
	
	static int tab[12][12]{};

	int x1 = rand() % 11 + 1;
	int y1 = rand() % 11 + 1;
	while (tab[x1][y1] == 1||x1==11||y1==11)
	{
		x1 = rand() % 11 + 1;
		y1 = rand() % 11 + 1;
	}
	if (gracz.tab[x1][y1] != 0)
	{
		
		
		gracz.tab[x1][y1] = 12;
		tab[x1][y1] = 1;
	

	}
	else
	{
		tab[x1][y1] = 1;
	}





}




int koniec(plansza &gracz,plansza &podglad)
{
	int trzy = 0, jeden = 0, piec = 0;
	int x = 0;
	for (int i = 1; i<12; i++)
		for (int j = 1; j < 12; j++)
		{
			if (podglad.tab[i][j] == 1)jeden++;
			if (podglad.tab[i][j] == 3)trzy++;
			if (podglad.tab[i][j] == 5)piec++;
		}

	for (int i = 0; i<12; i++)
		for (int j = 0; j < 12; j++)
		{
			if (gracz.tab[i][j] == 12)
				x++;
		}
	if ((jeden == 1 && trzy == 3 && piec == 5))
	{
		cout<<"wygrales\n"; return 0;
	}

	if (x == 9)
	{
		cout<<"przegrales\n"; return 0;
	}

	return 1;



}


void gra_osoba_vs_komputer()
{
	int x=0, y=0;
	plansza gracz;
	plansza wrog;
	plansza podglad;
	wystawa(gracz, wrog);
	cout << "Zaczynasz gre\n";
	while (koniec(gracz, podglad))
	{
		x = 0;
		y = 0;
		while ((x <= 0 || x >= 11) || (y <= 0 || y >=11))
		{
			cout << "\npodaj x,y \n";

			cin >> x >> y;
		}
		strzal_osoba(wrog, podglad, x, y);
		if (!koniec(gracz, podglad))break;
		strzal_komputer( gracz);

		gracz.wyswietl();
		cout << endl << endl;
		podglad.wyswietl();















	}
}
