#pragma once
#include <iostream>
#include <Windows.h>
#include <ctime>
#include "snake.h"
#include "food.h"
using namespace std;
typedef struct Arrow {
	int x;
	int y;
	string str;
};
class Gameset
{
public:
	static const int window_height = 40;
	static const int window_width = 80;
	static int score;
	Food* f = new Food;
	snake* s = new snake;
public:
	static void Gameinit();		//界面初始化，主要是固定控制台输出大小和清除尾部光标
	static void Map();			//画地图
	static void Score();		//主要显示得分情况和游戏难度
	static void gotoxy(int x, int y);
	bool food_eat(snake* s,Food *f);	//判断食物是否吃掉
	void Show();
	bool Choose_module();
	void run();			//游戏运行
	~Gameset();
};