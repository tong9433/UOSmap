
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

extern void gotoxy(int,int);
extern void gotoprint(int,int,char*);
extern void pathprint(int n);


#define N		43		// 노드의 수, 43개의 노드
#define M		999	// MAXIMUM을 의미

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
					26,52,43,50,64,57,40};// 각 노선에 대응되는 시간(초)

	int matrix[N][N] = {0};
	int timematrix[N][N]={0};

	int patharray[20]={0};// 차례대로 노드를 저장할 배열
	int linearray[20]={0};// 차례대로 노선을 저장할 배열


	char temp[16];			// 그냥 시작 노드를 입력받기 위한 키보드 입력용 버퍼
	int start, cur, finish;			// 각각 시작 노드 번호, 현재 처리중인 노드 번호를 저장할 변수
	int i,j;				// 반복문(for)을 돌리기 위한 변수
	int min;				// 현재 처리중인 최소값을 저장하기 위한 변수
	int cost[N];			// (시작점에서) 각 노드로의 비용을 저장하기 위한 배열변수
	int solution[N];		// 확정이 된 (계산이 끝난) 노드인지 표시하는 기능
	int index[N]={0};           // 경로를 저장해줄 변수
	int size=0;


	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			matrix[i][j]=M;
			timematrix[i][j]=M;
		}
	}// 모든 행렬의 요소를 M으로 초기화해준다. M값이 들어있다는 것은 각각의 노드들이 연결되지 않음을 의미

	for(i=0;i<=N;i++){
		matrix[i][i]=0;
		timematrix[i][i]=0;
	}// 자기자신과는 거리가 없으므로 0을 대입

	
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
	}//timematrix의 각각의 노선에 대응되는 경과 시간을 time matrix에 대입

	while(1){

	gotoxy(15,44);
	gets(temp);//시작점 입력
	start = atoi(temp)-1;// 배열의 첨자는 실제로 1번이 아닌 0번부터 시작되므로 내부적으로는 -1씩 작은 노드번호로 계산된다.
		if(atoi(temp)>=1&&atoi(temp)<=43){
			break;
		}else{
			gotoprint(15,44,"    ");
			gotoprint(12,46,"1~43까지의 숫자를 입력하세요");
		}	
	}

	gotoprint(12,46,"                            ");


	for(i=0;i<N;i++)							// 결과가 저장 될 공간을 초기화 하기 위해 N만큼 루프를 돈다
	{
		cost[i] = M;							// 비용(사용자가 지정한 노드 -> i번 노드로의 비용을 의미)
		solution[i] = 0;						// 확정된 노드인지 여부 (1이라면 계산이 끝나서 더이상 후보 노드가 아님을 의미)
	}
	cost[start] = 0;							// 시작점(start번 노드)에서 시작점으로는 당연히 비용이 0



	for(i=0;i<N;i++)						// 총 노드의 개수만큼 루프를 돈다.
	{
		min = M;								// 우선 최소값을 Maximum으로 놓고 시작
		for(j=0 ; j<N ; j++)					// 서브 루프문, 사용되지 않은 노드중 비용이 최소인 노드를 찾기 위한 것임. 
		{
			if(solution[j]==0 && cost[j]<min)	//남아있는 노드(solution[i]가 0인)의 비용 중 현재 최소값보다 작으면
			{	
				cur = j;						// 노드 번호 기록.
				min = cost[j];					// 그 비용을 최소값으로 기록
			}
		}
		solution[cur] = 1;						// 기록한 노드은 사용된 노드으로 마킹. 

		if(min == M)							// min값이 M(무한대값)이면 위의 for문에서 최소값을 구하지 못한 것, 즉 연결이 안되어있다는 의미
		{
			printf("그래프가 연결되어있지 않음.\n");
		}

		for(j=0;j<N ; j++)						// 두번째 서브 루프문, 최소비용을 확정하기 위한 루프문이다
		{
			if(solution[j] ==1)						// 새로 계산해 낼 노드이 이미 확정된 노드이라면 계산할 필요없으므로
				continue;							// 패스.
			if(cost[cur]+timematrix[cur][j] <cost[j])	// 현재 노드별로 저장된 비용(시작점으로부터의)과 위에서 얻어낸 최소비용을 가지는 노드과의 비용합
			{	
				cost[j] = cost[cur] + timematrix[cur][j];	// 이 이전에 저장된 비용보다 작으면 갱신해 준다. 
				index[j]=cur;
			}
			
		}
		index[start]=-1;
	}

	// 저장된 노드별 결과를 화면에 출력
	
	while(1){

	gotoxy(35,44);
	gets(temp);//끝점 입력
	finish = atoi(temp)-1;// 배열의 첨자는 실제로 1번이 아닌 0번부터 시작되므로 내부적으로는 -1씩 작은 노드번호로 계산된다.
		if(atoi(temp)>=1&&atoi(temp)<=43){
			break;
		}else{
			gotoprint(35,44,"    ");
			gotoprint(12,46,"1~43까지의 숫자를 입력하세요");
		}	
	}

	gotoprint(12,46,"                            ");


	gotoxy(52,44);
	printf("약 %d분 %d초 \n ",cost[finish]/60,cost[finish]%60);
	
	
	cur=finish;
	
	patharray[0]=finish+1;
	i=1;
	while(index[cur]!=-1){
		patharray[i]=index[cur]+1;//차례차례 배열에 넣어줌

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
					26,52,43,50,64,57,40};// 각 노선에 대응되는 시간(초)

	int matrix[N][N] = {0};
	int timematrix[N][N]={0};

	int patharray[20]={0};// 차례대로 노드를 저장할 배열
	int linearray[20]={0};// 차례대로 노선을 저장할 배열


	char temp[16];			// 그냥 시작 노드를 입력받기 위한 키보드 입력용 버퍼
	int start, cur;			// 각각 시작 노드 번호, 현재 처리중인 노드 번호를 저장할 변수
	int i,j;				// 반복문(for)을 돌리기 위한 변수
	int min;				// 현재 처리중인 최소값을 저장하기 위한 변수
	int cost[N];			// (시작점에서) 각 노드로의 비용을 저장하기 위한 배열변수
	int solution[N];		// 확정이 된 (계산이 끝난) 노드인지 표시하는 기능
	int index[N]={0};           // 경로를 저장해줄 변수
	int size=0;
	int minatm=9999;
	int minnode=0;
	int atm[9]={10,22,23,31,6,9,43,36,40};//대학본부,학생회관,21세기관,중도,미래관,법학관,정기관,자연과학관


	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			matrix[i][j]=M;
			timematrix[i][j]=M;
		}
	}// 모든 행렬의 요소를 M으로 초기화해준다. M값이 들어있다는 것은 각각의 노드들이 연결되지 않음을 의미

	for(i=0;i<=N;i++){
		matrix[i][i]=0;
		timematrix[i][i]=0;
	}// 자기자신과는 거리가 없으므로 0을 대입

	
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
	}//timematrix의 각각의 노선에 대응되는 경과 시간을 time matrix에 대입

	while(1){
		gotoxy(15,44);
		gets(temp);//시작점 입력
		start = atoi(temp)-1;// 배열의 첨자는 실제로 1번이 아닌 0번부터 시작되므로 내부적으로는 -1씩 작은 노드번호로 계산된다.
			if(atoi(temp)>=1&&atoi(temp)<=43){
				break;
			}else{
				gotoprint(15,44,"    ");
				gotoprint(12,46,"1~43까지의 숫자를 입력하세요");
			}	
	}

	gotoprint(12,46,"                            ");


	for(i=0;i<N;i++)							// 결과가 저장 될 공간을 초기화 하기 위해 N만큼 루프를 돈다
	{
		cost[i] = M;							// 비용(사용자가 지정한 노드 -> i번 노드로의 비용을 의미)
		solution[i] = 0;						// 확정된 노드인지 여부 (1이라면 계산이 끝나서 더이상 후보 노드가 아님을 의미)
	}
	cost[start] = 0;							// 시작점(start번 노드)에서 시작점으로는 당연히 비용이 0

	for(i=0;i<N;i++)						// 총 노드의 개수만큼 루프를 돈다.
	{
		min = M;								// 우선 최소값을 Maximum으로 놓고 시작
		for(j=0 ; j<N ; j++)					// 서브 루프문, 사용되지 않은 노드중 비용이 최소인 노드를 찾기 위한 것임. 
		{
			if(solution[j]==0 && cost[j]<min)	//남아있는 노드(solution[i]가 0인)의 비용 중 현재 최소값보다 작으면
			{	
				cur = j;						// 노드 번호 기록.
				min = cost[j];					// 그 비용을 최소값으로 기록
			}
		}
		solution[cur] = 1;						// 기록한 노드은 사용된 노드으로 마킹. 

		if(min == M)							// min값이 M(무한대값)이면 위의 for문에서 최소값을 구하지 못한 것, 즉 연결이 안되어있다는 의미
		{
			printf("그래프가 연결되어있지 않음.\n");
			return 1;
		}

		for(j=0;j<N ; j++)						// 두번째 서브 루프문, 최소비용을 확정하기 위한 루프문이다
		{
			if(solution[j] ==1)						// 새로 계산해 낼 노드이 이미 확정된 노드이라면 계산할 필요없으므로
				continue;							// 패스.
			if(cost[cur]+timematrix[cur][j] <cost[j])	// 현재 노드별로 저장된 비용(시작점으로부터의)과 위에서 얻어낸 최소비용을 가지는 노드과의 비용합
			{	
				cost[j] = cost[cur] + timematrix[cur][j];	// 이 이전에 저장된 비용보다 작으면 갱신해 준다. 
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
			gotoprint(32,44,"대학본부");
			break;
		case 22:
			gotoprint(32,44,"학생회관");
			break;
		case 23:
			gotoprint(32,44,"학생회관");
			break;
		case 31:
			gotoprint(32,44,"21세기관");
			break;
		case 6:
			gotoprint(32,44,"중앙도서관");
			break;
		case 9:
			gotoprint(33,44,"미래관");
			break;
		case 43:
			gotoprint(33,44,"법학관");
			break;
		case 36:
			gotoprint(32,44,"정보기술관");
			break;
		case 40:
			gotoprint(32,44,"자연과학관");
			break;
	}

	gotoxy(52,44);
	printf("약 %d분 %d초 \n ",minatm/60,minatm%60);
	
	cur=minnode-1;
	
	patharray[0]=minnode;
	i=1;

	while(index[cur]!=-1){
		patharray[i]=index[cur]+1;//차례차례 배열에 넣어줌

		cur=index[cur];
		i++;
	};

	size=i-1;
	for(i=0;i<size;i++){
		linearray[i]=matrix[patharray[i]-1][patharray[i+1]-1];
		pathprint(linearray[i]);
	}

}
