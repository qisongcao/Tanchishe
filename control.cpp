#include "control.h"
#include <iostream>
#include "snake.h"
#define H 50
#define Z 13
#define EXIT system("exit")
#define CLS system("cls")
int Gameset::score = 0;
Arrow arrow = { H - 2,Z,"→" };
void Gameset::Gameinit()
{
	char buffer[32];
	sprintf_s(buffer, "mode con cols=%d lines=%d", window_width, window_height);	//固定控制台输出大小
	system(buffer);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE)  ;		
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);	
	CursorInfo.bVisible = false; 
	SetConsoleCursorInfo(handle, &CursorInfo);	//清除光标
	srand((unsigned int)time(0));
}
Gameset::~Gameset()
{
	delete s;
	delete f;
}
void Gameset::Map()
{
	system("cls");
	int i, j;
	for (i = 0;i < Gameset::window_width;i++)
	{
		printf("-");
	}
	printf("\n");
	for (i=0;i<Gameset::window_height -2;i++)
	{
		for (j=0;j<Gameset::window_width;j++)
		{
			if (i==13 && j>=Gameset::window_width -29)
			{
				printf("-");
				continue;
			}
			if (j==0 || j==Gameset::window_width - 29 || j==Gameset::window_width -1)
			{
				printf("|");
			}
			else
				printf(" ");

		}
		printf("\n");
	}
	for (i=0;i<Gameset::window_width;i++)
		printf("-");
}
void Gameset::gotoxy(int x, int y)
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;    // position 是一个 COORD 结构
	position.X = x;
	position.Y = y;
	//将光标放在那里，然后开始打印
	SetConsoleCursorPosition(screen, position);
}
void Gameset::Score()
{
	snake s;
	//gotoxy(Gameset::window_width - 20 + 13, 7);
	//cout << "";
	//gotoxy(Gameset::window_height - 20 + 13, 5);
	//cout << "";
	gotoxy(Gameset::window_width - 20, 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	cout << "当前分数为: " << score << endl;
	if (score >= 0 && score < 30)
	{
		gotoxy(Gameset::window_width - 20, 8);
		cout << "当前难度为：简单级" << endl;
	}
	else if (score >= 30 && score < 100)
	{
		gotoxy(Gameset::window_width - 20, 8);
		cout << "当前难度为：普通级" << endl;
	}
	else if (score >= 100 && score < 250)
	{
		gotoxy(Gameset::window_width - 20, 8);
		cout << "当前难度为：困难级" << endl;
	}
	else if (score >= 250 && score < 300)
	{
		gotoxy(Gameset::window_width - 20, 8);
		cout << "当前难度为：地狱级" << endl;
	}
	else if (score >= 300 && score <500)
	{
		gotoxy(Gameset::window_width - 20, 8);
		cout << "当前难度为：噩梦级" << endl;
	}
	else
	{
		gotoxy(Gameset::window_width - 20, 8);
		cout << "当前难度为：变态级" << endl;
	}
	gotoxy(Gameset::window_width - 25, Gameset::window_height / 2+5);
	cout << "编写者:Qisong Cao" << endl;
	gotoxy(Gameset::window_width - 25, Gameset::window_height / 2+6);
	cout << "游戏名称：贪吃蛇" << endl;
	

}
bool Gameset::food_eat(snake* s,Food *f)
{
	COORD Food = f->Getfood();
	if (s->body[0].X == Food.X && s->body[0].Y == Food.Y)
	{
		f->gotoxy(Food.X,Food.Y);
		f->food_produce();
		return true;
	}
	else
	{
		s->gotxy(s->body.back().X,s->body.back().Y);
		cout << " ";
		s->body.pop_back();
		//s->body.erase(s->body.end() - 1);
		return false;
	}
}

void Gameset::Show()
{
	unit p;
	p.gotoxy(arrow.x, arrow.y);
	cout << arrow.str;
	p.gotoxy(H, Z);
	cout << "开始游戏" << endl;
	p.gotoxy(H, Z+1);
	cout << "排行榜" << endl;
	p.gotoxy(H, Z+2);
	cout << "退出游戏" << endl;
}

bool Gameset::Choose_module()
{
	char ch;
	while (_kbhit())
	{
		ch = _getch();
		switch (ch)
		{
		case'w':
		case'W':
		if (arrow.y == Z)
			arrow.y = arrow.y;
		else
		{
			arrow.y = arrow.y - 1;
			CLS;
			Show();
			break;
		}
		case's':
		case'S':
		if (arrow.y == Z + 2)
			arrow.y = arrow.y;
		else
		{
			arrow.y = arrow.y + 1;
			CLS;
			Show();
			break;
		}
		default:
			break;
		}
	}
		//if (GetAsyncKeyState(VK_UP) && 0x26)
		//{
		//	if (arrow.y == Z)
		//		arrow.y = arrow.y;
		//	else
		//	{
		//		arrow.y = arrow.y - 1;
		//		CLS;
		//		Show();
		//	}
		//}
		//else if (GetAsyncKeyState(VK_DOWN) && 0x28)
		//{
		//	if (arrow.y <= Z + 2)
		//		arrow.y = arrow.y;
		//	else
		//	{
		//		arrow.y = arrow.y + 1;
		//		CLS;
		//		Show();
		//	}
		//}
		//else if (GetAsyncKeyState(VK_RETURN) && 0x0D)
		//{
		//	if (arrow.y == Z)
		//	{
		//		return true;
		//	}
		//	else if (arrow.y == Z + 1)
		//	{
		//		return false;
		//	}
		//	else if (arrow.y == Z + 2)
		//		EXIT;
		//}
		//if (_kbhit())
		//{
		//	ch = _getch();
		//	switch (ch)
		//	{
		//	case'w':
		//	case'W':
		//		if (arrow.y == Z)
		//			arrow.y = arrow.y;
		//		else
		//		{
		//			arrow.y = arrow.y - 1;
		//			CLS;
		//			Show();
		//		}
		//	case's':
		//	case'S':
		//		if (arrow.y == Z + 2)
		//			arrow.y = arrow.y;
		//		else
		//		{
		//			arrow.y = arrow.y + 1;
		//			CLS;
		//			Show();
		//		}
		//	default:
		//		break;
		//	}
		//}
	return true;
}	

//int main()
//{
//	Gameset* set = new Gameset;
//	snake* s = new snake;
//	set->Gameinit();
//	set->Score();
//	s->snake_show();
//	bool flag = true;
//	while (flag)
//	{
//		s->listen_keyborad();
//		s->snake_move();
//
//	}
//}

void Gameset::run()
{
	bool flag = true;
	bool flag1 = true;
	bool flag2;
	//set->Show();
	//set->Choose_module();
	Gameinit();
	Map();
	Score();
	s->snake_show();
	while (flag)
	{
		Score();
		if (flag1)
		{
			f->food_produce();
			flag1 = false;
		}
		s->listen_keyborad();
		s->module();
		if (food_eat(s, f))
		{
			score = score + 10;
			flag1 = true;
		}
		if (s->Alive())
			continue;
		else
			flag = false;
	}
	system("cls");
	unit::gotoxy(25, 19);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	cout << "游戏结束,您的最终分数为：" << score;
	getchar();
	system("pause");
}
