#pragma once
#include <Windows.h>
#include <iostream>
#include <ctime>
#include "unit.h"

class Food :public unit
{
public:
	COORD Zuobiao;
public:
	void food_produce();	//生产食物
	COORD Getfood();	//获得食物的坐标
	void show(int x, int y);
};