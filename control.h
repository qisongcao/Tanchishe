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
	static void Gameinit();		//�����ʼ������Ҫ�ǹ̶�����̨�����С�����β�����
	static void Map();			//����ͼ
	static void Score();		//��Ҫ��ʾ�÷��������Ϸ�Ѷ�
	static void gotoxy(int x, int y);
	bool food_eat(snake* s,Food *f);	//�ж�ʳ���Ƿ�Ե�
	void Show();
	bool Choose_module();
	void run();			//��Ϸ����
	~Gameset();
};