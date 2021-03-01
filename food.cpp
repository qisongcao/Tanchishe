#include "food.h"
#include "control.h"
#include "snake.h"
void Food::food_produce()
{
	snake s;
	srand(unsigned int(time(0)));
	X = rand() % (Gameset::window_height - 2) +1;
	Y = rand() % (Gameset::window_width - 30)+1 ;
	while (X >= Gameset::window_width -29 || Y >= Gameset::window_height -2 || X<=3 || Y<=3)	//如果食物生成到墙里面就重新生成
	{
		X = rand() % (Gameset::window_height - 2) + 1;
		Y = rand() % (Gameset::window_width - 30) + 1;
	}
	for (short i = 0;i < s.body.size();i++)
	{
		if (X == s.body[i].X && Y == s.body[i].Y)			//如果食物生成的地方和蛇身坐标重叠也重新生成
		{
			X = rand() % (Gameset::window_height - 2) + 1;
			Y = rand() % (Gameset::window_width - 30) + 1;
		}
	}
	show(X,Y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); //将食物用亮白色显示
	cout << "#";
}
COORD Food::Getfood()
{
	COORD zuobiao;
	zuobiao.X = X;
	zuobiao.Y = Y;
	return zuobiao;
}
void Food::show(int x, int y)
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;    // position 是一个 COORD 结构
	position.X = x;
	position.Y = y;
	//将光标放在那里，然后开始打印
	SetConsoleCursorPosition(screen, position);
}

//int main()
//{
//	Food* f = new Food;
//	f->food_produce();
//	system("pause");
//}