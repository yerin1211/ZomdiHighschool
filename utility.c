#include "utility.h"
#define WIN32_LEAN_AND_MEAN
static HWND hWnd;
static HINSTANCE hInst;
#define MINUS_Y 40
#define MINUS_X 15
void LifeCheck(int x, int y) { //하트를 출력함. 현재 생명 개수에 따라 줄어들음
	for (int i = 0; i < CurrentLife; i++) {
		/*for (int j = x; j <= y; j += 30) {
		   PT(j, 10, 30, 30, player[chchange].LifeDC[i]);
		}*/
		if (CurrentLife == 5) {
			PT(y, 20, 30, 30,LifeDC[i]);
			PT(y - 30, 20, 30, 30, LifeDC[i]);
			PT(y - 60, 20, 30, 30,LifeDC[i]);
			PT(y - 90, 20, 30, 30,LifeDC[i]);
			PT(y - 120, 20, 30, 30,LifeDC[i]);
		}
		else if (CurrentLife == 4) {
			PT(y - 30, 20, 30, 30,LifeDC[i]);
			PT(y - 60, 20, 30, 30,LifeDC[i]);
			PT(y - 90, 20, 30, 30,LifeDC[i]);
			PT(y - 120, 20, 30, 30,LifeDC[i]);
		}
		else if (CurrentLife == 3) {
			PT(y - 60, 20, 30, 30,LifeDC[i]);
			PT(y - 90, 20, 30, 30,LifeDC[i]);
			PT(y - 120, 20, 30, 30,LifeDC[i]);
		}
		else if (CurrentLife == 2) {
			PT(y - 90, 20, 30, 30,LifeDC[i]);
			PT(y - 120, 20, 30, 30,LifeDC[i]);
		}
		else if (CurrentLife == 1) {
			PT(y - 120, 20, 30, 30,LifeDC[i]);
		}

	}
}
//여기부터 노가다..장애물 판정
int cannotgoup() {
	if (((player[chchange].xPosition <= 135 - MINUS_X && player[chchange].xPosition >= 35 - MINUS_X) || (player[chchange].xPosition >= 260 - MINUS_X && player[chchange].xPosition <= 425 - MINUS_X) ||
		(player[chchange].xPosition >= 545 - MINUS_X && player[chchange].xPosition <= 675 - MINUS_X) || (player[chchange].xPosition >= 730 - MINUS_X && player[chchange].xPosition <= 840 - MINUS_X) ||
		(player[chchange].xPosition >= 930 - MINUS_X && player[chchange].xPosition <= 1027 - MINUS_X))
		&& (player[chchange].yPosition == 320 - MINUS_Y)) {
		return -1;
	}
	else if (((player[chchange].xPosition >= 130 - MINUS_X && player[chchange].xPosition <= 260 - MINUS_X) || (player[chchange].xPosition >= 415 - MINUS_X && player[chchange].xPosition <= 545 - MINUS_X))
		&& (player[chchange].yPosition == 350 - MINUS_Y)) {
		return -1;
	}
	else if (((player[chchange].xPosition >= 670 - MINUS_X && player[chchange].xPosition <= 740 - MINUS_X)) && player[chchange].yPosition == 410 - MINUS_Y) {
		return -1;
	}
	else if (((player[chchange].xPosition >= 35 - MINUS_X && player[chchange].xPosition <= 1090 - MINUS_X)) && player[chchange].yPosition == 730 - MINUS_Y) {
		return -1;
	}
	else if (player[chchange].yPosition == 20 - MINUS_Y && ((player[chchange].xPosition <= 845 - MINUS_X || player[chchange].xPosition >= 925 - MINUS_X))) {
		return -1;
	}
	else if ((player[chchange].xPosition >= 0 - MINUS_X && player[chchange].xPosition <= 35 - MINUS_X) && player[chchange].yPosition <= 50 - MINUS_Y) {
		return 10;
	}
	else if (((player[chchange].xPosition >= 35 - MINUS_X && player[chchange].xPosition <= 70 - MINUS_X) || (player[chchange].xPosition >= 100 - MINUS_X && player[chchange].xPosition <= 170 - MINUS_X)
		|| (player[chchange].xPosition >= 190 - MINUS_X && player[chchange].xPosition <= 350 - MINUS_X) || (player[chchange].xPosition >= 390 - MINUS_X && player[chchange].xPosition <= 450 - MINUS_X)
		|| (player[chchange].xPosition >= 480 - MINUS_X && player[chchange].xPosition <= 640 - MINUS_X) || (player[chchange].xPosition >= 680 - MINUS_X && player[chchange].xPosition <= 770 - MINUS_X)
		|| (player[chchange].xPosition >= 800 - MINUS_X && player[chchange].xPosition <= 840 - MINUS_X) || (player[chchange].xPosition >= 930 - MINUS_X && player[chchange].xPosition <= 1180 - MINUS_X))
		&& (player[chchange].yPosition == 90 - MINUS_Y)) {
		return -1;
	}
	else if ((player[chchange].xPosition >= 70 - MINUS_X && player[chchange].xPosition <= 100 - MINUS_X) && player[chchange].yPosition <= 50 - MINUS_Y) {
		return 4;
	}
	else if ((player[chchange].xPosition >= 160 - MINUS_X && player[chchange].xPosition <= 190 - MINUS_X) && player[chchange].yPosition <= 50 - MINUS_Y) {
		return 3;
	}
	else if ((player[chchange].xPosition >= 360 - MINUS_X && player[chchange].xPosition <= 390) && player[chchange].yPosition <= 50 - MINUS_Y) {
		return 5;
	}
	else if ((player[chchange].xPosition >= 450 - MINUS_X && player[chchange].xPosition <= 480 - MINUS_X) && player[chchange].yPosition <= 50 - MINUS_Y) {
		return 6;
	}
	else if ((player[chchange].xPosition >= 640 - MINUS_X && player[chchange].xPosition <= 680 - MINUS_X) && player[chchange].yPosition <= 50 - MINUS_Y) {
		return 7;
	}
	else if ((player[chchange].xPosition >= 770 - MINUS_X && player[chchange].xPosition <= 800 - MINUS_X) && player[chchange].yPosition <= 50 - MINUS_Y) {
		return 8;
	}
	if (player[chchange].yPosition <= 0) {
		return 1;
	}
	else return 0;
}
int cannotgodown() {
	if (((player[chchange].xPosition >= 53 - MINUS_X && player[chchange].xPosition <= 640 - MINUS_X) || (player[chchange].xPosition >= 740 - MINUS_X && player[chchange].xPosition <= 800 - MINUS_X)
		|| (player[chchange].xPosition >= 835 - MINUS_X &&
			player[chchange].xPosition <= 930 - MINUS_X) || (player[chchange].xPosition >= 965 - MINUS_X && player[chchange].xPosition <= 1025 - MINUS_X))
		&& (player[chchange].yPosition == 600 - MINUS_Y))
	{
		return -1;
	}
	else if (((player[chchange].xPosition >= 35 - MINUS_X && player[chchange].xPosition <= 135 - MINUS_X) || (player[chchange].xPosition >= 255 - MINUS_X && player[chchange].xPosition <= 420 - MINUS_X)
		|| (player[chchange].xPosition >= 545 - MINUS_X && player[chchange].xPosition <= 680 - MINUS_X)) && (player[chchange].yPosition == 600 - MINUS_Y)) {
		return -1;
	}
	else if (((player[chchange].xPosition >= 130 - MINUS_X && player[chchange].xPosition <= 260 - MINUS_X) || (player[chchange].xPosition >= 420 - MINUS_X && player[chchange].xPosition <= 545 - MINUS_X)) &&
		(player[chchange].yPosition == 570 - MINUS_Y)) {
		return -1;
	}
	else if (((player[chchange].xPosition >= 35 - MINUS_X && player[chchange].xPosition <= 835 - MINUS_X) || (player[chchange].xPosition >= 930 - MINUS_X && player[chchange].xPosition <= 1090 - MINUS_X)) &&
		(player[chchange].yPosition == 180 - MINUS_Y)) {
		return -1;
	}
	else if (((player[chchange].xPosition >= 675 - MINUS_X && player[chchange].xPosition <= 740 - MINUS_X)
		|| (player[chchange].xPosition >= 1027 - MINUS_X && player[chchange].xPosition <= 1090 - MINUS_X)) && (player[chchange].yPosition == 500 - MINUS_Y)) {
		return -1;
	}
	else if (((player[chchange].xPosition >= 640 - MINUS_X && player[chchange].xPosition <= 675 - MINUS_X) || (player[chchange].xPosition >= 800 - MINUS_X && player[chchange].xPosition <= 835 - MINUS_X) ||
		(player[chchange].xPosition >= 930 - MINUS_X && player[chchange].xPosition <= 965 - MINUS_X)) && (player[chchange].yPosition == 570 - MINUS_Y)) {
		return -1;
	}
	/*
	if (((zombie.xPosition >= 53 - MINUS_X && zombie.xPosition <= 640 - MINUS_X) || (zombie.xPosition >= 740 - MINUS_X && zombie.xPosition <= 800 - MINUS_X)
	   || (zombie.xPosition >= 835 - MINUS_X &&
		zombie.xPosition <= 930 - MINUS_X) || (zombie.xPosition >= 965 - MINUS_X && zombie.xPosition <= 1025 - MINUS_X))
	   && (zombie.yPosition == 600 - MINUS_Y))
	{
	   return -1;
	}
	else if (((zombie.xPosition >= 35 - MINUS_X && zombie.xPosition <= 135 - MINUS_X) || (zombie.xPosition >= 255 - MINUS_X && zombie.xPosition <= 420 - MINUS_X)
	   || (zombie.xPosition >= 545 - MINUS_X && zombie.xPosition <= 680 - MINUS_X)) && (zombie.yPosition == 600 - MINUS_Y)) {
	   return -1;
	}
	else if (((zombie.xPosition >= 130 - MINUS_X && zombie.xPosition <= 260 - MINUS_X) || (zombie.xPosition >= 420 - MINUS_X && zombie.xPosition <= 545 - MINUS_X)) &&
	   (zombie.yPosition == 570 - MINUS_Y)) {
	   return -1;
	}
	else if (((zombie.xPosition >= 35 - MINUS_X && zombie.xPosition <= 835 - MINUS_X) || (zombie.xPosition >= 930 - MINUS_X && zombie.xPosition <= 1090 - MINUS_X)) &&
	   (zombie.yPosition == 180 - MINUS_Y)) {
	   return -1;
	}
	else if (((zombie.xPosition >= 675 - MINUS_X && zombie.xPosition <= 740 - MINUS_X)
	   || (zombie.xPosition >= 1027 - MINUS_X && zombie.xPosition <= 1090 - MINUS_X)) && (zombie.yPosition == 500 - MINUS_Y)) {
	   return -1;
	}
	else if (((zombie.xPosition >= 640 - MINUS_X && zombie.xPosition <= 675 - MINUS_X) || (zombie.xPosition >= 800 - MINUS_X && zombie.xPosition <= 835 - MINUS_X) ||
	   (zombie.xPosition >= 930 - MINUS_X && zombie.xPosition <= 965 - MINUS_X)) && (zombie.yPosition == 570 - MINUS_Y)) {
	   return -1;
	}*/
	if (player[chchange].yPosition == 760) {
		return -1;
	}
	else return 0;
}
int cannotgoleft() {
	if (((player[chchange].yPosition >= 190 - MINUS_Y
		&& player[chchange].yPosition <= 310 - MINUS_Y))
		&& player[chchange].xPosition == 845 - MINUS_X) {
		return -1;
	}
	else if (((player[chchange].yPosition >= 310 - MINUS_Y && player[chchange].yPosition <= 410 - MINUS_Y) ||
		(player[chchange].yPosition >= 510 - MINUS_Y && player[chchange].yPosition <= 600 - MINUS_Y)) && player[chchange].xPosition == 745 - MINUS_X) {
		return -1;
	}
	else if (((player[chchange].xPosition == 265 - MINUS_X || player[chchange].xPosition == 555 - MINUS_X) && (player[chchange].yPosition >= 260 - MINUS_Y && player[chchange].yPosition <= 345 - MINUS_Y))) {
		return -1;
	}
	else if (((player[chchange].xPosition == 265 - MINUS_X) || (player[chchange].xPosition == 555 - MINUS_X)
		|| (player[chchange].xPosition == 845 - MINUS_X) || (player[chchange].xPosition == 975 - MINUS_X)) && (player[chchange].yPosition >= 570 - MINUS_Y && player[chchange].yPosition <= 600 - MINUS_Y)) {
		return -1;
	}
	else if ((player[chchange].xPosition == 1105 - MINUS_X) && (player[chchange].yPosition >= 190 - MINUS_Y && player[chchange].yPosition <= 730 - MINUS_Y)) {
		return -1;
	}
	/*if (((zombie.yPosition >= 190 - MINUS_Y && zombie.yPosition <= 310 - MINUS_Y)) && zombie.xPosition == 845 - MINUS_X) {
	   return -1;
	}
	else if (((zombie.yPosition >= 310 - MINUS_Y && zombie.yPosition <= 410 - MINUS_Y) ||
	   (player.yPosition >= 510 - MINUS_Y && zombie.yPosition <= 600 - MINUS_Y)) && zombie.xPosition == 745 - MINUS_X) {
	   return -1;
	}
	else if (((zombie.xPosition == 265 - MINUS_X || zombie.xPosition == 555 - MINUS_X) && (zombie.yPosition >= 260 - MINUS_Y && zombie.yPosition <= 345 - MINUS_Y))) {
	   return -1;
	}
	else if (((zombie.xPosition == 265 - MINUS_X) || (zombie.xPosition == 555 - MINUS_X)
	   || (zombie.xPosition == 845 - MINUS_X) || (zombie.xPosition == 975 - MINUS_X)) && (zombie.yPosition >= 570 - MINUS_Y && zombie.yPosition <= 600 - MINUS_Y)) {
	   return -1;
	}
	else if ((zombie.xPosition == 1105 - MINUS_X) && (zombie.yPosition >= 190 - MINUS_Y && zombie.yPosition <= 730 - MINUS_Y)) {
	   return -1;
	}
	*/
	else if (player[chchange].xPosition == 15 - MINUS_X) {
		return -1;
	}
	else return 0;
}
int cannotgoright() {
	if (((player[chchange].xPosition == 135 - MINUS_X || player[chchange].xPosition == 425 - MINUS_X) && (player[chchange].yPosition >= 260 - MINUS_Y && player[chchange].yPosition <= 345 - MINUS_Y))) {
		return -1;
	}
	else if ((player[chchange].xPosition == 35 - MINUS_X) && (player[chchange].yPosition >= 185 - MINUS_Y && player[chchange].yPosition <= 315 - MINUS_Y)) {
		return -1;
	}
	else if ((player[chchange].xPosition == 35 - MINUS_X) && (player[chchange].yPosition >= 605 - MINUS_Y && player[chchange].yPosition <= 730 - MINUS_Y)) {
		return -1;
	}
	else if (((player[chchange].xPosition == 125 - MINUS_X) || (player[chchange].xPosition == 415 - MINUS_X) || (player[chchange].xPosition == 645 - MINUS_X)
		|| (player[chchange].xPosition == 805 - MINUS_X) || (player[chchange].xPosition == 935 - MINUS_X)) && (player[chchange].yPosition >= 570 - MINUS_Y && player[chchange].yPosition <= 600 - MINUS_Y)) {
		return -1;
	}
	else if ((player[chchange].xPosition == 675 - MINUS_X || player[chchange].xPosition == 1025 - MINUS_X) && player[chchange].yPosition >= 510 - MINUS_Y && player[chchange].yPosition <= 610 - MINUS_Y) {
		return -1;
	}
	else if ((player[chchange].xPosition == 925 - MINUS_X) && (player[chchange].yPosition >= 190 - MINUS_Y && player[chchange].yPosition <= 315 - MINUS_Y)) {
		return -1;
	}
	else if ((player[chchange].xPosition == 1025 - MINUS_X) && (player[chchange].yPosition >= 310 - MINUS_Y && player[chchange].yPosition <= 600 - MINUS_Y)) {
		return -1;
	}
	else if ((player[chchange].xPosition == 675 - MINUS_X) && (player[chchange].yPosition >= 310 - MINUS_Y && player[chchange].yPosition <= 410 - MINUS_Y)) {
		return -1;
	}
	/*
	if (((zombie.xPosition == 135 - MINUS_X || zombie.xPosition == 425 - MINUS_X) && (zombie.yPosition >= 260 - MINUS_Y && zombie.yPosition <= 345 - MINUS_Y))) {
	   return -1;
	}
	else if ((zombie.xPosition == 35 - MINUS_X) && (zombie.yPosition >= 185 - MINUS_Y && zombie.yPosition <= 315 - MINUS_Y)) {
	   return -1;
	}
	else if ((zombie.xPosition == 35 - MINUS_X) && (zombie.yPosition >= 605 - MINUS_Y && zombie.yPosition <= 730 - MINUS_Y)) {
	   return -1;
	}
	else if (((zombie.xPosition == 125 - MINUS_X) || (zombie.xPosition == 415 - MINUS_X) || (zombie.xPosition == 645 - MINUS_X)
	   || (zombie.xPosition == 805 - MINUS_X) || (zombie.xPosition == 935 - MINUS_X)) && (zombie.yPosition >= 570 - MINUS_Y && zombie.yPosition <= 600 - MINUS_Y)) {
	   return -1;
	}
	else if ((zombie.xPosition == 675 - MINUS_X || zombie.xPosition == 1025 - MINUS_X) && zombie.yPosition >= 510 - MINUS_Y && zombie.yPosition <= 610 - MINUS_Y) {
	   return -1;
	}
	else if ((zombie.xPosition == 925 - MINUS_X) && (zombie.yPosition >= 190 - MINUS_Y && zombie.yPosition <= 315 - MINUS_Y)) {
	   return -1;
	}
	else if ((zombie.xPosition == 1025 - MINUS_X) && (zombie.yPosition >= 310 - MINUS_Y && zombie.yPosition <= 600 - MINUS_Y)) {
	   return -1;
	}
	else if ((zombie.xPosition == 675 - MINUS_X) && (zombie.yPosition >= 310 - MINUS_Y && zombie.yPosition <= 410 - MINUS_Y)) {
	   return -1;
	} */
	else if (player[chchange].xPosition == 1170) {
		return -1;
	}
	else {
		return 0;
	}
}
int cannotgoupincafe() {
	if (player[chchange].xPosition >= 0 - MINUS_X && player[chchange].xPosition <= 195 - MINUS_X && player[chchange].yPosition == 400 - MINUS_Y) {
		return -1;
	}
	else if (player[chchange].xPosition >= 195 - MINUS_X && player[chchange].xPosition <= 355 - MINUS_X && player[chchange].yPosition == 140 - MINUS_Y) {
		return -1;
	}
	else if (player[chchange].yPosition == 80 - MINUS_Y && player[chchange].xPosition >= 95 - MINUS_X && player[chchange].xPosition <= 195 - MINUS_X) {
		return 3;
	}
	else if (player[chchange].yPosition == 400 - MINUS_Y && player[chchange].xPosition >= 345 - MINUS_X && player[chchange].xPosition <= 965 - MINUS_X) {
		return -1;
	}
	else if (player[chchange].xPosition >= 415 - MINUS_X && player[chchange].xPosition <= 875 - MINUS_X && player[chchange].yPosition == 150 - MINUS_Y) {
		return -1;
	}
	else if (player[chchange].yPosition == 300 - MINUS_Y && player[chchange].xPosition >= 1055 - MINUS_X && player[chchange].xPosition <= 1155 - MINUS_X) {
		return -1;
	}
	else if (player[chchange].xPosition >= 350 - MINUS_X && player[chchange].xPosition <= 960 - MINUS_X && player[chchange].yPosition == 660 - MINUS_Y) {
		return -1;
	}
	else if (player[chchange].xPosition >= 0 - MINUS_X && player[chchange].xPosition <= 195 - MINUS_X && player[chchange].yPosition == 660 - MINUS_Y) {
		return -1;
	}
	return 0;
}
int cannotgoleftincafe() {
	if (player[chchange].xPosition == 105 - MINUS_X && player[chchange].yPosition >= 130 - MINUS_Y && player[chchange].yPosition <= 240 - MINUS_Y) {
		return -1;
	}
	else if (player[chchange].xPosition == 215 - MINUS_X && player[chchange].yPosition >= 200 - MINUS_Y && player[chchange].yPosition <= 400 - MINUS_Y) {
		return -1;
	}
	else if ((player[chchange].xPosition == 105 - MINUS_X) && (player[chchange].yPosition >= 70 - MINUS_Y && player[chchange].yPosition <= 140 - MINUS_Y)) {
		return -1;
	}
	else if (player[chchange].xPosition == 365 - MINUS_X && player[chchange].yPosition >= 0 - MINUS_Y && player[chchange].yPosition <= 130 - MINUS_Y) {
		return -1;
	}
	else if (player[chchange].xPosition == 975 - MINUS_X && player[chchange].yPosition >= 230 - MINUS_Y && player[chchange].yPosition <= 400 - MINUS_Y) {
		return -1;
	}
	else if (player[chchange].xPosition == 575 - MINUS_X && player[chchange].yPosition >= 200 - MINUS_Y && player[chchange].yPosition <= 230 - MINUS_Y) {
		return -1;
	}
	else if (player[chchange].xPosition == 835 - MINUS_X && player[chchange].yPosition >= 200 - MINUS_Y && player[chchange].yPosition <= 230 - MINUS_Y) {
		return -1;
	}
	else if (player[chchange].yPosition >= 70 - MINUS_Y && player[chchange].yPosition <= 140 - MINUS_Y && player[chchange].xPosition == 885 - MINUS_X) {
		return -1;
	}
	else if (player[chchange].yPosition >= 100 - MINUS_Y && player[chchange].yPosition <= 300 - MINUS_Y && player[chchange].xPosition == 1165 - MINUS_X) {
		return -1;
	}
	else if (player[chchange].yPosition >= 490 - MINUS_Y && player[chchange].yPosition <= 660 - MINUS_Y && ((player[chchange].xPosition == 97 - MINUS_X)
		|| (player[chchange].xPosition == 205 - MINUS_X))) {
		return -1;
	}
	else if (player[chchange].xPosition == 195 - MINUS_X && player[chchange].yPosition >= 750 - MINUS_Y && player[chchange].yPosition <= 860 - MINUS_Y) {
		return -1;
	}
	else if (player[chchange].xPosition == 955 - MINUS_X && player[chchange].yPosition >= 730 - MINUS_Y && player[chchange].yPosition <= 860 - MINUS_Y) {
		return -1;
	}
	else return 0;
}
int cannotgorightincafe() {
	if (player[chchange].xPosition == 155 - MINUS_X && player[chchange].yPosition >= 200 - MINUS_Y && player[chchange].yPosition <= 230 - MINUS_Y) {
		return -1;
	}
	else if ((player[chchange].xPosition == 195 - MINUS_X) && (player[chchange].yPosition >= 70 - MINUS_Y && player[chchange].yPosition <= 140 - MINUS_Y)) {
		return -1;
	}
	else if (player[chchange].xPosition == 345 - MINUS_X && player[chchange].yPosition >= 230 - MINUS_Y && player[chchange].yPosition <= 400 - MINUS_Y) {
		return -1;
	}
	else if (player[chchange].xPosition == 485 - MINUS_X && player[chchange].yPosition >= 200 - MINUS_Y && player[chchange].yPosition <= 230 - MINUS_Y) {
		return -1;
	}
	else if (player[chchange].xPosition == 745 - MINUS_X && player[chchange].yPosition >= 200 - MINUS_Y && player[chchange].yPosition <= 230 - MINUS_Y) {
		return -1;
	}
	else if (player[chchange].yPosition >= 70 - MINUS_Y && player[chchange].yPosition <= 140 - MINUS_Y && player[chchange].xPosition == 415 - MINUS_X) {
		return -1;
	}
	else if (player[chchange].yPosition >= 100 - MINUS_Y && player[chchange].yPosition <= 300 - MINUS_Y && player[chchange].xPosition == 1055 - MINUS_X) {
		return -1;
	}
	else if (player[chchange].yPosition >= 490 - MINUS_Y && player[chchange].yPosition <= 660 - MINUS_Y && player[chchange].xPosition == 355 - MINUS_X) {
		return -1;
	}
	else if (player[chchange].xPosition == 345 - MINUS_X && player[chchange].yPosition >= 730 - MINUS_Y && player[chchange].yPosition <= 860 - MINUS_Y) {
		return -1;
	}
	return 0;
}
int cannotgodownincafe() {
	if (player[chchange].yPosition == 230 - MINUS_Y && player[chchange].xPosition >= 95 - MINUS_X && player[chchange].xPosition <= 155 - MINUS_X) {
		return -1;
	}
	else if (player[chchange].xPosition >= 155 - MINUS_X && player[chchange].xPosition <= 185 - MINUS_X && player[chchange].yPosition == 190 - MINUS_Y) {
		return -1;
	}
	else if (player[chchange].yPosition == 230 - MINUS_Y && ((player[chchange].xPosition >= 345 && player[chchange].xPosition <= 485 - MINUS_X) ||
		(player[chchange].xPosition >= 565 - MINUS_X && player[chchange].xPosition <= 745 - MINUS_X) || (player[chchange].xPosition >= 825 - MINUS_X && player[chchange].xPosition <= 955 - MINUS_X))) {
		return -1;
	}
	else if (player[chchange].yPosition == 200 - MINUS_Y && ((player[chchange].xPosition >= 485 - MINUS_X && player[chchange].xPosition <= 565 - MINUS_X)
		|| (player[chchange].xPosition >= 745 - MINUS_X && player[chchange].xPosition <= 825 - MINUS_X))) {
		return -1;
	}
	else if (player[chchange].yPosition == 100 - MINUS_Y && player[chchange].xPosition >= 1055 - MINUS_X && player[chchange].xPosition <= 1155 - MINUS_X) {
		return -1;
	}
	else if (player[chchange].xPosition >= 350 - MINUS_X && player[chchange].xPosition <= 960 - MINUS_X && player[chchange].yPosition == 490 - MINUS_Y) {
		return -1;
	}
	else if ((player[chchange].xPosition >= 0 - MINUS_X && player[chchange].xPosition <= 195 - MINUS_X) && ((player[chchange].yPosition == 490 - MINUS_Y) || (player[chchange].yPosition == 740 - MINUS_Y))) {
		return -1;
	}
	else if (player[chchange].yPosition == 730 - MINUS_Y && player[chchange].xPosition >= 345 - MINUS_X && player[chchange].xPosition <= 955 - MINUS_X) {
		return -1;
	}
	else if (player[chchange].yPosition == 810 - MINUS_Y && player[chchange].xPosition >= 965 - MINUS_X && player[chchange].xPosition <= 1313 - MINUS_X) {
		return -1;
	}
	else if (player[chchange].yPosition == 830 - MINUS_Y && player[chchange].xPosition <= 345 - MINUS_X && player[chchange].xPosition >= 195 - MINUS_X) {
		return 2;
	}
	else return 0;
}
int cannotgoupinpark() {
	if ((player[chchange].xPosition >= 190 - MINUS_X && player[chchange].xPosition <= 230 - MINUS_X ||
		(player[chchange].xPosition >= 460 - MINUS_X && player[chchange].xPosition <= 490 - MINUS_X) ||
		(player[chchange].xPosition >= 710 - MINUS_X && player[chchange].xPosition <= 750 - MINUS_X) ||
		(player[chchange].xPosition >= 980 - MINUS_X) ||
		(player[chchange].xPosition >= 310 - MINUS_X && player[chchange].xPosition <= 380 - MINUS_X) ||
		(player[chchange].xPosition >= 570 - MINUS_X && player[chchange].xPosition <= 640 - MINUS_X)) &&
		(player[chchange].yPosition <= 460 - MINUS_Y && player[chchange].yPosition >= 410)) {
		return -1;
	}
	else if (((player[chchange].xPosition >= 300 - MINUS_X && player[chchange].xPosition <= 380 - MINUS_X) ||
		(player[chchange].xPosition >= 560 - MINUS_X && player[chchange].xPosition <= 640 - MINUS_X)) &&
		(((player[chchange].yPosition == 460 - MINUS_Y) || (player[chchange].yPosition == 610 - MINUS_Y)))) {
		return -1;
	}
	return 0;
}
int cannotgodowninpark() {
	if (((player[chchange].xPosition >= 190 - MINUS_X && player[chchange].xPosition <= 230 - MINUS_X) ||
		(player[chchange].xPosition >= 460 - MINUS_X && player[chchange].xPosition <= 490 - MINUS_X) ||
		(player[chchange].xPosition >= 710 - MINUS_X && player[chchange].xPosition <= 750 - MINUS_X) ||
		(player[chchange].xPosition >= 980 - MINUS_X)) && ((player[chchange].yPosition == 410 - MINUS_Y) || (player[chchange].yPosition == 560 - MINUS_Y))) {
		return -1;
	}
	else if (player[chchange].xPosition <= 800 - MINUS_X && player[chchange].xPosition <= 900 - MINUS_X && player[chchange].yPosition == 560 - MINUS_Y) {
		return 3;
	}
	else if (((player[chchange].xPosition >= 300 - MINUS_X && player[chchange].xPosition <= 380 - MINUS_X) ||
		(player[chchange].xPosition >= 560 - MINUS_X && player[chchange].xPosition <= 640 - MINUS_X)) &&
		(((player[chchange].yPosition == 430 - MINUS_Y) || (player[chchange].yPosition == 580 - MINUS_Y)))) {
		return -1;
	}
	else if (player[chchange].xPosition >= 0 - MINUS_X && player[chchange].xPosition <= 500 - MINUS_X && player[chchange].yPosition == 620 - MINUS_Y) {
		return -1;
	}
	else if (player[chchange].xPosition >= 500 - MINUS_X && player[chchange].xPosition <= 670 - MINUS_X && player[chchange].yPosition == 800 - MINUS_Y) {
		return -1;
	}
	else if (player[chchange].xPosition >= 750 - MINUS_X && player[chchange].xPosition <= 850 - MINUS_X && player[chchange].yPosition == 820 - MINUS_Y) {
		return 2;
	}
	return 0;
}
int cannotgoleftinpark() {
	if (((player[chchange].yPosition <= 460 - MINUS_Y && player[chchange].yPosition >= 410 - MINUS_Y)
		|| (player[chchange].yPosition <= 610 - MINUS_Y && player[chchange].yPosition >= 570 - MINUS_Y)) &&
		((player[chchange].xPosition == 245 - MINUS_X) || (player[chchange].xPosition == 505 - MINUS_X) ||
		(player[chchange].xPosition == 765 - MINUS_X))) {
		return -1;
	}
	else if (((player[chchange].xPosition == 485 - MINUS_X) || (player[chchange].xPosition == 645 - MINUS_X))
		&& (player[chchange].yPosition >= 430 - MINUS_Y && player[chchange].yPosition <= 460 - MINUS_Y)) {
		return -1;
	}
	else if (((player[chchange].xPosition == 385 - MINUS_X) || (player[chchange].xPosition == 645 - MINUS_X))
		&& ((player[chchange].yPosition >= 430 - MINUS_Y && player[chchange].yPosition <= 460 - MINUS_Y)
			|| (player[chchange].yPosition >= 580 - MINUS_Y && player[chchange].yPosition <= 610 - MINUS_Y))) {
		return -1;
	}
	else if (player[chchange].xPosition == 515 - MINUS_X && player[chchange].yPosition >= 620 - MINUS_Y && player[chchange].yPosition <= 800 - MINUS_Y) {
		return -1;
	}
	else if (player[chchange].yPosition >= 800 - MINUS_Y && player[chchange].xPosition == 685 - MINUS_X) {
		return -1;
	}
	else return 0;
}
int cannotgorightinpark() {
	if ((player[chchange].yPosition <= 460 - MINUS_Y && player[chchange].yPosition >= 410 - MINUS_Y) &&
		((player[chchange].xPosition == 195 - MINUS_X) || (player[chchange].xPosition == 455 - MINUS_X) ||
		(player[chchange].xPosition == 725 - MINUS_X) || (player[chchange].xPosition == 975 - MINUS_X))) {
		return -1;
	}
	else if (((player[chchange].xPosition == 305 - MINUS_X) || (player[chchange].xPosition == 565 - MINUS_X))
		&& ((player[chchange].yPosition >= 430 - MINUS_Y && player[chchange].yPosition <= 460 - MINUS_Y)
			|| (player[chchange].yPosition >= 580 - MINUS_Y && player[chchange].yPosition <= 610 - MINUS_Y))) {
		return -1;
	}
	else if (player[chchange].xPosition == 85 - MINUS_X && player[chchange].yPosition >= 0 - MINUS_Y && player[chchange].yPosition <= 120 - MINUS_Y) {
		return -1;
	}
	return 0;
}
int cannotgoupincl1() {
	return 0;
}
int cannotgodownincl1() {
	if (((player[chchange].xPosition >= 160 - MINUS_X && player[chchange].xPosition <= 210 - MINUS_X)) && player[chchange].yPosition == 700 - MINUS_Y) {
		return 1;
	}
	else if ((player[chchange].xPosition >= 760 - MINUS_X && player[chchange].xPosition <= 810 - MINUS_X) && player[chchange].yPosition == 700 - MINUS_Y) {
		return 2;
	}
	return 0;
}
int cannotgoleftincl1() {
	return 0;
}
int cannotgorightincl1() {
	return 0;
}
int cannotgoupincl2() {
	return 0;
}
int cannotgodownincl2() {
	if (((player[chchange].xPosition >= 120 - MINUS_X && player[chchange].xPosition <= 170 - MINUS_X)) && player[chchange].yPosition >= 710 - MINUS_Y) {
		return 1;
	}
	else if ((player[chchange].xPosition >= 775 - MINUS_X && player[chchange].xPosition <= 835 - MINUS_X) && player[chchange].yPosition == 710 - MINUS_Y) {
		return 2;
	}
	return 0;
}
int cannotgoleftincl2() {

	return 0;
}
int cannotgorightincl2() {
	return 0;
}
int cannotgoupinmyroom() {
	return 0;
}
int cannotgodowninmyroom() {
	if ((player[chchange].xPosition >= 120 - MINUS_X && player[chchange].xPosition <= 220 - MINUS_X) && player[chchange].yPosition >= 660 - MINUS_Y) {
		return 1;
	}
	else if ((player[chchange].xPosition >= 775 - MINUS_X && player[chchange].xPosition <= 875 - MINUS_X) && player[chchange].yPosition >= 650 - MINUS_Y) {
		return 2;
	}
	return 0;
}
int cannotgorightinmyroom() {
	return 0;
}
int cannotgoleftinmyroom() {
	return 0;
}
int cannotgoupinfire() {
	if (player[chchange].yPosition <= 220 - MINUS_Y) {
		return 1;
	}
	return 0;
};
int cannotgodowninfire() {
	if (player[chchange].yPosition >= 710 - MINUS_Y) {
		return 1;
	}
	return 0;
};
int cannotgorightinfire() {
	if (player[chchange].xPosition >= 790 - MINUS_X) {
		return 1;
	}
	return 0;
};
int cannotgoleftinfire() {
	if (player[chchange].xPosition <= 175 - MINUS_X) {
		return 1;
	}
	return 0;
};
void UtilityInit() {               //이미지 불러오는 함수, 변수 설정
	SetConsoleTitle("UtilityInit");  //콘솔 이름 설정
	ConsoleInstance = GetModuleHandle(NULL);  // ┐
	ConsoleWindow = GetConsoleWindow();       // │이미지 관련 설정
	ConsoleDC = GetDC(ConsoleWindow);         // ┘
	for (int i = 0; i < 20; i++) {
		LI(&quest[i].QuestDC, &quest[i].QuestMAP, "..//Debug//resources//icon//quest.bmp");
	}
	LI(&FirstDC, &FirstMap, "..//Debug//resources//background//first.bmp");
	LI(&FinalDC, &FinalMap, "..//Debug//resources//background//final.bmp");
	LI(&ItemBoomDC, &ItemBoomMap, "..//Debug//resources//icon//itemboom.bmp");
	LI(&MissionDC, &MissionMap, "..//Debug//resources//icon//itemboom.bmp");
	LI(&ItemPosionDC, &ItemPosionMap, "..//Debug//resources//icon//mul2.bmp");
	LI(&NewDC, &NewMap, "..//Debug//resources//icon//new.bmp");
	LI(&JaryoDC, &JaryoMap, "..//Debug//resources//mission//20.bmp");
	char path[300];
	player[3].Height = 47;
	player[3].Width = 19;
	player[1].Width = 20;
	player[1].Height = 55;
	player[2].Width = 29;
	player[2].Height = 49;
	player[4].Width = 19;
	player[4].Height = 54;
	zombie[0].Height = 86;
	zombie[0].Width = 52;
	followcheckyuk = 0;
	finalcheck = 0;
	jaryocheck = 1;
	followcheckyuk2 = 0;
	zombiecnt = 0;
	int tcnt = 0;
	int zombie1alive = 1;
	zombie1dir = 0;
	newcheck = 1;
	ion = 0;
	int rk = 0;
	mulcheck = 0;
	int mulcheckforlife = 0;
	int gap = ((int)(endTime - startTime)) / (CLOCKS_PER_SEC);
	int startTime = 0;
	int endTime = 0;
	for (int i = 0; i < 10; i++) {
		player[i].dir = 1;
	}
	int i;
	int min = 0, sip = 0, il = 0;
	boss.Width = 408;
	boss.Height = 396;
	mission1check = 0;
	quest1check = 1;
	zombie[2].Width = 68;
	zombie[2].Height = 92;
	daecheck = 0;
	ion2 = 0;
	zombie[2].xPosition = 620;
	zombie[2].yPosition = 740;
	zombie[3].xPosition = 235;
	zombie[3].yPosition = 150;
	zombie[5].xPosition = 350;
	zombie[5].yPosition = 400;
	zombie[0].xPosition = 600;
	zombie[0].yPosition = 40;
	itemboomcheck = 0;
	zombie[1].xPosition = 1120;
	zombie[1].yPosition = 400;
	boom.xPosition = 0;
	boom.yPosition = 0;
	zombie[7].xPosition = 580;
	zombie[7].yPosition = 180;
	zomcnt1 = 0;
	chchange = 1;
	olcnt = 0;
	wherein = 0;
	myscnt = 0;
	for (int i = 0; i < 20; i++) {
		zombie[i].visible = 1;
	}
	zombie[3].cnt = 0;
	followcheckzombie = 0;
	zombie[1].check = 0;
	CurrentLife = 5;
	boss.cnt = 0;
	player[0].daegicheck = 1;
	player[1].daegicheck = 1;
	player[2].daegicheck = 0;
	lifecnt = 0;
	ik = 0;
	zombie[2].check = 1;
	zombie[0].check = 1;
	zombie[1].check = 1;
	zombie[4].xPosition = 350;
	zombie[4].yPosition = 140;
	zombie[6].xPosition = 350;
	zombie[6].yPosition = 650;
	zombie[8].xPosition = 200;
	zombie[8].yPosition = 100;
	zombie[8].dir = 1;
	zombie[8].cnt = 0;
	key = 0;
	cnt = 0;
	scil = 0;
	itemboomcheck = 0;
	finalvisible = 1;
	boom.cnt = 0;
	scsip = 0;
	scsip = 0;
	scbak = 0;
	scchun = 0;
	questflag = 0;
	rockcheck = 0;
	visibleu = 0;
	mission2check = 0;
	scman = 0;
	u = 0;
	score = 0;
	min = 2;
	sec = 0;
	followchecktink = 0;
	visiblecnt = 3;
	zombie[5].cnt = 0;
	jon = 0;
	sk = 0;
	dae = 0;
	scbak = 0;
	chrcheck = 0;
	followcheck = 0;
	yk = 0;
	roundcheck = 1;
	finaldae = 0;
	effectcnt = 0;
	finalbosscnt = 0;
	crk = 0;
	tk = 0;
	npccnt = 0;

	for (int i = 0; i < 9; i++) {
		sprintf(path, "..//Debug//resources//effect//%d.bmp", i);
		LI(&EffectDC[i], &EffectMap[i], path);
	}
	for (int i = 0; i < 8; i++) {
		sprintf(path, "..//Debug//resources//finalboss//%d.bmp", i);
		LI(&FinalbossDC[i], &FinalbossMap[i], path);
	}
	for (int i = 0; i < 5; i++) {
		sprintf(path, "..//Debug//resources//combackdae//%d.bmp", i);
		LI(&FinaldaeDC[i], &FinaldaeMap[i], path);
	}
	for (int i = 0; i < 3; i++) {
		sprintf(path, "..//Debug//resources//icon//%d.bmp", i);
		LI(&rock[i].RockDC, &rock[i].RockMap, path);
		rock[i].visible = 1;
	}
	for (int i = 0; i < 20; i++) {
		sprintf(path, "..//Debug//resources//mission//%d.bmp", i);
		LI(&MissionDC[i], &MissionMap[i], path);
	}
	for (int i = 0; i <5; i++) {
		sprintf(path, "..//Debug//resources//npc//%d.bmp", i);
		LI(&NPCDC[i], &NPCMap[i], path);
	}
	for (int i = 0; i < 20; i++) {
		sprintf(path, "..//Debug//resources//dae//%d.bmp", i);
		LI(&DaeDC[i], &DaeMap[i], path);
	}
	for (int i = 0; i < 20; i++) {
		zombie[i].visible = 1;
	}
	for (int i = 0; i < 10; i++) { //0 : 메인 1:교실1 2:교실2 3:미스터리 4:fire 5:카페
		sprintf(path, "..//Debug//resources//background//back%d.bmp",i);
		LI(&BackgroundDC[i], &BackgroundMap[i], path);
	}
	for (int i = 0; i < 10; i++) {
		sprintf(path, "..//Debug//resources//score//%d.bmp", i);
		LI(&ScoreDC[i], &ScoreMap[i], path);
	}
	for (int i = 0; i < 10; i++) {
		mineral1[i].minon = 0;
		mineral1[i].visible = 0;
		mineral2[i].minon = 0;
		mineral2[i].visible = 0;
		mineral3[i].minon = 0;
		mineral3[i].visible = 0;
	}
	for (int i = 0; i < 10; i++) {
		sprintf(path, "..//Debug//resources//icon//minsmall.bmp");
		LI(&mineral1[i].MineralDC, &mineral1[i].MineralMAP, path);
	}
	for (int i = 0; i < 10; i++) {
		sprintf(path, "..//Debug//resources//icon//minmid.bmp");
		LI(&mineral2[i].MineralDC, &mineral2[i].MineralMAP, path);
	}
	for (int i = 0; i < 10; i++) {
		sprintf(path, "..//Debug//resources//icon//minbig.bmp");
		LI(&mineral3[i].MineralDC, &mineral3[i].MineralMAP, path);
	}
	for (int i = 0; i < 5; i++) {
		sprintf(path, "..//Debug//resources//background//ch%d.bmp", i);
		LI(&ChooseDC[i], &ChooseMAP[i], path);
	}
	for (int i = 0; i < 4; i++) {
		sprintf(path, "..//Debug//resources//background//time%d.bmp", i);
		LI(&TimeDC[i], &TimeMAP[i], path);
	}
	for (int i = 0; i < 4; i++) {
		sprintf(path, "..//Debug//resources//jusa//%d.bmp", i);
		LI(&jusa.JusaDC[i], &jusa.JusaMap[i], path);
	}
	for (int i = 0; i < 4; i++) {
		sprintf(path, "..//Debug//resources//background//game%d.bmp", i);
		LI(&GameDC[i], &GameMAP[i], path);
	}
	for (int i = 0; i < 14; i++) {
		sprintf(path, "..//Debug//resources//bomb//%d.bmp", i);
		LI(&boom.BoomDC[i], &boom.BoomMAP[i], path);
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			sprintf(path, "..//Debug//resources//crazy//%d//%d.bmp", i, j);
			LI(&zombie[8].WalkDC[i][j], &zombie[8].WalkMap[i][j], path);
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			sprintf(path, "..//Debug//resources//yuk//wait//%d//%d.bmp", i, j);
			LI(&zombie[7].WaitDC[i][j], &zombie[7].WaitMap[i][j], path);
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			sprintf(path, "..//Debug//resources//tink//%d//%d.bmp", i, j);
			LI(&zombie[2].WalkDC[i][j], &zombie[2].WalkMap[i][j], path);
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			sprintf(path, "..//Debug//resources//yuk//walk//%d//%d.bmp", i, j);
			LI(&zombie[7].WalkDC[i][j], &zombie[7].WalkMap[i][j], path);
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			sprintf(path, "..//Debug//resources//smok//%d//%d.bmp", i, j);
			LI(&zombie[6].WalkDC[i][j], &zombie[6].WalkMap[i][j], path);
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			sprintf(path, "..//Debug//resources//yeongu//%d//%d.bmp", i, j);
			LI(&zombie[5].WalkDC[i][j], &zombie[5].WalkMap[i][j], path);
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			sprintf(path, "..//Debug//resources//ible//geunyang//%d//%d.bmp", i, j);
			LI(&zombie[4].WaitDC[i][j], &zombie[4].WaitMap[i][j], path);
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			sprintf(path, "..//Debug//resources//ible//geunyang//%d//%d.bmp", i, j);
			LI(&zombie[4].WalkDC[i][j], &zombie[4].WalkMap[i][j], path);
		}
	}
	for (int i = 0; i <= 9; i++) {
		pencil.atxPosition = player[i].xPosition;
		pencil.atyPosition = player[i].yPosition;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			sprintf(path, "..//Debug//resources//hakim//walk//%d//%d.bmp", i, j);
			LI(&player[1].WalkDC[i][j], &player[1].WalkMap[i][j], path);
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			sprintf(path, "..//Debug//resources//player//walk//%d//%d.bmp", i, j);
			LI(&player[3].WalkDC[i][j], &player[3].WalkMap[i][j], path);
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			sprintf(path, "..//Debug//resources//player//wait//%d//%d.bmp", i, j);
			LI(&player[3].WaitDC[i][j], &player[3].WaitMap[i][j], path);
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			sprintf(path, "..//Debug//resources//hanam//walk//%d//%d.bmp", i, j);
			LI(&player[4].WalkDC[i][j], &player[4].WalkMap[i][j], path);
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			sprintf(path, "..//Debug//resources//hanam//walk//%d//%d.bmp", i, j);
			LI(&player[4].WalkDC[i][j], &player[4].WalkMap[i][j], path);
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			sprintf(path, "..//Debug//resources//hakim//wait//%d//%d.bmp", i, j);
			LI(&player[1].WaitDC[i][j], &player[1].WaitMap[i][j], path);
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			sprintf(path, "..//Debug//resources//hajung//wait//%d//%d.bmp", i, j);
			LI(&player[2].WaitDC[i][j], &player[2].WaitMap[i][j], path);
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			sprintf(path, "..//Debug//resources//hajung//walk//%d//%d.bmp", i, j);
			LI(&player[2].WalkDC[i][j], &player[2].WalkMap[i][j], path);
		}
	}

	for (int i = 0; i < 19; i++) {
		sprintf(path, "..//Debug//resources//longga//%d.bmp", i);
		LI(&LonggaDC[i], &LonggaMAP[i], path);
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			sprintf(path, "..//Debug//resources//padak//walk//%d//%d.bmp", i, j);
			LI(&zombie[3].WalkDC[i][j], &zombie[3].WalkMap[i][j], path);
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 1; j++) {
			sprintf(path, "..//Debug//resources//padak//wait//%d//%d.bmp", i, j);
			LI(&zombie[3].WaitDC[i][j], &zombie[3].WaitMap[i][j], path);
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			sprintf(path, "..//Debug//resources//tink//%d//%d.bmp", i, j);
			LI(&zombie[2].WalkDC[i][j], &zombie[2].WalkMap[i][j], path);
		}
	}
	for (int i = 1; i < 15; i++) {
		sprintf(path, "..//Debug//resources//icon//fire//%d.bmp", i);
		LI(&FireDC[i], &FireMap[i], path);
	}
	for (int i = 0; i < 70; i++) {
		sprintf(path, "..//Debug//resources//number//%d.bmp", i);
		LI(&NumberDC[i], &NumberMap[i], path);
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			sprintf(path, "..//Debug//resources//zombie//%d//%d.bmp", i, j);
			LI(&zombie[0].WalkDC[i][j], &zombie[0].WalkMap[i][j], path);
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			sprintf(path, "..//Debug//resources//zombie//%d//%d.bmp", i, j);
			LI(&zombie[1].WalkDC[i][j], &zombie[1].WalkMap[i][j], path);
		}
	}

	player[4].Width = 19;
	player[4].Height = 54;
	for (int i = 3; i <= 104; i++) {
		sprintf(path, "..//Debug//resources//boss//%d.bmp", i);
		LI(&boss.WaitDC[i], &boss.WaitMap[i - 3], path);
	}
	for (int i = 1; i <= 2; i++) {
		sprintf(path, "..//Debug//resources//background//start%d.bmp", i);
		LI(&StartScreenDC[i], &StartScreenMap[i], path);
	}
	for (int i = 0; i < 4; i++) {                 //캐릭터 대기이미지 불러옴
		for (int j = 0; j < 4; j++) {
			sprintf(path, "..//Debug//resources//hanam//wait//%d//%d.bmp", i, j);
			LI(&player[4].WaitDC[i][j], &player[4].WaitMap[i][j], path);
		}
	}
	for (int i = 0; i < 4; i++) {                 //캐릭터 대기이미지 불러옴
		for (int j = 0; j < 4; j++) {
			sprintf(path, "..//Debug//resources//hanam//walk//%d//%d.bmp", i, j);
			LI(&player[4].WalkDC[i][j], &player[4].WalkMap[i][j], path);
		}
	}
	for (i = 0; i < 5; i++) {                 //방향키 이미지 불러옴
		sprintf(path, "..//Debug//resources//button//button%d.bmp", i);
		LI(&ButtonDC[i], &ButtonMap[i], path);
	}
	for (i = 0; i < 2; i++) {                 //공격버튼 이미지 불러옴
		sprintf(path, "..//Debug//resources//button//attack%d.bmp", i);
		LI(&AttackButtonDC[i], &AttackButtonMap[i], path);
	}
	for (i = 0; i < 10; i++) {               //음악 경로 저장
		sprintf(Music[i], "..//Debug//resources//music//music%d.wav", i);
	}
	for (int i = 1; i <= 4; i++) {
		sprintf(path, "..//Debug//resources//weapon//%d.bmp", i);
		LI(&pencil.WeaponDC[i], &pencil.WeaponMap[i], path);
	}
	for (int i = 0; i < 6; i++) {
		sprintf(path, "..//Debug//resources//heart//%d.bmp", i);
		LI(&LifeDC[i], &LifeMap[i], path);
	}
	for (int i = 0; i < 4; i++) {
		sprintf(path, "..//Debug//resources//olivia//%d.bmp", i);
		LI(&OlDC[i], &OlMap[i], path);
	}
}

