#include "main.h"

#ifndef KEY_CODE
#define KEY_CODE

//keyboard
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

#define SUBMIT 4	//select button(Spacebar)
#define OUT 5

#endif

void move(int*, int*, int, int, int*, int*);	//move for the movement of character
//x,y,_x,_y,key,playing, vision
void gameLoop(int);		//for game loop
int keyboardControl();		//WASD - UP DOWN LEFT RIGHT
void titleDraw();			//show title on screen
int menuSelection();		//for options in the beginning
void gameInfo();				//explains controls, developer's name, etc
int maplistDraw();
void drawMap(int*, int*);		//prints map when select easy, hard
// int* int* to save memory address (pointer)
void drawUI(int*, int*, int*);
//void vision(int*, int*);	//flashlight

//char mapArray[20][56];		//2 dimentional array for map x=56,y=20
//[rows][cols], so [ vertical (y) ][ horizontal (x) ]

