
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

extern void gotoxy(int,int);
extern void gotoprint(int,int,char*);
extern void pathprint(int n);


#define N		43		// ����� ��, 43���� ���
#define M		999	// MAXIMUM�� �ǹ�

void mapSetting(int matrix[N][N]){

		matrix[0][1]=1;
		matrix[0][8]=3;

		matrix[1][0]=1;
		matrix[1][10]=4;
		matrix[1][2]=2;

		matrix[2][1]=2;
		matrix[2][3]=33;

		matrix[3][2]=33;
		matrix[3][4]=34;
		matrix[3][15]=37;
		matrix[3][13]=36;

		matrix[4][3]=34;
		matrix[4][5]=35;

		matrix[5][4]=35;
		matrix[5][16]=38;

		matrix[6][17]=45;

		matrix[7][18]=9;
		matrix[7][28]=13;
		matrix[7][8]=8;

		matrix[8][7]=8;
		matrix[8][0]=3;
		matrix[8][9]=5;

		matrix[9][8]=5;
		matrix[9][10]=6;

		matrix[10][1]=4;
		matrix[10][9]=6;
		matrix[10][11]=7;
		matrix[10][19]=14;

		matrix[11][10]=7;
		matrix[11][12]=39;
		matrix[11][20]=15;

		matrix[12][11]=39;
		matrix[12][13]=40;
		matrix[12][21]=47;

		matrix[13][12]=40;
		matrix[13][14]=41;
		matrix[13][3]=36;

		matrix[14][13]=41;
		matrix[14][15]=42;
		matrix[14][22]=48;

		matrix[15][3]=37;
		matrix[15][16]=43;
		matrix[15][14]=42;
		matrix[15][23]=49;

		matrix[16][15]=43;
		matrix[16][5]=38;
		matrix[16][17]=44;

		matrix[17][16]=44;
		matrix[17][6]=45;
		matrix[17][24]=46;

		matrix[18][25]=10;
		matrix[18][7]=9;
		matrix[18][27]=12;

		matrix[19][10]=14;
		matrix[19][20]=16;
		matrix[19][31]=17;

		matrix[20][19]=16;
		matrix[20][11]=15;
		matrix[20][21]=50;
		matrix[20][32]=18;

		matrix[21][12]=47;
		matrix[21][20]=50;
		matrix[21][22]=51;
		matrix[21][34]=53;

		matrix[22][14]=48;
		matrix[22][23]=52;
		matrix[22][21]=51;
		matrix[22][35]=54;

		matrix[23][15]=49;
		matrix[23][22]=52;
		matrix[23][36]=55;

		matrix[24][17]=46;

		matrix[25][18]=10;
		matrix[25][26]=11;

		matrix[26][25]=11;
		matrix[26][27]=23;
		matrix[26][42]=31;

		matrix[27][18]=12;
		matrix[27][26]=23;
		matrix[27][28]=24;

		matrix[28][7]=13;
		matrix[28][27]=24;
		matrix[28][29]=25;

		matrix[29][28]=25;
		matrix[29][30]=26;
		matrix[29][37]=29;

		matrix[30][31]=19;
		matrix[30][29]=26;
		matrix[30][38]=27;

		matrix[31][19]=17;
		matrix[31][32]=20;
		matrix[31][30]=19;

		matrix[32][20]=18;
		matrix[32][31]=20;
		matrix[32][33]=21;
		matrix[32][34]=56;

		matrix[33][32]=21;
		matrix[33][39]=22;

		matrix[34][32]=56;
		matrix[34][21]=53;
		matrix[34][35]=57;

		matrix[35][22]=54;
		matrix[35][34]=57;
		matrix[35][40]=59;
		matrix[35][36]=58;

		matrix[36][23]=55;
		matrix[36][35]=58;
		matrix[36][41]=60;

		matrix[37][29]=29;
		matrix[37][42]=30;

		matrix[38][30]=27;
		matrix[38][39]=28;
		matrix[38][42]=32;

		matrix[39][38]=28;
		matrix[39][33]=22;
		matrix[39][40]=61;

		matrix[40][39]=61;
		matrix[40][35]=59;
		matrix[40][41]=62;

		matrix[41][40]=62;
		matrix[41][36]=60;

		matrix[42][26]=31;
		matrix[42][37]=30;
		matrix[42][38]=32;


}