void deletemap() {
	SetConsoleTitle("DeleteMap");  //콘솔 이름 설정
	int i, j, k;
	DeleteObject(SelectObject(ItemPosionDC, ItemPosionMap));
	DeleteObject(ItemPosionMap);
	DeleteObject(SelectObject(BackgroundDC, BackgroundMap));
	DeleteObject(BackgroundMap);
	DeleteObject(SelectObject(ItemBoomDC, ItemBoomMap));
	DeleteObject(ItemBoomMap);
	DeleteObject(ParkcutMap);
	DeleteObject(SelectObject(Dup1DC, Dup1Map));
	DeleteObject(Dup1Map);
	DeleteObject(SelectObject(Dup2DC, Dup2Map));
	DeleteObject(Dup2Map);
	DeleteObject(SelectObject(Classroom1DC, Classroom1Map));
	DeleteObject(Classroom1Map);
	DeleteObject(SelectObject(Classroom2DC, Classroom2Map));
	DeleteObject(Classroom2Map);
	for (i = 0; i < 20; i++) {
		DeleteObject(SelectObject(MissionDC[i], MissionMap[i]));
		DeleteObject(MissionMap[i]);
		DeleteObject(SelectObject(quest[i].QuestDC, quest[i].QuestMAP));
		DeleteObject(quest[i].QuestMAP);
	}
	for (i = 0; i < 19; i++) {
		DeleteObject(SelectObject(LonggaDC, LonggaMAP));
		DeleteObject(LonggaMAP[i]);
	}
	for (i = 0; i < 15; i++) {
		DeleteObject(SelectObject(FireDC[i], FireMap[i]));
		DeleteObject(FireMap[i]);
	}
	for (i = 0; i < 14; i++) {
		DeleteObject(SelectObject(boom.BoomDC[i], boom.BoomMAP[i]));
		DeleteObject(boom.BoomMAP[i]);
	}
	for (i = 0; i < 10; i++) {
		DeleteObject(SelectObject(DaeDC[i], DaeMap[i]));
		DeleteObject(DaeMap[i]);
		DeleteObject(SelectObject(ScoreDC[i], ScoreMap[i]));
		DeleteObject(ScoreMap[i]);
		DeleteObject(SelectObject(mineral1[i].MineralDC, mineral1[i].MineralMAP));
		DeleteObject(mineral1[i].MineralMAP);
	}
	for (i = 0; i < 5; i++) {
		DeleteObject(SelectObject(rock[i].RockDC, rock[i].RockMap));
		DeleteObject(rock[i].RockMap);
		DeleteObject(SelectObject(NPCDC[i], NPCMap[i]));
		DeleteObject(NPCMap[i]);
		DeleteObject(SelectObject(ChooseDC[i], ChooseMAP[i]));
		DeleteObject(ChooseMAP[i]);
		DeleteObject(SelectObject(ButtonDC[i], ButtonMap[i]));
		DeleteObject(ButtonMap[i]);
	}
	for (int i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			DeleteObject(SelectObject(zombie[0].WalkDC[i][j], zombie[0].WaitMap[i][j]));
			DeleteObject(zombie[0].WalkDC[i][j]);
			DeleteObject(SelectObject(zombie[1].WalkDC[i][j], zombie[1].WalkMap[i][j]));
			DeleteObject(zombie[1].WalkMap[i][j]);
		}
	}
	for (i = 0; i < 4; i++) {
		DeleteObject(SelectObject(TimeDC[i], TimeMAP[i]));
		DeleteObject(TimeMAP[i]);
		DeleteObject(SelectObject(GameDC[i], GameMAP[i]));
		DeleteObject(GameMAP[i]);
		DeleteObject(SelectObject(zombie[3].WaitDC[i][0], zombie[3].WaitMap[i][0]));
		DeleteObject(zombie[3].WaitMap[i][0]);
		DeleteObject(SelectObject(OlDC[i], OlMap[i]));
		DeleteObject(OlMap[i]);
		for (j = 0; j < 6; j++) {
			DeleteObject(SelectObject(zombie[8].WalkDC[i][j], zombie[8].WalkMap[i][j]));
			DeleteObject(zombie[8].WalkMap[i][j]);
			DeleteObject(SelectObject(zombie[7].WalkDC[i][j], zombie[7].WalkMap[i][j]));
			DeleteObject(zombie[7].WaitMap[i][j]);
			DeleteObject(SelectObject(zombie[5].WalkDC[i][j], zombie[5].WalkMap[i][j]));
			DeleteObject(zombie[5].WalkMap[i][j]);
			DeleteObject(SelectObject(zombie[4].WalkDC[i][j], zombie[4].WalkMap[i][j]));
			DeleteObject(zombie[4].WaitMap[i][j]);
			DeleteObject(SelectObject(zombie[4].WalkDC[i][j], zombie[4].WalkMap[i][j]));
			DeleteObject(zombie[4].WalkMap[i][j]);
		}
		for (j = 0; j < 4; j++) {
			DeleteObject(SelectObject(zombie[2].WalkDC[i][j], zombie[2].WalkMap[i][j]));
			DeleteObject(zombie[2].WalkMap[i][j]);
			DeleteObject(SelectObject(zombie[7].WalkDC[i][j], zombie[7].WalkMap[i][j]));
			DeleteObject(zombie[7].WalkMap[i][j]);
			DeleteObject(SelectObject(zombie[6].WalkDC[i][j], zombie[6].WalkMap[i][j]));
			DeleteObject(zombie[6].WalkMap[i][j]);
			DeleteObject(SelectObject(player[1].WalkDC[i][j], player[1].WalkMap[i][j]));
			DeleteObject(player[1].WalkMap[i][j]);
			DeleteObject(SelectObject(player[1].WalkDC[i][j], player[1].WalkMap[i][j]));
			DeleteObject(player[3].WalkMap[i][j]);
			DeleteObject(SelectObject(player[3].WaitDC[i][j], player[3].WaitMap[i][j]));
			DeleteObject(player[3].WaitMap[i][j]);
			DeleteObject(SelectObject(player[4].WalkDC[i][j], player[4].WalkMap[i][j]));
			DeleteObject(player[4].WalkMap[i][j]);
			DeleteObject(SelectObject(player[4].WalkDC[i][j], player[4].WalkMap[i][j]));
			DeleteObject(player[4].WalkMap[i][j]);
			DeleteObject(SelectObject(player[1].WaitDC[i][j], player[1].WaitMap[i][j]));
			DeleteObject(player[1].WaitMap[i][j]);
			DeleteObject(SelectObject(player[2].WaitDC[i][j], player[2].WaitMap[i][j]));
			DeleteObject(player[2].WaitMap[i][j]);
			DeleteObject(SelectObject(player[2].WalkDC[i][j], player[2].WalkMap[i][j]));
			DeleteObject(player[2].WalkMap[i][j]);
			DeleteObject(SelectObject(zombie[2].WalkDC[i][j], zombie[2].WalkMap[i][j]));
			DeleteObject(zombie[2].WalkMap[i][j]);
			DeleteObject(SelectObject(player[4].WaitDC[i][j], player[4].WaitMap[i][j]));
			DeleteObject(player[4].WaitMap[i][j]);
			DeleteObject(SelectObject(player[4].WalkDC[i][j], player[4].WalkMap[i][j]));
			DeleteObject(player[4].WalkMap[i][j]);
		}
		for (j = 0; j < 3; j++) {
			DeleteObject(SelectObject(zombie[3].WalkDC[i][j], zombie[3].WalkMap[i][j]));
			DeleteObject(zombie[3].WalkMap[i][j]);
		}
	}
	for (i = 0; i < 70; i++) {
		DeleteObject(SelectObject(NumberDC[i], NumberMap[i]));
		DeleteObject(NumberMap[i]);
	}
	for (i = 3; i <= 104; i++) {
		DeleteObject(SelectObject(boss.WaitDC[i], boss.WaitMap[i]));
		DeleteObject(boss.WaitMap[i]);
	}
	for (i = 1; i <= 2; i++) {
		DeleteObject(SelectObject(StartScreenMap[i], StartScreenMap[i]));
		DeleteObject(StartScreenMap[i]);
	}
	for (i = 0; i < 2; i++) {
		DeleteObject(SelectObject(AttackButtonDC[i], AttackButtonMap[i]));
		DeleteObject(AttackButtonMap[i]);
	}
	for (i = 1; i <= 4; i++) {
		DeleteObject(SelectObject(pencil.WeaponDC[i], pencil.WeaponMap[i]));
		DeleteObject(pencil.WeaponMap[i]);
	}
	for (i = 0; i < 6; i++) {
		DeleteObject(SelectObject(LifeDC[i],LifeMap[i]));
		DeleteObject(LifeMap[i]);
	}
}
void deletedc() {
	SetConsoleTitle("DeleteDC");  //콘솔 이름 설정
	int i, j, k;
	DeleteDC(ItemPosionDC);
	DeleteDC(BackgroundDC);
	DeleteDC(ItemBoomDC);
	DeleteDC(colDC);
	DeleteDC(Dup1DC);
	DeleteDC(Dup2DC);
	DeleteDC(Classroom1DC);
	DeleteDC(Classroom2DC);
	for (i = 0; i < 20; i++) {
		DeleteDC(MissionDC[i]);
		DeleteDC(quest[i].QuestDC);
	}
	for (i = 0; i < 19; i++) {
		DeleteDC(LonggaDC[i]);
	}
	for (i = 0; i < 15; i++) {
		DeleteDC(FireDC[i]);
	}
	for (i = 0; i < 14; i++) {
		DeleteDC(boom.BoomDC[i]);
	}
	for (i = 0; i < 10; i++) {
		DeleteDC(ScoreDC[i]);
		DeleteDC(DaeDC[i]);
		DeleteDC(mineral1[i].MineralDC);
	}
	for (i = 0; i < 5; i++) {
		DeleteDC(rock[i].RockDC);
		DeleteDC(NPCDC[i]);
		DeleteDC(ChooseDC[i]);
		DeleteDC(ButtonDC[i]);
		for (j = 0; j < 4; j++) {
			DeleteDC(zombie[0].WalkDC[i][j]);
			DeleteDC(zombie[1].WalkDC[i][j]);
		}
	}
	for (i = 0; i < 4; i++) {
		DeleteDC(TimeDC[i]);
		DeleteDC(GameDC[i]);
		DeleteDC(zombie[3].WaitDC[i][0]);
		DeleteDC(OlDC[i]);
		for (j = 0; j < 6; j++) {
			DeleteDC(zombie[8].WalkDC[i][j]);
			DeleteDC(zombie[7].WaitDC[i][j]);
			DeleteDC(zombie[5].WalkDC[i][j]);
			DeleteDC(zombie[4].WaitDC[i][j]);
			DeleteDC(zombie[4].WalkDC[i][j]);
		}
		for (j = 0; j < 4; j++) {
			DeleteDC(zombie[2].WalkDC[i][j]);
			DeleteDC(zombie[7].WalkDC[i][j]);
			DeleteDC(zombie[6].WalkDC[i][j]);
			DeleteDC(player[1].WalkDC[i][j]);
			DeleteDC(player[3].WalkDC[i][j]);
			DeleteDC(player[3].WaitDC[i][j]);
			DeleteDC(player[4].WalkDC[i][j]);
			DeleteDC(player[4].WalkDC[i][j]);
			DeleteDC(player[1].WaitDC[i][j]);
			DeleteDC(player[2].WaitDC[i][j]);
			DeleteDC(player[2].WalkDC[i][j]);
			DeleteDC(zombie[2].WalkDC[i][j]);
			DeleteDC(player[4].WaitDC[i][j]);
			DeleteDC(player[4].WalkDC[i][j]);
		}
		for (j = 0; j < 3; j++) {
			DeleteDC(zombie[3].WalkDC[i][j]);
		}
	}
	for (i = 0; i < 70; i++) {
		DeleteDC(NumberDC[i]);
	}
	for (i = 3; i <= 104; i++) {
		DeleteDC(boss.WaitDC[i]);
	}
	for (i = 1; i <= 2; i++) {
		DeleteDC(StartScreenDC[i]);
	}
	for (i = 0; i < 2; i++) {
		DeleteDC(AttackButtonDC[i]);
	}
	for (i = 1; i <= 4; i++) {
		DeleteDC(pencil.WeaponDC[i]);
	}
	for (i = 0; i < 6; i++) {
		DeleteDC(LifeDC[i]);
	}
}

