#include "main.h"

#ifndef __COLOR_LIST_		//enum을 한번만 정의하기 위한 작업 (중복 제거)
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
