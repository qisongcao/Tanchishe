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
	void food_produce();	//����ʳ��
	COORD Getfood();	//���ʳ�������
	void show(int x, int y);
};