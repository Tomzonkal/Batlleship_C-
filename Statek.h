#pragma once
class Statek
{
	int rozmiar;
	int poziom;
	int x;
	int y;

public:
	Statek();
	Statek(int ,int ,int, int, int[12][12]);
	Statek(int,int,int[12][12]);
	~Statek();
	
};