void getpatharray(){
	int time[62]={41,52,56,72,36,33,40,29,52,94,26,35,67,28,29,37,20,36,32,64,18,24,37,57,13,39,26,46,
					29,21,141,70,83,40,88,52,74,37,67,29,25,46,19,38,67,50,22,23,29,37,44,42,41,39,41,
					26,52,43,50,64,57,40};// �� �뼱�� �����Ǵ� �ð�(��)

	int matrix[N][N] = {0};
	int timematrix[N][N]={0};

	int patharray[20]={0};// ���ʴ�� ��带 ������ �迭
	int linearray[20]={0};// ���ʴ�� �뼱�� ������ �迭


	char temp[16];			// �׳� ���� ��带 �Է¹ޱ� ���� Ű���� �Է¿� ����
	int start, cur, finish;			// ���� ���� ��� ��ȣ, ���� ó������ ��� ��ȣ�� ������ ����
	int i,j;				// �ݺ���(for)�� ������ ���� ����
	int min;				// ���� ó������ �ּҰ��� �����ϱ� ���� ����
	int cost[N];			// (����������) �� ������ ����� �����ϱ� ���� �迭����
	int solution[N];		// Ȯ���� �� (����� ����) ������� ǥ���ϴ� ���
	int index[N]={0};           // ��θ� �������� ����
	int size=0;


	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			matrix[i][j]=M;
			timematrix[i][j]=M;
		}
	}// ��� ����� ��Ҹ� M���� �ʱ�ȭ���ش�. M���� ����ִٴ� ���� ������ ������ ������� ������ �ǹ�

	for(i=0;i<=N;i++){
		matrix[i][i]=0;
		timematrix[i][i]=0;
	}// �ڱ��ڽŰ��� �Ÿ��� �����Ƿ� 0�� ����

	
	mapSetting(matrix);
	mapSetting(timematrix);
		

	for(i=0;i<N;i++){
		printf("\n");
		for(j=0;j<N;j++){
			if(timematrix[i][j]==M||timematrix[i][j]==0){
				//printf("%3d ",timematrix[i][j]);
			}
			else {
				//printf("%3d ",time[matrix[i][j]-1]);
				timematrix[i][j]=time[matrix[i][j]-1];
			}
		}
	}//timematrix�� ������ �뼱�� �����Ǵ� ��� �ð��� time matrix�� ����

	while(1){

	gotoxy(15,44);
	gets(temp);//������ �Է�
	start = atoi(temp)-1;// �迭�� ÷�ڴ� ������ 1���� �ƴ� 0������ ���۵ǹǷ� ���������δ� -1�� ���� ����ȣ�� ���ȴ�.
		if(atoi(temp)>=1&&atoi(temp)<=43){
			break;
		}else{
			gotoprint(15,44,"    ");
			gotoprint(12,46,"1~43������ ���ڸ� �Է��ϼ���");
		}	
	}

	gotoprint(12,46,"                            ");


	for(i=0;i<N;i++)							// ����� ���� �� ������ �ʱ�ȭ �ϱ� ���� N��ŭ ������ ����
	{
		cost[i] = M;							// ���(����ڰ� ������ ��� -> i�� ������ ����� �ǹ�)
		solution[i] = 0;						// Ȯ���� ������� ���� (1�̶�� ����� ������ ���̻� �ĺ� ��尡 �ƴ��� �ǹ�)
	}
	cost[start] = 0;							// ������(start�� ���)���� ���������δ� �翬�� ����� 0



	for(i=0;i<N;i++)						// �� ����� ������ŭ ������ ����.
	{
		min = M;								// �켱 �ּҰ��� Maximum���� ���� ����
		for(j=0 ; j<N ; j++)					// ���� ������, ������ ���� ����� ����� �ּ��� ��带 ã�� ���� ����. 
		{
			if(solution[j]==0 && cost[j]<min)	//�����ִ� ���(solution[i]�� 0��)�� ��� �� ���� �ּҰ����� ������
			{	
				cur = j;						// ��� ��ȣ ���.
				min = cost[j];					// �� ����� �ּҰ����� ���
			}
		}
		solution[cur] = 1;						// ����� ����� ���� ������� ��ŷ. 

		if(min == M)							// min���� M(���Ѵ밪)�̸� ���� for������ �ּҰ��� ������ ���� ��, �� ������ �ȵǾ��ִٴ� �ǹ�
		{
			printf("�׷����� ����Ǿ����� ����.\n");
		}

		for(j=0;j<N ; j++)						// �ι�° ���� ������, �ּҺ���� Ȯ���ϱ� ���� �������̴�
		{
			if(solution[j] ==1)						// ���� ����� �� ����� �̹� Ȯ���� ����̶�� ����� �ʿ�����Ƿ�
				continue;							// �н�.
			if(cost[cur]+timematrix[cur][j] <cost[j])	// ���� ��庰�� ����� ���(���������κ�����)�� ������ �� �ּҺ���� ������ ������ �����
			{	
				cost[j] = cost[cur] + timematrix[cur][j];	// �� ������ ����� ��뺸�� ������ ������ �ش�. 
				index[j]=cur;
			}
			
		}
		index[start]=-1;
	}

	// ����� ��庰 ����� ȭ�鿡 ���
	
	while(1){

	gotoxy(35,44);
	gets(temp);//���� �Է�
	finish = atoi(temp)-1;// �迭�� ÷�ڴ� ������ 1���� �ƴ� 0������ ���۵ǹǷ� ���������δ� -1�� ���� ����ȣ�� ���ȴ�.
		if(atoi(temp)>=1&&atoi(temp)<=43){
			break;
		}else{
			gotoprint(35,44,"    ");
			gotoprint(12,46,"1~43������ ���ڸ� �Է��ϼ���");
		}	
	}

	gotoprint(12,46,"                            ");


	gotoxy(52,44);
	printf("�� %d�� %d�� \n ",cost[finish]/60,cost[finish]%60);
	
	
	cur=finish;
	
	patharray[0]=finish+1;
	i=1;
	while(index[cur]!=-1){
		patharray[i]=index[cur]+1;//�������� �迭�� �־���

		//printf(" %d",index[cur]+1);
		cur=index[cur];
		i++;
	};


	size=i-1;
	for(i=0;i<size;i++){
		linearray[i]=matrix[patharray[i]-1][patharray[i+1]-1];
		pathprint(linearray[i]);
	}

}

