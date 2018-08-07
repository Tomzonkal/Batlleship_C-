#include "Statek.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

Statek::Statek()
{
	cout << "brak argumentów";
}
Statek::Statek(int poziom, int rozmiar,int xu,int yu, int tab[12][12])
{

	bool granice=1;
	while(granice==true)
	{
		if (poziom == 0)
		{
			if ((xu > 10|| xu < 1) || (yu < 1 || y>10))
			{
				cout << "wspolrzedne sa poza plansza wprowadz jeszcze raz\n";
			}
			else
				if (tab[xu][yu] != 0 || tab[xu][yu - (rozmiar / 2)] || tab[xu][yu + (rozmiar / 2)] )
				{
					cout << "wspolrzedne nachodza na pole innego obiektu lub poza granica \n";
				}
				else
					if(tab[xu + 1][yu] == 0 || tab[xu - 1][yu] == 0&&rozmiar==5)
				{
					granice = false;
				}
		}


		if (poziom == 1)
		{
			if ((xu > 10 || xu < 1) || (yu < 1 || y>10))
			{
				cout << "wspolrzedne s¹ poza plansza wprowadz jeszcze raz\n";
			}
			else
				if (tab[xu][yu] != 0 || tab[xu - (rozmiar / 2)][yu ]!=0|| tab[xu+ (rozmiar / 2)][yu]!=0)
				{
					cout << "wspolrzedne nachodza na pole innego obiektu lub poza granica \n";
				}
				else
				{
					if (rozmiar == 5 && (tab[xu + 1][yu] != 0 || tab[xu - 1][yu] != 0))
						cout << "zle wspolrzedne";
					else
					granice = false;
				}
		}
		if (granice == true)
		{
			cout << "wprowadz x \n";
			cin >> xu;
			cout << "wprowadz y \n";
			cin >> yu;
		}


		x = xu;
		y = yu;
	}



	if (poziom == 0)
	{
		for (int i = 0; i <= (rozmiar / 2); i++)
		{
			tab[x][y - i] = rozmiar;
			tab[x][y + i] = rozmiar;
		}
	}


	if (poziom == 1)
	{
		for (int i = 0; i <= (rozmiar / 2); i++)
		{
			tab[x - i][y] = rozmiar;
			tab[x + i][y] = rozmiar;
		}
	}
}


Statek::Statek(int poziom,int rozmiar,int tab[12][12])
{
	bool granice = 1;
	srand(time(NULL));
	int xu = rand() % 11;
	int yu = rand() % 11;

	while (granice == true)
	{
		if (poziom == 0)
		{
			if (
				(xu <= 9 || xu >= 0) || (yu >= 0 || yu <= 9) ||
				tab[xu][yu] == 0 || tab[xu][yu - (rozmiar / 2)] == 0 || tab[xu][yu + (rozmiar / 2)] == 0 ||
				tab[xu][yu + 1] == 0 || tab[xu][yu - 1] == 0)
			{
			
				granice = false;
			}
		}
		if (poziom == 1)
		{
			if (
				(xu <= 9 || xu >= 0) || (yu >= 0 || yu <= 9) ||
				tab[xu][yu] == 0 || tab[xu - (rozmiar / 2)][yu ] == 0 || tab[xu + (rozmiar / 2)][yu] == 0 ||
				tab[xu+1][yu] == 0 || tab[xu-1][yu] == 0)
			{
			
					granice = false;
			}
		}
		if (granice == true)
		{
			int xu = rand() % 10;
			int yu = rand() % 10;

		}
		else
		{
			x = xu;
			y = yu;
			
		}
	}
	if (poziom == 0)
	{
		for (int i = 0; i <= (rozmiar / 2); i++)
		{
			tab[x][y - i] = rozmiar;
			tab[x][y + i] = rozmiar;
		}
	}
	if (poziom == 1)
	{
		for (int i = 0; i <= (rozmiar / 2); i++)
		{
			tab[x - i][y] = rozmiar;
			tab[x + i][y] = rozmiar;
		}
	}
}




Statek::~Statek()
{
}
