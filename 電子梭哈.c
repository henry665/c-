/*�q�l����*/
/*������ 2345678910AJKQ */ 
#include<stdio.h> 
#include<stdlib.h>
#include<conio.h> 
void stud(){
	//���D// 
	printf("********************************************************\n");
	printf("*                         �q�l����		       *\n");
	printf("********************************************************\n\n");	
	
	int i,j,k,m,n,o,p,q;
	extern int money;//�]�w��l���B 
	int title[5]={100,500,1000,5000,10000};//������ﶵ 
	printf("\t\t");
	for(i=0;i<5;i++){
		printf("%d\t\t",title[i]);
	}//�L�X����ﶵ 
	printf("\n");
	printf("----------------------------------------------------------------------------------------\n");
	int num[9][5]={{25000,125000,250000,1250000,40000000},
				   {5000,25000,50000,250000,500000},
				   {2500,12500,25000,125000,250000},
				   {900,4500,9000,45000,90000},
				   {600,3000,6000,30000,60000},
				   {400,2000,4000,20000,40000},
				   {300,1500,3000,15000,30000},
				   {200,1000,2000,10000,20000},
				   {100,500,1000,5000,10000}};//��߲ܽv 
	char* type[9]={"�Ӯa�P�ᶶ","�P�ᶶ   ","�|�i     ",
				   "��Ī      ","�P��     ","���l     ",
				   "�T�i      ","���     ","�@��J�H�W"};//��ܱƫ� 
	for(j=0;j<9;j++){
		printf("%s",type[j]);
		for(k=0;k<5;k++){
			printf("\t%d\t",num[j][k]);
		}
		printf("\n");
	}
	printf("\n");
	//�i�ܱƫ��M�߲v 
	
	printf("�z�ثe�@��%d��\n",money);
	//��ܥثe���B
	int odds=999;//���H�K�]odd����l�Ȭ��@�Ӿ�����U����while�j��i�H�] 
	while( money>0 || odds!=404){
		if(money<=0){
			printf("�z�w���L����!�C������!\n");
			printf("�Ы��U���N��H�����C��"); 
			getch();
  			exit(0);
		}//�p�G���S�F�C���N����; 
		int final_odds[9];
		for(p=1;p<6;p++){
			printf("%d.%d\n",p,title[p-1]);
		}//�L�X�i�H��ܪ�����ﶵ 
		printf("%d.%s\n",404,"����");
		printf("�п�߲ܽv:");
		scanf("%d",&odds);
		if(odds<6 && odds>0){
			money=money-title[odds-1];
			printf("�ثe�ѤU%d��\n",money);
			for(q=0;q<9;q++){
			final_odds[q]=num[q][odds-1];
			}
		}//��ܧ��߲v����final_odds�̦s�J����������߲v�ﶵ 
		else if (odds==404 ){
			printf("\n�Ѿl%d��\n",money);
			printf("�C������\n");
			printf("�Ы��U���N��H��^�J�f");
			getch(); 
			system ("cls");
  			main();
		}//�p�G��J404�C������ 
		else {
			do {
				printf("�ЦA���s��J�@���ﶵ\n");
				scanf("%d",&odds);
			}while(!(odds<6 && odds>0 || odds==404));
			money=money-title[odds-1];
			printf("�z�ثe�ѤU%d��\n",money);
			for(q=0;q<9;q++){
			final_odds[q]=num[q][odds-1];
			}
		}//�p�G��J���ﶵ�A���{�����A���ƿ�J����אּ�� 
		if (money<0 ){
			printf("�z�w���L����!�C������!\n");
			printf("�Ы��U���N��H�����C��"); 
			getch();
  			exit(0);
		}//�p�G�A�������S���A�C������ 
	 	//��߲ܽv 
		srand(time(0)); 
		int poker_kinds[4]={6,3,4,5};//���J�P��������ascii : �®� ���� ��� ����
		int poker_points[13]={2,3,4,5,6,7,8,9,10,65,74,81,75};//���J�P���Ʀr���� : 2,3,4,5,6,7,8,9,10,A,J,K,Q 
		int answer_kinds[5]={0,0,0,0,0};//�]�m�@�ӹ�⪺���}�C 
		int answer_points[5]={0,0,0,0,0};//�]�m�@�ӹ�⪺�Ʀr�}�C 
		answer_kinds[-1]=0;
		answer_points[-1]=0;
		answer_kinds[-2]=0;
		answer_points[-2]=0;
		answer_kinds[-3]=0;
		answer_points[-3]=0;
		answer_kinds[-4]=0;
		answer_points[-4]=0;
		//	for(m=0;m<4;m++){
		//		for(n=0;n<14;n++){ 
		//			printf("%c%s ",poker_kinds[m],poker_points[n]);
		//		}
		//					printf("\n");
		//	}
		//�i��52�i���M�Ʀr 
		for(o=0;o<5;o++){
			do{
				answer_kinds[o] = poker_kinds[rand() % 4];
				answer_points[o] = poker_points[rand() % 13];//�H���⤭�i�P
			}while((answer_kinds[o] == answer_kinds[o-1] && answer_points[o] == answer_points[o-1]) ||
				   (answer_kinds[o] == answer_kinds[o-2] && answer_points[o] == answer_points[o-2]) || 
				   (answer_kinds[o] == answer_kinds[o-3] && answer_points[o] == answer_points[o-3]) || 
				   (answer_kinds[o] == answer_kinds[o-4] && answer_points[o] == answer_points[o-4]) );//�L�X�Ĥ@�����ƫ��A�åB���|���A���P�έ��� 
		}
		printf("\n");
		int x, y, temp_point,temp_kinds;

	    for(x=1; x<5; x++){
	        for(y=0; y<(5-x); y++){
	            if(answer_points[y] > answer_points[y+1]){
	                temp_point = answer_points[y];
	                temp_kinds = answer_kinds[y];
	                answer_points[y] = answer_points[y+1];
	                answer_kinds[y] = answer_kinds[y+1];
	                answer_points[y+1] = temp_point;
	                answer_kinds[y+1] = temp_kinds;
	            }  
	        }
	    }//�N�P���Ӥj�p�ƦC 
	    printf("�{�����P:\n");
	    int h;
	    for(h=0;h<5;h++){
	        if(answer_points[h] == 65 || answer_points[h] == 74 || answer_points[h] == 81|| answer_points[h] == 75 )
				printf("(%d)%c%c\t",h+1,answer_kinds[h],answer_points[h]);	
			else	   
				printf("(%d)%c%d\t",h+1,answer_kinds[h],answer_points[h]);
	    }//�p�G�Ʀr�O�^��N��%c�L�X�� 
		printf("\n");

		int r=0,answer;
		int abandon[6]={0,0,0,0,0,0};//�]�p�@�ӿ�J�˱�P���}�C 
		printf("�п�ܭn�˱󪺵P(�����˱�п�J0): ");
		do{
			scanf("%d",&answer);
			abandon[r]=answer;
			r++;
		}while(answer != 0 && answer < 6 && answer > 0);	//��J�n�˱󪺵P ����A��J0
		
		int s;
		for(s=0;s<5;s++){
			if(abandon[s] == 0){
				answer_kinds[s] == answer_kinds[s];
				answer_points[s] == answer_points[s];
			}
			if(abandon[s] == 1){
				do{
					answer_kinds[0] = poker_kinds[rand() % 4];
					answer_points[0] = poker_points[rand() % 13];
				}while(answer_kinds[0] == answer_kinds[1] && answer_points[0] == answer_points[1] ||
				       answer_kinds[0] == answer_kinds[2] && answer_points[0] == answer_points[2] || 
				       answer_kinds[0] == answer_kinds[3] && answer_points[0] == answer_points[3] || 
				       answer_kinds[0] == answer_kinds[4] && answer_points[0] == answer_points[4] );
			}
			if(abandon[s] == 2){
				do{
					   answer_kinds[1] = poker_kinds[rand() % 4];
					   answer_points[1] = poker_points[rand() % 13];
				}while(answer_kinds[1] == answer_kinds[0] && answer_points[1] == answer_points[0] ||
				       answer_kinds[1] == answer_kinds[2] && answer_points[1] == answer_points[2] || 
				       answer_kinds[1] == answer_kinds[3] && answer_points[1] == answer_points[3] || 
				       answer_kinds[1] == answer_kinds[4] && answer_points[1] == answer_points[4] );	
			}
			if(abandon[s] == 3){
				do{
					   answer_kinds[2] = poker_kinds[rand() % 4];
				   	   answer_points[2] = poker_points[rand() % 13];
				}while(answer_kinds[2] == answer_kinds[0] && answer_points[2] == answer_points[0] ||
				       answer_kinds[2] == answer_kinds[1] && answer_points[2] == answer_points[1] || 
				       answer_kinds[2] == answer_kinds[3] && answer_points[2] == answer_points[3] || 
				       answer_kinds[2] == answer_kinds[4] && answer_points[2] == answer_points[4] );
			}
			if(abandon[s] == 4){
				do{
					   answer_kinds[3] = poker_kinds[rand() % 4];
					   answer_points[3] = poker_points[rand() % 13];
				}while(answer_kinds[3] == answer_kinds[0] && answer_points[3] == answer_points[0] ||
				       answer_kinds[3] == answer_kinds[1] && answer_points[3] == answer_points[1] || 
				       answer_kinds[3] == answer_kinds[2] && answer_points[3] == answer_points[2] || 
				       answer_kinds[3] == answer_kinds[4] && answer_points[3] == answer_points[4] );
			}
			if(abandon[s] == 5){
				do{
					   answer_kinds[4] = poker_kinds[rand() % 4];
					   answer_points[4] = poker_points[rand() % 13];
				}while(answer_kinds[4] == answer_kinds[0] && answer_points[4] == answer_points[0] ||
				       answer_kinds[4] == answer_kinds[1] && answer_points[4] == answer_points[1] || 
				       answer_kinds[4] == answer_kinds[2] && answer_points[4] == answer_points[2] || 
				       answer_kinds[4] == answer_kinds[3] && answer_points[4] == answer_points[3] );	
			}
		}//�N�A���ﶵ�ҹ�������l���P���@�i�s���åB���|�P�Ĥ@���M�{�����P������ 
			int b,c;
			for(b=1; b<5; b++){
	        for(c=0; c<(5-b); c++){
	            if(answer_points[c] > answer_points[c+1]){
	                temp_point = answer_points[c];
	                temp_kinds = answer_kinds[c];
	                answer_points[c] = answer_points[c+1];
	                answer_kinds[c] = answer_kinds[c+1];
	                answer_points[c+1] = temp_point;
	                answer_kinds[c+1] = temp_kinds;
	            }  //�N���P�᪺�P���Ӥj�p�ƦC 
	        }
	    	}
	    	printf("\n���P���G:\n");
			int d;
			for(d=0;d<5;d++){
				if(answer_points[d] == 65 || answer_points[d] ==74 || answer_points[d] ==81 || answer_points[d] == 75)
					printf("(%d)%c%c\t",d+1,answer_kinds[d],answer_points[d]);	
				else	   
					printf("(%d)%c%d\t",d+1,answer_kinds[d],answer_points[d]);
			}//�C�L�X�@�ձ˱󧹫᪺�P 
			int decide;//�P�_�P��(�H�̤j�P���u��) 
			if (answer_kinds[0] == 6 && answer_kinds[1] == 6 && answer_kinds[2] == 6 && answer_kinds[3] == 6 && answer_kinds[4] == 6 &&
				answer_points[0] == 2 &&answer_points[1] == 65 && answer_points[2] == 74 && answer_points[3] == 75 &&answer_points[4] == 81 ){
				decide=1;
			}// �Ӯa�P�ᶶ �®�2AJKQ 
			else if ((answer_kinds[0] == answer_kinds[1] && answer_kinds[1] == answer_kinds[2] && answer_kinds[2] == answer_kinds[3] && answer_kinds[3] == answer_kinds[4]) &&
				     (answer_kinds[0] == 2 && answer_kinds[1] == 3 && answer_kinds[2] == 4 && answer_kinds[3] == 5 && answer_kinds[4] == 65 )||
				     (answer_kinds[0] == 3 && answer_kinds[1] == 4 && answer_kinds[2] == 5 && answer_kinds[3] == 6 && answer_kinds[4] == 7 )||
				     (answer_kinds[0] == 4 && answer_kinds[1] == 5 && answer_kinds[2] == 6 && answer_kinds[3] == 7 && answer_kinds[4] == 8 )||
				     (answer_kinds[0] == 5 && answer_kinds[1] == 6 && answer_kinds[2] == 7 && answer_kinds[3] == 8 && answer_kinds[4] == 9 )||
				     (answer_kinds[0] == 6 && answer_kinds[1] == 7 && answer_kinds[2] == 8 && answer_kinds[3] == 9 && answer_kinds[4] == 10 )||
				     (answer_kinds[0] == 7 && answer_kinds[1] == 8 && answer_kinds[2] == 9 && answer_kinds[3] == 10 && answer_kinds[4] == 74 )|| 
					 (answer_kinds[0] == 8 && answer_kinds[1] == 9 && answer_kinds[2] == 10 && answer_kinds[3] == 74 && answer_kinds[4] == 81 )||
					 (answer_kinds[0] == 9 && answer_kinds[1] == 10 && answer_kinds[2] == 74 && answer_kinds[3] == 75 && answer_kinds[4] == 81 )||
					 (answer_kinds[0] == 10 && answer_kinds[1] == 65 && answer_kinds[2] == 74 && answer_kinds[3] == 75 && answer_kinds[4] == 81 )||
					 (answer_kinds[0] == 2 && answer_kinds[1] == 65 && answer_kinds[2] == 74 && answer_kinds[3] == 75 && answer_kinds[4] == 81 )||
					 (answer_kinds[0] == 2 && answer_kinds[1] == 3 && answer_kinds[2] == 65 && answer_kinds[3] == 75 && answer_kinds[4] == 81 )){
	          decide=2;
			}//�P�ᶶ  2345678910AJKQ �����ǿ來�i(�i�HJKQA2)�åB�P���  
			else if ((answer_points[0] == answer_points[1] && answer_points[1] == answer_points[2] && answer_points[2] == answer_points[3])||
					 (answer_points[0] == answer_points[1] && answer_points[1] == answer_points[2] && answer_points[2] == answer_points[4])||
				     (answer_points[0] == answer_points[1] && answer_points[1] == answer_points[3] && answer_points[3] == answer_points[4])||
					 (answer_points[0] == answer_points[2] && answer_points[2] == answer_points[3] && answer_points[3] == answer_points[4])||
					 (answer_points[1] == answer_points[2] && answer_points[2] == answer_points[3] && answer_points[3] == answer_points[4] )){
				decide=3;
			}//�|�i �|�i�ۦP�Ʀr���P(�����K��)  
			else if ((answer_points[0] == answer_points[1] && answer_points[1] == answer_points[2] && answer_points[3] == answer_points[4])||
					 (answer_points[0] == answer_points[1] && answer_points[1] == answer_points[3] && answer_points[2] == answer_points[4])||
					 (answer_points[0] == answer_points[1] && answer_points[1] == answer_points[4] && answer_points[2] == answer_points[3])||
					 (answer_points[0] == answer_points[2] && answer_points[2] == answer_points[3] && answer_points[1] == answer_points[4])||
					 (answer_points[0] == answer_points[2] && answer_points[2] == answer_points[4] && answer_points[1] == answer_points[3])||
					 (answer_points[0] == answer_points[3] && answer_points[3] == answer_points[4] && answer_points[1] == answer_points[2])||
					 (answer_points[1] == answer_points[2] && answer_points[2] == answer_points[4] && answer_points[0] == answer_points[3])||
					 (answer_points[1] == answer_points[2] && answer_points[2] == answer_points[3] && answer_points[0] == answer_points[4])||
					 (answer_points[2] == answer_points[3] && answer_points[3] == answer_points[4] && answer_points[0] == answer_points[1])||
					 (answer_points[1] == answer_points[3] && answer_points[3] == answer_points[4] && answer_points[0] == answer_points[2])){
				decide=4;
			}//��Ī �T�i�ۦP�Ʀr���P�[�t�~��i�ۦP�Ʀr���P 
			else if (answer_kinds[0] == answer_kinds[1] && answer_kinds[1] == answer_kinds[2] && answer_kinds[2] == answer_kinds[3] &&
					 answer_kinds[3] == answer_kinds[4] && answer_kinds[4] == answer_kinds[0]){
				decide=5;
			}//�P�� ���i���ۦP 
			else if ((answer_kinds[0] == 2 && answer_kinds[1] == 3 && answer_kinds[2] == 4 && answer_kinds[3] == 5 && answer_kinds[4] == 65 )||
				     (answer_kinds[0] == 3 && answer_kinds[1] == 4 && answer_kinds[2] == 5 && answer_kinds[3] == 6 && answer_kinds[4] == 7 )||
				     (answer_kinds[0] == 4 && answer_kinds[1] == 5 && answer_kinds[2] == 6 && answer_kinds[3] == 7 && answer_kinds[4] == 8 )||
				     (answer_kinds[0] == 5 && answer_kinds[1] == 6 && answer_kinds[2] == 7 && answer_kinds[3] == 8 && answer_kinds[4] == 9 )||
				     (answer_kinds[0] == 6 && answer_kinds[1] == 7 && answer_kinds[2] == 8 && answer_kinds[3] == 9 && answer_kinds[4] == 10 )||
				     (answer_kinds[0] == 7 && answer_kinds[1] == 8 && answer_kinds[2] == 9 && answer_kinds[3] == 10 && answer_kinds[4] == 74 )|| 
					 (answer_kinds[0] == 8 && answer_kinds[1] == 9 && answer_kinds[2] == 10 && answer_kinds[3] == 74 && answer_kinds[4] == 81 )||
					 (answer_kinds[0] == 9 && answer_kinds[1] == 10 && answer_kinds[2] == 74 && answer_kinds[3] == 75 && answer_kinds[4] == 81 )||
					 (answer_kinds[0] == 10 && answer_kinds[1] == 65 && answer_kinds[2] == 74 && answer_kinds[3] == 75 && answer_kinds[4] == 81 )||
					 (answer_kinds[0] == 2 && answer_kinds[1] == 65 && answer_kinds[2] == 74 && answer_kinds[3] == 75 && answer_kinds[4] == 81 )||
					 (answer_kinds[0] == 2 && answer_kinds[1] == 3 && answer_kinds[2] == 65 && answer_kinds[3] == 75 && answer_kinds[4] == 81 )){
				decide=6;
			}//���l  2345678910AJKQ �����ǿ來�i(�i�HJKQA2) 
			else if ((answer_points[0] == answer_points[1] && answer_points[1] == answer_points[2] )||
					 (answer_points[0] == answer_points[1] && answer_points[1] == answer_points[3] )||
					 (answer_points[0] == answer_points[1] && answer_points[1] == answer_points[4] )||
					 (answer_points[0] == answer_points[2] && answer_points[2] == answer_points[3] )||
					 (answer_points[0] == answer_points[2] && answer_points[2] == answer_points[4] )||
					 (answer_points[0] == answer_points[3] && answer_points[3] == answer_points[4] )||
					 (answer_points[1] == answer_points[2] && answer_points[2] == answer_points[3] )||
					 (answer_points[1] == answer_points[2] && answer_points[2] == answer_points[4] )||
					 (answer_points[1] == answer_points[3] && answer_points[3] == answer_points[4] )||
					 (answer_points[2] == answer_points[3] && answer_points[3] == answer_points[4] )){
				decide=7;
			}//�T�i �T�i�ۦP�Ʀr���P
			else if ((answer_points[0] == answer_points[1]) && (answer_points[2] == answer_points[3] )||
					 (answer_points[0] == answer_points[1]) && (answer_points[2] == answer_points[4] )||
					 (answer_points[0] == answer_points[1]) && (answer_points[3] == answer_points[4] )||
					 (answer_points[0] == answer_points[2]) && (answer_points[1] == answer_points[3] )||
					 (answer_points[0] == answer_points[2]) && (answer_points[1] == answer_points[4] )||
					 (answer_points[0] == answer_points[2]) && (answer_points[3] == answer_points[4] )||
					 (answer_points[0] == answer_points[3]) && (answer_points[1] == answer_points[2] )||
					 (answer_points[0] == answer_points[3]) && (answer_points[1] == answer_points[4] )||
					 (answer_points[0] == answer_points[3]) && (answer_points[2] == answer_points[4] )||
					 (answer_points[1] == answer_points[2]) && (answer_points[3] == answer_points[4] )){
				decide=8;
			}// ��� ��i�ۦP�Ʀr���P�[�t�~��i�ۦP�Ʀr���P 
			else if ((answer_points[0] == answer_points[1] && answer_points[0]>65 )||
					 (answer_points[0] == answer_points[2] && answer_points[0]>65 )||
					 (answer_points[0] == answer_points[3] && answer_points[0]>65 )||
					 (answer_points[0] == answer_points[4] && answer_points[0]>65 )||
					 (answer_points[1] == answer_points[2] && answer_points[1]>65 )||
					 (answer_points[1] == answer_points[3] && answer_points[1]>65 )||
				 	 (answer_points[1] == answer_points[4] && answer_points[1]>65 )||
				 	 (answer_points[2] == answer_points[3] && answer_points[2]>65 )||
				 	 (answer_points[2] == answer_points[4] && answer_points[2]>65 )||
					 (answer_points[3] == answer_points[4] && answer_points[3]>65)){
				decide=9;
			}//�@��J�H�W ��i�ۦP�^�媺�P(���]�AA) 
			else{
				decide=10;
			}//�A���A�F 
			if (decide==1){
				money=money+num[0][odds-1];
				printf("\n�Ӯa�P�ᶶ�A���߱z��o%d��!\n\n",num[0][odds-1]);
				printf("�z�ثe�@��%d��\n",money);
			}
			else if (decide==2){
				money=money+num[1][odds-1];
				printf("\n�P�ᶶ�A���߱z��o%d��!\n\n",num[1][odds-1]);
				printf("�z�ثe�@��%d��\n",money);
			} 
			else if (decide==3){
				money=money+num[2][odds-1];
				printf("\n�|�i�A���߱z��o%d��!\n\n",num[2][odds-1]);
				printf("�z�ثe�@��%d��\n",money);
			}
			else if (decide==4){
				money=money+num[3][odds-1];
				printf("\n��Ī�A���߱z��o%d��!\n\n",num[3][odds-1]);
				printf("�z�ثe�@��%d��\n",money);
			}
			else if (decide==5){
				money=money+num[4][odds-1];
				printf("\n�P��A���߱z��o%d��!\n\n",num[4][odds-1]);
				printf("�z�ثe�@��%d��\n",money);
			}
			else if (decide==6){
				money=money+num[5][odds-1];
				printf("\n���l�A���߱z��o%d��!\n\n",num[5][odds-1]);
				printf("�z�ثe�@��%d��\n",money);
			}
			else if (decide==7){
				money=money+num[6][odds-1];
				printf("\n�T�i�A���߱z��o%d��!\n\n",num[6][odds-1]);
				printf("�z�ثe�@��%d��\n",money);
			}
			else if (decide==8){
				money=money+num[7][odds-1];
				printf("\n���A���߱z��o%d��!\n\n",num[7][odds-1]);
				printf("�z�ثe�@��%d��\n",money);
			}
			else if (decide==9){
				money=money+num[8][odds-1];
				printf("\n�@��J�H�W�A���߱z��o%d��!\n\n",num[8][odds-1]);
				printf("�z�ثe�@��%d��\n",money);
			}
			else if (decide==10){ 
				money=money;
				printf("\n�A���A�F!\n\n");
				printf("�z�ثe�ѤU%d��\n",money);
			}
		}
}
