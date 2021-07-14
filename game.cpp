#include "game.h"
#include "util.h"

char tempMap[20][56];		//save the map that we're using. If easy level, map 1 goes in here. For hard level, map 2 goes in here

char mapArray_1[20][56] = {	//for easy level
	{"1111111111111111111111111111111111111111111111111111111"},	//56 lines (cols), 20 rows
	{"1000000000000000010000000000000010000000010000011000001"},
	{"1000111111100100010111111101111010111111110111011010101"},
	{"1000100000100100010100000101111010111110000001011011111"},
	{"1000100100100100010000000100000010000010111100000000001"},
	{"1000100100100100010100000001111011111010000111111111111"},
	{"1000100100000100010111111101100000000010100100000000001"},
	{"1000111111111100010000001101100111111010100101100111001"},
	{"1000000000000000011111101101100000000000100111100111111"},
	{"10000000000000000L0000000000001111111001100000000000001"},
	{"1000111111100110011111111101101111111101001011100111101"},
	{"100010000000011001001110110000000000010100100000001k101"},
	{"1000100111111110010011101111111111110111001001111010101"},
	{"1000100111100000010000001100000000000100001001000010001"},
	{"1000100111100110000111111111110110111110101001010011111"},
	{"1000100011100110010110000101110110000000101001110011101"},
	{"1000110000000000010110111101110110111110101000000000001"},
	{"100011001111110111010000010001011011111011101111L111111"},
	{"10s0110k000001000000011111110000000000100000111100000f1"},
	{"1111111111111111111111111111111111111111111111111111111"}
};
//set 0 = empty space, 1 = wall, s = player start location, f = location, k = key, L = locked door
char mapArray_2[20][56] = {	//for hard level
	{"1111111111111111111111111111111111111111111111111111111"},	//56 lines (cols), 20 rows
	{"1k00000000000001010000000000000010000000010000011000001"},
	{"1110111111101101010111111101111010111111110111011010f01"},
	{"1010100001000101010100000001111010111110000111011L11111"},
	{"101000010101010111011111110000001000001011111100101k101"},
	{"10101111010101000L0100000001111011111010111111111L10001"},
	{"1010100101010101110111111101100010000010000000000011101"},
	{"1010100100010000010000001101111111111110111111111010101"},
	{"1000000111110111011111101101100L00000000100000001010101"},
	{"1010000000000000010000100001101111111101k01010101010001"},
	{"1010111111100110111110101101101111111101111010101010101"},
	{"1010100000000110101010101100L00000000100010010101000101"},
	{"1000101101111110100010101111111111110111011110111111101"},
	{"1010101101100000110000001100000000000100001010000000101"},
	{"1010101100101111010111111111110110111110101011111110001"},
	{"1010100111101111010110000101110110000k10101001110000101"},
	{"1000110000000000010110111101110110111110100100000111101"},
	{"1010111111111111110100000000010110111110111111111111101"},
	{"1s1011k000000000000101111111000000000010000000000000001"},
	{"1111111111111111111111111111111111111111111111111111111"}
};



