#pragma once
#include "Main.h"
#include "stage.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <mmsystem.h> 
#include <time.h>
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "msimg32.lib")
#define gamemusic "..//Debug//resources//music//start.wav"
#define startmusic "..//Debug//resources//music/music0.wav"
#define AttackButtonSize 90
#define ButtonSize 147
void UtilityInit();
void gotoxy(int x, int y);
void HideCursor(char show);
void LI(HDC* DC, HBITMAP* Map, char* path);
void PO(int sx, int sy, int ox, int oy, int w, int h, HDC originDC);
void PI(int sx, int sy, int w, int h, HDC originDC);
void PT(int sx, int sy, int w, int h, HDC originDC);

void deletedc();
void deletemap();

HWND ConsoleWindow;
HINSTANCE ConsoleInstance;
HDC ConsoleDC;
DWORD WINAPI ThreadFunc(LPVOID);
HANDLE hThrd; //스레드를 접근하기 위한 손잡이 개념
DWORD threadId;
HDC     StartScreenDC[10];
HBITMAP StartScreenMap[10];
HDC BackgroundDC[10];
HBITMAP BackgroundMap[10];
HDC Dup1DC, Dup2DC;
HBITMAP Dup1Map, Dup2Map;
HDC OlDC[4];
HBITMAP OlMap[4];
HBITMAP ParkMap;
HDC FireDC[15];
HBITMAP FireMap[15];
HDC NewDC;
HBITMAP NewMap;
HDC NumberDC[70];
HBITMAP NumberMap[70];
HDC Classroom1DC, Classroom2DC;
HBITMAP Classroom1Map, Classroom2Map;
HBITMAP ParkcutMap;
HDC     ButtonDC[10];        //방향키
HBITMAP ButtonMap[10];       //방향키
HDC LonggaDC[18];
HBITMAP LonggaMAP[18];
HDC colDC;
HBITMAP colMap;
HDC ChooseDC[5];
HBITMAP ChooseMAP[5];
HDC MysteryDC[4];
HBITMAP MysteryMap[4];
HDC TimeDC[3];
HBITMAP TimeMAP[3];
HDC GameDC[3];
HBITMAP GameMAP[3];
HDC     AttackButtonDC[5];  //공격버튼
HBITMAP AttackButtonMap[5];  //공격버튼
HDC ScoreDC[10];
HBITMAP ScoreMap[10];
HDC ItemBoomDC;
HBITMAP ItemBoomMap;
HDC ItemLifeDC;
HBITMAP ItemLifeMap;
HDC FirstDC;
HBITMAP FirstMap;
HDC FinalDC;
HBITMAP FinalMap;
HDC ItemPosionDC;
HBITMAP ItemPosionMap;
HDC LifeDC[5];
HBITMAP LifeMap[5];
HDC DaeDC[20];
HBITMAP DaeMap[20];
HDC NPCDC[4];
HBITMAP NPCMap[4];
HDC MissionDC[30];
HBITMAP MissionMap[30];
char Music[10][300];
HDC JaryoDC;
HBITMAP JaryoMap;
HDC FinaldaeDC[10];
HBITMAP FinaldaeMap[10];
HDC FinalbossDC[8];
HBITMAP FinalbossMap[8];
HDC EffectDC[9];
HBITMAP EffectMap[9];
int roundcheck;
int zombiecnt;
int effectcnt;
int finalbosscnt;
int finaldae;
int jaryocheck;
int MaxLife;
int CurrentLife;
int finalvisible;
int zomcnt1;
int iblecnt;
int finalcheck;
int jon;
int rockvisible[4];
int npccnt;
int mulcheck;
int mulcheckforlife;
int quest1check;
int minmidcheck1;
int newcheck;
int key;
int mission1check;
int yk;
int visiblecnt;
int itemboomcheck;
int scil;
int dae;
int scsip;
int scbak;
int scchun;
int daecheck;
int scman;
int lifecnt;
int sk;
int score;
int questflag;
int followcheckyuk;
int wherein;
int olcnt;
int tcnt;
int zombie1alive;
int chchange;
int ion;
int followchecktink;
int crk;
int zombie1dir;
int tk;
int k;
int zk;
int myscnt;
int u;
int chrcheck;
int followcheck;
int followcheckzombie;
int followcheckyuk2;
int followcheckinyeongu;
int ik;
int zkr;
int rk;
int prk;
int ion2;
int sec, min;
int CurrentLife;
int mission2check;
int rockcheck;
int visibleu;
typedef struct {
	HDC RockDC;
	HBITMAP RockMap;
	int visible;
}Rock;
Rock rock[3];
typedef struct {
	HDC MineralDC;
	HBITMAP MineralMAP;
	int xPosition;
	int yPosition;
	int visible;
	int minon;
}Mineral1;
Mineral1 mineral1[10];
typedef struct {
	HDC MineralDC;
	HBITMAP MineralMAP;
	int xPosition;
	int yPosition;
	int visible;
	int minon;
}Mineral2;
Mineral2 mineral2[10];
typedef struct {
	HDC MineralDC;
	HBITMAP MineralMAP;
	int xPosition;
	int yPosition;
	int visible;
	int minon;
}Mineral3;
Mineral3 mineral3[10];
typedef struct {
	HDC QuestDC;
	HBITMAP QuestMAP;
}Quest[20];
Quest  quest;
typedef struct {
	int Width;   //가로길이
	int Height;  //세로길이
	HDC WaitDC[5][5];        //대기이미지    0=뒤  1=앞  2=왼  3=오
	HBITMAP WaitMap[5][5];   //대기이미지
	HDC WalkDC[5][5];        //걷는이미지
	HBITMAP WalkMap[5][5];   //걷는이미지
	int SpriteCount;    //캐릭터 이미지 카운트
	int xPosition;  //캐릭터 X좌표
	int yPosition;  //캐릭터 Y좌표
	int dw;
	int daegicheck;
	int hp;
	int cnt;
	int su;
	int dir;   //캐릭터가 보고 있는 방향
}Character;
Character player[10];
typedef struct {
	int Width; //0 : 메인에서 가로세로 광기 1 : 메인에서 위아래 광기 2:팅크좀비 3:파닥좀비 4:이블아이 5:연구좀비 6:연기좀비
	//7 : 육상좀비 8 : 사진찍는 좀비
	int Height;
	HDC WalkDC[5][6];
	HBITMAP WalkMap[5][6];
	HDC WaitDC[5][6];
	HBITMAP WaitMap[5][6];
	int hp;
	int cnt;
	int xPosition;
	int yPosition;
	int visible;
	int dir;
	int check;
}Zombie;
Zombie zombie[20];
typedef struct {
	HDC WaitDC[104];
	HBITMAP WaitMap[104];
	int Width; // 408
	int Height; //396
	int xPosition;
	int yPosition;
	int cnt;

}Boss;
typedef struct {
	int Width;
	int Height;
	int xPosition;
	int yPosition;
	int cnt;
	HDC WaitDC[4][4];
	HBITMAP WaitMap[4][4];
	HDC WalkDC[4][4];
	HBITMAP WalkMap[4][4];
	int dir;
}Yang;
Yang yang;
Boss boss;
typedef struct {
	HDC BoomDC[14];
	HBITMAP BoomMAP[14];
	int xPosition;
	int yPosition;
	int cnt;
}Boom;
Boom boom;
typedef struct {
	int atxPosition;
	int atyPosition;
	HDC WeaponDC[30];
	HBITMAP WeaponMap[30];
	int dir;
}Pencil;
Pencil pencil;
typedef struct {
	int xPosition;
	int yPosition;
	HDC JusaDC[4];
	HBITMAP JusaMap[4];
	int dir;
}Jusa;
Jusa jusa;