void getatmpath(){
	int time[62]={41,52,56,72,36,33,40,29,52,94,26,35,67,28,29,37,20,36,32,64,18,24,37,57,13,39,26,46,
					29,21,141,70,83,40,88,52,74,37,67,29,25,46,19,38,67,50,22,23,29,37,44,42,41,39,41,
					26,52,43,50,64,57,40};// �� �뼱�� �����Ǵ� �ð�(��)

	int matrix[N][N] = {0};
	int timematrix[N][N]={0};

	int patharray[20]={0};// ���ʴ�� ��带 ������ �迭
	int linearray[20]={0};// ���ʴ�� �뼱�� ������ �迭


	char temp[16];			// �׳� ���� ��带 �Է¹ޱ� ���� Ű���� �Է¿� ����
	int start, cur;			// ���� ���� ��� ��ȣ, ���� ó������ ��� ��ȣ�� ������ ����
	int i,j;				// �ݺ���(for)�� ������ ���� ����
	int min;				// ���� ó������ �ּҰ��� �����ϱ� ���� ����
	int cost[N];			// (����������) �� ������ ����� �����ϱ� ���� �迭����
	int solution[N];		// Ȯ���� �� (����� ����) ������� ǥ���ϴ� ���
	int index[N]={0};           // ��θ� �������� ����
	int size=0;
	int minatm=9999;
	int minnode=0;
	int atm[9]={10,22,23,31,6,9,43,36,40};//���к���,�л�ȸ��,21�����,�ߵ�,�̷���,���а�,�����,�ڿ����а�


	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			matrix[i][j]=M;
			timematrix[i][j]=M;
		}
	}// ��� ����� ��Ҹ� M���� �ʱ�ȭ���ش�. M���� ����ִٴ� ���� ������ ������ ������� ������ �ǹ�

	for(i=0;i<=N;i++){
		matrix[i][i]=0;
		timematrix[i][i]=0;
	}// �ڱ��ڽŰ��� �Ÿ��� �����Ƿ� 0�� ����

	
	mapSetting(matrix);
	mapSetting(timematrix);
		

	for(i=0;i<N;i++){
		printf("\n");
		for(j=0;j<N;j++){
			if(timematrix[i][j]==M||timematrix[i][j]==0){
				//printf("%3d ",timematrix[i][j]);
			}
			else {
				//printf("%3d ",time[matrix[i][j]-1]);
				timematrix[i][j]=time[matrix[i][j]-1];
			}
		}
	}//timematrix�� ������ �뼱�� �����Ǵ� ��� �ð��� time matrix�� ����

	while(1){
		gotoxy(15,44);
		gets(temp);//������ �Է�
		start = atoi(temp)-1;// �迭�� ÷�ڴ� ������ 1���� �ƴ� 0������ ���۵ǹǷ� ���������δ� -1�� ���� ����ȣ�� ���ȴ�.
			if(atoi(temp)>=1&&atoi(temp)<=43){
				break;
			}else{
				gotoprint(15,44,"    ");
				gotoprint(12,46,"1~43������ ���ڸ� �Է��ϼ���");
			}	
	}

	gotoprint(12,46,"                            ");


	for(i=0;i<N;i++)							// ����� ���� �� ������ �ʱ�ȭ �ϱ� ���� N��ŭ ������ ����
	{
		cost[i] = M;							// ���(����ڰ� ������ ��� -> i�� ������ ����� �ǹ�)
		solution[i] = 0;						// Ȯ���� ������� ���� (1�̶�� ����� ������ ���̻� �ĺ� ��尡 �ƴ��� �ǹ�)
	}
	cost[start] = 0;							// ������(start�� ���)���� ���������δ� �翬�� ����� 0

	for(i=0;i<N;i++)						// �� ����� ������ŭ ������ ����.
	{
		min = M;								// �켱 �ּҰ��� Maximum���� ���� ����
		for(j=0 ; j<N ; j++)					// ���� ������, ������ ���� ����� ����� �ּ��� ��带 ã�� ���� ����. 
		{
			if(solution[j]==0 && cost[j]<min)	//�����ִ� ���(solution[i]�� 0��)�� ��� �� ���� �ּҰ����� ������
			{	
				cur = j;						// ��� ��ȣ ���.
				min = cost[j];					// �� ����� �ּҰ����� ���
			}
		}
		solution[cur] = 1;						// ����� ����� ���� ������� ��ŷ. 

		if(min == M)							// min���� M(���Ѵ밪)�̸� ���� for������ �ּҰ��� ������ ���� ��, �� ������ �ȵǾ��ִٴ� �ǹ�
		{
			printf("�׷����� ����Ǿ����� ����.\n");
			return 1;
		}

		for(j=0;j<N ; j++)						// �ι�° ���� ������, �ּҺ���� Ȯ���ϱ� ���� �������̴�
		{
			if(solution[j] ==1)						// ���� ����� �� ����� �̹� Ȯ���� ����̶�� ����� �ʿ�����Ƿ�
				continue;							// �н�.
			if(cost[cur]+timematrix[cur][j] <cost[j])	// ���� ��庰�� ����� ���(���������κ�����)�� ������ �� �ּҺ���� ������ ������ �����
			{	
				cost[j] = cost[cur] + timematrix[cur][j];	// �� ������ ����� ��뺸�� ������ ������ �ش�. 
				index[j]=cur;
			}
			
		}
		index[start]=-1;
	}


	for(i=0;i<=8;i++){
		if(cost[atm[i]-1]<minatm){ 
			minatm=cost[atm[i]-1];
			minnode=atm[i];
		}
	}

	
	switch(minnode){
		case 10:
			gotoprint(32,44,"���к���");
			break;
		case 22:
			gotoprint(32,44,"�л�ȸ��");
			break;
		case 23:
			gotoprint(32,44,"�л�ȸ��");
			break;
		case 31:
			gotoprint(32,44,"21�����");
			break;
		case 6:
			gotoprint(32,44,"�߾ӵ�����");
			break;
		case 9:
			gotoprint(33,44,"�̷���");
			break;
		case 43:
			gotoprint(33,44,"���а�");
			break;
		case 36:
			gotoprint(32,44,"���������");
			break;
		case 40:
			gotoprint(32,44,"�ڿ����а�");
			break;
	}

	gotoxy(52,44);
	printf("�� %d�� %d�� \n ",minatm/60,minatm%60);
	
	cur=minnode-1;
	
	patharray[0]=minnode;
	i=1;

	while(index[cur]!=-1){
		patharray[i]=index[cur]+1;//�������� �迭�� �־���

		cur=index[cur];
		i++;
	};

	size=i-1;
	for(i=0;i<size;i++){
		linearray[i]=matrix[patharray[i]-1][patharray[i+1]-1];
		pathprint(linearray[i]);
	}

}