void titleDraw() {
	printf("\n\n\n\n");
	printf("	#####   ###   ###   #    ####   #####\n");
	printf("	#      #     #	   # #   #  #   #    \n");
	printf("	#####   ###  #    #   #  ###    #####\n");
	printf("	#          # #    #####  #      #    \n");
	printf("	#####   ###   ### #   #  #      #####\n");

}
int menuSelection() {
	int x = 24;
	int y = 12;
	cursor(x - 2, y);	//-2 for >
	printf("> GAME START");
	cursor(x, y + 1);
	printf("GAME INFO");
	cursor(x, y + 2);
	printf("EXIT");

	while (1) {	//inf. loop
		int n = keyboardControl();	//keyboard event goes into n (as a value)
		switch (n) {
		case UP: {		//when we pressed UP (w)
			if (y > 12) {			//y would only move from y= 12 ~ 14 (y 12부터 14까지만 움직임!)
				cursor(x - 2, y);	//x-2 so that we can put >
				printf(" ");		//delete pre-existing > (from the current location)
				cursor(x - 2, --y);	//move to the new location
				printf(">");		//retype >
			}
			break;
		}
		case DOWN: {	//when pressed DOWN (s)
			if (y < 14) {	//y 14 is max
				cursor(x - 2, y);
				printf(" ");
				cursor(x - 2, ++y);	//add to y (because in cmd, y inc = download)
				printf(">");
			}
			break;
		}
		case SUBMIT: {	//when we press SPACEBAR, y - 12
			return y - 12;	//y location at beginning is 12, so if we y-12, we can get 0, 1, 2
		}	//12- 12 = 0, 13-12=1,14-12=2 so GAMESTART=0, GAMEINFO = 1, EXIT=2
		}


	}
}
int keyboardControl() {
	char temp = _getch();	//when key is pressed, returns right away (no need to press ENTER)

	if (temp == 'w' || temp == 'W') {
		return UP;
	}
	else if (temp == 'a' || temp == 'A') {
		return LEFT;
	}
	else if (temp == 's' || temp == 'S') {
		return DOWN;
	}
	else if (temp == 'd' || temp == 'D') {
		return RIGHT;
	}
	else if (temp == ' ') {	//SPACEBAR (BLANK, ' ')is the select button
		return SUBMIT;	//press SPACEBAR -> returns SUBMIT
	}
	else if (temp == 'z' || temp == 'Z') {
		return OUT;
	}
}
void gameInfo() {
	system("cls");
	printf("\n\n");
	printf("          [Control]\n\n");
	printf("       MOVE : W, A, S, D\n");
	printf("       Exit During Game : Z ");
	printf("      SELECT : SPACEBAR\n\n\n\n\n\n\n");
	printf("      DEVELOPER : Aiden Seo\n");
	printf("     PRESS SPACEBAR TO RETURN TO THE MAIN PAGE");

	while (1) {
		if (keyboardControl() == SUBMIT) {
			break;
		}
	}
}
int maplistDraw() {			//level of difficulty
	int x = 24;
	int y = 6;
	system("cls");
	printf("\n\n");
	printf("                   [Select the map]");

	cursor(x - 2, y);
	printf("> EASY");
	cursor(x, y + 1);
	printf("HARD");
	cursor(x, y + 2);
	printf("EXIT");

	while (1) {
		int n = keyboardControl();	//get keyboard and put it in n
		switch (n) {
		case UP: {	//if UP(w)
			if (y > 6) {	//y moves from 6 ~ 9
				cursor(x - 2, y);
				printf(" ");	//delete > from original location
				cursor(x - 2, --y);	//move to the next location
				printf(">");	//put > to new location
			}
			break;
		}
		case DOWN: {	//DOWN(s)
			if (y < 9) {	//9 is the max
				cursor(x - 2, y);
				printf(" ");		//delete > from original location
				cursor(x - 2, ++y);	//move to next location (down = increase in y, so ++y)
				printf(">");		//add > to new location
			}
			break;
		}
		case SUBMIT: {
			return y - 6;	//when SPACEBAR is pressed, y-6
		}//so EASY : 6-6 = 0, HARD : 7-6=1, EXIT: 8-6=2
		}

	}
}

void drawMap(int* x, int* y) {
	system("cls");
	int h, w;
	//int vision_arr[9][2] = { {*x - 1,*y - 1}, {*x,*y - 1},{*x + 1,*y - 1},{*x - 1,*y},{*x,*y},{*x + 1,*y},{*x - 1,*y + 1},{*x,*y + 1},{*x + 1,*y + 1} };
	for (h = 0; h < 20; h++) {
		for (w = 0; w < 56; w++) {
			char temp = tempMap[h][w];
			if (temp == '0') {	//for 0, print blank space
				setColor(black, black);
				printf(" ");
			}
			else if (temp == '1') {	//for 1, print # for wall
				setColor(white, white);
				printf("#");
			}
			else if (temp == 's') {
				*x = w;		//save player's start position
				*y = h;
				setColor(lightgray, black);
				printf("@");
			}
			else if (temp == 'f') {	//destination
				setColor(lightgreen, black);
				printf("O");
			}
			else if (temp == 'k') {	//key
				setColor(yellow, black);
				printf("*");
			}
			else if (temp == 'L') {	//locked door
				setColor(lightblue, black);
				printf("D");
			}
		}
		printf("\n");
	}
	
	setColor(white, black);		//return to original color
	//Sleep(3000);	this was to sleep the program for 3 sec so that we can check the map! I erased it b/c we're adding more functions
}

