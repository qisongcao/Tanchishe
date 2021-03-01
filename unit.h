#pragma once
#include <Windows.h>
#include <iostream>
#include <ctime>
#define random(x) rand()%(x)
using namespace std;
class unit
{
public:
	unit(int x = 10, int y = 5, char pic = '*');
	~unit();
	void show();
	void erase();
	static void gotoxy(int x, int y);

public:
	int X;
	int Y;
	char m_cPic;
};
