#pragma once
#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <windows.h>
#include <stdio.h>
#include <mmsystem.h> 
#include "Utility.h"
#include "stage.h"
char name[200];  //플레이어 이름
int round;       //라운드
int score;       //점수
int level;       //난이도 : 1=쉬움  2=보통  3=어려움
int restartflag;
int exitgameflag;
void npcprint();
void printImageinfire();
void finalmap();
void checkscore();
void questmap();
void MainGame();
void olprint();
void checkzombie();
void MainRender();
void mysprint();
void thirdback();
void yukfollow();
void displayStart();
void bossprint();
void crazycheck1();
void resizeConsole(int width, int height);
void gameStart();
void saveCheck();
void secondback();
void timeImage();
void Lifecheck(int x, int y);
void fireplace();
void classroom1();
void classroom2();
void finalboss();
void finalfollow(int x, int y);
void myroom();
void fire();
void zombiecheck1();
void zombiecheck2();
int cnt;
void missioncheck();
void saveProcess();
void restart();
void chrchoose();

int cannotgoleft();
int cannotgoright();
int cannotgoup();
int cannotgodown();
int cannotgorightinpark();
int cannotgoleftinpark();
int cannotgoupinpark();
int cannotgodowninpark();
int cannotgorightincafe();
int cannotgoleftincafe();
int cannotgoupincafe();
int cannotgodownincafe();
int cannotgorightinmyroom();
int cannotgoleftinmyroom();
int cannotgoupinmyroom();
int cannotgodowninmyroom();
int cannotgodownincl2();
int cannotgodowninfire();
int cannotgodowninmyroom();
int cannotgorightincl1();
int cannotgoleftincl1();
int cannotgoupincl1();
int cannotgodownincl1();
int cannotgorightincl2();
int cannotgoleftinfire();
int cannotgoleftincl2();
int cannotgoupinfire();
int cannotgoupincl2();



time_t startTime;
time_t endTime;
#endif
