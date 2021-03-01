//#include "pch.h"
#include "unit.h"


unit::unit(int x, int y, char pic):X(x),Y(y), m_cPic(pic)
{
}

unit::~unit()
{
}

void unit::show()
{
	gotoxy(X, Y);
	cout << m_cPic;
}

void unit::erase()
{
	gotoxy(X, Y);
	cout << " ";
}

void unit::gotoxy(int x, int y)
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;    // position 是一个 COORD 结构
	position.X = x;
	position.Y = y;
	//将光标放在那里，然后开始打印
	SetConsoleCursorPosition(screen, position);
}
