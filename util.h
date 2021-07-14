#include "main.h"

#ifndef __COLOR_LIST_		//enum�� �ѹ��� �����ϱ� ���� �۾� (�ߺ� ����)
#define __COLOR_LIST_

enum {					//list of colors (0~15)
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray,
	darkgray,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yellow,
	white
};
#endif

void cursor(int, int);		//function that moves the cursor
void init();				//controls the size of the console
void setColor(int, int);	//for color of background/text
