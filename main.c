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
	

	system("mode con: cols=400 lines=90");// ȭ�� ũ�� �� ����

	mainmenu();

	while(1){
		mapprint();
		Sleep(500);
		mapprintnum();
		Sleep(500);
		getpatharray();
		timecount();
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);//���

	}

}

void atm(){
	while(1){
	mapprint();
	
	gotoprint(5, 41, "����������������������������������������������������������������");
	gotoprint(5, 42, "��     ������ġ     ��  ����� ATM ��ġ ��      �ҿ� �ð�     ��");
	gotoprint(5, 43, "����������������������������������������������������������������");
	gotoprint(5, 44, "��                  ��                  ��                    ��");
	gotoprint(5, 45, "����������������������������������������������������������������");
	
	gotoprint(124, 25,"[ATM ��ġ���]");
	gotoprint(124, 27,"���к��� 1��");
	gotoprint(124, 28,"�л�ȸ�� 1��");
	gotoprint(124, 29,"21����� 1��");
	gotoprint(124, 30,"�߾ӵ����� 1��");
	gotoprint(124, 31,"�̷��� 1��");
	gotoprint(124, 32,"���а� 2��");
	gotoprint(124, 33,"��������� 2��");
	gotoprint(124, 34,"�ڿ����а� 1��");

	Sleep(500);
	mapprintnum();
	Sleep(500);
		getatmpath();
		timecount();
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 7);//���
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
	gotoprint(63, 26, "��");

	while(1){

	gotoprint(65, 10, "���������������������� ");
	gotoprint(63, 11, "���� ���� �ø��� Map�� �� ");
	gotoprint(65, 12, "���������������������� ");
	
	gotoprint(65, 25, "����������������������");
	gotoprint(65, 26, "��    ������ ã��   ��");
	gotoprint(65, 27, "����������������������");

	gotoprint(65, 28, "����������������������");
	gotoprint(65, 29, "��  ����� ATM ã�� ��");
	gotoprint(65, 30, "����������������������");
	
	gotoprint(63, 32, "�̵� : ��� ���� : Enter");

	gotoprint(65, 40, " ");

	if (GetKeyState(VK_RETURN) < 0)
			continue;

		Select = _getch();

		switch (Select) {
		case 80: // �Ʒ� 
			num = 2;
			gotoprint(63, 26, "  ");
			gotoprint(63, 29, "��");
			break;
		case 72: // ��
			num = 1;
			gotoprint(63, 26, "��");
			gotoprint(63, 29, "  ");
			break;
		case 13: // ����
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
	gotoprint(70, 41, "   �ƢƢ�   ");
	gotoprint(70, 42, "   ��       ");
	gotoprint(70, 43, "   �ƢƢ�   ");
	gotoprint(70, 44, "       ��   ");
	gotoprint(70, 45, "   �ƢƢ�   ");
	Sleep(1000);

	gotoprint(70, 41, "    �� ��   ");
	gotoprint(70, 42, "   ��  ��   ");
	gotoprint(70, 43, "  ��   ��   ");
	gotoprint(70, 44, "  �ƢƢƢ�  ");
	gotoprint(70, 45, "       ��   ");

	Sleep(1000);
	gotoprint(70, 41, "   �ƢƢ�   ");
	gotoprint(70, 42, "       ��   ");
	gotoprint(70, 43, "   �ƢƢ�   ");
	gotoprint(70, 44, "       ��   ");
	gotoprint(70, 45, "   �ƢƢ�   ");
	
	Sleep(1000);
	gotoprint(70, 41, "   �ƢƢ�   ");
	gotoprint(70, 42, "      ��    ");
	gotoprint(70, 43, "   �Ƣ�     ");
	gotoprint(70, 44, "   ��       ");
	gotoprint(70, 45, "   �ƢƢ�   ");

	Sleep(1000);
	gotoprint(70, 41, "     ��     ");
	gotoprint(70, 42, "   �Ƣ�     ");
	gotoprint(70, 43, "     ��     ");
	gotoprint(70, 44, "     ��     ");
	gotoprint(70, 45, "   �ƢƢ�   ");

	Sleep(1000);
	gotoprint(70, 41, "            ");
	gotoprint(70, 42, "            ");
	gotoprint(70, 43, "            ");
	gotoprint(70, 44, "            ");
	gotoprint(70, 45, "            ");
}

void pathprint(int n){//��θ� ����ϴ� �Լ�
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 6);//�����

		switch(n){
		//1������
		case 1:
			gotoprint(47,8, "��ƢƢƢơ�");
			break;

		//2������
		case 2:
		gotoprint(57,8, "��ƢƢƢƢƢƢƢƢơ�");
			break;

		//3������	
		case 3:
		gotoprint(47,8, "��");
		gotoprint(47,9, "��");
		gotoprint(47,10, "��");
		gotoprint(47,11, "��");
		gotoprint(47,12, "��");
		gotoprint(47,13, "��");
		gotoprint(47,14, "��");
			break;

		//4������
		case 4:
		gotoprint(57,8, "��");
		gotoprint(57,9, "��");
		gotoprint(57,10, "��");
		gotoprint(57,11, "�ƢƢƢƢƢ�");
		gotoprint(67,12, "��");
		gotoprint(67,13, "��");
		gotoprint(67,14, "��");
		gotoprint(67,15, "��");
		break;

		//5������
		case 5:
		gotoprint(47,14, "��Ƣ�");
		gotoprint(51,15, "�ƢƢơ�");
		break;

		//6������
		case 6:
		gotoprint(57,15, "��ƢƢƢơ�");
		break;

		//7������
		case 7:
		gotoprint(67,15, "��ƢƢƢơ�");
		break;

		//8������
		case 8:
		gotoprint(47,14, "��");
		gotoprint(43,15, "�Ƣ�");
		gotoprint(37,16, "��Ƣ�");
		break;
	
		//9������
		case 9:
		gotoprint(37,16, "��");
		gotoprint(35,17, "��");
		gotoprint(33,18, "��");
		gotoprint(31,19, "��");
		gotoprint(27,20, "���");
		break;

		//10������
		case 10:
		gotoprint(27,20, "��");
		gotoprint(23,21, "�Ƣ�");
		gotoprint(21,22, "��");
		gotoprint(17,23, "�Ƣ�");
		gotoprint(15,24, "��");
		gotoprint(13,25, "��");
		break;

		//11������
		case 11:
		gotoprint(13,25, "��");
		gotoprint(15,26, "��");
		gotoprint(17,27, "��");
		break;

		//12������
		case 12:
		gotoprint(27,20, "��");
		gotoprint(27,21, "��");
		gotoprint(27,22, "��");
		gotoprint(27,23, "��");
		gotoprint(25,24, "�Ƣ�");
		gotoprint(25,25, "��");
		gotoprint(25,26, "��");
		gotoprint(25,27, "��");
		break;

		//13������
		case 13:
		gotoprint(37,16, "��");
		gotoprint(37,17, "��");
		gotoprint(37,18, "��");
		gotoprint(37,19, "��");
		gotoprint(37,20, "��");
		gotoprint(37,21, "��");
		gotoprint(37,22, "��");
		gotoprint(37,23, "��");
		gotoprint(37,24, "��");
		gotoprint(37,25, "��");
		gotoprint(37,26, "��");
		gotoprint(37,27, "��");
		break;

		//14������
		case 14:
		gotoprint(67,15, "��");
		gotoprint(67,16, "��");
		gotoprint(67,17, "��");
		gotoprint(67,18, "��");
		gotoprint(67,19, "��");
		gotoprint(67,20, "��");
		break;

		//15������
		case 15:
		gotoprint(77,15, "��");
		gotoprint(77,16, "��");
		gotoprint(77,17, "��");
		gotoprint(77,18, "��");
		gotoprint(77,19, "��");
		gotoprint(77,20, "��");
		break;

		//16������
		case 16:
		gotoprint(67,20, "��ƢƢƢơ�");
		break;
		
		//17������
		case 17:
		gotoprint(67,20, "��");
		gotoprint(67,21, "��");
		gotoprint(67,22, "��");
		gotoprint(67,23, "��");
		gotoprint(67,24, "��");
		gotoprint(67,25, "��");
		break;

		//18������
		case 18:
		gotoprint(77,20, "��");
		gotoprint(77,21, "��");
		gotoprint(77,22, "��");
		gotoprint(77,23, "��");
		gotoprint(77,24, "��");
		gotoprint(77,25, "��");
		break;

		//19������
		case 19:
		gotoprint(57,25, "�ƢƢƢƢơ�");
		gotoprint(57,26, "��");
		gotoprint(57,27, "��");
		gotoprint(57,28, "��");
		break;

		//20������
		case 20:
		gotoprint(67,25, "��ƢƢƢơ�");
		break;

		//21������
		case 21:
		gotoprint(77,25, "��");
		gotoprint(77,26, "��");
		gotoprint(79,27, "��");
		gotoprint(81,28, "��");
		break;

		//22������
		case 22:
		gotoprint(81,28, "��");
		gotoprint(81,29, "��");
		gotoprint(81,30, "��");
		gotoprint(81,31, "��");
		gotoprint(81,32, "��");
		break;

		//23������
		case 23:
		gotoprint(17,27,"��ƢƢơ�");
		break;
		
		//24������
		case 24:
		gotoprint(25,27,"��ƢƢƢƢơ�");
		break;

		//25������
		case 25:
		gotoprint(37,27,"��ƢƢƢơ�");
		break;

		//26������
		case 26:
		gotoprint(47,27,"���");
		gotoprint(51,28,"�ƢƢơ�");
		break;

		//27������
		case 27:
		gotoprint(57,28,"��");
		gotoprint(59,29,"��");
		gotoprint(61,30,"��");
		gotoprint(63,31,"��");
		gotoprint(65,32,"�ơ�");
		break;

		//28������
		case 28:
		gotoprint(67,32,"��ƢƢƢƢƢơ�");
		break;

		//29������
		case 29:
		gotoprint(47,27,"��");
		gotoprint(47,28,"��");
		gotoprint(47,29,"��");
		gotoprint(47,30,"��");
		gotoprint(47,31,"��");
		gotoprint(47,32,"��");
		break;

		//30������
		case 30:
		gotoprint(47,32,"��");
		gotoprint(47,33,"��");
		gotoprint(47,34,"��");
		gotoprint(47,35,"��");
		break;

		//32������
		case 31:
		gotoprint(17,27,"��");
		gotoprint(17,28,"��");
		gotoprint(19,29,"��");
		gotoprint(21,30,"��");
		gotoprint(21,31,"��");
		gotoprint(21,32,"��");
		gotoprint(23,33,"��");
		gotoprint(23,34,"��");
		gotoprint(25,35,"�ƢƢƢƢƢƢƢƢƢƢơ�");
		break;

		//32������
		case 32:
		gotoprint(47,35,"��ƢƢƢƢƢƢƢƢƢ�");
		gotoprint(67,34,"��");
		gotoprint(67,33,"��");
		gotoprint(67,32,"��");
		break;

		//33������
		case 33:
		gotoprint(77,8,"��ƢƢƢƢƢƢƢƢ�");
		gotoprint(95,9,"�Ƣơ�");
		break;

		//34������
		case 34:
		gotoprint(99,9,"���");
		gotoprint(103,8,"��");
		gotoprint(105,7,"��");
		gotoprint(107,6,"��");
		gotoprint(109,5,"��");
		break;
		
		//35������
		case 35:
		gotoprint(109,5,"��ƢƢƢƢ�");
		gotoprint(119,6,"��");
		gotoprint(119,7,"��");
		gotoprint(119,8,"��");
		gotoprint(119,9,"��");
		gotoprint(119,10,"�ƢƢơ�");
		break;

		//36������
		case 36:
		gotoprint(99,9,"��");
		gotoprint(99,10,"��");
		gotoprint(97,11,"��");
		gotoprint(95,12,"��");
		gotoprint(95,13,"��");
		gotoprint(95,14,"��");
		gotoprint(95,15,"��");
		break;

		//37������
		case 37:
		gotoprint(99,9,"��ƢƢƢƢƢƢ�");
		gotoprint(113,10,"��");
		gotoprint(113,11,"��");
		gotoprint(113,12,"��");
		gotoprint(113,13,"��");
		gotoprint(113,14,"��");
		gotoprint(113,15,"��");
		break;

		//38������
		case 38:
		gotoprint(125,10,"��");
		gotoprint(123,11,"��");
		gotoprint(123,12,"��");
		gotoprint(121,13,"��");
		gotoprint(119,14,"��");
		gotoprint(117,15,"��");
		break;

		//39������
		case 39:
		gotoprint(77,15,"��ƢƢƢơ�");
		break;
		
		//40������
		case 40:
		gotoprint(87,15,"��ƢƢơ�");
		break;

		//41������
		case 41:
		gotoprint(95,15,"��ƢƢơ�");
		break;

		//42������
		case 42:
		gotoprint(103,15,"��ƢƢƢơ�");
		break;

		//43������
		case 43:
		gotoprint(113,15,"��ơ�");
		break;

		//44������
		case 44:
		gotoprint(117,15,"��ƢƢ�");
		gotoprint(125,14,"�ƢƢơ�");
		break;

		//45������
		case 45:
		gotoprint(131,14,"��Ƣ�");
		gotoprint(137,13,"��");
		gotoprint(139,12,"��");
		gotoprint(141,11,"��");
		gotoprint(143,10,"��");
		break;

		//46������
		case 46:
		gotoprint(131,14,"��");
		gotoprint(131,15,"��");
		gotoprint(131,16,"��");
		gotoprint(131,17,"��");
		gotoprint(131,18,"��");
		gotoprint(131,19,"�Ƣơ�");
		break;

		//47������
		case 47:
		gotoprint(87,15,"��");
		gotoprint(87,16,"��");
		gotoprint(87,17,"��");
		gotoprint(87,18,"��");
		gotoprint(87,19,"��");
		break;

		//48������
		case 48:
		gotoprint(103,15,"��");
		gotoprint(103,16,"��");
		gotoprint(101,17,"��");
		gotoprint(99,18,"��");
		gotoprint(99,19,"��");
		break;

		//49������
		case 49:
		gotoprint(113,15,"��");
		gotoprint(113,16,"��");
		gotoprint(113,17,"��");
		gotoprint(113,18,"��");
		gotoprint(113,19,"��");
		break;

		//50������
		case 50:
		gotoprint(77,20,"��Ƣ�");
		gotoprint(83,19,"�Ƣơ�");
		break;

		//51������
		case 51:
		gotoprint(87,19,"��ƢƢƢƢơ�");
		break;

		//52������
		case 52:
		gotoprint(99,19,"��ƢƢƢƢƢơ�");
		break;

		//53������
		case 53:
		gotoprint(87,19,"��");
		gotoprint(87,20,"��");
		gotoprint(87,21,"��");
		gotoprint(87,22,"��");
		gotoprint(87,23,"��");
		gotoprint(87,24,"��");
		gotoprint(87,25,"��");
		break;

		//54������
		case 54:
		gotoprint(99,19,"��");
		gotoprint(99,20,"��");
		gotoprint(99,21,"��");
		gotoprint(99,22,"��");
		gotoprint(99,23,"��");
		gotoprint(99,24,"��");
		gotoprint(99,25,"��");
		break;

		//55������
		case 55:
		gotoprint(113,19,"��");
		gotoprint(113,20,"��");
		gotoprint(113,21,"��");
		gotoprint(113,22,"��");
		gotoprint(113,23,"��");
		gotoprint(113,24,"��");
		gotoprint(113,25,"��");
		break;

		//56������
		case 56:
		gotoprint(77,25,"��ƢƢƢơ�");
		break;

		//57������
		case 57:
		gotoprint(87,25,"��ƢƢƢƢơ�");
		break;

		//58������
		case 58:
		gotoprint(99,25,"��ƢƢƢƢƢơ�");
		break;

		//59������
		case 59:
		gotoprint(99,25,"��");
		gotoprint(99,26,"��");
		gotoprint(97,27,"��");
		gotoprint(95,28,"��");
		gotoprint(93,29,"��");
		gotoprint(93,30,"��");
		gotoprint(93,31,"��");
		gotoprint(93,32,"��");
		break;

		//60������
		case 60:
		gotoprint(113,25,"��");
		gotoprint(113,26,"��");
		gotoprint(113,27,"��");
		gotoprint(113,28,"��");
		gotoprint(113,29,"��");
		gotoprint(113,30,"��");
		gotoprint(113,31,"��");
		gotoprint(107,32,"��ƢƢ�");
		break;

		//61������
		case 61:
		gotoprint(81,32,"��ƢƢƢƢơ�");
		break;

		//62������
		case 62:
		gotoprint(93,32,"��ƢƢƢƢƢơ�");
		break;
		
		default:
			break;
		}
}

void mapprint(){
	int i=0;
	

		gotoprint(5,3,"��"); //�ǿ��� �� Ʋ
		for(i=4;i<=38;i++)
		gotoprint(5,i,"��");

		for(i=4;i<=75;i++)
		gotoprint(2*i-1,3,"��");//������ �� Ʋ

		gotoprint(151,3,"��");
		for(i=4;i<=38;i++)//�ǿ����� �� Ʋ
		gotoprint(151,i,"��");

		gotoprint(5,39,"�� ");
		for(i=4;i<=75;i++)
		gotoprint(2*i-1,39,"��");//�ǾƷ� �� Ʋ
		gotoprint(151,39,"��");

		gotoprint(5, 41, "����������������������������������������������������������������");
		gotoprint(5, 42, "��      �����      ��      ������      ��      �ҿ� �ð�     ��");
		gotoprint(5, 43, "����������������������������������������������������������������");
		gotoprint(5, 44, "��                  ��                  ��                    ��");
		gotoprint(5, 45, "����������������������������������������������������������������");
		
		
		


		//1������
		gotoprint(47,8, "��ƢƢƢơ�");
		
		//2������	
		gotoprint(57,8, "��ƢƢƢƢƢƢƢƢơ�");

		//3������	
		gotoprint(47,8, "��");
		gotoprint(47,9, "��");
		gotoprint(47,10, "��");
		gotoprint(47,11, "��");
		gotoprint(47,12, "��");
		gotoprint(47,13, "��");
		gotoprint(47,14, "��");

		//4������
		gotoprint(57,8, "��");
		gotoprint(57,9, "��");
		gotoprint(57,10, "��");
		gotoprint(57,11, "�ƢƢƢƢƢ�");
		gotoprint(67,12, "��");
		gotoprint(67,13, "��");
		gotoprint(67,14, "��");
		gotoprint(67,15, "��");

		//5������
		gotoprint(47,14, "��Ƣ�");
		gotoprint(51,15, "�ƢƢơ�");

		//6������
		gotoprint(57,15, "��ƢƢƢơ�");

		//7������
		gotoprint(67,15, "��ƢƢƢơ�");

		//8������	
		gotoprint(47,14, "��");
		gotoprint(43,15, "�Ƣ�");
		gotoprint(37,16, "��Ƣ�");
	
		//9������	
		gotoprint(37,16, "��");
		gotoprint(35,17, "��");
		gotoprint(33,18, "��");
		gotoprint(31,19, "��");
		gotoprint(27,20, "���");

		//10������
		gotoprint(27,20, "��");
		gotoprint(23,21, "�Ƣ�");
		gotoprint(21,22, "��");
		gotoprint(17,23, "�Ƣ�");
		gotoprint(15,24, "��");
		gotoprint(13,25, "��");

		//11������
		gotoprint(13,25, "��");
		gotoprint(15,26, "��");
		gotoprint(17,27, "��");

		//12������
		gotoprint(27,20, "��");
		gotoprint(27,21, "��");
		gotoprint(27,22, "��");
		gotoprint(27,23, "��");
		gotoprint(25,24, "�Ƣ�");
		gotoprint(25,25, "��");
		gotoprint(25,26, "��");
		gotoprint(25,27, "��");

		//13������
		gotoprint(37,16, "��");
		gotoprint(37,17, "��");
		gotoprint(37,18, "��");
		gotoprint(37,19, "��");
		gotoprint(37,20, "��");
		gotoprint(37,21, "��");
		gotoprint(37,22, "��");
		gotoprint(37,23, "��");
		gotoprint(37,24, "��");
		gotoprint(37,25, "��");
		gotoprint(37,26, "��");
		gotoprint(37,27, "��");

		//14������
		gotoprint(67,15, "��");
		gotoprint(67,16, "��");
		gotoprint(67,17, "��");
		gotoprint(67,18, "��");
		gotoprint(67,19, "��");
		gotoprint(67,20, "��");

		//15������
		gotoprint(77,15, "��");
		gotoprint(77,16, "��");
		gotoprint(77,17, "��");
		gotoprint(77,18, "��");
		gotoprint(77,19, "��");
		gotoprint(77,20, "��");

		//16������
		gotoprint(67,20, "��ƢƢƢơ�");
		
		//17������
		gotoprint(67,20, "��");
		gotoprint(67,21, "��");
		gotoprint(67,22, "��");
		gotoprint(67,23, "��");
		gotoprint(67,24, "��");
		gotoprint(67,25, "��");

		//18������
		gotoprint(77,20, "��");
		gotoprint(77,21, "��");
		gotoprint(77,22, "��");
		gotoprint(77,23, "��");
		gotoprint(77,24, "��");
		gotoprint(77,25, "��");

		//19������
		gotoprint(57,25, "�ƢƢƢƢơ�");
		gotoprint(57,26, "��");
		gotoprint(57,27, "��");
		gotoprint(57,28, "��");

		//20������
		gotoprint(67,25, "��ƢƢƢơ�");

		//21������
		gotoprint(77,25, "��");
		gotoprint(77,26, "��");
		gotoprint(79,27, "��");
		gotoprint(81,28, "��");

		//22������
		gotoprint(81,28, "��");
		gotoprint(81,29, "��");
		gotoprint(81,30, "��");
		gotoprint(81,31, "��");
		gotoprint(81,32, "��");

		//23������
		gotoprint(17,27,"��ƢƢơ�");
		
		//24������
		gotoprint(25,27,"��ƢƢƢƢơ�");

		//25������
		gotoprint(37,27,"��ƢƢƢơ�");

		//26������
		gotoprint(47,27,"���");
		gotoprint(51,28,"�ƢƢơ�");

		//27������
		gotoprint(57,28,"��");
		gotoprint(59,29,"��");
		gotoprint(61,30,"��");
		gotoprint(63,31,"��");
		gotoprint(65,32,"�ơ�");

		//28������
		gotoprint(67,32,"��ƢƢƢƢƢơ�");

		//29������
		gotoprint(47,27,"��");
		gotoprint(47,28,"��");
		gotoprint(47,29,"��");
		gotoprint(47,30,"��");
		gotoprint(47,31,"��");
		gotoprint(47,32,"��");

		//30������
		gotoprint(47,32,"��");
		gotoprint(47,33,"��");
		gotoprint(47,34,"��");
		gotoprint(47,35,"��");

		//31������
		gotoprint(17,27,"��");
		gotoprint(17,28,"��");
		gotoprint(19,29,"��");
		gotoprint(21,30,"��");
		gotoprint(21,31,"��");
		gotoprint(21,32,"��");
		gotoprint(23,33,"��");
		gotoprint(23,34,"��");
		gotoprint(25,35,"�ƢƢƢƢƢƢƢƢƢƢơ�");

		//32������
		gotoprint(47,35,"��ƢƢƢƢƢƢƢƢƢ�");
		gotoprint(67,34,"��");
		gotoprint(67,33,"��");
		gotoprint(67,32,"��");

		//33������
		gotoprint(77,8,"��ƢƢƢƢƢƢƢƢ�");
		gotoprint(95,9,"�Ƣơ�");

		//34������
		gotoprint(99,9,"���");
		gotoprint(103,8,"��");
		gotoprint(105,7,"��");
		gotoprint(107,6,"��");
		gotoprint(109,5,"��");
		
		//35������
		gotoprint(109,5,"��ƢƢƢƢ�");
		gotoprint(119,6,"��");
		gotoprint(119,7,"��");
		gotoprint(119,8,"��");
		gotoprint(119,9,"��");
		gotoprint(119,10,"�ƢƢơ�");

		//36������
		gotoprint(99,9,"��");
		gotoprint(99,10,"��");
		gotoprint(97,11,"��");
		gotoprint(95,12,"��");
		gotoprint(95,13,"��");
		gotoprint(95,14,"��");
		gotoprint(95,15,"��");

		//37������
		gotoprint(99,9,"��ƢƢƢƢƢƢ�");
		gotoprint(113,10,"��");
		gotoprint(113,11,"��");
		gotoprint(113,12,"��");
		gotoprint(113,13,"��");
		gotoprint(113,14,"��");
		gotoprint(113,15,"��");

		//38������
		gotoprint(125,10,"��");
		gotoprint(123,11,"��");
		gotoprint(123,12,"��");
		gotoprint(121,13,"��");
		gotoprint(119,14,"��");
		gotoprint(117,15,"��");

		//39������
		gotoprint(77,15,"��ƢƢƢơ�");
		
		//40������
		gotoprint(87,15,"��ƢƢơ�");

		//41������
		gotoprint(95,15,"��ƢƢơ�");

		//42������
		gotoprint(103,15,"��ƢƢƢơ�");

		//43������
		gotoprint(113,15,"��ơ�");

		//44������
		gotoprint(117,15,"��ƢƢ�");
		gotoprint(125,14,"�ƢƢơ�");

		//45������
		gotoprint(131,14,"��Ƣ�");
		gotoprint(137,13,"��");
		gotoprint(139,12,"��");
		gotoprint(141,11,"��");
		gotoprint(143,10,"��");

		//46������
		gotoprint(131,14,"��");
		gotoprint(131,15,"��");
		gotoprint(131,16,"��");
		gotoprint(131,17,"��");
		gotoprint(131,18,"��");
		gotoprint(131,19,"�Ƣơ�");

		//47������
		gotoprint(87,15,"��");
		gotoprint(87,16,"��");
		gotoprint(87,17,"��");
		gotoprint(87,18,"��");
		gotoprint(87,19,"��");

		//48������
		gotoprint(103,15,"��");
		gotoprint(103,16,"��");
		gotoprint(101,17,"��");
		gotoprint(99,18,"��");
		gotoprint(99,19,"��");

		//49������
		gotoprint(113,15,"��");
		gotoprint(113,16,"��");
		gotoprint(113,17,"��");
		gotoprint(113,18,"��");
		gotoprint(113,19,"��");

		//50������
		gotoprint(77,20,"��Ƣ�");
		gotoprint(83,19,"�Ƣơ�");

		//51������
		gotoprint(87,19,"��ƢƢƢƢơ�");

		//52������
		gotoprint(99,19,"��ƢƢƢƢƢơ�");

		//53������
		gotoprint(87,19,"��");
		gotoprint(87,20,"��");
		gotoprint(87,21,"��");
		gotoprint(87,22,"��");
		gotoprint(87,23,"��");
		gotoprint(87,24,"��");
		gotoprint(87,25,"��");

		//54������
		gotoprint(99,19,"��");
		gotoprint(99,20,"��");
		gotoprint(99,21,"��");
		gotoprint(99,22,"��");
		gotoprint(99,23,"��");
		gotoprint(99,24,"��");
		gotoprint(99,25,"��");

		//55������
		gotoprint(113,19,"��");
		gotoprint(113,20,"��");
		gotoprint(113,21,"��");
		gotoprint(113,22,"��");
		gotoprint(113,23,"��");
		gotoprint(113,24,"��");
		gotoprint(113,25,"��");

		//56������
		gotoprint(77,25,"��ƢƢƢơ�");

		//57������
		gotoprint(87,25,"��ƢƢƢƢơ�");

		//58������
		gotoprint(99,25,"��ƢƢƢƢƢơ�");

		//59������
		gotoprint(99,25,"��");
		gotoprint(99,26,"��");
		gotoprint(97,27,"��");
		gotoprint(95,28,"��");
		gotoprint(93,29,"��");
		gotoprint(93,30,"��");
		gotoprint(93,31,"��");
		gotoprint(93,32,"��");

		//60������
		gotoprint(113,25,"��");
		gotoprint(113,26,"��");
		gotoprint(113,27,"��");
		gotoprint(113,28,"��");
		gotoprint(113,29,"��");
		gotoprint(113,30,"��");
		gotoprint(113,31,"��");
		gotoprint(107,32,"��ƢƢ�");

		//61������
		gotoprint(81,32,"��ƢƢƢƢơ�");

		//62������
		gotoprint(93,32,"��ƢƢƢƢƢơ�");


		//�ǹ��̸�
		gotoprint(31,23,"�����");
		gotoprint(61,10,"��1���а�");
		gotoprint(55,19,"�Ǽ����а�");
		gotoprint(103,12,"â����");
		gotoprint(103,19,"�ι��а�");
		gotoprint(85,11,"�����");
		gotoprint(49,11,"���к���");
		gotoprint(77,34,"�ڿ����а�");
		gotoprint(137,21,"���ǰ�");
		gotoprint(31,29,"����");
		gotoprint(75,12,"��2���а�");
		gotoprint(89,19,"�л�ȸ��");
		gotoprint(107,8,"�𹫰�");
		gotoprint(49,6,"���б����");
		gotoprint(63,28,"21�����");
		gotoprint(29,16,"������");
		gotoprint(13,18,"�ùι�ȭ������");
		gotoprint(51,30,"���۸���");
		gotoprint(101,29,"���������");
		gotoprint(35,37,"���а�");
		gotoprint(123,8,"�߾ӵ�����");
		gotoprint(143,7,"��Ȱ��");
		gotoprint(93,34,"�̵���");
		gotoprint(85,29,"�밭��");
		gotoprint(35,8,"����");
		gotoprint(9,25,"����");
		gotoprint(109,4,"�Ĺ�");
		gotoprint(39,12,"�̷���");
		

}

void mapprintnum(){
	int i=0;
	

		gotoprint(5,3,"��"); //�ǿ��� �� Ʋ
		for(i=4;i<=38;i++)
		gotoprint(5,i,"��");

		for(i=4;i<=75;i++)
		gotoprint(2*i-1,3,"��");//������ �� Ʋ

		gotoprint(151,3,"��");
		for(i=4;i<=38;i++)//�ǿ����� �� Ʋ
		gotoprint(151,i,"��");

		gotoprint(5,39,"�� ");
		for(i=4;i<=75;i++)
		gotoprint(2*i-1,39,"��");//�ǾƷ� �� Ʋ
		gotoprint(151,39,"��");

		//1������
		gotoprint(47,8, " 1�ƢƢƢ� 2");
		
		//2������	
		gotoprint(57,8, " 2�ƢƢƢƢƢƢƢƢ� 3");

		//3������	
		gotoprint(47,8, " 1");
		gotoprint(47,9, "��");
		gotoprint(47,10, "��");
		gotoprint(47,11, "��");
		gotoprint(47,12, "��");
		gotoprint(47,13, "��");
		gotoprint(47,14, " 9");

		//4������
		gotoprint(57,8, " 2");
		gotoprint(57,9, "��");
		gotoprint(57,10, "��");
		gotoprint(57,11, "�ƢƢƢƢƢ�");
		gotoprint(67,12, "��");
		gotoprint(67,13, "��");
		gotoprint(67,14, "��");
		gotoprint(67,15, "11");

		//5������
		gotoprint(47,14, " 9�Ƣ�");
		gotoprint(51,15, "�ƢƢ�10");

		//6������
		gotoprint(57,15, "10�ƢƢƢ�11");

		//7������
		gotoprint(67,15, "11�ƢƢƢ�12");

		//8������	
		gotoprint(47,14, " 9");
		gotoprint(43,15, "�Ƣ�");
		gotoprint(37,16, " 8�Ƣ�");
	
		//9������	
		gotoprint(37,16, " 8");
		gotoprint(35,17, "��");
		gotoprint(33,18, "��");
		gotoprint(31,19, "��");
		gotoprint(27,20, "19��");

		//10������
		gotoprint(27,20, "19");
		gotoprint(23,21, "�Ƣ�");
		gotoprint(21,22, "��");
		gotoprint(17,23, "�Ƣ�");
		gotoprint(15,24, "��");
		gotoprint(13,25, "26");

		//11������
		gotoprint(13,25, "26");
		gotoprint(15,26, "��");
		gotoprint(17,27, "27");

		//12������
		gotoprint(27,20, "19");
		gotoprint(27,21, "��");
		gotoprint(27,22, "��");
		gotoprint(27,23, "��");
		gotoprint(25,24, "�Ƣ�");
		gotoprint(25,25, "��");
		gotoprint(25,26, "��");
		gotoprint(25,27, "28");

		//13������
		gotoprint(37,16, " 8");
		gotoprint(37,17, "��");
		gotoprint(37,18, "��");
		gotoprint(37,19, "��");
		gotoprint(37,20, "��");
		gotoprint(37,21, "��");
		gotoprint(37,22, "��");
		gotoprint(37,23, "��");
		gotoprint(37,24, "��");
		gotoprint(37,25, "��");
		gotoprint(37,26, "��");
		gotoprint(37,27, "29");

		//14������
		gotoprint(67,15, "11");
		gotoprint(67,16, "��");
		gotoprint(67,17, "��");
		gotoprint(67,18, "��");
		gotoprint(67,19, "��");
		gotoprint(67,20, "20");

		//15������
		gotoprint(77,15, "12");
		gotoprint(77,16, "��");
		gotoprint(77,17, "��");
		gotoprint(77,18, "��");
		gotoprint(77,19, "��");
		gotoprint(77,20, "21");

		//16������
		gotoprint(67,20, "20�ƢƢƢ�21");
		
		//17������
		gotoprint(67,20, "20");
		gotoprint(67,21, "��");
		gotoprint(67,22, "��");
		gotoprint(67,23, "��");
		gotoprint(67,24, "��");
		gotoprint(67,25, "32");

		//18������
		gotoprint(77,20, "21");
		gotoprint(77,21, "��");
		gotoprint(77,22, "��");
		gotoprint(77,23, "��");
		gotoprint(77,24, "��");
		gotoprint(77,25, "33");

		//19������
		gotoprint(57,25, "�ƢƢƢƢ�32");
		gotoprint(57,26, "��");
		gotoprint(57,27, "��");
		gotoprint(57,28, "31");

		//20������
		gotoprint(67,25, "32�ƢƢƢ�33");

		//21������
		gotoprint(77,25, "33");
		gotoprint(77,26, "��");
		gotoprint(79,27, "��");
		gotoprint(81,28, "34");

		//22������
		gotoprint(81,28, "34");
		gotoprint(81,29, "��");
		gotoprint(81,30, "��");
		gotoprint(81,31, "��");
		gotoprint(81,32, "40");

		//23������
		gotoprint(17,27,"27�ƢƢ�28");
		
		//24������
		gotoprint(25,27,"28�ƢƢƢƢ�29");

		//25������
		gotoprint(37,27,"29�ƢƢƢ�30");

		//26������
		gotoprint(47,27,"30��");
		gotoprint(51,28,"�ƢƢ�31");

		//27������
		gotoprint(57,28,"31");
		gotoprint(59,29,"��");
		gotoprint(61,30,"��");
		gotoprint(63,31,"��");
		gotoprint(65,32,"��39");

		//28������
		gotoprint(67,32,"39�ƢƢƢƢƢ�40");

		//29������
		gotoprint(47,27,"30");
		gotoprint(47,28,"��");
		gotoprint(47,29,"��");
		gotoprint(47,30,"��");
		gotoprint(47,31,"��");
		gotoprint(47,32,"38");

		//30������
		gotoprint(47,32,"38");
		gotoprint(47,33,"��");
		gotoprint(47,34,"��");
		gotoprint(47,35,"43");

		//31������
		gotoprint(17,27,"27");
		gotoprint(17,28,"��");
		gotoprint(19,29,"��");
		gotoprint(21,30,"��");
		gotoprint(21,31,"��");
		gotoprint(21,32,"��");
		gotoprint(23,33,"��");
		gotoprint(23,34,"��");
		gotoprint(25,35,"�ƢƢƢƢƢƢƢƢƢƢ�43");

		//32������
		gotoprint(47,35,"43�ƢƢƢƢƢƢƢƢƢ�");
		gotoprint(67,34,"��");
		gotoprint(67,33,"��");
		gotoprint(67,32,"39");

		//33������
		gotoprint(77,8," 3�ƢƢƢƢƢƢƢƢ�");
		gotoprint(95,9,"�Ƣ� 4");

		//34������
		gotoprint(99,9," 4��");
		gotoprint(103,8,"��");
		gotoprint(105,7,"��");
		gotoprint(107,6,"��");
		gotoprint(109,5," 5");
		
		//35������
		gotoprint(109,5," 5�ƢƢƢƢ�");
		gotoprint(119,6,"��");
		gotoprint(119,7,"��");
		gotoprint(119,8,"��");
		gotoprint(119,9,"��");
		gotoprint(119,10,"�ƢƢ� 6");

		//36������
		gotoprint(99,9," 4");
		gotoprint(99,10,"��");
		gotoprint(97,11,"��");
		gotoprint(95,12,"��");
		gotoprint(95,13,"��");
		gotoprint(95,14,"��");
		gotoprint(95,15,"14");

		//37������
		gotoprint(99,9," 4�ƢƢƢƢƢƢ�");
		gotoprint(113,10,"��");
		gotoprint(113,11,"��");
		gotoprint(113,12,"��");
		gotoprint(113,13,"��");
		gotoprint(113,14,"��");
		gotoprint(113,15,"16");

		//38������
		gotoprint(125,10," 6");
		gotoprint(123,11,"��");
		gotoprint(123,12,"��");
		gotoprint(121,13,"��");
		gotoprint(119,14,"��");
		gotoprint(117,15,"17");

		//39������
		gotoprint(77,15,"12�ƢƢƢ�13");
		
		//40������
		gotoprint(87,15,"13�ƢƢ�14");

		//41������
		gotoprint(95,15,"14�ƢƢ�15");

		//42������
		gotoprint(103,15,"15�ƢƢƢ�16");

		//43������
		gotoprint(113,15,"16��17");

		//44������
		gotoprint(117,15,"17�ƢƢ�");
		gotoprint(125,14,"�ƢƢ�18");

		//45������
		gotoprint(131,14,"18�Ƣ�");
		gotoprint(137,13,"��");
		gotoprint(139,12,"��");
		gotoprint(141,11,"��");
		gotoprint(143,10," 7");

		//46������
		gotoprint(131,14,"18");
		gotoprint(131,15,"��");
		gotoprint(131,16,"��");
		gotoprint(131,17,"��");
		gotoprint(131,18,"��");
		gotoprint(131,19,"�Ƣ�25");

		//47������
		gotoprint(87,15,"13");
		gotoprint(87,16,"��");
		gotoprint(87,17,"��");
		gotoprint(87,18,"��");
		gotoprint(87,19,"22");

		//48������
		gotoprint(103,15,"15");
		gotoprint(103,16,"��");
		gotoprint(101,17,"��");
		gotoprint(99,18,"��");
		gotoprint(99,19,"23");

		//49������
		gotoprint(113,15,"16");
		gotoprint(113,16,"��");
		gotoprint(113,17,"��");
		gotoprint(113,18,"��");
		gotoprint(113,19,"24");

		//50������
		gotoprint(77,20,"21�Ƣ�");
		gotoprint(83,19,"�Ƣ�22");

		//51������
		gotoprint(87,19,"22�ƢƢƢƢ�23");

		//52������
		gotoprint(99,19,"23�ƢƢƢƢƢ�24");

		//53������
		gotoprint(87,19,"22");
		gotoprint(87,20,"��");
		gotoprint(87,21,"��");
		gotoprint(87,22,"��");
		gotoprint(87,23,"��");
		gotoprint(87,24,"��");
		gotoprint(87,25,"35");

		//54������
		gotoprint(99,19,"23");
		gotoprint(99,20,"��");
		gotoprint(99,21,"��");
		gotoprint(99,22,"��");
		gotoprint(99,23,"��");
		gotoprint(99,24,"��");
		gotoprint(99,25,"36");

		//55������
		gotoprint(113,19,"24");
		gotoprint(113,20,"��");
		gotoprint(113,21,"��");
		gotoprint(113,22,"��");
		gotoprint(113,23,"��");
		gotoprint(113,24,"��");
		gotoprint(113,25,"37");

		//56������
		gotoprint(77,25,"33�ƢƢƢ�35");

		//57������
		gotoprint(87,25,"35�ƢƢƢƢ�36");

		//58������
		gotoprint(99,25,"36�ƢƢƢƢƢ�37");

		//59������
		gotoprint(99,25,"36");
		gotoprint(99,26,"��");
		gotoprint(97,27,"��");
		gotoprint(95,28,"��");
		gotoprint(93,29,"��");
		gotoprint(93,30,"��");
		gotoprint(93,31,"��");
		gotoprint(93,32,"41");

		//60������
		gotoprint(113,25,"37");
		gotoprint(113,26,"��");
		gotoprint(113,27,"��");
		gotoprint(113,28,"��");
		gotoprint(113,29,"��");
		gotoprint(113,30,"��");
		gotoprint(113,31,"��");
		gotoprint(107,32,"42�ƢƢ�");

		//61������
		gotoprint(81,32,"40�ƢƢƢƢ�41");

		//62������
		gotoprint(93,32,"41�ƢƢƢƢƢ�42");


		//�ǹ��̸�
		gotoprint(31,23,"�����");
		gotoprint(61,10,"��1���а�");
		gotoprint(55,19,"�Ǽ����а�");
		gotoprint(103,12,"â����");
		gotoprint(103,19,"�ι��а�");
		gotoprint(85,11,"�����");
		gotoprint(49,11,"���к���");
		gotoprint(77,34,"�ڿ����а�");
		gotoprint(137,21,"���ǰ�");
		gotoprint(31,29,"����");
		gotoprint(75,12,"��2���а�");
		gotoprint(89,19,"�л�ȸ��");
		gotoprint(107,8,"�𹫰�");
		gotoprint(49,6,"���б����");
		gotoprint(63,28,"21�����");
		gotoprint(29,16,"������");
		gotoprint(13,18,"�ùι�ȭ������");
		gotoprint(51,30,"���۸���");
		gotoprint(101,29,"���������");
		gotoprint(35,37,"���а�");
		gotoprint(123,8,"�߾ӵ�����");
		gotoprint(143,7,"��Ȱ��");
		gotoprint(93,34,"�̵���");
		gotoprint(85,29,"�밭��");
		gotoprint(35,8,"����");
		gotoprint(9,25,"����");
		gotoprint(109,4,"�Ĺ�");
		gotoprint(39,12,"�̷���");
		

}

void gotoxy(int x, int y) {//�ش� ��ǥ�� �̵��ϴ� �Լ�
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void gotoprint(int x, int y, char *m) {//�ش���ǥ�� ����ϴ� �Լ�
	gotoxy(x, y);
	puts(m);
}
