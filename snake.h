#pragma once
#include <Windows.h>
#include <iostream>
#include "unit.h"
#include <vector>
#include <conio.h>
#include <string.h>
#define DOWN 1	//定义方向的宏变量
#define UP 2
#define	RIGHT 3
#define LEFT 4
#define PAUSE 5
#define Default Sleep(400)	//定义速度的宏变量，通过定义sleep时间来决定蛇的移动速度
#define Simple Sleep(200)	
#define Hard Sleep(100)
#define Hell Sleep(75)
#define Nightmare Sleep(50)
#define Budangren Sleep(25)
class snake :public unit
{
public:
	bool alive; 
	int direction;
	vector<COORD>body;
public:
	snake();
	void listen_keyborad();		//监听键盘事件
	void snake_show();			//画蛇身
	bool Alive();				//判断蛇是否存活
	void snake_move();			//蛇的移动
	void gotxy(int x, int y);	//蛇的坐标获取
	void module();				//游戏难度（通过蛇的移动速度控制难度）
	//bool Pause();
};