void HideCursor(char show) {  //커서숨기기 :  show의 값이 0이면 숨김, 1이면 보임
	CONSOLE_CURSOR_INFO cc;
	cc.bVisible = show;
	cc.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cc);
}
void gotoxy(int x, int y) {        //좌표로 커서 이동 함수
	COORD co = { x,y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), co);
}
int kp(int key) {   //키보드 입력 상태 확인하는 함수  ????
	return (GetAsyncKeyState(key) & 0x8000);
}
void LI(HDC* DC, HBITMAP* Map, char* path) {  //LoadImage, 이미지를 불러오는 함수
	(*DC) = CreateCompatibleDC(ConsoleDC);
	(*Map) = (HBITMAP)LoadImage(NULL, path, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	SelectObject(*DC, *Map);
}
void PT(int sx, int sy, int w, int h, HDC originDC) {  //투명화 이미지 출력 
	TransparentBlt(ConsoleDC, sx, sy, w, h, originDC, 0, 0, w, h, RGB(255, 0, 255));  //RGB인자 값 : 제거할 배경 색
}
void PTforF(int sx, int sy, int w, int h, HDC originDC) {  //투명화 이미지 출력 
	TransparentBlt(ConsoleDC, sx, sy, w, h, originDC, 0, 0, w, h, RGB(0, 0, 0));  //RGB인자 값 : 제거할 배경 색
}
void PO(int sx, int sy, int ox, int oy, int w, int h, HDC originDC) { //?
	BitBlt(ConsoleDC, sx, sy, w, h, originDC, ox, oy, SRCCOPY);
}
void PI(int sx, int sy, int w, int h, HDC originDC) {         //?
	BitBlt(ConsoleDC, sx, sy, w, h, originDC, 0, 0, SRCCOPY);
}
void ST(int sx, int sy, int w, int h, HDC originDC) { // w,h -> 콘솔에 출력할 이미지 크기 , 400,100,300,150 ->위치, 크기
	StretchBlt(ConsoleDC, sx, sy, w, h, BackgroundDC, 0, 0, w, h, SRCCOPY);
}
