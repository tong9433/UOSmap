#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

extern int getpatharray();
extern int getatmpath();

void mapprint();
void mainmenu();
void gotoxy(int,int);
void gotoprint(int,int,char*);
void pathprint(int n);
void mapprintnum();
void timecount();
void atm();


void main(){

	int linearray[20];
	int i=0;
	

	system("mode con: cols=400 lines=90");// 화면 크기 색 지정

	mainmenu();

	while(1){
		mapprint();
		Sleep(500);
		mapprintnum();
		Sleep(500);
		getpatharray();
		timecount();
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);//흰색

	}

}

void atm(){
	while(1){
	mapprint();
	
	gotoprint(5, 41, "┌─────────┬─────────┬──────────┐");
	gotoprint(5, 42, "│     현재위치     │  가까운 ATM 위치 │      소요 시간     │");
	gotoprint(5, 43, "├─────────┼─────────┼──────────┤");
	gotoprint(5, 44, "│                  │                  │                    │");
	gotoprint(5, 45, "└─────────┴─────────┴──────────┘");
	
	gotoprint(124, 25,"[ATM 설치장소]");
	gotoprint(124, 27,"대학본부 1층");
	gotoprint(124, 28,"학생회관 1층");
	gotoprint(124, 29,"21세기관 1층");
	gotoprint(124, 30,"중앙도서관 1층");
	gotoprint(124, 31,"미래관 1층");
	gotoprint(124, 32,"법학관 2층");
	gotoprint(124, 33,"정보기술관 2층");
	gotoprint(124, 34,"자연과학관 1층");

	Sleep(500);
	mapprintnum();
	Sleep(500);
		getatmpath();
		timecount();
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);//흰색
	}

}

void mainmenu(){

	int input;
	int Select;
	int num = 1;
	int truth = 1;
	int check = 0;

	gotoprint(65, 15, "..Loading...");
	Sleep(1000);
	gotoprint(65, 15, "            ");
	gotoprint(65, 40, " ");
	gotoprint(63, 26, "☞");

	while(1){

	gotoprint(65, 10, "─────────── ");
	gotoprint(63, 11, "│※ 서울 시립대 Map※ │ ");
	gotoprint(65, 12, "─────────── ");
	
	gotoprint(65, 25, "┌─────────┐");
	gotoprint(65, 26, "│    빠른길 찾기   │");
	gotoprint(65, 27, "└─────────┘");

	gotoprint(65, 28, "┌─────────┐");
	gotoprint(65, 29, "│  가까운 ATM 찾기 │");
	gotoprint(65, 30, "└─────────┘");
	
	gotoprint(63, 32, "이동 : ↑↓ 선택 : Enter");

	gotoprint(65, 40, " ");

	if (GetKeyState(VK_RETURN) < 0)
			continue;

		Select = _getch();

		switch (Select) {
		case 80: // 아래 
			num = 2;
			gotoprint(63, 26, "  ");
			gotoprint(63, 29, "☞");
			break;
		case 72: // 위
			num = 1;
			gotoprint(63, 26, "☞");
			gotoprint(63, 29, "  ");
			break;
		case 13: // 엔터
			system("cls");
			if (num == 1) {
				truth = 0;
				system("cls");
				break;
			} else if (num == 2) {
				atm();
			}
		}

		if (truth == 0) break;
	}
	
}

void timecount(){
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12);
	gotoprint(70, 41, "   ▒▒▒   ");
	gotoprint(70, 42, "   ▒       ");
	gotoprint(70, 43, "   ▒▒▒   ");
	gotoprint(70, 44, "       ▒   ");
	gotoprint(70, 45, "   ▒▒▒   ");
	Sleep(1000);

	gotoprint(70, 41, "    ▒ ▒   ");
	gotoprint(70, 42, "   ▒  ▒   ");
	gotoprint(70, 43, "  ▒   ▒   ");
	gotoprint(70, 44, "  ▒▒▒▒  ");
	gotoprint(70, 45, "       ▒   ");

	Sleep(1000);
	gotoprint(70, 41, "   ▒▒▒   ");
	gotoprint(70, 42, "       ▒   ");
	gotoprint(70, 43, "   ▒▒▒   ");
	gotoprint(70, 44, "       ▒   ");
	gotoprint(70, 45, "   ▒▒▒   ");
	
	Sleep(1000);
	gotoprint(70, 41, "   ▒▒▒   ");
	gotoprint(70, 42, "      ▒    ");
	gotoprint(70, 43, "   ▒▒     ");
	gotoprint(70, 44, "   ▒       ");
	gotoprint(70, 45, "   ▒▒▒   ");

	Sleep(1000);
	gotoprint(70, 41, "     ▒     ");
	gotoprint(70, 42, "   ▒▒     ");
	gotoprint(70, 43, "     ▒     ");
	gotoprint(70, 44, "     ▒     ");
	gotoprint(70, 45, "   ▒▒▒   ");

	Sleep(1000);
	gotoprint(70, 41, "            ");
	gotoprint(70, 42, "            ");
	gotoprint(70, 43, "            ");
	gotoprint(70, 44, "            ");
	gotoprint(70, 45, "            ");
}

