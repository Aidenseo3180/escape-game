#include "main.h"
#include "game.h"
#include "util.h"

int main(void)
{
	init();
	while (1) {
		titleDraw();
		int menuCode = menuSelection();
		//select one of the options, either 0,1,2 goes into menuCode
		if (menuCode == 0) {
			//game start
			int n = maplistDraw();
			if (n == 0) {	//EASY
				gameLoop(0);	//0 for easy map
			}
			if (n == 1) {	//HARD
				gameLoop(1);	//1 for hard map
			}
		}
		else if (menuCode == 1) {
			gameInfo();	//game info
		}
		else if (menuCode == 2) {
			return 0;	//EXIT
		}
		system("cls");	//"cls" clears everything from cmd screen (and reset console to 0,0)
		setColor(white, black);	//just in case, set to default color
	}

	return 0;
}
