#pragma once
#include <Windows.h>
#include <iostream>
#include "unit.h"
#include <vector>
#include <conio.h>
#include <string.h>
#define DOWN 1	//���巽��ĺ����
#define UP 2
#define	RIGHT 3
#define LEFT 4
#define PAUSE 5
#define Default Sleep(400)	//�����ٶȵĺ������ͨ������sleepʱ���������ߵ��ƶ��ٶ�
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
	void listen_keyborad();		//���������¼�
	void snake_show();			//������
	bool Alive();				//�ж����Ƿ���
	void snake_move();			//�ߵ��ƶ�
	void gotxy(int x, int y);	//�ߵ������ȡ
	void module();				//��Ϸ�Ѷȣ�ͨ���ߵ��ƶ��ٶȿ����Ѷȣ�
	//bool Pause();
};