void pathprint(int n){//경로를 출력하는 함수
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);//노란색

		switch(n){
		//1번라인
		case 1:
			gotoprint(47,8, "■▒▒▒▒■");
			break;

		//2번라인
		case 2:
		gotoprint(57,8, "■▒▒▒▒▒▒▒▒▒■");
			break;

		//3번라인	
		case 3:
		gotoprint(47,8, "■");
		gotoprint(47,9, "▒");
		gotoprint(47,10, "▒");
		gotoprint(47,11, "▒");
		gotoprint(47,12, "▒");
		gotoprint(47,13, "▒");
		gotoprint(47,14, "■");
			break;

		//4번라인
		case 4:
		gotoprint(57,8, "■");
		gotoprint(57,9, "▒");
		gotoprint(57,10, "▒");
		gotoprint(57,11, "▒▒▒▒▒▒");
		gotoprint(67,12, "▒");
		gotoprint(67,13, "▒");
		gotoprint(67,14, "▒");
		gotoprint(67,15, "■");
		break;

		//5번라인
		case 5:
		gotoprint(47,14, "■▒▒");
		gotoprint(51,15, "▒▒▒■");
		break;

		//6번라인
		case 6:
		gotoprint(57,15, "■▒▒▒▒■");
		break;

		//7번라인
		case 7:
		gotoprint(67,15, "■▒▒▒▒■");
		break;

		//8번라인
		case 8:
		gotoprint(47,14, "■");
		gotoprint(43,15, "▒▒");
		gotoprint(37,16, "■▒▒");
		break;
	
		//9번라인
		case 9:
		gotoprint(37,16, "■");
		gotoprint(35,17, "▒");
		gotoprint(33,18, "▒");
		gotoprint(31,19, "▒");
		gotoprint(27,20, "■▒");
		break;

		//10번라인
		case 10:
		gotoprint(27,20, "■");
		gotoprint(23,21, "▒▒");
		gotoprint(21,22, "▒");
		gotoprint(17,23, "▒▒");
		gotoprint(15,24, "▒");
		gotoprint(13,25, "■");
		break;

		//11번라인
		case 11:
		gotoprint(13,25, "■");
		gotoprint(15,26, "▒");
		gotoprint(17,27, "■");
		break;

		//12번라인
		case 12:
		gotoprint(27,20, "■");
		gotoprint(27,21, "▒");
		gotoprint(27,22, "▒");
		gotoprint(27,23, "▒");
		gotoprint(25,24, "▒▒");
		gotoprint(25,25, "▒");
		gotoprint(25,26, "▒");
		gotoprint(25,27, "■");
		break;

		//13번라인
		case 13:
		gotoprint(37,16, "■");
		gotoprint(37,17, "▒");
		gotoprint(37,18, "▒");
		gotoprint(37,19, "▒");
		gotoprint(37,20, "▒");
		gotoprint(37,21, "▒");
		gotoprint(37,22, "▒");
		gotoprint(37,23, "▒");
		gotoprint(37,24, "▒");
		gotoprint(37,25, "▒");
		gotoprint(37,26, "▒");
		gotoprint(37,27, "■");
		break;

		//14번라인
		case 14:
		gotoprint(67,15, "■");
		gotoprint(67,16, "▒");
		gotoprint(67,17, "▒");
		gotoprint(67,18, "▒");
		gotoprint(67,19, "▒");
		gotoprint(67,20, "■");
		break;

		//15번라인
		case 15:
		gotoprint(77,15, "■");
		gotoprint(77,16, "▒");
		gotoprint(77,17, "▒");
		gotoprint(77,18, "▒");
		gotoprint(77,19, "▒");
		gotoprint(77,20, "■");
		break;

		//16번라인
		case 16:
		gotoprint(67,20, "■▒▒▒▒■");
		break;
		
		//17번라인
		case 17:
		gotoprint(67,20, "■");
		gotoprint(67,21, "▒");
		gotoprint(67,22, "▒");
		gotoprint(67,23, "▒");
		gotoprint(67,24, "▒");
		gotoprint(67,25, "■");
		break;

		//18번라인
		case 18:
		gotoprint(77,20, "■");
		gotoprint(77,21, "▒");
		gotoprint(77,22, "▒");
		gotoprint(77,23, "▒");
		gotoprint(77,24, "▒");
		gotoprint(77,25, "■");
		break;

		//19번라인
		case 19:
		gotoprint(57,25, "▒▒▒▒▒■");
		gotoprint(57,26, "▒");
		gotoprint(57,27, "▒");
		gotoprint(57,28, "■");
		break;

		//20번라인
		case 20:
		gotoprint(67,25, "■▒▒▒▒■");
		break;

		//21번라인
		case 21:
		gotoprint(77,25, "■");
		gotoprint(77,26, "▒");
		gotoprint(79,27, "▒");
		gotoprint(81,28, "■");
		break;

		//22번라인
		case 22:
		gotoprint(81,28, "■");
		gotoprint(81,29, "▒");
		gotoprint(81,30, "▒");
		gotoprint(81,31, "▒");
		gotoprint(81,32, "■");
		break;

		//23번라인
		case 23:
		gotoprint(17,27,"■▒▒▒■");
		break;
		
		//24번라인
		case 24:
		gotoprint(25,27,"■▒▒▒▒▒■");
		break;

		//25번라인
		case 25:
		gotoprint(37,27,"■▒▒▒▒■");
		break;

		//26번라인
		case 26:
		gotoprint(47,27,"■▒");
		gotoprint(51,28,"▒▒▒■");
		break;

		//27번라인
		case 27:
		gotoprint(57,28,"■");
		gotoprint(59,29,"▒");
		gotoprint(61,30,"▒");
		gotoprint(63,31,"▒");
		gotoprint(65,32,"▒■");
		break;

		//28번라인
		case 28:
		gotoprint(67,32,"■▒▒▒▒▒▒■");
		break;

		//29번라인
		case 29:
		gotoprint(47,27,"■");
		gotoprint(47,28,"▒");
		gotoprint(47,29,"▒");
		gotoprint(47,30,"▒");
		gotoprint(47,31,"▒");
		gotoprint(47,32,"■");
		break;

		//30번라인
		case 30:
		gotoprint(47,32,"■");
		gotoprint(47,33,"▒");
		gotoprint(47,34,"▒");
		gotoprint(47,35,"■");
		break;

		//32번라인
		case 31:
		gotoprint(17,27,"■");
		gotoprint(17,28,"▒");
		gotoprint(19,29,"▒");
		gotoprint(21,30,"▒");
		gotoprint(21,31,"▒");
		gotoprint(21,32,"▒");
		gotoprint(23,33,"▒");
		gotoprint(23,34,"▒");
		gotoprint(25,35,"▒▒▒▒▒▒▒▒▒▒▒■");
		break;

		//32번라인
		case 32:
		gotoprint(47,35,"■▒▒▒▒▒▒▒▒▒▒");
		gotoprint(67,34,"▒");
		gotoprint(67,33,"▒");
		gotoprint(67,32,"■");
		break;

		//33번라인
		case 33:
		gotoprint(77,8,"■▒▒▒▒▒▒▒▒▒");
		gotoprint(95,9,"▒▒■");
		break;

		//34번라인
		case 34:
		gotoprint(99,9,"■▒");
		gotoprint(103,8,"▒");
		gotoprint(105,7,"▒");
		gotoprint(107,6,"▒");
		gotoprint(109,5,"▒");
		break;
		
		//35번라인
		case 35:
		gotoprint(109,5,"■▒▒▒▒▒");
		gotoprint(119,6,"▒");
		gotoprint(119,7,"▒");
		gotoprint(119,8,"▒");
		gotoprint(119,9,"▒");
		gotoprint(119,10,"▒▒▒■");
		break;

		//36번라인
		case 36:
		gotoprint(99,9,"■");
		gotoprint(99,10,"▒");
		gotoprint(97,11,"▒");
		gotoprint(95,12,"▒");
		gotoprint(95,13,"▒");
		gotoprint(95,14,"▒");
		gotoprint(95,15,"■");
		break;

		//37번라인
		case 37:
		gotoprint(99,9,"■▒▒▒▒▒▒▒");
		gotoprint(113,10,"▒");
		gotoprint(113,11,"▒");
		gotoprint(113,12,"▒");
		gotoprint(113,13,"▒");
		gotoprint(113,14,"▒");
		gotoprint(113,15,"■");
		break;

		//38번라인
		case 38:
		gotoprint(125,10,"■");
		gotoprint(123,11,"▒");
		gotoprint(123,12,"▒");
		gotoprint(121,13,"▒");
		gotoprint(119,14,"▒");
		gotoprint(117,15,"■");
		break;

		//39번라인
		case 39:
		gotoprint(77,15,"■▒▒▒▒■");
		break;
		
		//40번라인
		case 40:
		gotoprint(87,15,"■▒▒▒■");
		break;

		//41번라인
		case 41:
		gotoprint(95,15,"■▒▒▒■");
		break;

		//42번라인
		case 42:
		gotoprint(103,15,"■▒▒▒▒■");
		break;

		//43번라인
		case 43:
		gotoprint(113,15,"■▒■");
		break;

		//44번라인
		case 44:
		gotoprint(117,15,"■▒▒▒");
		gotoprint(125,14,"▒▒▒■");
		break;

		//45번라인
		case 45:
		gotoprint(131,14,"■▒▒");
		gotoprint(137,13,"▒");
		gotoprint(139,12,"▒");
		gotoprint(141,11,"▒");
		gotoprint(143,10,"■");
		break;

		//46번라인
		case 46:
		gotoprint(131,14,"■");
		gotoprint(131,15,"▒");
		gotoprint(131,16,"▒");
		gotoprint(131,17,"▒");
		gotoprint(131,18,"▒");
		gotoprint(131,19,"▒▒■");
		break;

		//47번라인
		case 47:
		gotoprint(87,15,"■");
		gotoprint(87,16,"▒");
		gotoprint(87,17,"▒");
		gotoprint(87,18,"▒");
		gotoprint(87,19,"■");
		break;

		//48번라인
		case 48:
		gotoprint(103,15,"■");
		gotoprint(103,16,"▒");
		gotoprint(101,17,"▒");
		gotoprint(99,18,"▒");
		gotoprint(99,19,"■");
		break;

		//49번라인
		case 49:
		gotoprint(113,15,"■");
		gotoprint(113,16,"▒");
		gotoprint(113,17,"▒");
		gotoprint(113,18,"▒");
		gotoprint(113,19,"■");
		break;

		//50번라인
		case 50:
		gotoprint(77,20,"■▒▒");
		gotoprint(83,19,"▒▒■");
		break;

		//51번라인
		case 51:
		gotoprint(87,19,"■▒▒▒▒▒■");
		break;

		//52번라인
		case 52:
		gotoprint(99,19,"■▒▒▒▒▒▒■");
		break;

		//53번라인
		case 53:
		gotoprint(87,19,"■");
		gotoprint(87,20,"▒");
		gotoprint(87,21,"▒");
		gotoprint(87,22,"▒");
		gotoprint(87,23,"▒");
		gotoprint(87,24,"▒");
		gotoprint(87,25,"■");
		break;

		//54번라인
		case 54:
		gotoprint(99,19,"■");
		gotoprint(99,20,"▒");
		gotoprint(99,21,"▒");
		gotoprint(99,22,"▒");
		gotoprint(99,23,"▒");
		gotoprint(99,24,"▒");
		gotoprint(99,25,"■");
		break;

		//55번라인
		case 55:
		gotoprint(113,19,"■");
		gotoprint(113,20,"▒");
		gotoprint(113,21,"▒");
		gotoprint(113,22,"▒");
		gotoprint(113,23,"▒");
		gotoprint(113,24,"▒");
		gotoprint(113,25,"■");
		break;

		//56번라인
		case 56:
		gotoprint(77,25,"■▒▒▒▒■");
		break;

		//57번라인
		case 57:
		gotoprint(87,25,"■▒▒▒▒▒■");
		break;

		//58번라인
		case 58:
		gotoprint(99,25,"■▒▒▒▒▒▒■");
		break;

		//59번라인
		case 59:
		gotoprint(99,25,"■");
		gotoprint(99,26,"▒");
		gotoprint(97,27,"▒");
		gotoprint(95,28,"▒");
		gotoprint(93,29,"▒");
		gotoprint(93,30,"▒");
		gotoprint(93,31,"▒");
		gotoprint(93,32,"■");
		break;

		//60번라인
		case 60:
		gotoprint(113,25,"■");
		gotoprint(113,26,"▒");
		gotoprint(113,27,"▒");
		gotoprint(113,28,"▒");
		gotoprint(113,29,"▒");
		gotoprint(113,30,"▒");
		gotoprint(113,31,"▒");
		gotoprint(107,32,"■▒▒▒");
		break;

		//61번라인
		case 61:
		gotoprint(81,32,"■▒▒▒▒▒■");
		break;

		//62번라인
		case 62:
		gotoprint(93,32,"■▒▒▒▒▒▒■");
		break;
		
		default:
			break;
		}
}