void gameLoop(int mapCode) {
	int x, y;	//save player's location (x,y)
	int key = 0;		//save number of keys 
	int playing = 1;	//playing = 1, not playing = 0

	//if mapNumber is 0, it's easy map. 1 is hard map. 2 for .... (add more if you want more levels here)
	if (mapCode == 0) {
		memcpy(tempMap, mapArray_1, sizeof(tempMap));	//copy mapArray_1 to tempMap
	}	//memcpy(where to save, what I want to copy, size)
	if (mapCode == 1) {
		memcpy(tempMap, mapArray_2, sizeof(tempMap));
	}
	drawMap(&x, &y);	//set map first, and print	(&x,&x returns x and y's memory address)

	//game loop
	while (playing) {
		drawUI(&x, &y, &key);
		switch (keyboardControl()) {
		case UP:
			move(&x, &y, 0, -1, &key, &playing);
			//real x, real y, how far to move to x direc, how far to move to y direc., num. of current keys
			break;
		case DOWN:
			move(&x, &y, 0, 1, &key, &playing);		//y+1 (b/c going down -> inc. y value)
			break;
		case LEFT:
			move(&x, &y, -1, 0, &key, &playing);	//x-1 (move to left)
			break;
		case RIGHT:
			move(&x, &y, 1, 0, &key, &playing);		//x+1 (move to right)
			break;
		case OUT:
			playing = 0;
		}
	}
	system("cls");				//when game ends
	setColor(white, black);
	cursor(20, 4);
	printf("***************************");
	cursor(30, 8);
	printf("Game Clear!");
	cursor(20, 12);
	printf("***************************");
	Sleep(3000);
}

//to move character's location
// original position (x,y), addition of position (_x, _y)
void move(int* x, int* y, int _x, int _y, int* key, int*playing) {
	char mapObject = tempMap[*y + _y][*x + _x];		//used when character touches the wall. returns the location that character is about to walk towards
	//이동할 위치 (이동X 이동 전 이동을 할 위치, 즉 키를 눌렀을 때 움직이기 전에, 앞으로 움직일 위치를 리턴)
	
	if (mapObject == '0') {	//move when mapObject = 0 (0일때 움직임)
		
		cursor(*x, *y);
		printf(" ");	//delete

		setColor(cyan, black);	//set Color
		cursor(*x + _x, *y + _y);	//add to the original position as character moves
		printf("@");

		*x += _x;	//change to "Real Position values" (실제 좌표값으로 반영)
		*y += _y;
	}
	else if (mapObject == '1') {	
		//dont do anything when mapObject = 1 (tbh, we don't even need this else if statement. just added)
	}
	else if (mapObject == 'k') {	//if there's a key that the character is about to move towards
		*key += 1;	//add to number of key
		tempMap[*y + _y][*x + _x] = '0';	//set the location of key as '0' (when obtained) (so that the character can move through)
		cursor(*x + _x, *y + _y);
		printf(" ");	//replace key with empty space
	}
	else if (mapObject == 'L') {
		if (*key > 0) {
			*key -= 1;	//consume a key
			tempMap[*y + _y][*x + _x] = '0';	//set the location of locked door as '0' (so that the character can move through)
			setColor(white, black);		//change to default color
			cursor(*x + _x, *y + _y);	
			printf(" ");	//replace door with empty space
		}
	}
	else if (mapObject == 'f') {	//when player reaches the destination
		*playing = 0;	//1 : game running, 0 : end of the game
	}
}

void drawUI(int* x, int* y, int* key) {		//for Current location and item status during the game
	setColor(white, black);
	cursor(3, 23);
	printf("Current Location : (%02d,%02d)", *x, *y);	//%02d = int type + 2 letters
	//print current location on the bottom

	setColor(yellow, black);
	cursor(40, 23);
	printf("Items : %d", *key);	//print keys on the bottom

}
/*
int vision(int* x, int* y) {
	int vision_arr[9][2] = { {*x - 1,*y - 1}, {*x,*y-1},{*x+1,*y-1},{*x - 1,*y},{*x,*y},{*x+1,*y},{*x-1,*y+1},{*x,*y+1},{*x+1,*y+1} };
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 2; j++) {
			return vision_arr[i][j];
		}
	}
}
*/