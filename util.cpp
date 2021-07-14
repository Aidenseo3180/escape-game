#include "util.h"

void init() {
	system("mode con sols=56 lines=20 | title ESCAPE ");	//56 horizontal, 20 vertical, title : ESCAPE
	//so x=56, y=20

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);	//get Console Handle
	CONSOLE_CURSOR_INFO consoleCursor;
	consoleCursor.bVisible = 0;		//false or 0 : hide cursor
	consoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &consoleCursor);	//these(last 5 lines of code) are to hide the cursor
}

//control cursor
void cursor(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);	//gain console handle
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void setColor(int forground, int background) {	//when it gets enum data, it changes the corresponding text color, and background color
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);	//bring console handle
	int code = forground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}