void mapprint(){
	int i=0;
	

		gotoprint(5,3,"┏"); //맨왼쪽 맵 틀
		for(i=4;i<=38;i++)
		gotoprint(5,i,"┃");

		for(i=4;i<=75;i++)
		gotoprint(2*i-1,3,"━");//맨위쪽 맵 틀

		gotoprint(151,3,"┓");
		for(i=4;i<=38;i++)//맨오른쪽 맵 틀
		gotoprint(151,i,"┃");

		gotoprint(5,39,"┗ ");
		for(i=4;i<=75;i++)
		gotoprint(2*i-1,39,"━");//맨아래 맵 틀
		gotoprint(151,39,"┛");

		gotoprint(5, 41, "┌─────────┬─────────┬──────────┐");
		gotoprint(5, 42, "│      출발지      │      도착지      │      소요 시간     │");
		gotoprint(5, 43, "├─────────┼─────────┼──────────┤");
		gotoprint(5, 44, "│                  │                  │                    │");
		gotoprint(5, 45, "└─────────┴─────────┴──────────┘");
		
		
		


		//1번라인
		gotoprint(47,8, "■▒▒▒▒■");
		
		//2번라인	
		gotoprint(57,8, "■▒▒▒▒▒▒▒▒▒■");

		//3번라인	
		gotoprint(47,8, "■");
		gotoprint(47,9, "▒");
		gotoprint(47,10, "▒");
		gotoprint(47,11, "▒");
		gotoprint(47,12, "▒");
		gotoprint(47,13, "▒");
		gotoprint(47,14, "■");

		//4번라인
		gotoprint(57,8, "■");
		gotoprint(57,9, "▒");
		gotoprint(57,10, "▒");
		gotoprint(57,11, "▒▒▒▒▒▒");
		gotoprint(67,12, "▒");
		gotoprint(67,13, "▒");
		gotoprint(67,14, "▒");
		gotoprint(67,15, "■");

		//5번라인
		gotoprint(47,14, "■▒▒");
		gotoprint(51,15, "▒▒▒■");

		//6번라인
		gotoprint(57,15, "■▒▒▒▒■");

		//7번라인
		gotoprint(67,15, "■▒▒▒▒■");

		//8번라인	
		gotoprint(47,14, "■");
		gotoprint(43,15, "▒▒");
		gotoprint(37,16, "■▒▒");
	
		//9번라인	
		gotoprint(37,16, "■");
		gotoprint(35,17, "▒");
		gotoprint(33,18, "▒");
		gotoprint(31,19, "▒");
		gotoprint(27,20, "■▒");

		//10번라인
		gotoprint(27,20, "■");
		gotoprint(23,21, "▒▒");
		gotoprint(21,22, "▒");
		gotoprint(17,23, "▒▒");
		gotoprint(15,24, "▒");
		gotoprint(13,25, "■");

		//11번라인
		gotoprint(13,25, "■");
		gotoprint(15,26, "▒");
		gotoprint(17,27, "■");

		//12번라인
		gotoprint(27,20, "■");
		gotoprint(27,21, "▒");
		gotoprint(27,22, "▒");
		gotoprint(27,23, "▒");
		gotoprint(25,24, "▒▒");
		gotoprint(25,25, "▒");
		gotoprint(25,26, "▒");
		gotoprint(25,27, "■");

		//13번라인
		gotoprint(37,16, "■");
		gotoprint(37,17, "▒");
		gotoprint(37,18, "▒");
		gotoprint(37,19, "▒");
		gotoprint(37,20, "▒");
		gotoprint(37,21, "▒");
		gotoprint(37,22, "▒");
		gotoprint(37,23, "▒");
		gotoprint(37,24, "▒");
		gotoprint(37,25, "▒");
		gotoprint(37,26, "▒");
		gotoprint(37,27, "■");

		//14번라인
		gotoprint(67,15, "■");
		gotoprint(67,16, "▒");
		gotoprint(67,17, "▒");
		gotoprint(67,18, "▒");
		gotoprint(67,19, "▒");
		gotoprint(67,20, "■");

		//15번라인
		gotoprint(77,15, "■");
		gotoprint(77,16, "▒");
		gotoprint(77,17, "▒");
		gotoprint(77,18, "▒");
		gotoprint(77,19, "▒");
		gotoprint(77,20, "■");

		//16번라인
		gotoprint(67,20, "■▒▒▒▒■");
		
		//17번라인
		gotoprint(67,20, "■");
		gotoprint(67,21, "▒");
		gotoprint(67,22, "▒");
		gotoprint(67,23, "▒");
		gotoprint(67,24, "▒");
		gotoprint(67,25, "■");

		//18번라인
		gotoprint(77,20, "■");
		gotoprint(77,21, "▒");
		gotoprint(77,22, "▒");
		gotoprint(77,23, "▒");
		gotoprint(77,24, "▒");
		gotoprint(77,25, "■");

		//19번라인
		gotoprint(57,25, "▒▒▒▒▒■");
		gotoprint(57,26, "▒");
		gotoprint(57,27, "▒");
		gotoprint(57,28, "■");

		//20번라인
		gotoprint(67,25, "■▒▒▒▒■");

		//21번라인
		gotoprint(77,25, "■");
		gotoprint(77,26, "▒");
		gotoprint(79,27, "▒");
		gotoprint(81,28, "■");

		//22번라인
		gotoprint(81,28, "■");
		gotoprint(81,29, "▒");
		gotoprint(81,30, "▒");
		gotoprint(81,31, "▒");
		gotoprint(81,32, "■");

		//23번라인
		gotoprint(17,27,"■▒▒▒■");
		
		//24번라인
		gotoprint(25,27,"■▒▒▒▒▒■");

		//25번라인
		gotoprint(37,27,"■▒▒▒▒■");

		//26번라인
		gotoprint(47,27,"■▒");
		gotoprint(51,28,"▒▒▒■");

		//27번라인
		gotoprint(57,28,"■");
		gotoprint(59,29,"▒");
		gotoprint(61,30,"▒");
		gotoprint(63,31,"▒");
		gotoprint(65,32,"▒■");

		//28번라인
		gotoprint(67,32,"■▒▒▒▒▒▒■");

		//29번라인
		gotoprint(47,27,"■");
		gotoprint(47,28,"▒");
		gotoprint(47,29,"▒");
		gotoprint(47,30,"▒");
		gotoprint(47,31,"▒");
		gotoprint(47,32,"■");

		//30번라인
		gotoprint(47,32,"■");
		gotoprint(47,33,"▒");
		gotoprint(47,34,"▒");
		gotoprint(47,35,"■");

		//31번라인
		gotoprint(17,27,"■");
		gotoprint(17,28,"▒");
		gotoprint(19,29,"▒");
		gotoprint(21,30,"▒");
		gotoprint(21,31,"▒");
		gotoprint(21,32,"▒");
		gotoprint(23,33,"▒");
		gotoprint(23,34,"▒");
		gotoprint(25,35,"▒▒▒▒▒▒▒▒▒▒▒■");

		//32번라인
		gotoprint(47,35,"■▒▒▒▒▒▒▒▒▒▒");
		gotoprint(67,34,"▒");
		gotoprint(67,33,"▒");
		gotoprint(67,32,"■");

		//33번라인
		gotoprint(77,8,"■▒▒▒▒▒▒▒▒▒");
		gotoprint(95,9,"▒▒■");

		//34번라인
		gotoprint(99,9,"■▒");
		gotoprint(103,8,"▒");
		gotoprint(105,7,"▒");
		gotoprint(107,6,"▒");
		gotoprint(109,5,"■");
		
		//35번라인
		gotoprint(109,5,"■▒▒▒▒▒");
		gotoprint(119,6,"▒");
		gotoprint(119,7,"▒");
		gotoprint(119,8,"▒");
		gotoprint(119,9,"▒");
		gotoprint(119,10,"▒▒▒■");

		//36번라인
		gotoprint(99,9,"■");
		gotoprint(99,10,"▒");
		gotoprint(97,11,"▒");
		gotoprint(95,12,"▒");
		gotoprint(95,13,"▒");
		gotoprint(95,14,"▒");
		gotoprint(95,15,"■");

		//37번라인
		gotoprint(99,9,"■▒▒▒▒▒▒▒");
		gotoprint(113,10,"▒");
		gotoprint(113,11,"▒");
		gotoprint(113,12,"▒");
		gotoprint(113,13,"▒");
		gotoprint(113,14,"▒");
		gotoprint(113,15,"■");

		//38번라인
		gotoprint(125,10,"■");
		gotoprint(123,11,"▒");
		gotoprint(123,12,"▒");
		gotoprint(121,13,"▒");
		gotoprint(119,14,"▒");
		gotoprint(117,15,"■");

		//39번라인
		gotoprint(77,15,"■▒▒▒▒■");
		
		//40번라인
		gotoprint(87,15,"■▒▒▒■");

		//41번라인
		gotoprint(95,15,"■▒▒▒■");

		//42번라인
		gotoprint(103,15,"■▒▒▒▒■");

		//43번라인
		gotoprint(113,15,"■▒■");

		//44번라인
		gotoprint(117,15,"■▒▒▒");
		gotoprint(125,14,"▒▒▒■");

		//45번라인
		gotoprint(131,14,"■▒▒");
		gotoprint(137,13,"▒");
		gotoprint(139,12,"▒");
		gotoprint(141,11,"▒");
		gotoprint(143,10,"■");

		//46번라인
		gotoprint(131,14,"■");
		gotoprint(131,15,"▒");
		gotoprint(131,16,"▒");
		gotoprint(131,17,"▒");
		gotoprint(131,18,"▒");
		gotoprint(131,19,"▒▒■");

		//47번라인
		gotoprint(87,15,"■");
		gotoprint(87,16,"▒");
		gotoprint(87,17,"▒");
		gotoprint(87,18,"▒");
		gotoprint(87,19,"■");

		//48번라인
		gotoprint(103,15,"■");
		gotoprint(103,16,"▒");
		gotoprint(101,17,"▒");
		gotoprint(99,18,"▒");
		gotoprint(99,19,"■");

		//49번라인
		gotoprint(113,15,"■");
		gotoprint(113,16,"▒");
		gotoprint(113,17,"▒");
		gotoprint(113,18,"▒");
		gotoprint(113,19,"■");

		//50번라인
		gotoprint(77,20,"■▒▒");
		gotoprint(83,19,"▒▒■");

		//51번라인
		gotoprint(87,19,"■▒▒▒▒▒■");

		//52번라인
		gotoprint(99,19,"■▒▒▒▒▒▒■");

		//53번라인
		gotoprint(87,19,"■");
		gotoprint(87,20,"▒");
		gotoprint(87,21,"▒");
		gotoprint(87,22,"▒");
		gotoprint(87,23,"▒");
		gotoprint(87,24,"▒");
		gotoprint(87,25,"■");

		//54번라인
		gotoprint(99,19,"■");
		gotoprint(99,20,"▒");
		gotoprint(99,21,"▒");
		gotoprint(99,22,"▒");
		gotoprint(99,23,"▒");
		gotoprint(99,24,"▒");
		gotoprint(99,25,"■");

		//55번라인
		gotoprint(113,19,"■");
		gotoprint(113,20,"▒");
		gotoprint(113,21,"▒");
		gotoprint(113,22,"▒");
		gotoprint(113,23,"▒");
		gotoprint(113,24,"▒");
		gotoprint(113,25,"■");

		//56번라인
		gotoprint(77,25,"■▒▒▒▒■");

		//57번라인
		gotoprint(87,25,"■▒▒▒▒▒■");

		//58번라인
		gotoprint(99,25,"■▒▒▒▒▒▒■");

		//59번라인
		gotoprint(99,25,"■");
		gotoprint(99,26,"▒");
		gotoprint(97,27,"▒");
		gotoprint(95,28,"▒");
		gotoprint(93,29,"▒");
		gotoprint(93,30,"▒");
		gotoprint(93,31,"▒");
		gotoprint(93,32,"■");

		//60번라인
		gotoprint(113,25,"■");
		gotoprint(113,26,"▒");
		gotoprint(113,27,"▒");
		gotoprint(113,28,"▒");
		gotoprint(113,29,"▒");
		gotoprint(113,30,"▒");
		gotoprint(113,31,"▒");
		gotoprint(107,32,"■▒▒▒");

		//61번라인
		gotoprint(81,32,"■▒▒▒▒▒■");

		//62번라인
		gotoprint(93,32,"■▒▒▒▒▒▒■");


		//건물이름
		gotoprint(31,23,"전농관");
		gotoprint(61,10,"제1공학관");
		gotoprint(55,19,"건설공학관");
		gotoprint(103,12,"창공관");
		gotoprint(103,19,"인문학관");
		gotoprint(85,11,"배봉관");
		gotoprint(49,11,"대학본부");
		gotoprint(77,34,"자연과학관");
		gotoprint(137,21,"음악관");
		gotoprint(31,29,"경농관");
		gotoprint(75,12,"제2공학관");
		gotoprint(89,19,"학생회관");
		gotoprint(107,8,"언무관");
		gotoprint(49,6,"과학기술관");
		gotoprint(63,28,"21세기관");
		gotoprint(29,16,"조형관");
		gotoprint(13,18,"시민문화교육관");
		gotoprint(51,30,"자작마루");
		gotoprint(101,29,"정보기술관");
		gotoprint(35,37,"법학관");
		gotoprint(123,8,"중앙도서관");
		gotoprint(143,7,"생활관");
		gotoprint(93,34,"미디어관");
		gotoprint(85,29,"대강당");
		gotoprint(35,8,"대운동장");
		gotoprint(9,25,"정문");
		gotoprint(109,4,"후문");
		gotoprint(39,12,"미래관");
		

}

