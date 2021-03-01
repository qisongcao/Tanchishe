#include "snake.h"
#include "control.h"
static int front;
snake::snake()
{
	direction = 2;
	alive = true;
	int i = 0;
	COORD head;	
	head.Y = Gameset::window_height / 2;	//定义蛇头初始横坐标
	head.X = Gameset::window_width / 2 - 15;	//定义蛇头初始尾坐标
	while (i < 4)						//定义初始长度为4
	{
		body.push_back(head);		//把一个一个点加入到body里面构成蛇身
		head.Y++;
		i++;
	}
	body.push_back(head);	
}

void snake::listen_keyborad()
{
	char ch;
	if (_kbhit())	//从键盘获取一个按键，判断其是否按下，按下为1，否则为0
	{
		ch = _getch();		//获取按下的键
		switch (ch)
		{
		case 'w':			
		case 'W':
		case 72:	//方向键的 up_arrow；
			if (direction ==DOWN)
				break;
			direction = UP;
			//front = UP;
			break;
		case'S':
		case's':
		case 80:	//方向键的 down_arrow；
			if (direction == UP)
				break;
			direction = DOWN;
			front = DOWN;
			break;
		case'A':
		case'a':
		case 75:	//方向键的 left_arrow；
			if (direction == RIGHT)
				break;
			direction = LEFT;
			front = LEFT;
			break;
		case'D':
		case'd':
		case 77:	//方向键的 right_arrow；
			if (direction == LEFT)
				break;
			direction = RIGHT;
			front = RIGHT;
			break;
		case 32:
			direction = PAUSE;
		default:
			break;
		}
	}
//	else
//	{
//		if ((GetKeyState(VK_UP)) )
//		{
//			if (direction == DOWN)
//				return;
//			direction = UP;
//		}
//		else if ((GetKeyState(VK_DOWN) ))
//		{
//			if (direction == UP)
//				return;
//			direction = DOWN;
//		}
//		else if (GetKeyState(VK_LEFT) )
//		{
//			if (direction == RIGHT)
//				return;
//			direction = LEFT;
//		}
//		else if (GetKeyState(VK_RIGHT) )
//		{
//			if (direction==LEFT)
//				return;
//			direction = RIGHT;
//		}
//	}
}
void snake::snake_show()
{
	gotxy(body[this->body.size() - 1].X, body[this->body.size() - 1].Y);
	cout << " ";
	short i = 0;
	for (;i < body.size();i++)
	{
		gotxy(body[i].X, body[i].Y);
		if (i == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);
			cout <<'@';
			continue;
		}
		cout <<'*';
	}
}
bool snake::Alive()	
{
	if (body[0].X <=0  || body[0].X >=Gameset::window_width-29  || body[0].Y <= 0 || body[0].Y >=Gameset::window_height -1 )	//判断碰壁死
	{
		alive = false;
		return alive;
	}
	short i = 1;
	for (;i < body.size();i++)			//判断自残死
	{
		if (body[i].X == body[0].X && body[i].Y == body[0].Y)
		{
			alive = false;
			return alive;
		}
	}
	alive = true;
	return alive;
}
void snake::snake_move()
{
	listen_keyborad();
	COORD head = body[0];
	switch (direction)
	{
	case UP:
		head.Y=body.front().Y-1;		//上移就是头的纵坐标-1;
		head.X = body.front().X;
		break;
	case DOWN:
		head.Y=body.front().Y+1;
		head.X = body.front().X;
		break;
	case RIGHT:
		head.X=body.front().X+1;		//右移就是头的横坐标+1
		head.Y = body.front().Y;
		break;
	case LEFT:
		head.X=body.front().X-1;
		head.Y=body.front().Y;
		break;
	case PAUSE:
		system("pause");
		break;
	default:
		break;
	}
	snake_show();							//每次移动后重新画出蛇身
	body.insert(body.begin(), head);		//清除蛇的移动痕迹
}
void snake::gotxy(int x, int y)
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;    // position 是一个 COORD 结构
	position.X = x;
	position.Y = y;
	//将光标放在那里，然后开始打印
	SetConsoleCursorPosition(screen, position);
}
void snake::module()			//游戏难度调整（通过判断分数)
{
	if(Gameset::score>=0 && Gameset::score<30)
	{ 
		snake_move();
		Default;
	}
	else if (Gameset::score>=30 && Gameset::score < 100)
	{
		snake_move();
		Simple;
	}
	else if (Gameset::score >= 100 && Gameset::score < 250)
	{
		snake_move();
		Hard;
	}
	else if(Gameset::score >= 250 && Gameset::score<=300)
	{
		snake_move();
		Hell;
	}
	else if(Gameset::score >=300 && Gameset::score<500)
	{
		snake_move();
		Nightmare;
	}
	else
	{
		snake_move();
		Budangren;
	}
}
//bool snake::Pause()
//{
//	char ch;
//	if (_kbhit())
//	{
//		ch = _getch();
//		if (ch == 224)
//		{
//			ch = _getch();
//			if (ch == 32)
//			{
//				direction = PAUSE;
//				return true;
//			}
//			else
//				return false;
//		}
//	}
//	else
//		return false;
//}