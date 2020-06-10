#include "Main.h"
/* 
전체적으로 key값에 따라 화면이 전환되며, 좀비가 보이고 안보이고는 변수에 따라서 결정됨.
Time.h를 이용해 시간을 출력했으며 pencilAttack()함수는 스레드를 사용해서 동시 출력을 함
처음에 퀘스트를 받고 게임이 시작되면 M키를 누르면 깨야 할 퀘스트를 볼 수 있다.
1라운드의 미션은 미네랄을 먹고 점수를 따고 좀비를 5마리 죽이는 것이고, 2라운드는 신비의 돌을 찾아
올리비아에게 전달하는 것이고, 올리비아에게 M버튼을 눌러 전달하면 옆에 자료를 먹고 엔터키를 누르면
최종 보스의 방으로 이동한다. 보스의 방으로 이동해서 물약을 먹으면 3번 버튼으로 주사기를 쏠 수 있는데,
주사기로 보스를 죽일 수 있고 최종 보스를 죽이면 게임클리어 화면이 나타난다. 게임오버되는 조건은
생명이 다 닳거나 시간이 다 지나는것이다

 ===>  좀디고등학교 플레이 방법  <===

W,A,S,D : 방향키
M (꾹 누르기) : 미션 보이기
M : 올리비아에게 신비한 돌 전달

엔터 : 대화창 넘기기

공격키 (공격은 아이템을 획득한 후 사용할 수 있습니다)
1 : 연필
2 : 폭탄
3 : 주사기

게임종료, 타임아웃, 게임 클리어 화면에서
s : 저장
q : 게임 종료
r : 다시 시작


제작자 : 18HD 김서은,김예린
원작 : 좀비고등학교
재밌지 않지만 재미ㅔㅅㄲㄴㅇ레즐기셈!!
*/
unsigned _stdcall pencilAttack() { //플레이어의 움직임과 동시에 움직이고 아이템을 먹을 시 쓸 수 있는 아이템 출력
	while (1) {
		pencil.atxPosition = player[chchange].xPosition - 10;
		pencil.atyPosition = player[chchange].yPosition + 20;
		boom.xPosition = player[chchange].xPosition - 80;
		boom.yPosition = player[chchange].yPosition - 90;
		if (GetAsyncKeyState(0x31) < 0 && player[chchange].dir == 3 && ion == 1) {
			for (int i = pencil.atxPosition; i <= pencil.atxPosition + 120; i += 12) {
				PT(i, pencil.atyPosition + 20, 43, 7, pencil.WeaponDC[3]);
				Sleep(20);
				for (int j = 0; j < 10; j++) { //무기가 좀비에게 닿으면 좀비는 사라짐
					if (pencil.atxPosition >= zombie[j].xPosition - 40 && pencil.atxPosition <= zombie[j].xPosition +40
						&& pencil.atyPosition >= zombie[j].yPosition - 30 && pencil.atyPosition <= zombie[j].yPosition+30 && visibleu % 2 == 0) {
						if(zombie[j].visible==1){
							visiblecnt+=1;
						}
						zombie[j].visible = 0;
					}
				}
				PT(72, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[1]);
			}
		}
		if (GetAsyncKeyState(0x31) < 0 && player[chchange].dir == 2 && ion == 1) {
			for (int i = pencil.atxPosition; i >= player[chchange].xPosition - 120; i -= 12) {
				PT(i, pencil.atyPosition + 20, 43, 7, pencil.WeaponDC[2]);
				Sleep(20);
				for (int j = 0; j < 10; j++) {
					if (pencil.atxPosition >= zombie[j].xPosition -40 && pencil.atxPosition <= zombie[j].xPosition+40
						&& pencil.atyPosition >= zombie[j].yPosition - 30 && pencil.atyPosition <= zombie[j].yPosition+30) {
						if (zombie[j].visible == 1 && visibleu % 2 == 0) {
							visiblecnt++;
						}
						if (j == 0 || 1 || 2 && wherein == 0) {
							zombie[j].visible = 0;
						}
						else if (j == 3 || 4 || 5 || 6 && wherein == 4) {
							zombie[j].visible = 0;
						}
					}
				}
				PT(72, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[1]);
			}
		}
		if (GetAsyncKeyState(0x31) < 0 && player[chchange].dir == 1 && ion == 1) {
			for (int i = pencil.atyPosition; i <= pencil.atyPosition + 120; i += 12) {
				PT(pencil.atxPosition + 20, i, 7, 43, pencil.WeaponDC[1]);
				Sleep(20);
				for (int j = 0; j < 10; j++) {
					if (pencil.atxPosition >= zombie[j].xPosition - 15 && pencil.atxPosition <= zombie[j].xPosition + 15
						&& pencil.atyPosition >= zombie[j].yPosition-30&& pencil.atyPosition <= zombie[j].yPosition) {
						if (zombie[j].visible == 1 && visibleu % 2 == 0) {
							visiblecnt++;
						}
						if (j == 0 || 1 || 2 && wherein == 0) {
							zombie[j].visible = 0;
						}
						else if (j == 3 || 4 || 5 || 6 && wherein == 4) {
							zombie[j].visible = 0;
						}
					}
				}
				PT(72, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[1]);
			}
		}
		if (GetAsyncKeyState(0x31) < 0 && player[chchange].dir == 0 && ion == 1) {
			for (int i = pencil.atyPosition; i >= pencil.atyPosition - 120; i -= 12) {
				PT(pencil.atxPosition + 20, i, 7, 43, pencil.WeaponDC[4]);
				Sleep(20);
				for (int j = 0; j < 10; j++) {
					if (pencil.atxPosition >= zombie[j].xPosition - 50 && pencil.atxPosition <= zombie[j].xPosition +50
						&& pencil.atyPosition >= zombie[j].yPosition - 30 && pencil.atyPosition <= zombie[j].yPosition+30) {
						if (zombie[j].visible == 1 && visibleu % 2 == 0) {
							visiblecnt++;
						}
						if (j == 0 || 1 || 2 && wherein == 0) {
							zombie[j].visible = 0;
						}
						else if (j == 3 || 4 || 5 || 6 && wherein == 4) {
							zombie[j].visible = 0;
						}
					}
				}
				PT(72, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[1]);
			}
		}
		if (GetAsyncKeyState(0x32) < 0 && player[chchange].dir == 3 && itemboomcheck == 1) {
			for (int i = 0; i < 15; i++) { //2번 눌렀을 때 폭탄 출력
				PT(boom.xPosition+80, boom.yPosition, 192, 176, boom.BoomDC[i]);
				checkzombie();
				Sleep(20);
				for (int j = 0; j < 10; j++) {
					if (boom.xPosition >= zombie[j].xPosition - 120 && boom.xPosition <= zombie[j].xPosition + 120
						&& boom.yPosition >= zombie[j].yPosition - 100 && boom.yPosition <= zombie[j].yPosition + 100) {
						if (zombie[j].visible == 1 && visibleu % 2 == 0) {
							visiblecnt++;
						}
						if (j == 0 || 1 || 2 && wherein == 0) {
							zombie[j].visible = 0;
						}
						else if (j == 3 || 4 || 5 || 6 && wherein == 4) {
							zombie[j].visible = 0;
						}
					}
				}
				PT(72, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[1]);
			}
		}
		if (GetAsyncKeyState(0x32) < 0 && player[chchange].dir == 2 && itemboomcheck == 1) {
			for (int i = 0; i < 14; i++) {
				PT(boom.xPosition-80, boom.yPosition, 192, 176, boom.BoomDC[i]);
				checkzombie();
				Sleep(20);
				for (int j = 0; j < 10; j++) {
					if (boom.xPosition >= zombie[j].xPosition - 120 && boom.xPosition <= zombie[j].xPosition + 120
						&& boom.yPosition >= zombie[j].yPosition - 100 && boom.yPosition <= zombie[j].yPosition + 100 ) {
						if (zombie[j].visible == 1 && visibleu % 2 == 0) {
							visiblecnt++;
						}
						if (j == 0 || 1 || 2 && wherein == 0) {
							zombie[j].visible = 0;
						}
						else if (j == 3 || 4 || 5 || 6 && wherein == 4) {
							zombie[j].visible = 0;
						}
					}
				}
				PT(72, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[1]);
			}
		}
		if (GetAsyncKeyState(0x32) < 0 && player[chchange].dir == 1 && itemboomcheck == 1) {
			for (int i = 0; i < 14; i++) {
				PT(boom.xPosition, boom.yPosition+80, 192, 176, boom.BoomDC[i]);
				checkzombie();
				Sleep(20);
				for (int j = 0; j < 10; j++) {
					if (boom.xPosition >= zombie[j].xPosition - 100 && boom.xPosition <= zombie[j].xPosition + 100
						&& boom.yPosition >= zombie[j].yPosition -100 && boom.yPosition <= zombie[j].yPosition + 100 ) {
						if (zombie[j].visible == 1 && visibleu % 2 == 0) {
							visiblecnt++;
						}
						if (j == 0 || 1 || 2 && wherein == 0) {
							zombie[j].visible = 0;
						}
						else if (j == 3 || 4 || 5 || 6 && wherein == 4) {
							zombie[j].visible = 0;
						}
					}
				}
				PT(72, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[1]);
			}
		}
		if (GetAsyncKeyState(0x32) < 0 && player[chchange].dir == 0 && itemboomcheck == 1) {
			for (int i = 0; i < 14; i++) {
				PT(boom.xPosition, boom.yPosition-80, 192, 176, boom.BoomDC[i]);
				checkzombie();
				Sleep(20);
				for (int j = 0; j < 10; j++) {
					if (boom.xPosition >= zombie[j].xPosition -100 && boom.xPosition <= zombie[j].xPosition + 100
						&& boom.yPosition >= zombie[j].yPosition -100 && boom.yPosition <= zombie[j].yPosition +100) {
						if (zombie[j].visible == 1 && visibleu % 2 == 0) {
							visiblecnt++;
						}
						if (j == 0 || 1 || 2 && wherein == 0) {
							zombie[j].visible = 0;
						}
						else if (j == 3 || 4 || 5 || 6 && wherein == 4) {
							zombie[j].visible = 0;
						}
						visibleu++;
					}
				}
				PT(72, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[1]);
			}
		}
		if(GetAsyncKeyState(0x33) < 0 && player[chchange].dir == 3 && jon == 1) {
			for (int i = jusa.xPosition; i <=jusa.xPosition + 300; i += 30) {
				PT(i, jusa.yPosition + 20, 46, 9, jusa.JusaDC[3]);
				Sleep(20);
				if (jusa.xPosition >= 960 && jusa.xPosition <= 1000 && jusa.yPosition >= 180 && jusa.yPosition <= 240) {
					finalvisible = 0;
				}
				PT(72, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[3]);
			}
		}
		if (GetAsyncKeyState(0x33) < 0 && player[chchange].dir == 2 && jon == 1) {
			for (int i = jusa.xPosition; i >= player[chchange].xPosition - 300; i -= 30) {
				PT(i, jusa.yPosition + 20, 46, 9, jusa.JusaDC[2]);
				Sleep(20); //3번 누르고 물약 먹었을 때 주사기 출력
				if (jusa.xPosition >= 960 && jusa.xPosition<=1000&& jusa.yPosition >= 180 && jusa.yPosition <= 240) {
					finalvisible = 0;
				}
				PT(72, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[2]);
			}
		}
		if (GetAsyncKeyState(0x33) < 0 && player[chchange].dir == 1 && jon == 1) {
			for (int i = jusa.yPosition; i <= jusa.yPosition + 300; i += 30) {
				PT(pencil.atxPosition + 20, i, 9, 46, jusa.JusaDC[1]);
				Sleep(20);
				if (jusa.xPosition >= 960 && jusa.xPosition <= 1000 && jusa.yPosition >= 180 && jusa.yPosition <= 240) {
					finalvisible = 0;
				}
				PT(72, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[1]);
			}
		}
		if (GetAsyncKeyState(0x33) < 0 && player[chchange].dir == 0 && jon == 1) {
			for (int i = jusa.yPosition; i >= jusa.yPosition - 300; i -= 30) {
				PT(jusa.xPosition + 20, i, 9, 46, jusa.JusaDC[0]);
				Sleep(20);
				if (jusa.xPosition >= 960 && jusa.xPosition <= 1000 && jusa.yPosition >= 180 && jusa.yPosition <= 240) {
					finalvisible = 0;
				}
				PT(72, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[1]);
			}
		}
		pencil.atxPosition = player[chchange].xPosition;
		pencil.atyPosition = player[chchange].yPosition;
		boom.xPosition = player[chchange].xPosition - 60;
		boom.yPosition = player[chchange].yPosition - 60;
		jusa.xPosition = player[chchange].xPosition;
		jusa.yPosition = player[chchange].yPosition;
	}
}
void lifeinmain() {//플레이어의 좀비와의 충돌을 체크하고 생명을 감소시키는 함수
	if (player[chchange].xPosition >= zombie[0].xPosition - 15 && player[chchange].xPosition <= zombie[0].xPosition + 15 &&
		player[chchange].yPosition >= zombie[0].yPosition - 20 && player[chchange].yPosition <= zombie[0].yPosition + 20 
		&& lifecnt % 70 == 0 && wherein == 0 && zombie[0].visible==1) {
		CurrentLife--;
	}
	if (player[chchange].yPosition >= zombie[1].yPosition - 20 && player[chchange].yPosition <= zombie[1].yPosition + 20 &&
		player[chchange].xPosition >=1075 && player[chchange].xPosition <= 1165 
		&& lifecnt % 70 == 0 && wherein == 0 && zombie[1].visible==1) {
		CurrentLife--;
	}
	if (player[chchange].yPosition >= zombie[2].yPosition - 15 && player[chchange].yPosition <= zombie[2].yPosition + 15 &&
		player[chchange].xPosition >= zombie[2].xPosition - 20 && player[chchange].xPosition <= zombie[2].xPosition + 20 
		&& lifecnt % 70 == 0 && wherein == 0 &&zombie[2].visible==1) {
		CurrentLife--;
	}
	if (player[chchange].yPosition >= zombie[3].yPosition - 30 && player[chchange].yPosition <= zombie[3].yPosition + 30 &&
		player[chchange].xPosition >= 215 && player[chchange].xPosition <=255
		&& lifecnt % 70 == 0 && wherein == 4 &&zombie[3].visible==1) {
		CurrentLife--;
	}
	if (player[chchange].yPosition >= zombie[4].yPosition - 30 && player[chchange].yPosition <= zombie[4].yPosition + 30 &&
		player[chchange].xPosition >= zombie[4].xPosition - 20 && player[chchange].xPosition <= zombie[4].xPosition + 20
		&& lifecnt % 70 == 0 && wherein == 4 && zombie[4].visible == 1) {
		CurrentLife-=1;
	}
	if (player[chchange].yPosition >= zombie[5].yPosition - 30 && player[chchange].yPosition <= zombie[5].yPosition + 30 &&
		player[chchange].xPosition >= zombie[5].xPosition - 20 && player[chchange].xPosition <= zombie[5].xPosition + 20
		&& lifecnt % 50 == 0 && wherein == 4 && zombie[5].visible == 1) {
		CurrentLife-=1;
	}
	if (player[chchange].yPosition >= zombie[6].yPosition - 30 && player[chchange].yPosition <= zombie[6].yPosition + 30 &&
		player[chchange].xPosition >= zombie[6].xPosition - 20 && player[chchange].xPosition <= zombie[6].xPosition + 20
		&& lifecnt % 50 == 0 && wherein == 4 && zombie[6].visible == 1) {
		CurrentLife-=1;
	}
	lifecnt++;
}
int main() {
	HideCursor(0); //커서숨기기
	deletedc();    //DC
	deletemap();   //MAP해제
	UtilityInit(); //이미지 불러오기
	restartpoint:   //다시시작여기서
	chrcheck = 0;
	u = 0;
	dae = 0;
	restartflag = 0; //다시하기체크 초기화
	exitgameflag = 0;
	displayStart();  //시작 화면 출력
	saveCheck();     //세이브 파일 불러오기 및 체크
	key = 0;
	CurrentLife = 5;    //현재 생명
	_beginthreadex(NULL, 0, pencilAttack, 0, 0, NULL);  //연필공격 스레드
	//_beginthreadex(NULL, 0, Thread_Zombie, 0, 0, NULL);
	//_beginthreadex(NULL, 0, Thread_Bomb, 0, 0, NULL);
	player[0].xPosition = 0;
	player[0].yPosition = 0;
	zombie[0].xPosition = 100;
	zombie[0].yPosition = 100;
	zombie[1].xPosition = 800;
	zombie[1].yPosition = 140;
	min = 3;
	startTime = clock(); //Time.h에서 시작 시간 담음
	while (1) {
		if (restartflag) goto restartpoint;
		if (exitgameflag) goto exit;
		if (questflag == 3) {
			key = 100;
			player[chchange].xPosition = 600;
			player[chchange].yPosition = 350;
		}
		gameStart();
		switch (key) //key값에 따라 화면이 바뀜
		{
		case -3:
			finalmap();
			Sleep(60);
			break;
		case -1:
			questmap();
			Sleep(60);
			break;
		case 0:
			chrchoose();
			break;
		case 1:
			MainRender();
			Sleep(60);
			lifeinmain();
			break;
		case 2:
			secondback();
			Sleep(60);
			break;
		case 4:
			SetConsoleTitle("stage 1");
			classroom1();
			Sleep(60);
			break;
		case 5:
			SetConsoleTitle("stage 2");
			classroom2();
			Sleep(60);
			break;
		case 6:
			SetConsoleTitle("stage 3");
			myroom();
			Sleep(60);
			break;
		case 7:
			fireplace();
			Sleep(60);
			break;
		case 100:
			finalmap();
			Sleep(60);
			break;
		}
		lifeinmain();
	}

exit:   //게임종료 시 여기로
	deletemap();
	deletedc();
	return 0;
}
void questmap() { //첫 화면에서 진행할 때
	PT(0, 0, 1199,604, FirstDC);
	PT(0, 600, 1200, 268, DaeDC[dae]);
	int daecnt = 0;
	if (GetAsyncKeyState(VK_DOWN) < 0) {   //아래 방향키 눌렀을때
		player[chchange].dir = 1; //yPosition-50
		if (cannotgodowninfire() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[1][player[chchange].cnt++]);
		}
		else {
			PT(player[chchange].xPosition, player[chchange].yPosition + 10, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[1][player[chchange].cnt++]);
			player[chchange].yPosition += 10;
			npcprint();
		}
	}
	else if (GetAsyncKeyState(VK_UP) < 0) {  //위 방향키 눌렀을때
		player[chchange].dir = 0;
		if (cannotgoupincl2() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[0][player[chchange].cnt++]);
			
		}
		else {
			PT(player[chchange].xPosition, player[chchange].yPosition - 10, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[0][player[chchange].cnt++]);
			player[chchange].yPosition -= 10;
			npcprint();
		}
	}
	else if (GetAsyncKeyState(VK_LEFT) < 0) {   //왼쪽 방향키 눌렀을때
		if (cannotgoleftincl2() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[2][player[chchange].cnt++]);
			
		}
		else
		{
			PT(player[chchange].xPosition - 10, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[2][player[chchange].cnt++]);
			player[chchange].xPosition -= 10;
			
		}
		player[chchange].dir = 2;
		npcprint();
	}
	else if (GetAsyncKeyState(VK_RIGHT) < 0) {
		if (cannotgorightincl2() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[3][player[chchange].cnt++]);
			
		}
		else {
			PT(player[chchange].xPosition + 10, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[3][player[chchange].cnt++]);
			player[chchange].xPosition += 10;
		}
		player[chchange].dir = 3;
		npcprint();
	}
	else if (GetAsyncKeyState(VK_RETURN) < 0 && daecnt%7==0) {
		if (dae < 4 || dae>5) {
			dae++;
		}
		daecnt++;
	}
	else if (GetAsyncKeyState(0x59) < 0) {
		dae = 5;
	}
	else if (GetAsyncKeyState(0x4E) < 0) {
		dae = 6;
	}
	else if (GetAsyncKeyState(0x53) < 0) {
		key = 1;
		PlaySound(0, 0, 0);
		PlaySound(TEXT(Music[1]), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		player[chchange].xPosition = 80;
		player[chchange].yPosition = 750;
		resizeConsole(122, 42);
	}
	else {
		PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[player[chchange].dir][player[chchange].cnt]);
		npcprint();
	}
	npcprint();
	player[chchange].cnt = player[chchange].cnt % 4;
}
void finalmap() { //마지막 맵에서 보스와 싸울 때
	PT(0, 0, 1200, 658,FinalDC);
	PT(0, 600, 1200, 268, FinaldaeDC[finaldae]);
	if (GetAsyncKeyState(VK_DOWN) < 0) {   //아래 방향키 눌렀을때
		player[chchange].dir = 1; //yPosition-50
		if (cannotgodowninfire() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[1][player[chchange].cnt++]);
		}
		else {
			PT(player[chchange].xPosition, player[chchange].yPosition + 10, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[1][player[chchange].cnt++]);
			player[chchange].yPosition += 10;
		}
	}
	else if (GetAsyncKeyState(VK_UP) < 0) {  //위 방향키 눌렀을때
		player[chchange].dir = 0;
		if (cannotgoupincl2() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[0][player[chchange].cnt++]);

		}
		else {
			PT(player[chchange].xPosition, player[chchange].yPosition - 10, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[0][player[chchange].cnt++]);
			player[chchange].yPosition -= 10;
		}
	}
	else if (GetAsyncKeyState(VK_LEFT) < 0) {   //왼쪽 방향키 눌렀을때
		if (cannotgoleftincl2() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[2][player[chchange].cnt++]);

		}
		else
		{
			PT(player[chchange].xPosition - 10, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[2][player[chchange].cnt++]);
			player[chchange].xPosition -= 10;

		}
		player[chchange].dir = 2;
	}
	else if (GetAsyncKeyState(VK_RIGHT) < 0) {
		if (cannotgorightincl2() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[3][player[chchange].cnt++]);

		}
		else {
			PT(player[chchange].xPosition + 10, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[3][player[chchange].cnt++]);
			player[chchange].xPosition += 10;
		}
		player[chchange].dir = 3;
	}
	else if (GetAsyncKeyState(VK_RETURN) < 0 ) {
		if (finaldae < 5) {
			finaldae++;
		}
		if (finaldae == 5) {
			resizeConsole(120, 35);
		}
	}
	else {
		PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, 
		player[chchange].Height, player[chchange].WalkDC[player[chchange].dir][player[chchange].cnt++]);
	}
	if (player[chchange].xPosition >= 285 && player[chchange].xPosition <= 315 && player[chchange].yPosition >= 185
		&& player[chchange].yPosition <= 215 && newcheck==1) {
		newcheck = 0;
		jon = 1;
	}
	if (newcheck == 1) {
		PT(300, 200, 40, 50, NewDC);
	}
	if (finalvisible == 0) {
		GameClear();
	}
	player[chchange].cnt = player[chchange].cnt % 4;
	lifeinmain();
	LifeCheck(1000, 1150);
	finalfollow(190, 530);
	finalboss();
}
void GameClear() { //마지막 보스를 죽였을 때 나오는 클리어 화면
	system("cls");
	while (1) {
		PT(0, 0, 1200, 811, GameClearDC);
		if (GetAsyncKeyState(0x52) < 0) {
			Sleep(50);
			saveProcess();
			restart();
			return;
		}
		else if (GetAsyncKeyState(0x53) < 0) {
			Sleep(50);
			saveProcess();
		}
		else if (GetAsyncKeyState(0x51) < 0) {
			system("cls");
			printf("게임 종료");
			Sleep(500);
			exitgameflag = 1;
			return;
		}
	}
}
void printImageincl1() { //첫번째 교실에서  계속 출력하는 이미지
	PT(40, 630, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
	PT(170, 570, ButtonSize, ButtonSize, ButtonDC[player[chchange].dir]);
	checkscore();
	LifeCheck(1000, 1150);
	player[chchange].cnt = player[chchange].cnt % 4;
}
void printImageinfire() { //모닥불 맵에서 계속 출력하는 함수
	LifeCheck(800, 950);
	player[chchange].cnt = player[chchange].cnt % 4;
}
void checkzombie(){
	boom.xPosition = player[chchange].xPosition - 80;
	boom.yPosition = player[chchange].yPosition - 90;
	if (boom.xPosition >= zombie[0].xPosition - 20 && boom.xPosition <= zombie[0].xPosition + 20 &&
		boom.yPosition >= zombie[0].yPosition - 20 && boom.yPosition <= zombie[0].yPosition + 20) {
		zombie[0].visible = 0;
	}
}
//640 575 -> + 160 +195
void finalboss() { //마지막 보스 프린트
	if (finalvisible == 1) {
		PT(985, 210, 37, 46, FinalbossDC[finalbosscnt++]);
	}
	finalbosscnt = finalbosscnt % 8;
	PT(830,65,288,240,EffectDC[effectcnt++]);
	effectcnt = effectcnt % 8;
}
void checkscore() { //점수 누적
	if (mineral1[1].minon == 1 && mineral1[1].visible == 0) {
		mineral1[1].visible = 1;
		scsip += 1;
		score += 10;
	}
	if (mineral1[2].minon == 1 && mineral1[2].visible == 0) {
		mineral1[2].visible = 1;
		scsip += 1;
		score += 10;
	}
	if (mineral1[3].minon == 1 && mineral1[3].visible == 0) {
		mineral1[3].visible = 1;
		scsip += 1;
		score += 10;
	}
	if (mineral1[4].minon == 1 && mineral1[4].visible == 0) {
		mineral1[4].visible = 1;
		scsip += 1;
		score += 10;
	}
	if (mineral1[5].minon == 1 && mineral1[5].visible == 0) {
		mineral1[5].visible = 1;
		scsip += 1;
		score += 10;
	}
	if (mineral2[1].minon == 1 && mineral2[1].visible==0) {
		mineral2[1].visible = 1;
		scbak += 1;
		score += 100;
	}
	if (mineral3[1].minon == 1 && mineral3[1].visible == 0) {
		mineral3[1].visible = 1;
		scchun += 1;
		score += 1000;
	}
	if (mineral3[2].minon == 1 && mineral3[2].visible == 0) {
		mineral3[2].visible = 1;
		scchun += 1;
		score += 1000;
	}
	if (mineral3[3].minon == 1 && mineral3[3].visible == 0) {
		mineral3[3].visible = 1;
		scchun += 1;
		score += 1000;
	}
	if (mineral3[4].minon == 1 && mineral3[4].visible == 0) {
		mineral3[4].visible = 1;
		scchun += 1;
		score += 1000;
	}
	if (mineral3[5].minon == 1 && mineral3[5].visible == 0) {
		mineral3[5].visible = 1;
		scchun += 1;
		score += 1000;
	}
	PT(1030, 48, 30, 39, ScoreDC[scman]);
	PT(1060, 48, 30, 39, ScoreDC[scchun]);
	PT(1090, 48, 30, 39, ScoreDC[scbak]);
	PT(1120, 48, 30, 39, ScoreDC[scsip]);
	PT(1150, 48, 30, 39, ScoreDC[scil]);
}
void fireplace() { //모닥불 맵에서의 움직임과 출력
	wherein = 8;
	PT(0, 0, 1000, 906, BackgroundDC[4]);
	if (GetAsyncKeyState(VK_DOWN) < 0) {   //아래 방향키 눌렀을때
		player[chchange].dir = 1; //yPosition-50
		if (cannotgodowninfire() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[1][player[chchange].cnt++]);
			endTime = clock();
		}
		else if (cannotgodowninfire() == 1) {
			key = 1;
			system("cls");
			resizeConsole(120, 40);
			player[chchange].xPosition = 15;
			player[chchange].yPosition = 60;
		}
		else {
			printImageinfire();
			PT(player[chchange].xPosition, player[chchange].yPosition + 10, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[1][player[chchange].cnt++]);
			player[chchange].yPosition += 10;
			endTime = clock();
		}
		endTime = clock();
		printImageinfire();
	}
	else if (GetAsyncKeyState(VK_UP) < 0) {  //위 방향키 눌렀을때
		player[chchange].dir = 0;
		if (cannotgoupincl2() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[0][player[chchange].cnt++]);
			endTime = clock();
		}
		else if (cannotgoupinfire() == 1) {
			key = 1;
			system("cls");
			resizeConsole(120, 40);
			player[chchange].xPosition = 15;
			player[chchange].yPosition = 60;
		}
		else {
			printImageinfire();
			PT(player[chchange].xPosition, player[chchange].yPosition - 10, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[0][player[chchange].cnt++]);
			player[chchange].yPosition -= 10;
			endTime = clock();
		}
		endTime = clock();
		printImageinfire();
	}
	else if (GetAsyncKeyState(VK_LEFT) < 0) {   //왼쪽 방향키 눌렀을때
		if (cannotgoleftincl2() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[2][player[chchange].cnt++]);
			endTime = clock();
		}
		else if (cannotgoleftinfire() == 1) {
			key = 1;
			system("cls");
			resizeConsole(120, 40);
			player[chchange].xPosition = 15;
			player[chchange].yPosition = 60;
		}
		else
		{
			PT(player[chchange].xPosition - 10, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[2][player[chchange].cnt++]);
			player[chchange].xPosition -= 10;
			printImageinfire();
			endTime = clock();
		}
		player[chchange].dir = 2;
		printImageinfire();
	}
	else if (GetAsyncKeyState(VK_RIGHT) < 0) {
		if (cannotgorightincl2() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[3][player[chchange].cnt++]);
			endTime = clock();
		}
		else if (cannotgoleftinfire() == 1) {
			key = 1;
			system("cls");
			resizeConsole(120, 40);
			player[chchange].xPosition = 15;
			player[chchange].yPosition = 60;
		}
		else {
			PT(player[chchange].xPosition + 10, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[3][player[chchange].cnt++]);
			player[chchange].xPosition += 10;
			endTime = clock();
			printImageinfire();
		}
		player[chchange].dir = 3;
		printImageinfire();
	}
	else {
		printImageinfire();
		if (player[chchange].daegicheck == 1) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WaitDC[player[chchange].dir][player[chchange].cnt++]);
		}
		else PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[player[chchange].dir][player[chchange].cnt++]);
		PT(40, 630, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
		PT(170, 570, ButtonSize, ButtonSize, ButtonDC[4]);
	}
	missioncheck();
	endTime = clock();
	timeImage();
	olprint();
	printImageinfire();
	player[chchange].cnt = player[chchange].cnt % 4;
}
void olprint() {//캐릭터 프린트
	PT(480, 380, 62, 122, OlDC[olcnt++]);
	olcnt = olcnt % 4;
}
void npcprint() {//캐릭터 프린트
	PT(400, 500, 24, 41,NPCDC[npccnt++]);
	npccnt = npccnt % 5;
}
void classroom1() { //교실 맵 첫번째에서 게임 구동 함수
	wherein = 1;
	PT(0, 0, 1000, 752, BackgroundDC[1]);
	if (GetAsyncKeyState(VK_DOWN) < 0) {   //아래 방향키 눌렀을때
		player[chchange].dir = 1; //yPosition-50
		if (cannotgodownincl1() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[1][player[chchange].cnt++]);
			endTime = clock();
			PT(0, 0, 1000, 752, Dup1DC);
		}
		else if (cannotgodownincl1() == 1) {
			key = 1;
			system("cls");
			resizeConsole(120, 40);
			player[chchange].xPosition = 85;
			player[chchange].yPosition = 60;
		}
		else if (cannotgodownincl1() == 2) {
			key = 1;
			system("cls");
			resizeConsole(120, 40);
			player[chchange].xPosition = 185;
			player[chchange].yPosition = 60;
		}
		else {
			PT(player[chchange].xPosition, player[chchange].yPosition + 10, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[1][player[chchange].cnt++]);
			player[chchange].yPosition += 10;
			endTime = clock();
		}
		endTime = clock();
		PT(0, 0, 1000, 752, Dup1DC);
	}
	else if (GetAsyncKeyState(VK_UP) < 0) {  //위 방향키 눌렀을때
		player[chchange].dir = 0;
		if (cannotgoupincl1() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[0][player[chchange].cnt++]);
			endTime = clock();
			PT(0, 0, 1000, 752, Dup1DC);
		}
		else {
			PT(player[chchange].xPosition, player[chchange].yPosition - 10, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[0][player[chchange].cnt++]);
			player[chchange].yPosition -= 10;
			endTime = clock();
		}
		endTime = clock();
		PT(0, 0, 1000, 752, Dup1DC);
	}
	else if (GetAsyncKeyState(VK_LEFT) < 0) {   //왼쪽 방향키 눌렀을때
		if (cannotgoleftincl1() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[2][player[chchange].cnt++]);
			endTime = clock();
			PT(0, 0, 1000, 752, Dup1DC);
		}
		else
		{
			PT(player[chchange].xPosition - 10, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[2][player[chchange].cnt++]);
			player[chchange].xPosition -= 10;
			endTime = clock();
		}
		player[chchange].dir = 2;
		PT(0, 0, 1000, 752, Dup1DC);
	}
	else if (GetAsyncKeyState(VK_RIGHT) < 0) {
		if (cannotgorightincl1() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[3][player[chchange].cnt++]);
			endTime = clock();
			PT(0, 0, 1000, 752, Dup1DC);
		}
		else {
			PT(player[chchange].xPosition + 10, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[3][player[chchange].cnt++]);
			player[chchange].xPosition += 10;
			endTime = clock();
		}
		player[chchange].dir = 3;
		PT(0, 0, 1000, 752, Dup1DC);
	}
	else {
		if (player[chchange].daegicheck == 1) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WaitDC[player[chchange].dir][player[chchange].cnt++]);
		}
		else PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[player[chchange].dir][player[chchange].cnt++]);
		PT(40, 630, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
		PT(170, 570, ButtonSize, ButtonSize, ButtonDC[4]);
		PT(0, 0, 1000, 752, Dup1DC);
	}
	if (player[chchange].xPosition >= 170 && player[chchange].xPosition <= 190 && player[chchange].yPosition >= 130 &&
		player[chchange].yPosition <= 150 && rock[0].visible==1) {
		rock[0].visible = 0;
		rockcheck += 1;
	}
	if (rock[0].visible == 1) {
		PT(180, 140, 32, 32, rock[0].RockDC);
	}
	missioncheck();
	endTime = clock();
	timeImage();
	checkscore();
	crazycheck1();
	printImageincl1();
	lifeinmain();
	LifeCheck(800, 928);
	player[chchange].cnt = player[chchange].cnt % 4;
}
void classroom2() { // 교실 두 번째에서 게임 구동 함수
	wherein = 3;
	PT(0, 0, 1000, 770,BackgroundDC[2]);
	if (GetAsyncKeyState(VK_DOWN) < 0) {   //아래 방향키 눌렀을때
		player[chchange].dir = 1; //yPosition-50
		if (cannotgodownincl2() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[1][player[chchange].cnt++]);
			endTime = clock();
			PT(0, 0, 1000, 752, Dup2DC);
			printImageincl1();
		}
		else if (cannotgodownincl2() == 1) {
			key = 1;
			system("cls");
			resizeConsole(120, 40);
			player[chchange].xPosition = 375;
			player[chchange].yPosition = 60;
		}
		else if (cannotgodownincl2() == 2) {
			key = 1;
			system("cls");
			resizeConsole(120, 40);
			player[chchange].xPosition = 465;
			player[chchange].yPosition = 60;
		}
		else {
			PT(player[chchange].xPosition, player[chchange].yPosition + 10, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[1][player[chchange].cnt++]);
			player[chchange].yPosition += 10;
			endTime = clock();
		}
		endTime = clock();
		printImageincl1();
		PT(0, 0, 1000, 752, Dup2DC);
	}
	else if (GetAsyncKeyState(VK_UP) < 0) {  //위 방향키 눌렀을때
		player[chchange].dir = 0;
		if (cannotgoupincl2() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[0][player[chchange].cnt++]);
			endTime = clock();
			PT(0, 0, 1000, 752, Dup2DC);
			printImageincl1();
		}
		else {
			PT(player[chchange].xPosition, player[chchange].yPosition - 10, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[0][player[chchange].cnt++]);
			player[chchange].yPosition -= 10;
			endTime = clock();
		}
		endTime = clock();
		printImageincl1();
		PT(0, 0, 1000, 752, Dup2DC);
	}
	else if (GetAsyncKeyState(VK_LEFT) < 0) {   //왼쪽 방향키 눌렀을때
		if (cannotgoleftincl2() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[2][player[chchange].cnt++]);
			endTime = clock();
			PT(0, 0, 1000, 752, Dup2DC);
			printImageincl1();
		}
		else
		{
			PT(player[chchange].xPosition - 10, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[2][player[chchange].cnt++]);
			player[chchange].xPosition -= 10;
			endTime = clock();
		}
		player[chchange].dir = 2;
		printImageincl1();
		PT(0, 0, 1000, 752, Dup2DC);
	}
	else if (GetAsyncKeyState(VK_RIGHT) < 0) {
		if (cannotgorightincl2() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[3][player[chchange].cnt++]);
			endTime = clock();
			PT(0, 0, 1000, 752, Dup2DC);
			printImageincl1();
		}
		else {
			PT(player[chchange].xPosition + 10, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[3][player[chchange].cnt++]);
			player[chchange].xPosition += 10;
			endTime = clock();
		}
		player[chchange].dir = 3;
		printImageincl1();
		PT(0, 0, 1000, 752, Dup2DC);
	}
	else {
		if (player[chchange].daegicheck == 1) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WaitDC[player[chchange].dir][player[chchange].cnt++]);
		}
		else PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[player[chchange].dir][player[chchange].cnt++]);
		PT(40, 630, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
		PT(170, 570, ButtonSize, ButtonSize, ButtonDC[4]);
		PT(0, 0, 1000, 752, Dup2DC);
		printImageincl1();
	}
	if (player[chchange].xPosition >= 460 && player[chchange].xPosition <= 520 && player[chchange].yPosition >= 110 &&
		player[chchange].yPosition <= 150) {
		mulcheck = 1;
		if (mulcheckforlife == 0) {
			CurrentLife==5;
			mulcheckforlife++;
		}
	}
	if (player[chchange].xPosition >= 290 && player[chchange].xPosition <= 310 && player[chchange].yPosition >= 170 &&
		player[chchange].yPosition <= 190 && rock[1].visible == 1) {
		rock[1].visible = 0;
		rockcheck += 1;
	}
	if (rock[1].visible == 1) {
		PT(300, 180, 32, 32, rock[1].RockDC);
	}
	if (player[chchange].xPosition >= 380 && player[chchange].xPosition <= 420 && player[chchange].yPosition >= 330
		&& player[chchange].yPosition <= 370) {
		mineral2[1].minon= 1;
	}
	if (player[chchange].xPosition >= 190 && player[chchange].xPosition <= 210 &&
		player[chchange].yPosition >= 540 && player[chchange].yPosition <= 580) {
		mineral1[5].minon = 1;
	}
	if (mulcheck != 1) {
		PT(500, 130, 62, 70, ItemPosionDC);
	}
	if (mineral1[5].minon != 1) {
		PT(200, 560, 10, 24, mineral1[5].MineralDC);
	}
	if (mineral2[1].minon != 1) {
		PT(400, 350, 26, 26, mineral2[1].MineralDC);
	}
	missioncheck();
	endTime = clock();
	checkscore();
	timeImage();
	//mysprint();
	yukfollow();
	printImageincl1();
	LifeCheck(800, 928);
	player[chchange].cnt = player[chchange].cnt % 4;
}
void myroom() { //미스터리 방에서 게임 구동 함수
	wherein = 4;
	PT(0, 0, 1000, 710, BackgroundDC[3]);
	if (GetAsyncKeyState(VK_DOWN) < 0) {   //아래 방향키 눌렀을때
		player[chchange].dir = 1; //yPosition-50
		if (cannotgodowninmyroom() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[1][player[chchange].cnt++]);
			endTime = clock();
		}
		else if (cannotgodowninmyroom() == 1) {
			key = 1;
			system("cls");
			resizeConsole(120, 40);
			player[chchange].xPosition = 655;
			player[chchange].yPosition = 60;
		}
		else if (cannotgodowninmyroom() == 2) {
			key = 1;
			system("cls");
			resizeConsole(120, 40);
			player[chchange].xPosition = 785;
			player[chchange].yPosition = 60;
		}
		else {
			PT(player[chchange].xPosition, player[chchange].yPosition + 10, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[1][player[chchange].cnt++]);
			player[chchange].yPosition += 10;
			endTime = clock();
		}
		endTime = clock();
	}
	else if (GetAsyncKeyState(VK_UP) < 0) {  //위 방향키 눌렀을때
		player[chchange].dir = 0;
		if (cannotgoupinmyroom() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[0][player[chchange].cnt++]);
			endTime = clock();
		}
		else {
			PT(player[chchange].xPosition, player[chchange].yPosition - 10, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[0][player[chchange].cnt++]);
			player[chchange].yPosition -= 10;
			endTime = clock();
		}
		endTime = clock();
	}
	else if (GetAsyncKeyState(VK_LEFT) < 0) {   //왼쪽 방향키 눌렀을때
		if (cannotgoleftinmyroom() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[2][player[chchange].cnt++]);
			endTime = clock();
		}
		else
		{
			PT(player[chchange].xPosition - 10, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[2][player[chchange].cnt++]);
			player[chchange].xPosition -= 10;
			endTime = clock();
		}
		player[chchange].dir = 2;
	}
	else if (GetAsyncKeyState(VK_RIGHT) < 0) {
		if (cannotgorightinmyroom() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[3][player[chchange].cnt++]);
			endTime = clock();
		}
		else {
			PT(player[chchange].xPosition + 10, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[3][player[chchange].cnt++]);
			player[chchange].xPosition += 10;
			endTime = clock();
		}
		player[chchange].dir = 3;
	}
	else {
		if (player[chchange].daegicheck == 1) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WaitDC[player[chchange].dir][player[chchange].cnt++]);
		}
		else PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[player[chchange].dir][player[chchange].cnt++]);
		PT(40, 610, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
		PT(170, 550, ButtonSize, ButtonSize, ButtonDC[4]);
	}
	if (player[chchange].xPosition >= 590 && player[chchange].xPosition <= 610 && player[chchange].yPosition >= 440 &&
		player[chchange].yPosition <= 460 && rock[2].visible == 1) {
		rock[2].visible = 0;
		rockcheck += 1;
	}
	if (rock[2].visible == 1) {
		PT(600, 450, 32, 32, rock[2].RockDC);
	}
	endTime = clock();
	bossprint();
	timeImage();
	LifeCheck(800, 928);
	player[chchange].cnt = player[chchange].cnt % 4;
}
void timeover() {
	if (min == 0) {
		system("cls");
		while (1) {
			PT(0, 0, 1200, 690, GameDC[0]);
			if (GetAsyncKeyState(0x52) < 0) {
				PT(0, 0, 1200, 690, GameDC[1]);
				Sleep(50);
				saveProcess();
				restart();
				return;
			}
			else if (GetAsyncKeyState(0x53) < 0) {
				PT(0, 0, 1200, 690, GameDC[2]);
				Sleep(50);
				saveProcess();
			}
			else if (GetAsyncKeyState(0x51) < 0) {
				system("cls");
				printf("게임 종료");
				Sleep(500);
				exitgameflag = 1;
				return;
			}
		}
	}
}
void gameover() {
	if (CurrentLife == 0) {
		system("cls");
		while (1) {
			PT(0, 0, 1200, 690, GameDC[0]);
			if (GetAsyncKeyState(0x52) < 0) {
				PT(0, 0, 1200, 690, GameDC[1]);
				Sleep(50);
				saveProcess();
				restart();
				return;
			}
			else if (GetAsyncKeyState(0x53) < 0) {
				PT(0, 0, 1200, 690, GameDC[2]);
				Sleep(50);
				saveProcess();
			}
			else if(GetAsyncKeyState(0x51) < 0) {
				system("cls");
				printf("게임 종료");
				Sleep(500);
				exitgameflag = 1;
				return;
			}
		}
	}
}
void saveProcess() {
	system("cls");
	printf("asdf");
	Sleep(1000);
	FILE* fp = fopen(name, "w");
	fprintf(fp, "%d %d", round, score);
	fclose(fp);
	printf("세이브완료");
	Sleep(2000);
}
void restart() {
	restartflag = 1;
}
void chrchoose() {//초기에 캐릭터 고르기 함수
	while (_kbhit() != 1) {
		PT(0, 0, 1200, 700, ChooseDC[0]);
	}
	while (chrcheck != 3) {
		if (_kbhit()) {
			int key = _getch();
			switch (key) {
			case 77:
				if (u < 4) {
					u += 1;
				}
				PT(0, 0, 1200, 700, ChooseDC[u]);
				break;
			case 75:
				if (u > 1) {
					u -= 1;
				}
				PT(0, 0, 1200, 700, ChooseDC[u]);
				break;
			case 13:
				chchange = u;
				if (u != 0) {
					chrcheck = 3;
				}
				key = 1;
				break;
			}
		}
	}
	resizeConsole(120, 43);
	player[chchange].xPosition = 600;
	player[chchange].yPosition = 350;
	PlaySound(0, 0, 0);
	PlaySound(TEXT(Music[5]), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	key = -1;
}
void zombie1follow() { //첫번째 좀비가 플레이어를 따라오게 만드는 함수
	if (player[chchange].xPosition > zombie[0].xPosition&& player[chchange].xPosition < zombie[0].xPosition + 430 && player[chchange].yPosition <= zombie[0].yPosition + 60
		&& player[chchange].yPosition >= zombie[0].yPosition - 60) {
		followcheck = 1;
	}
	else if (player[chchange].xPosition<zombie[0].xPosition && player[chchange].xPosition>zombie[0].xPosition - 430
		&& player[chchange].yPosition <= zombie[0].yPosition + 60 && player[chchange].yPosition >= zombie[0].yPosition - 60) {
		followcheck = 2;
	}
	else followcheck = 0;
	if (followcheck == 1 && zombie[0].check == 1 &&zombie[0].visible==1) {
		PT(zombie[0].xPosition + 6, 70, 44, 86, zombie[0].WalkDC[2][zombie[0].cnt++]);
		zombie[0].xPosition += 6;
	}
	else if (followcheck == 2 && zombie[0].check == 1 && zombie[0].visible == 1) {
		PT(zombie[0].xPosition - 6, 70, 44, 86, zombie[0].WalkDC[3][zombie[0].cnt++]);
		zombie[0].xPosition -= 6;
	}
	else if (zombie[0].visible == 1) {
		PT(zombie[0].xPosition, 70, 44, 86, zombie[0].WalkDC[1][zombie[0].cnt++]);
		zombie[0].cnt = zombie[0].cnt % 4;
	}
}
void zombie2follow() { //두번째 좀비가 플레이어를 따라오게 만드는 함수
	if (player[chchange].yPosition > zombie[1].yPosition&& player[chchange].yPosition < zombie[1].yPosition + 430 && player[chchange].xPosition <= 1140
		&& player[chchange].xPosition >= 1080) {
		followcheckzombie = 1;
	}
	else if (player[chchange].yPosition<zombie[1].yPosition && player[chchange].yPosition>zombie[1].yPosition - 430
		&& player[chchange].xPosition <= 1140 && player[chchange].xPosition >= 1080) {
		followcheckzombie = 2;
	}
	else followcheckzombie = 0;
	if (followcheckzombie == 1 && zombie[1].check == 1 &&zombie[1].visible==1) {
		PT(1120, zombie[1].yPosition + 6, 44, 86, zombie[1].WalkDC[1][zombie[1].cnt++]);
		zombie[1].yPosition += 6;
	}
	else if (followcheckzombie == 2 && zombie[1].check == 1 && zombie[1].visible == 1) {
		PT(1120, zombie[1].yPosition - 6, 44, 86, zombie[1].WalkDC[0][zombie[1].cnt++]);
		zombie[1].yPosition -= 6;
	}
	else if(zombie[1].visible == 1){
		PT(1120, zombie[1].yPosition, 44, 86, zombie[1].WalkDC[1][zombie[1].cnt++]);
		zombie[1].cnt = zombie[1].cnt % 4;
	}
}
void tinkfollow() { //팅커벨 좀비가 플레이어를 따라오는 함수
	if (player[chchange].xPosition > zombie[2].xPosition&& player[chchange].xPosition < zombie[2].xPosition + 430 && player[chchange].yPosition <= zombie[2].yPosition + 80
		&& player[chchange].yPosition >= zombie[2].yPosition - 80) {
		followchecktink = 1;
	}
	else if (player[chchange].xPosition<zombie[2].xPosition && player[chchange].xPosition>zombie[2].xPosition - 430
		&& player[chchange].yPosition <= zombie[2].yPosition + 30 && player[chchange].yPosition >= zombie[2].yPosition - 50) {
		followchecktink = 2;
	}
	else followchecktink = 0;
	if (followchecktink == 1 && zombie[2].check == 1 &&zombie[2].visible==1) {
		PT(zombie[2].xPosition + 6, zombie[2].yPosition - 20, 68, 92, zombie[2].WalkDC[2][zombie[2].cnt++]);
		zombie[2].xPosition += 6;
	}
	else if (followchecktink == 2 && zombie[2].check == 1 &&zombie[2].visible==1) {
		PT(zombie[2].xPosition - 6, zombie[2].yPosition - 20, 68, 92, zombie[2].WalkDC[3][zombie[2].cnt++]);
		zombie[2].xPosition -= 6;
	}
	else if (zombie[2].check == 1 &&zombie[2].visible==1) {
		PT(zombie[2].xPosition, zombie[2].yPosition, 68, 92, zombie[2].WalkDC[1][zombie[2].cnt++]);
		zombie[2].cnt = zombie[2].cnt % 4;
	}
}
void bosscheck() { //보스 캐릭터의 움직임을 표현하는 함수
	if (boss.xPosition == 950) {
		k = 2;
	}
	else if (boss.xPosition == 80) {
		k = 3;
	}
	if (boss.xPosition >= 80 && boss.xPosition < 1000 && k == 3) {
		PT(boss.xPosition + 10, boss.yPosition, 280, 271, boss.WaitDC[boss.cnt++]);
		boss.xPosition += 10;
	}
	else if (k == 2) {
		PT(boss.xPosition - 10, boss.yPosition, 280, 271, boss.WaitDC[boss.cnt++]);
		boss.xPosition -= 10;
	}
}
void crazycheck1() {
	if (zombie[8].visible == 1) {
		PT(zombie[8].xPosition, zombie[8].yPosition, 72, 113, zombie[8].WalkDC[1][zombie[8].cnt++]);
		zombie[8].cnt = zombie[8].cnt % 6;
	}
	}
void finalfollow(int x,int y) { //구현 안함
	if (zombie[8].yPosition == y) {
		crk = 1;
	}
	else if (zombie[8].yPosition == x) {
		crk = 2;
	}
	if (zombie[8].yPosition >= x && zombie[3].yPosition < y && crk == 2) {
		PT(235, zombie[8].yPosition + 3, 110, 104, zombie[8].WalkDC[2][zombie[8].cnt++]);
		zombie[8].yPosition += 3;
	}
	else if (crk == 1) {
		PT(235, zombie[8].yPosition - 3, 110, 104, zombie[8].WalkDC[2][zombie[8].cnt++]);
		zombie[8].yPosition -= 3;
	}
	zombie[8].cnt = zombie[8].cnt % 4;
}
void yukfollow() { //역도 좀비가 플레이어의 x포지션대로 따라오게 하는 함수
	if (player[chchange].yPosition <= 500) {
		followcheckyuk = 1;
		if (player[chchange].xPosition > zombie[7].xPosition&& player[chchange].xPosition < zombie[7].xPosition + 430) {
			followcheckyuk2 = 1;
		}
		else if (player[chchange].xPosition<zombie[7].xPosition && player[chchange].xPosition>zombie[7].xPosition - 430) {
			followcheckyuk2 = 2;
		}
		else if (player[chchange].xPosition == zombie[7].xPosition) {
			followcheckyuk2 = 3;
		}
	}
	else if (player[chchange].yPosition > 500) {
		followcheckyuk = 2;
	}

	if (followcheckyuk == 1) {
		if (followcheckyuk2 == 1 && zombie[7].visible==1) {
			PT(zombie[7].xPosition + 10, zombie[7].yPosition, 115, 100, zombie[7].WalkDC[3][zombie[7].cnt++]);
			zombie[7].xPosition += 10;
		}
		else if (followcheckyuk2 == 2) {
			PT(zombie[7].xPosition - 10, zombie[7].yPosition, 115, 100, zombie[7].WalkDC[2][zombie[7].cnt++]);
			zombie[7].xPosition -= 10;
		}
		else
			PT(zombie[7].xPosition - 35, zombie[7].yPosition, 115, 100, zombie[7].WaitDC[1][zombie[7].cnt++]);
	}
	else  if (followcheckyuk == 2 &&zombie[7].visible==1) {
		PT(zombie[7].xPosition - 35, zombie[7].yPosition, 115, 100, zombie[7].WaitDC[0][zombie[7].cnt++]);
	}
	zombie[7].cnt = zombie[7].cnt % 4;
}
void bossprint() { //보스를 프린트하는 함수
	PT(380, 230, 280, 271, boss.WaitDC[boss.cnt++]);
	boss.cnt = boss.cnt % 104;
}
void timeImage() { //time.h를 이용해 시간을 1초씩 줄이고 위에 출력하는 함수
	int gap = (((int)(endTime - startTime)) / (CLOCKS_PER_SEC));
	if (gap == 60 && tcnt == 0) {
		min--;
		gap = 1;
		tcnt++;
	}
	else if (gap == 120 && tcnt == 1) {
		min--;
		gap = 1;
		tcnt++;
	}
	else if (gap == 180 && tcnt == 2) {
		min--;
		gap = 1;
		tcnt++;
	}
	else if (gap == 240 && tcnt == 3) {
		min--;
		gap = 1;
		tcnt++;
	}
	if (tcnt == 0) {
		sec = 60 - gap;
	}
	else if (tcnt == 1) {
		sec = 120 - gap;
	}
	else if (tcnt == 2) {
		sec = 180 - gap;
	}
	else if (tcnt == 3) {
		sec = 240 - gap;
	}
	PT(500, 15, 60, 44, NumberDC[min]);
	PT(570, 15, 11, 40, colDC);
	PT(590, 15, 60, 44, NumberDC[sec]);
}
void missioncheck() { //M을 눌렀을 때 나오는 미션 창
	if (GetAsyncKeyState(0x4D) < 0 && roundcheck == 1) {
		PT(920, 80, 120, 31, MissionDC[0]);
		if (score < 5040) {
			if (wherein == 0 || 4) {
				PT(920, 120, 250, 103, MissionDC[1]);
			} else PT(720, 120, 250, 103, MissionDC[1]);
		}
		else if (score >= 5040) {
			mission1check = 1;
			if (wherein == 0 || 4) {
				PT(920, 120, 250, 103, MissionDC[2]);
			}else PT(720, 120, 250, 103, MissionDC[2]);
		}
		if (visiblecnt >= 3 && visiblecnt <= 7 && mission1check == 1) {
			if (wherein == 0 || 4) {
				PT(920, 240, 250, 103, MissionDC[visiblecnt]);
			}
			else PT(720, 120, 250, 103, MissionDC[visiblecnt]);
		}
		if (visiblecnt == 8) {
			mission2check = 1;
			roundcheck = 2;
			if (wherein == 0 || 4) {
				PT(920, 240, 250, 103, MissionDC[8]);
			} else PT(720, 120, 250, 103, MissionDC[8]);
		}
	}
	if (GetAsyncKeyState(0x4D) < 0 && roundcheck == 2) {
		PT(920, 80, 120, 31, MissionDC[18]);
		if (rockcheck <3) {
			if (wherein == 0 || 4) {
				PT(920, 120, 250, 103, MissionDC[9]);
			}
			else PT(720, 120, 250, 103, MissionDC[9]);
		}
		else if (rockcheck == 3) {
			if (wherein == 0 || 4) {
				PT(920, 120, 250, 103, MissionDC[10]);
			}
			else PT(720, 120, 250, 103, MissionDC[10]);
			roundcheck = 3;
		}
	}
	if (GetAsyncKeyState(0x4D) < 0 && roundcheck == 3) {
		if (wherein == 0 || 4) {
			PT(890, 80, 120, 31, MissionDC[19]);
			PT(920, 120, 250, 103, MissionDC[10]);
		}
		else {
			PT(690, 80, 120, 31, MissionDC[19]);
			PT(720, 120, 250, 103, MissionDC[10]);
		}
		if (wherein == 8 && player[chchange].xPosition >= 435 && player[chchange].xPosition <= 545 &&
			player[chchange].yPosition >= 405 && player[chchange].yPosition <= 500) {
			finalcheck = 1;
		}
	}
	if (finalcheck == 1) {
		if (player[chchange].xPosition >= 265 && player[chchange].xPosition <= 295 && player[chchange].yPosition >= 325
			&& player[chchange].yPosition <= 355 && jaryocheck == 1) {
			jaryocheck = 0;
		}
		if (jaryocheck == 1) {
			PT(280, 340, 48, 25, JaryoDC);
		}
		if (jaryocheck == 0 && GetAsyncKeyState(VK_RETURN) < 0) {
			PlaySound(0, 0, 0);
			PlaySound(TEXT(Music[6]), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
			key = -3;
			resizeConsole(120,43);
		}
	}
}
void Iblecheck(int st, int des) { //이블 좀비가 움직이게 하는 함수
	if (zombie[4].xPosition == des) {
		ik = 1;
	}
	else if (zombie[4].xPosition == st) {
		ik = 2;
	}
	if (zombie[4].xPosition >= st && zombie[4].xPosition < des && ik == 2 &&zombie[4].visible==1) {
		PT(zombie[4].xPosition + 3, 80, 81, 127, zombie[4].WalkDC[3][zombie[4].cnt++]);
		zombie[4].xPosition += 3;
	}
	else if (ik == 1 && zombie[4].visible==1) {
		PT(zombie[4].xPosition - 3, 80, 81, 127, zombie[4].WalkDC[2][zombie[4].cnt++]);
		zombie[4].xPosition -= 3;
	}
	zombie[4].cnt = zombie[4].cnt % 6;
}
void yeongcheck(int st, int des) { //영좀비가 움직이게 하는 함수
	if (zombie[5].xPosition == des) {
		yk = 1;
	}
	else if (zombie[5].xPosition == st) {
		yk = 2;
	}
	if (zombie[5].xPosition >= st && zombie[5].xPosition < des && yk == 2 &&zombie[5].visible==1) {
		PT(zombie[5].xPosition + 3, 400, 63, 78, zombie[5].WalkDC[3][zombie[5].cnt++]);
		zombie[5].xPosition += 3;
	}
	else if (yk == 1 && zombie[5].visible==1) {
		PT(zombie[5].xPosition - 3, 400, 63, 78, zombie[5].WalkDC[2][zombie[5].cnt++]);
		zombie[5].xPosition -= 3;
	}
	zombie[5].cnt = zombie[5].cnt % 6;
}
void smokcheck(int st, int des) { //연기 좀비가 움직이게 하는 함수
	if (zombie[6].xPosition == des) {
		sk = 1;
	}
	else if (zombie[6].xPosition == st) {
		sk = 2;
	}
	if (zombie[6].xPosition >= st && zombie[6].xPosition < des && sk == 2 && zombie[6].visible==1) {
		PT(zombie[6].xPosition + 3, 650, 58, 95, zombie[6].WalkDC[3][zombie[6].cnt++]);
		zombie[6].xPosition += 3;
	}
	else if (sk == 1 && zombie[6].visible==1) {
		PT(zombie[6].xPosition - 3, 650, 58, 95, zombie[6].WalkDC[2][zombie[6].cnt++]);
		zombie[6].xPosition -= 3;
	}
	zombie[6].cnt = zombie[6].cnt % 4;
}
void Tinkcheck1(int st, int des) { //팅커벨 좀비가 움직이게 하는 함수
	tinkfollow();
	/*if (tink.xPosition == des - 50) {
	   rk = 1;
	}
	else if (tink.xPosition == st) {
	   rk = 2;
	}
	if (tink.xPosition >= st && tink.xPosition < des && rk == 2) {
	   PT(tink.xPosition + 3, tink.yPosition-20, 68, 92, tink.TinkDC[2][tink.cnt++]);
	   tink.xPosition += 3;
	}
	else if (rk == 1) {
	   PT(tink.xPosition - 3,tink.yPosition-20, 68, 92, tink.TinkDC[3][tink.cnt++]);
	   tink.xPosition -= 3;
	}*/
}
/*void Tinkcheck() {
   if (player.xPosition == tink.xPosition - 500) {
	  tk = 1;
   }
   else if (player.xPosition == tink.xPosition + 500) {
	  tk = 2;
   }
   else if (player.xPosition > tink.xPosition + 500 || player.xPosition < tink.xPosition - 500) {
	  tk = 0;
   }
   if (tk == 1) {
	  if (player.yPosition >= tink.yPosition - 100 && player.yPosition <= tink.yPosition + 100) {
		 PT(tink.xPosition - 10, tink.yPosition, tink.Width, tink.Height, tink.TinkDC[3][tink.cnt++]);
		 tink.xPosition -= 10;
	  }
	  else PT(tink.xPosition, tink.yPosition, tink.Width, tink.Height, tink.TinkDC[3][tink.cnt++]);
   }
   if (tk == 2) {
	  if (player.yPosition >= tink.yPosition - 100 && player.yPosition <= tink.yPosition + 100) {
		 PT(tink.xPosition + 10, tink.yPosition, tink.Width, tink.Height, tink.TinkDC[2][tink.cnt++]);
		 tink.xPosition + 10;
	  }
   }
   else Tinkcheck();
}*/
void zombiecheck2(int st, int des) { //두번째 좀비가 따라오게 하는 함수
	zombie2follow();
	/*if (zombie2.yPosition == des) {
	   zkr = 1;
	}
	else if (zombie2.yPosition == st) {
	   zkr = 2;
	}
	if (zombie2.yPosition >= st && zombie2.yPosition < des && zkr == 2) {
	   PT(1125, zombie2.yPosition + 3, 44, 86, zombie2.WalkDC[1][zombie2.cnt++]);
	   zombie2.yPosition += 3;
	}
	else if (zkr == 1) {
	   PT(1125, zombie2.yPosition - 3, 44, 86, zombie2.WalkDC[0][zombie2.cnt++]);
	   zombie2.yPosition -= 3;
	}*/
}
void padakcheck(int x, int y) { //파닥좀비가 이동하는 함수
	if (zombie[3].yPosition == y) {
		prk = 1;
	}
	else if (zombie[3].yPosition == x) {
		prk = 2;
	}
	if (zombie[3].yPosition >= x && zombie[3].yPosition < y && prk == 2 && zombie[3].visible==1) {
		PT(235, zombie[3].yPosition + 3, 110, 104, zombie[3].WalkDC[1][zombie[3].cnt++]);
		zombie[3].yPosition += 3;
	}
	else if (prk == 1 && zombie[3].visible==1) {
		PT(235, zombie[3].yPosition - 3, 110, 104, zombie[3].WalkDC[0][zombie[3].cnt++]);
		zombie[3].yPosition -= 3;
	}
	zombie[3].cnt = zombie[3].cnt % 3;
}
void printImageinMain() { //메인에서 프린트하는 이미지들 집합
	endTime = clock();
	timeImage();
	lifeinmain();
	missioncheck();
	PT(70, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
	if (chchange == 0) {
		PT(200, 650, ButtonSize, ButtonSize, ButtonDC[player[chchange].dir]);
		player[chchange].cnt = player[chchange].cnt % 4;
		LifeCheck(1000, 1150);
	}
	else if (chchange == 1) {
		PT(200, 650, ButtonSize, ButtonSize, ButtonDC[player[chchange].dir]);
		player[chchange].cnt = player[chchange].cnt % 4;
		LifeCheck(1000, 1150);
	}
	else if (chchange == 2) {
		PT(200, 650, ButtonSize, ButtonSize, ButtonDC[player[chchange].dir]);
		player[chchange].cnt = player[chchange].cnt % 4;
		LifeCheck(1000, 1150);
	}
	else {
		PT(200, 650, ButtonSize, ButtonSize, ButtonDC[player[chchange].dir]);
		player[chchange].cnt = player[chchange].cnt % 4;
		LifeCheck(1000, 1150);
	}
	player[chchange].cnt = player[chchange].cnt % 4;
	zombie[0].cnt = zombie[0].cnt % 4;
	zombie[1].cnt = zombie[1].cnt % 4;
	zombie[2].cnt = zombie[2].cnt % 4;
}
void secondback() { //카페 맵에서 게임 구동 함수
	wherein = 4;
	PT(0, 0, 1324, 865, BackgroundDC[5]);
	Iblecheck(350, 980);
	padakcheck(150, 510);
	yeongcheck(350, 980);
	smokcheck(350, 980);
	if (GetAsyncKeyState(VK_DOWN) < 0) {   //아래 방향키 눌렀을때
		player[chchange].dir = 1; //yPosition-50
		if (cannotgodownincafe() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[1][player[chchange].cnt++]);
			//bosscheck();
		}
		else if (cannotgodownincafe() == 2) {
			key = 1;
			system("cls");
			resizeConsole(120, 43);
			player[chchange].xPosition = 880;
			player[chchange].yPosition = 20;
		}
		else {
			PT(player[chchange].xPosition, player[chchange].yPosition + 10, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[1][player[chchange].cnt++]);
			//bosscheck();
			player[chchange].yPosition += 10;
		}
		PT(70, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
		PT(200, 650, ButtonSize, ButtonSize, ButtonDC[player[chchange].dir]);
		endTime = clock();
		timeImage();
		player[chchange].cnt = player[chchange].cnt % 4;
		//boss.cnt = boss.cnt % 104;
	}
	else if (GetAsyncKeyState(VK_UP) < 0) {  //위 방향키 눌렀을때
		player[chchange].dir = 0;
		if (cannotgoupincafe() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[0][player[chchange].cnt++]);
			//bosscheck();
		}
		else {
			PT(player[chchange].xPosition, player[chchange].yPosition - 10, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[0][player[chchange].cnt++]);
			//bosscheck();
			player[chchange].yPosition -= 10;
		}
		PT(70, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
		PT(200, 650, ButtonSize, ButtonSize, ButtonDC[player[chchange].dir]);
		endTime = clock();
		timeImage();
		player[chchange].cnt = player[chchange].cnt % 4;
		//boss.cnt = boss.cnt % 104;
	}
	else if (GetAsyncKeyState(VK_LEFT) < 0) {   //왼쪽 방향키 눌렀을때
		if (cannotgoleftincafe() == -1) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[2][player[chchange].cnt++]);
			//bosscheck();
		}
		else
		{
			PT(player[chchange].xPosition - 10, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[2][player[chchange].cnt++]);
			//bosscheck();
			player[chchange].xPosition -= 10;
		}
		player[chchange].dir = 2;
		PT(70, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
		PT(200, 650, ButtonSize, ButtonSize, ButtonDC[player[chchange].dir]);
		endTime = clock();
		timeImage();
		player[chchange].cnt = player[chchange].cnt % 4;
		//boss.cnt = boss.cnt % 104;
	}
	else if (GetAsyncKeyState(VK_RIGHT) < 0) {
		if (cannotgorightincafe() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[3][player[chchange].cnt++]);
			//bosscheck();
		}
		else {
			PT(player[chchange].xPosition + 10, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[3][player[chchange].cnt++]);
			//bosscheck();
			player[chchange].xPosition += 10;
		}
		player[chchange].dir = 3;
		PT(70, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
		PT(200, 650, ButtonSize, ButtonSize, ButtonDC[player[chchange].dir]);
		endTime = clock();
		timeImage();
		player[chchange].cnt = player[chchange].cnt % 4;
		//boss.cnt = boss.cnt % 104;
	}
	else {
		if (player[chchange].daegicheck == 1) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WaitDC[player[chchange].dir][player[chchange].cnt++]);
		}
		else PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[player[chchange].dir][player[chchange].cnt++]);
		//bosscheck();
		PT(70, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
		PT(200, 650, ButtonSize, ButtonSize, ButtonDC[4]);
		endTime = clock();
		timeImage();
		player[chchange].cnt = player[chchange].cnt % 4;
		//boss.cnt = boss.cnt % 104;
		player[chchange].dw = 0;
	}
	if (player[chchange].xPosition >= 190 && player[chchange].xPosition <= 210 && player[chchange].yPosition >= 140
		&& player[chchange].yPosition <= 160) {
		mineral3[1].minon = 1;
	}
	if (player[chchange].xPosition >= 340 && player[chchange].xPosition <= 360 && player[chchange].yPosition >= 350
		&& player[chchange].yPosition <= 370) {
		mineral3[2].minon = 1;
	}
	if (player[chchange].xPosition >= 790 && player[chchange].xPosition <= 810 && player[chchange].yPosition >= 150
		&& player[chchange].yPosition <= 170) {
		mineral3[3].minon = 1;
	}
	if (player[chchange].xPosition >= 470 && player[chchange].xPosition <= 490 && player[chchange].yPosition >= 640
		&& player[chchange].yPosition <= 660) {
		mineral3[4].minon = 1;
	}
	if (player[chchange].xPosition >= 890 && player[chchange].xPosition <= 910 && player[chchange].yPosition >= 690
		&& player[chchange].yPosition <= 710) {
		mineral3[5].minon = 1;
	}
	if (mineral3[1].minon != 1) {
		PT(200, 150, 34, 32, mineral3[1].MineralDC);
	}
	if (mineral3[2].minon != 1) {
		PT(350,360, 34, 32, mineral3[1].MineralDC);
	}
	if (mineral3[3].minon != 1) {
		PT(800, 160, 34, 32, mineral3[1].MineralDC);
	}
	if (mineral3[4].minon != 1) {
		PT(480, 650, 34, 32, mineral3[1].MineralDC);
	}
	if (mineral3[5].minon != 1) {
		PT(900, 700, 34, 32, mineral3[1].MineralDC);
	}
	lifeinmain();
	LifeCheck(1000, 1150);
	checkscore();
	missioncheck();
	Iblecheck(350, 980);
	padakcheck(150, 510);
	yeongcheck(350, 980);
	smokcheck(350, 980);
}
void resizeConsole(int width, int height) {  //콘솔 크기 설정
	char ch[100];
	sprintf(ch, "mode con cols=%d lines=%d", width, height);
	system(ch);
}
void saveCheck() {  //세이브 파일 불러오기 및 체크
	char continuegame;
	SetConsoleTitle("saveCheck"); //콘솔 이름 설정

	gotoxy(0, 0);
	printf("이름을 입력하세요\n");
	HideCursor(1);
	scanf("%s", name);
	HideCursor(0);
	FILE* fp = fopen(name, "r");
	if (fp != NULL) {
		printf("이전 세이브 파일이 존재합니다. 계속하시겠습니까?(y/n)\n");
		scanf(" %c", &continuegame);
		if (continuegame == 'y' || continuegame == 'Y') {
			//세이브 파일 읽어 그 라운드에서 계속
			printf("계속하기\n");
			fscanf(fp, "%d%d", &round, &score);
			printf("\nround : %d\nscore : %d\n", round, score);
			fclose(fp);
		}
		else if (continuegame == 'n' || continuegame == 'N') {
			//세이브 파일 버리고 새로 쓰기
			printf("새로하기\n");
			round = 0;
			score = 0;
			fclose(fp);
		}
		else printf("입력 : >>%c<<\n잘못 입력하셨습니다.\n", continuegame);
	}
	else {
		printf("새 게임");
		round = 0;
		score = 0;
	}
	Sleep(2000);
	system("cls");
	//choosech();
	PlaySound(0, 0, 0);
}
/*
void choosech() {
   while (GetAsyncKeyState(VK_RETURN) < 0) {
	  PT(0, 0, 1200, 700, ChooseDC[0]);
	  if (GetAsyncKeyState(VK_));
   }
}*/
void displayStart() {    //시작 화면 출력
	SetConsoleTitle("DisplayStart"); //콘솔 이름 설정
	PlaySound(TEXT(Music[4]), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	resizeConsole(120, 35);
	while (!_kbhit()) {
		for (int i = 1; i <= 2; i++) {
			PT(0, 0, 1200, 670, StartScreenDC[i]);
			Sleep(500);
		}
	}
	_getch();
	system("cls");
	resizeConsole(120, 35);
}
void gameStart() {
	if (round == 0) {
		round0();
	}
	else if (round == 1) {
		round1();
	}
	else if (round == 2) {
		round2();
	}
	else if (round == 3) {
		round3();
	}
	else if (round == 4) {
		gameclear();
	}
}
void MainRender() {   // render background -> 배경의 이동과 실상 프로그램에서 가장 중요한 부분. 아이템의 획득 여부 등 판정
	 //배경출력
	//0 : 뒤 1 : 앞 2 : 왼 3 : 오
	// render selection bar
	wherein = 0;
	PT(0, 0, 1222, 851, BackgroundDC[0]);
	if (GetAsyncKeyState(VK_DOWN) < 0) {   //아래 방향키 눌렀을때
		player[chchange].dir = 1; //yPosition-50
		if (cannotgodown() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[1][player[chchange].cnt++]);
			endTime = clock();
		}
		else {
			PT(player[chchange].xPosition, player[chchange].yPosition + 10, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[1][player[chchange].cnt++]);
			player[chchange].yPosition += 10;
			endTime = clock();
		}
		printImageinMain();
		endTime = clock();
	}
	else if (GetAsyncKeyState(VK_UP) < 0) {  //위 방향키 눌렀을때
		player[chchange].dir = 0;
		if (cannotgoup() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[0][player[chchange].cnt++]);
			endTime = clock();
		}
		else if (cannotgoup() == 4) {
			key = 4;
			system("cls");
			resizeConsole(100, 38);
			player[chchange].xPosition = 180;
			player[chchange].yPosition = 700;
		}
		else if (cannotgoup() == 3) {
			key = 4;
			system("cls");
			resizeConsole(100, 38);
			player[chchange].xPosition = 790;
			player[chchange].yPosition = 700;
		}
		else if (cannotgoup() == 5) {
			key = 5;
			system("cls");
			resizeConsole(100, 38);
			player[chchange].xPosition = 150;
			player[chchange].yPosition = 710;
		}
		else if (cannotgoup() == 6) {
			key = 5;
			system("cls");
			resizeConsole(100, 38);
			player[chchange].xPosition = 810;
			player[chchange].yPosition = 710;
		}
		else if (cannotgoup() == 1) {
			key = 2;
			system("cls");
			resizeConsole(130, 45);
			player[chchange].xPosition = 250;
			player[chchange].yPosition = 600;
		}
		else if (cannotgoup() == 7) {
			key = 6;
			system("cls");
			resizeConsole(105, 35);
			player[chchange].xPosition = 180;
			player[chchange].yPosition = 650;
		}
		else if (cannotgoup() == 8) {
			key = 6;
			system("cls");
			resizeConsole(105, 35);
			player[chchange].xPosition = 820;
			player[chchange].yPosition = 650;
		}
		else if (cannotgoup() == 10) {
			key = 7;
			resizeConsole(100, 40);
			player[chchange].xPosition = 820;
			player[chchange].yPosition = 650;
		}
		else {
			PT(player[chchange].xPosition, player[chchange].yPosition - 10, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[0][player[chchange].cnt++]);
			player[chchange].yPosition -= 10;
			endTime = clock();
		}
		endTime = clock();
		printImageinMain();
	}
	else if (GetAsyncKeyState(VK_LEFT) < 0) {   //왼쪽 방향키 눌렀을때
		if (cannotgoleft() < 0) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[2][player[chchange].cnt++]);
			endTime = clock();
		}
		else
		{
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[2][player[chchange].cnt++]);
			player[chchange].xPosition -= 10;
			endTime = clock();
		}
		player[chchange].dir = 2;
		printImageinMain();
	}
	else if (GetAsyncKeyState(VK_RIGHT) < 0) {
		if (cannotgoright() < 0) {
			PT(player[chchange].xPosition + 10, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[3][player[chchange].cnt++]);
			endTime = clock();
		}
		else {
			PT(player[chchange].xPosition + 10, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[3][player[chchange].cnt++]);
			player[chchange].xPosition += 10;
			endTime = clock();
		}
		player[chchange].dir = 3;
		printImageinMain();
	}
	else {
		if (player[chchange].daegicheck == 1) {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WaitDC[player[chchange].dir][player[chchange].cnt++]);
			PT(70, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
			PT(200, 650, ButtonSize, ButtonSize, ButtonDC[4]);
		}
		else {
			PT(player[chchange].xPosition, player[chchange].yPosition, player[chchange].Width, player[chchange].Height, player[chchange].WalkDC[player[chchange].dir][player[chchange].cnt++]);
			PT(70, 700, AttackButtonSize, AttackButtonSize, AttackButtonDC[0]);
			PT(200, 650, ButtonSize, ButtonSize, ButtonDC[4]);
		}
	}
	if (player[chchange].xPosition >= 65 && player[chchange].xPosition <= 95 && player[chchange].yPosition >= 470 && player[chchange].yPosition <= 510) {
		ion = 1;
	}
	if (player[chchange].xPosition >= 470 && player[chchange].xPosition <= 530 && player[chchange].yPosition >= 470 && player[chchange].yPosition <= 530) {
		itemboomcheck = 1;
	}
	if (player[chchange].xPosition >= 190 && player[chchange].xPosition <= 200
		&& player[chchange].yPosition >= 340 && player[chchange].yPosition <= 350) {
		mineral1[1].minon = 1;
	}
	if (player[chchange].xPosition >= 390 && player[chchange].xPosition <= 400
		&& player[chchange].yPosition >= 480 && player[chchange].yPosition <= 490) {
		mineral1[2].minon = 1;
	}
	if (player[chchange].xPosition >= 990 && player[chchange].xPosition <= 1000
		&& player[chchange].yPosition >= 310 && player[chchange].yPosition <= 320) {
		mineral1[3].minon = 1;
	}
	if (player[chchange].xPosition >= 590 && player[chchange].xPosition <= 600
		&& player[chchange].yPosition >= 60 && player[chchange].yPosition <= 70) {
		mineral1[4].minon = 1;
	}
	missioncheck();
	zombie1follow();
	zombiecheck2(140, 770);
	Tinkcheck1(50, 1090);
	endTime = clock();
	timeImage();
	checkscore();
	lifeinmain();
	LifeCheck(1000, 1150);
	timeover();
	gameover();
	if (restartflag)return;
	if (exitgameflag)return;
	player[chchange].cnt = player[chchange].cnt % 4;
	if (ion != 1) {
		PT(65, 500, 60, 71, quest[0].QuestDC);
	}
	if (itemboomcheck != 1) {
		PT(500, 500, 30, 31, ItemBoomDC);
	}
	if (mineral1[1].minon != 1) {
		PT(200, 380, 10, 24, mineral1[1].MineralDC);
	}
	if (mineral1[2].minon != 1) {
		PT(400, 520, 10, 24, mineral1[2].MineralDC);
	}
	if (mineral1[3].minon != 1) {
		PT(1000, 350, 10, 24, mineral1[3].MineralDC);
	}
	if (mineral1[4].minon != 1) {
		PT(600, 100, 10, 24, mineral1[4].MineralDC);
	}
	zombie[0].cnt = zombie[0].cnt % 4;
	zombie[1].cnt = zombie[1].cnt % 4;
	zombie[2].cnt = zombie[2].cnt % 4;
}
void MainGame() {  //?
   //MainInit();
	UtilityInit();
	MainRender(0);
}