void mapprintnum(){
	int i=0;
	

		gotoprint(5,3,"┏"); //맨왼쪽 맵 틀
		for(i=4;i<=38;i++)
		gotoprint(5,i,"┃");

		for(i=4;i<=75;i++)
		gotoprint(2*i-1,3,"━");//맨위쪽 맵 틀

		gotoprint(151,3,"┓");
		for(i=4;i<=38;i++)//맨오른쪽 맵 틀
		gotoprint(151,i,"┃");

		gotoprint(5,39,"┗ ");
		for(i=4;i<=75;i++)
		gotoprint(2*i-1,39,"━");//맨아래 맵 틀
		gotoprint(151,39,"┛");

		//1번라인
		gotoprint(47,8, " 1▒▒▒▒ 2");
		
		//2번라인	
		gotoprint(57,8, " 2▒▒▒▒▒▒▒▒▒ 3");

		//3번라인	
		gotoprint(47,8, " 1");
		gotoprint(47,9, "▒");
		gotoprint(47,10, "▒");
		gotoprint(47,11, "▒");
		gotoprint(47,12, "▒");
		gotoprint(47,13, "▒");
		gotoprint(47,14, " 9");

		//4번라인
		gotoprint(57,8, " 2");
		gotoprint(57,9, "▒");
		gotoprint(57,10, "▒");
		gotoprint(57,11, "▒▒▒▒▒▒");
		gotoprint(67,12, "▒");
		gotoprint(67,13, "▒");
		gotoprint(67,14, "▒");
		gotoprint(67,15, "11");

		//5번라인
		gotoprint(47,14, " 9▒▒");
		gotoprint(51,15, "▒▒▒10");

		//6번라인
		gotoprint(57,15, "10▒▒▒▒11");

		//7번라인
		gotoprint(67,15, "11▒▒▒▒12");

		//8번라인	
		gotoprint(47,14, " 9");
		gotoprint(43,15, "▒▒");
		gotoprint(37,16, " 8▒▒");
	
		//9번라인	
		gotoprint(37,16, " 8");
		gotoprint(35,17, "▒");
		gotoprint(33,18, "▒");
		gotoprint(31,19, "▒");
		gotoprint(27,20, "19▒");

		//10번라인
		gotoprint(27,20, "19");
		gotoprint(23,21, "▒▒");
		gotoprint(21,22, "▒");
		gotoprint(17,23, "▒▒");
		gotoprint(15,24, "▒");
		gotoprint(13,25, "26");

		//11번라인
		gotoprint(13,25, "26");
		gotoprint(15,26, "▒");
		gotoprint(17,27, "27");

		//12번라인
		gotoprint(27,20, "19");
		gotoprint(27,21, "▒");
		gotoprint(27,22, "▒");
		gotoprint(27,23, "▒");
		gotoprint(25,24, "▒▒");
		gotoprint(25,25, "▒");
		gotoprint(25,26, "▒");
		gotoprint(25,27, "28");

		//13번라인
		gotoprint(37,16, " 8");
		gotoprint(37,17, "▒");
		gotoprint(37,18, "▒");
		gotoprint(37,19, "▒");
		gotoprint(37,20, "▒");
		gotoprint(37,21, "▒");
		gotoprint(37,22, "▒");
		gotoprint(37,23, "▒");
		gotoprint(37,24, "▒");
		gotoprint(37,25, "▒");
		gotoprint(37,26, "▒");
		gotoprint(37,27, "29");

		//14번라인
		gotoprint(67,15, "11");
		gotoprint(67,16, "▒");
		gotoprint(67,17, "▒");
		gotoprint(67,18, "▒");
		gotoprint(67,19, "▒");
		gotoprint(67,20, "20");

		//15번라인
		gotoprint(77,15, "12");
		gotoprint(77,16, "▒");
		gotoprint(77,17, "▒");
		gotoprint(77,18, "▒");
		gotoprint(77,19, "▒");
		gotoprint(77,20, "21");

		//16번라인
		gotoprint(67,20, "20▒▒▒▒21");
		
		//17번라인
		gotoprint(67,20, "20");
		gotoprint(67,21, "▒");
		gotoprint(67,22, "▒");
		gotoprint(67,23, "▒");
		gotoprint(67,24, "▒");
		gotoprint(67,25, "32");

		//18번라인
		gotoprint(77,20, "21");
		gotoprint(77,21, "▒");
		gotoprint(77,22, "▒");
		gotoprint(77,23, "▒");
		gotoprint(77,24, "▒");
		gotoprint(77,25, "33");

		//19번라인
		gotoprint(57,25, "▒▒▒▒▒32");
		gotoprint(57,26, "▒");
		gotoprint(57,27, "▒");
		gotoprint(57,28, "31");

		//20번라인
		gotoprint(67,25, "32▒▒▒▒33");

		//21번라인
		gotoprint(77,25, "33");
		gotoprint(77,26, "▒");
		gotoprint(79,27, "▒");
		gotoprint(81,28, "34");

		//22번라인
		gotoprint(81,28, "34");
		gotoprint(81,29, "▒");
		gotoprint(81,30, "▒");
		gotoprint(81,31, "▒");
		gotoprint(81,32, "40");

		//23번라인
		gotoprint(17,27,"27▒▒▒28");
		
		//24번라인
		gotoprint(25,27,"28▒▒▒▒▒29");

		//25번라인
		gotoprint(37,27,"29▒▒▒▒30");

		//26번라인
		gotoprint(47,27,"30▒");
		gotoprint(51,28,"▒▒▒31");

		//27번라인
		gotoprint(57,28,"31");
		gotoprint(59,29,"▒");
		gotoprint(61,30,"▒");
		gotoprint(63,31,"▒");
		gotoprint(65,32,"▒39");

		//28번라인
		gotoprint(67,32,"39▒▒▒▒▒▒40");

		//29번라인
		gotoprint(47,27,"30");
		gotoprint(47,28,"▒");
		gotoprint(47,29,"▒");
		gotoprint(47,30,"▒");
		gotoprint(47,31,"▒");
		gotoprint(47,32,"38");

		//30번라인
		gotoprint(47,32,"38");
		gotoprint(47,33,"▒");
		gotoprint(47,34,"▒");
		gotoprint(47,35,"43");

		//31번라인
		gotoprint(17,27,"27");
		gotoprint(17,28,"▒");
		gotoprint(19,29,"▒");
		gotoprint(21,30,"▒");
		gotoprint(21,31,"▒");
		gotoprint(21,32,"▒");
		gotoprint(23,33,"▒");
		gotoprint(23,34,"▒");
		gotoprint(25,35,"▒▒▒▒▒▒▒▒▒▒▒43");

		//32번라인
		gotoprint(47,35,"43▒▒▒▒▒▒▒▒▒▒");
		gotoprint(67,34,"▒");
		gotoprint(67,33,"▒");
		gotoprint(67,32,"39");

		//33번라인
		gotoprint(77,8," 3▒▒▒▒▒▒▒▒▒");
		gotoprint(95,9,"▒▒ 4");

		//34번라인
		gotoprint(99,9," 4▒");
		gotoprint(103,8,"▒");
		gotoprint(105,7,"▒");
		gotoprint(107,6,"▒");
		gotoprint(109,5," 5");
		
		//35번라인
		gotoprint(109,5," 5▒▒▒▒▒");
		gotoprint(119,6,"▒");
		gotoprint(119,7,"▒");
		gotoprint(119,8,"▒");
		gotoprint(119,9,"▒");
		gotoprint(119,10,"▒▒▒ 6");

		//36번라인
		gotoprint(99,9," 4");
		gotoprint(99,10,"▒");
		gotoprint(97,11,"▒");
		gotoprint(95,12,"▒");
		gotoprint(95,13,"▒");
		gotoprint(95,14,"▒");
		gotoprint(95,15,"14");

		//37번라인
		gotoprint(99,9," 4▒▒▒▒▒▒▒");
		gotoprint(113,10,"▒");
		gotoprint(113,11,"▒");
		gotoprint(113,12,"▒");
		gotoprint(113,13,"▒");
		gotoprint(113,14,"▒");
		gotoprint(113,15,"16");

		//38번라인
		gotoprint(125,10," 6");
		gotoprint(123,11,"▒");
		gotoprint(123,12,"▒");
		gotoprint(121,13,"▒");
		gotoprint(119,14,"▒");
		gotoprint(117,15,"17");

		//39번라인
		gotoprint(77,15,"12▒▒▒▒13");
		
		//40번라인
		gotoprint(87,15,"13▒▒▒14");

		//41번라인
		gotoprint(95,15,"14▒▒▒15");

		//42번라인
		gotoprint(103,15,"15▒▒▒▒16");

		//43번라인
		gotoprint(113,15,"16▒17");

		//44번라인
		gotoprint(117,15,"17▒▒▒");
		gotoprint(125,14,"▒▒▒18");

		//45번라인
		gotoprint(131,14,"18▒▒");
		gotoprint(137,13,"▒");
		gotoprint(139,12,"▒");
		gotoprint(141,11,"▒");
		gotoprint(143,10," 7");

		//46번라인
		gotoprint(131,14,"18");
		gotoprint(131,15,"▒");
		gotoprint(131,16,"▒");
		gotoprint(131,17,"▒");
		gotoprint(131,18,"▒");
		gotoprint(131,19,"▒▒25");

		//47번라인
		gotoprint(87,15,"13");
		gotoprint(87,16,"▒");
		gotoprint(87,17,"▒");
		gotoprint(87,18,"▒");
		gotoprint(87,19,"22");

		//48번라인
		gotoprint(103,15,"15");
		gotoprint(103,16,"▒");
		gotoprint(101,17,"▒");
		gotoprint(99,18,"▒");
		gotoprint(99,19,"23");

		//49번라인
		gotoprint(113,15,"16");
		gotoprint(113,16,"▒");
		gotoprint(113,17,"▒");
		gotoprint(113,18,"▒");
		gotoprint(113,19,"24");

		//50번라인
		gotoprint(77,20,"21▒▒");
		gotoprint(83,19,"▒▒22");

		//51번라인
		gotoprint(87,19,"22▒▒▒▒▒23");

		//52번라인
		gotoprint(99,19,"23▒▒▒▒▒▒24");

		//53번라인
		gotoprint(87,19,"22");
		gotoprint(87,20,"▒");
		gotoprint(87,21,"▒");
		gotoprint(87,22,"▒");
		gotoprint(87,23,"▒");
		gotoprint(87,24,"▒");
		gotoprint(87,25,"35");

		//54번라인
		gotoprint(99,19,"23");
		gotoprint(99,20,"▒");
		gotoprint(99,21,"▒");
		gotoprint(99,22,"▒");
		gotoprint(99,23,"▒");
		gotoprint(99,24,"▒");
		gotoprint(99,25,"36");

		//55번라인
		gotoprint(113,19,"24");
		gotoprint(113,20,"▒");
		gotoprint(113,21,"▒");
		gotoprint(113,22,"▒");
		gotoprint(113,23,"▒");
		gotoprint(113,24,"▒");
		gotoprint(113,25,"37");

		//56번라인
		gotoprint(77,25,"33▒▒▒▒35");

		//57번라인
		gotoprint(87,25,"35▒▒▒▒▒36");

		//58번라인
		gotoprint(99,25,"36▒▒▒▒▒▒37");

		//59번라인
		gotoprint(99,25,"36");
		gotoprint(99,26,"▒");
		gotoprint(97,27,"▒");
		gotoprint(95,28,"▒");
		gotoprint(93,29,"▒");
		gotoprint(93,30,"▒");
		gotoprint(93,31,"▒");
		gotoprint(93,32,"41");

		//60번라인
		gotoprint(113,25,"37");
		gotoprint(113,26,"▒");
		gotoprint(113,27,"▒");
		gotoprint(113,28,"▒");
		gotoprint(113,29,"▒");
		gotoprint(113,30,"▒");
		gotoprint(113,31,"▒");
		gotoprint(107,32,"42▒▒▒");

		//61번라인
		gotoprint(81,32,"40▒▒▒▒▒41");

		//62번라인
		gotoprint(93,32,"41▒▒▒▒▒▒42");


		//건물이름
		gotoprint(31,23,"전농관");
		gotoprint(61,10,"제1공학관");
		gotoprint(55,19,"건설공학관");
		gotoprint(103,12,"창공관");
		gotoprint(103,19,"인문학관");
		gotoprint(85,11,"배봉관");
		gotoprint(49,11,"대학본부");
		gotoprint(77,34,"자연과학관");
		gotoprint(137,21,"음악관");
		gotoprint(31,29,"경농관");
		gotoprint(75,12,"제2공학관");
		gotoprint(89,19,"학생회관");
		gotoprint(107,8,"언무관");
		gotoprint(49,6,"과학기술관");
		gotoprint(63,28,"21세기관");
		gotoprint(29,16,"조형관");
		gotoprint(13,18,"시민문화교육관");
		gotoprint(51,30,"자작마루");
		gotoprint(101,29,"정보기술관");
		gotoprint(35,37,"법학관");
		gotoprint(123,8,"중앙도서관");
		gotoprint(143,7,"생활관");
		gotoprint(93,34,"미디어관");
		gotoprint(85,29,"대강당");
		gotoprint(35,8,"대운동장");
		gotoprint(9,25,"정문");
		gotoprint(109,4,"후문");
		gotoprint(39,12,"미래관");
		

}

void gotoxy(int x, int y) {//해당 좌표로 이동하는 함수
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void gotoprint(int x, int y, char *m) {//해당촤표에 출력하는 함수
	gotoxy(x, y);
	puts(m);
}
