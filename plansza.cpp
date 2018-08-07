#include "plansza.h"
#include<iostream>
using namespace std;


plansza::plansza()
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (j == 0)
				tab[i][j] = i;
			else
				if (i == 0)
					tab[i][j] = j;
				else
					tab[i][j] = 0;
		}
	}
	for (int i = 0; i < 12; i++)
	{
		tab[i][11] = -1;

	}
	for (int j = 0; j < 12; j++)
	{
		tab[11][j] = -1;
	}

}



plansza::~plansza()
{
}

void plansza::wyswietl()
{
	cout<<"\n \n";
	for (int i = 0; i < 11; i++)
	{

		for (int j = 0; j < 11; j++)
		{
			if (tab[i][j] == 12)
				cout << "    X";
			
			
				else
				if (tab[i][j] == 11||tab[i][j]==20)
					cout << "     ";
				else
					if (i == 0 && j == 0)
						cout << "     ";
					else
						if (i == 10 && j == 0)
						{
							cout.width(5);
							cout << tab[i][j];
						}
						else
						{
							cout.width(5);
							cout << tab[i][j];
						}
		}
		cout<<"\n";
	}
}