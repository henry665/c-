void enter()
{
	//�]�w�ܼ�// 
	extern int money;
	char choose;
	//�[�J�C�����// 
	void stud();
	void slot();
	void points();
	//���D// 
	printf("******************************************\n");
	printf("*                ����J�f                *\n");
	printf("******************************************\n\n");	
	printf("              �w��Ө���!\n");
	printf("           �z�ثe�@��%d��\n",money);
	printf("       �аݱz���ѷQ�C�����عC���O?\n\n");
	printf("              1. �q�l����\n");
	printf("              2.  �Ѫ��\n");
	printf("              3.   21�I\n");
	printf("              4. ���}���\n\n");
	//��J�ﶵ// 
	do
	{
		printf("�п�J�ﶵ�Ʀr:");
		scanf("%d",&choose);
		switch(choose)
  		{
  			system ("cls");
	  		case 1:
	  			system ("cls");
	    		stud();
	   		 	system ("cls");
	   		 	break;
	  		case 2:
	  			system ("cls");
	  			slot();
	  			system ("cls");
	  			break;
			case 3:
				system ("cls");
				points();
	  			system ("cls");
	  			break;
	  		case 4:
	  			printf("\n���ݱz�U�����{!\n");
	  			printf("���U���N��H�����C��\n");
	  			break;	
 	   }
	}while(choose!=4);  //��J����4�A�h����`��// 
}
 
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

void slot()
{
	//���D// 
	printf("********************************************************\n");
	printf("                         �Ѫ��\n"							);
	printf("********************************************************\n\n");	
	//�W�h// 
	int i,j,k;
	extern int money;
	int title[30]={50,250,500}; 
	printf("\t\t");
	for(i=0;i<3;i++)
	{
		printf("%d\t\t",title[i]);
	}
	printf("\n-----------------------------------------------------\n");
	int num[8][3]={{5000,25000,75000},
				{2500,12500,25000},
				{1000,5000,10000},
				{500,2500,5000},
				{250,1250,2500},
				{150,750,1500},
				{100,500,1000},
				{50,250,500}};
	int type[6]={55,11,12,36,64,37};	//�U���ϥܹ�����ASCII�X//
	for(j=0;j<8;j++)
	{
		if(j==6)
			printf("%c%c%d",64,42,2);
		else if(j==7)
			printf("%c%c%d",37,42,2);
		else
			printf("%c%c%c",type[j],type[j],type[j]);
		for(k=0;k<3;k++)
		{
			printf("\t\t%d",num[j][k]);
		}
		printf("\n");
	}
	printf("\n");
	//�}�l�C��// 
   	int a,b,c,t;											 
   	printf("�z�ثe�@����%d\n",money);
	while(1)
	{		 
		//�U�`���B����//	
   		for(t=1;t<=3;t++)					
		{
			printf("%d.%d\n",t,title[t-1]);
		}
		printf("%d.%s\n",4,"�����C��");
		//��ܤU�`����// 
   		printf("�п�ܤU�`���B:");
		scanf("%d",&t);	
		while(1)
   		{ 
   			if(t<1||t>3&&t!=4)
   			{
   				do 			//��J���ŦX�ﶵ�A�X�{���ܨí��s��J// 
				{
				printf("�z����J���ŦX�ﶵ!�Э��s��J!\n�п�ܤU�`���B:"); 
				scanf("%d",&t);
				}
				while(t<1&&t>3&&t!=4);
			}
			else if(t==4)		//��J4�A�����C��// 
			{		
				printf("\n�����C��\n");				
   				printf("�z�ثe�@��%d��\n",money);
   				printf("���U���@��H��^�J�f"); 
				getch();
				system("cls"); 
				main();
			}
			else	//��J���T�A�����j��// 
				break;
		}
		//��L���G// 
		printf("\n���G�p�U\n");									
		srand(time(0));
		a=type[rand()%6];
  		b=type[rand()%6];
  		c=type[rand()%6];
  		printf("%c %c %c\n",a,b,c);
  		//�P�_�O�_�o���Τ�������// 
  		if(a==55 && b==55 && c==55)
  		{
      	 	printf("���F�Y��!\n");
   			printf("���߱zĹ�o%d��!\n",num[0][t-1]);
      		money=money+num[0][t-1];
      		printf("\n�z�ثe�@��%d��\n",money);
    	}
    	else if(a==11 && b==11 && c==11)
    	{
      	 	printf("���F�G����!\n");
   			printf("���߱zĹ�o%d��!\n",num[1][t-1]);
      		money=money+num[1][t-1];
      		printf("\n�z�ثe�@��%d��\n",money);
    	}
    	else if(a==12 && b==12 && c==12)
    	{
      	 	printf("���F�T����!\n");
   			printf("���߱zĹ�o%d��!\n",num[2][t-1]);
      		money=money+num[2][t-1];
      		printf("\n�z�ثe�@��%d��\n",money);
    	}
    	else if(a==36 && b==36 && c==36)
    	{
      	 	printf("���F�|����!\n");
   			printf("���߱zĹ�o%d��!\n",num[3][t-1]);
      		money=money+num[3][t-1];
      		printf("\n�z�ثe�@��%d��\n",money);
    	}
    	else if(a==64 && b==64 && c==64)
    	{
      	 	printf("���F������!\n");
   			printf("���߱zĹ�o%d��!\n",num[4][t-1]);
      		money=money+num[4][t-1];
      		printf("\n�z�ثe�@��%d��\n",money);
    	}
    	else if(a==37 && b==37 && c==37)
    	{
      	 	printf("���F������!\n");
   			printf("���߱zĹ�o%d��!\n",num[5][t-1]);
      		money=money+num[5][t-1];
      		printf("\n�z�ثe�@��%d��\n",money);
    	}
    	else if((a==64 && b==64 && c!=64)||(b==64 && c==64 && a!=64)||(a==64 && c==64 && b!=64))
    	{
      	 	printf("���F�C����!\n");
   			printf("���߱zĹ�o%d��!\n",num[6][t-1]);
      		money=money+num[6][t-1];
      		printf("\n�z�ثe�@��%d��\n",money);
    	}
    	else if((a==37 && b==37 && c!=37)||(b==37 && c==37 && a!=37)||(a==37 && c==37 && b!=37))
    	{
      	 	printf("���F�K����!\n");
   			printf("���߱zĹ�o%d��!\n",num[7][t-1]);
      		money=money+num[7][t-1];
      		printf("\n�z�ثe�@��%d��\n",money);
    	}
    	else
   	 	{	
    		printf("�ܿ�ѡA�z������\n");
    		printf("�z�l���F%d��!\n",title[t-1]);
    		money=money-title[t-1];
    		if(money<=0)		//�p�G�l���Ҧ������A�h�����C��// 
    		{
    			printf("�z�w���L����!�C������!\n");		 
				printf("�Ы��U���N��H�����C��"); 
    			getch();
				system("cls");
				exit(0);
    		}
    		else
    		{
    			printf("\n�z�ثe�ѤU%d��\n",money);
   		 	}
		}
	}
}

void points(){
	//���D// 
	printf("********************************************************\n");
	printf("*                         21�I		               *\n");
	printf("********************************************************\n\n");	
	//�W�h// 
	extern int money;
	
	int odds=999;//���H�K�]odd����l�Ȭ��@�Ӿ�����U����while�j��i�H�] 
	while( money>0 || odds!=404){
		if(money<=0){
			printf("�z�w���L����!�C������!\n");
			printf("�Ы��U���N��H�����C��"); 
			getch();
  			exit(0);
		}//�p�G���S�F�C���N����; 
		int title[5]={100,500,1000,5000,money};//������ﶵ(money�Oall in)
		int a,b,c;
		printf("�ثe�@��%d��\n",money);//��ܥثe���B
		for(a=1;a<6;a++){
			printf("%d.%d",a,title[a-1]);
			if(a==5)
				printf("\t all in");
			printf("\n");
		}//�L�X�i�H��ܪ�����ﶵ 
		printf("%d.%s\n",404,"����");
		printf("�п�߲ܽv:");
		scanf("%d",&odds);
		if(odds<6 && odds>0){
			money=money-title[odds-1];
			printf("\n�ثe�ѤU%d��\n",money);
			printf("\n");
		}//�p�G��J1~5�C���}�l�åB��������� 
		else if (odds==404 ){
			printf("\n�C������\n");
			printf("�z�ثe�@��%d��\n",money);
			printf("���U���N��H��^�J�f"); 
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
			printf("\n�ثe�ѤU%d��\n",money);
			printf("\n");
		}//�p�G��J���ﶵ�A���{�����A���ƿ�J����אּ�� 
		if (money<0 ){
			printf("�z�w���L����!�C������!\n");
			printf("�Ы��U���N��H�����C��");
			getch(); 
			exit(0) ;
		}//�p�G�A�������S���A�C������ 
	srand(time(0)); 
	int poker_kinds[4]={6,3,4,5};//���J�P��������ascii : �®� ���� ��� ����
	int poker_points[13]={2,3,4,5,6,7,8,9,10,65,74,81,75};//���J�P���Ʀr���� : 2,3,4,5,6,7,8,9,10,A,J,K,Q 
	int your_kinds[5]={0,0,0,0,0};//�]�m�@�ӹ�⪺���}�C 
	int your_points[5]={0,0,0,0,0};//�]�m�@�ӧA���Ʀr�}�C 
	int opponent_kinds[5]={0,0,0,0,0};//�]�m�@�ӹ�⪺���}�C 
	int opponent_points[5]={0,0,0,0,0};//�]�m�@�ӹ�⪺�Ʀr�}�C 
	int d,dd;
	do{
		for(d=0;d<5;d++){
			your_kinds[d] = poker_kinds[rand() % 4];
			your_points[d] = poker_points[rand() % 13];
		}//�H���⤭�i�A���P 
		for(dd=0;dd<5;dd++){
			opponent_kinds[dd] = poker_kinds[rand() % 4];
			opponent_points[dd] = poker_points[rand() % 13];
		}//�H���⤭�i�P��⪺�P
	}while(	(your_kinds[0]==opponent_kinds[0] && your_points[0]== opponent_points[0] )||
			(your_kinds[0]==opponent_kinds[1] && your_points[0]== opponent_points[1] )||
			(your_kinds[0]==opponent_kinds[2] && your_points[0]== opponent_points[2] )||
			(your_kinds[0]==opponent_kinds[3] && your_points[0]== opponent_points[3] )||
			(your_kinds[0]==opponent_kinds[4] && your_points[0]== opponent_points[4] )||
			(your_kinds[1]==opponent_kinds[0] && your_points[1]== opponent_points[0] )||
			(your_kinds[1]==opponent_kinds[1] && your_points[1]== opponent_points[1] )||
			(your_kinds[1]==opponent_kinds[2] && your_points[1]== opponent_points[2] )||
			(your_kinds[1]==opponent_kinds[3] && your_points[1]== opponent_points[3] )||
			(your_kinds[1]==opponent_kinds[4] && your_points[1]== opponent_points[4] )||
			(your_kinds[2]==opponent_kinds[0] && your_points[2]== opponent_points[0] )||
			(your_kinds[2]==opponent_kinds[1] && your_points[2]== opponent_points[1] )||
			(your_kinds[2]==opponent_kinds[2] && your_points[2]== opponent_points[2] )||
			(your_kinds[2]==opponent_kinds[3] && your_points[2]== opponent_points[3] )||
			(your_kinds[2]==opponent_kinds[4] && your_points[2]== opponent_points[4] )||
			(your_kinds[3]==opponent_kinds[0] && your_points[3]== opponent_points[0] )||
			(your_kinds[3]==opponent_kinds[1] && your_points[3]== opponent_points[1] )||
			(your_kinds[3]==opponent_kinds[2] && your_points[3]== opponent_points[2] )||
			(your_kinds[3]==opponent_kinds[3] && your_points[3]== opponent_points[3] )||
			(your_kinds[3]==opponent_kinds[4] && your_points[3]== opponent_points[4] )||
			(your_kinds[4]==opponent_kinds[0] && your_points[4]== opponent_points[0] )||
			(your_kinds[4]==opponent_kinds[1] && your_points[4]== opponent_points[1] )||
			(your_kinds[4]==opponent_kinds[2] && your_points[4]== opponent_points[2] )||
			(your_kinds[4]==opponent_kinds[3] && your_points[4]== opponent_points[3] )||
			(your_kinds[4]==opponent_kinds[4] && your_points[4]== opponent_points[4] )||
			(your_kinds[0]==opponent_kinds[1] && your_points[0]== opponent_points[1] )||
			(your_kinds[0]==opponent_kinds[2] && your_points[0]== opponent_points[2] )||
			(your_kinds[0]==opponent_kinds[3] && your_points[0]== opponent_points[3] )||
			(your_kinds[0]==opponent_kinds[4] && your_points[0]== opponent_points[4] )||
			(your_kinds[1]==opponent_kinds[2] && your_points[1]== opponent_points[2] )||
			(your_kinds[1]==opponent_kinds[3] && your_points[1]== opponent_points[3] )||
			(your_kinds[1]==opponent_kinds[4] && your_points[1]== opponent_points[4] )||
			(your_kinds[2]==opponent_kinds[3] && your_points[2]== opponent_points[3] )||
			(your_kinds[2]==opponent_kinds[4] && your_points[2]== opponent_points[4] )||
			(your_kinds[3]==opponent_kinds[4] && your_points[3]== opponent_points[4] )||
			(your_kinds[0]==opponent_kinds[1] && your_points[0]== opponent_points[1] )||
			(your_kinds[0]==opponent_kinds[2] && your_points[0]== opponent_points[2] )||
			(your_kinds[0]==opponent_kinds[3] && your_points[0]== opponent_points[3] )||
			(your_kinds[0]==opponent_kinds[4] && your_points[0]== opponent_points[4] )||
			(your_kinds[1]==opponent_kinds[2] && your_points[1]== opponent_points[2] )||
			(your_kinds[1]==opponent_kinds[3] && your_points[1]== opponent_points[3] )||
			(your_kinds[1]==opponent_kinds[4] && your_points[1]== opponent_points[4] )||
			(your_kinds[2]==opponent_kinds[3] && your_points[2]== opponent_points[3] )||
			(your_kinds[2]==opponent_kinds[4] && your_points[2]== opponent_points[4] )||
			(your_kinds[3]==opponent_kinds[4] && your_points[3]== opponent_points[4] ));//�ͦ��A���ƫ��M��⪺�ƫ��A�åB���|����̪��P������ 
	int e;
	printf("�z���P:");
	for(e=0;e<2;e++){
	        if(your_points[e] == 65 || your_points[e] == 74 || your_points[e] == 81|| your_points[e] == 75 )
				printf("(%d)%c%c\t",e+1,your_kinds[e],your_points[e]);	
			else	   
				printf("(%d)%c%d\t",e+1,your_kinds[e],your_points[e]);
	    }//�p�G�A���ƫ����Ʀr�O�^��N��%c�L�X�� 
	printf("\n");
	printf("\n");
	printf("��⪺�P:");
	    	if(opponent_points[0] == 65 || opponent_points[0] == 74 || opponent_points[0] == 81|| opponent_points[0] == 75 )
				printf("(%d)%c%c\t",1,opponent_kinds[0],opponent_points[0]);	
			else	   
				printf("(%d)%c%d\t",1,opponent_kinds[0],opponent_points[0]);
		//�p�G���ƫ����Ʀr�O�^��N��%c�L�X�� 
	printf("\n");		
	printf("\n");		
	char* then[4]={"���P","�����U�`","���P",}; 
	int f,answer,final_your=0,final_opponent=0;
		if(odds==5){
					printf("%d.%s",1,then[0]);
					printf("\n");
					printf("%d.%s",3,then[2]);
				}//�p�G��}�l��all in �h���|��������U�` 
		else
			for(f=0;f<3;f++){ 
					printf("%d.%s",f+1,then[f]);
					printf("\n");
				}//�L�X�i�H��ܪ��ﶵ 		
		printf("\n");

		printf("�п�ܤU�@�B:");
		scanf("%d",&answer);
		printf("\n");
		int g,h;
		if(answer!=1 && answer!=2 && answer!=3){
			do {
				printf("�ЦA���s��J�@���ﶵ: ");
				scanf("%d",&answer);
			}while(answer!=1 && answer!=2 && answer!=3);
		}//�p�G��J���ﶵ�A���{�����A���ƿ�J����אּ�� 
		
		if (answer==1){// answer==1(���P)
			printf("�z���P:");
			for(g=0;g<2;g++){
		        if(your_points[g] == 65 || your_points[g] == 74 || your_points[g] == 81|| your_points[g] == 75 )
					printf("(%d)%c%c\t",g+1,your_kinds[g],your_points[g]);	
				else	   
					printf("(%d)%c%d\t",g+1,your_kinds[g],your_points[g]);
		    }//�p�G�A���ƫ����Ʀr�O�^��N��%c�L�X�� 
		printf("\n");
		printf("\n");
		int j=0,jj=0,count1=2;	
			for(j=0;j<2;j++){
				if (opponent_points[j] == 65){
					final_opponent = final_opponent+10;
					if (final_opponent>21){
						final_opponent = final_opponent-10;
						final_opponent = final_opponent+1;
					}//�p�G�`�I�Ƥj��21�AA�N�ܥ[1 
				}//�p�G�I�ƬOA�N�[10 
				else if ((opponent_points[j] == 74) || (opponent_points[j] == 81) || (opponent_points[j] == 75)){
					final_opponent = final_opponent+10; 
				}//�p�G�I�ƬOJKQ�N�[10  
				else
					final_opponent = final_opponent + opponent_points[j];//�p�G�I�ƬO�Ʀr�N�[��Ʀr	 
		}//���⪺�P���I�ƥ[�_�� 
			while(final_opponent<15){
				count1++;
				final_opponent=0;
				for(jj=0;jj<count1;jj++){
					if (opponent_points[jj] == 65){
						final_opponent = final_opponent+10;
						if (final_opponent>21){
							final_opponent = final_opponent-10;
							final_opponent = final_opponent+1;
						}//�p�G�`�I�Ƥj��21�AA�N�ܥ[1 
					}//�p�G�I�ƬOA�N�[10
					else if ((opponent_points[jj] == 74) || (opponent_points[jj] == 81) || (opponent_points[jj] == 75)){
						final_opponent = final_opponent+10; 
					}//�p�G�I�ƬOJKQ�N�[10 
					else
						final_opponent = final_opponent + opponent_points[jj]; 
					//�p�G�I�ƬO�Ʀr�N�[��Ʀr
				}
			}//�p�G��⪺�P���I�Ƥp��15�N�A��P�A�����⪺�P���I�Ƥj��15�I�A���ۦA���⪺�P���I�ƥ[�_��
			printf("��⪺�P:");
			for(h=0;h<count1;h++){
		    	if(opponent_points[h] == 65 || opponent_points[h] == 74 || opponent_points[h] == 81|| opponent_points[h] == 75 )
					printf("(%d)%c%c\t",h+1,opponent_kinds[h],opponent_points[h]);	
				else	   
					printf("(%d)%c%d\t",h+1,opponent_kinds[h],opponent_points[h]);
			}//�p�G���ƫ����Ʀr�O�^��N��%c�L�X�� 
			
			printf("\n");
			printf("\n");
			int i=0;
			for(i=0;i<2;i++){
				if (your_points[i] == 65){
					final_your = final_your+10;
					if (final_your>21){
						final_your = final_your-10;
						final_your = final_your+1;
					}//�p�G�`�I�Ƥj��21�AA�N�ܥ[1
				}//�p�G�I�ƬOA�N�[10
				else if ((your_points[i] == 74) || (your_points[i] == 81) || (your_points[i] == 75)){
					final_your = final_your+10; 
				}//�p�G�I�ƬOJKQ�N�[10
				else
					final_your = final_your + your_points[i];//�p�G�I�ƬO�Ʀr�N�[��Ʀr 
		}//��A���P���I�ƥ[�_�� 
		printf("�z���I���`�M�O:%d\n\n",final_your);//�L�X�A���I�� 
		printf("��⪺�I���`�M�O:%d\n\n",final_opponent);//�L�X��⪺�I�� 
			
		if(((final_your>final_opponent) || (final_opponent>21)) && (final_your<22)){
			if(final_opponent>21){
				printf("��⪺�I�Ƥj��21�I\n");
			}
			printf("�zĹ�F!\n");
			printf("���߱z��o%d��\n\n",title[odds-1]*2);
			money=money+(title[odds-1]*2);
			final_your=0;
			final_opponent=0;
			
		}
		else if(((final_your<final_opponent) || (final_your>21)) && (final_opponent<22)){
			if(final_your>21){
				printf("�z���I�Ƥj��21�I\n");
			}
			printf("�ܿ�ѡA�z��F!\n\n");
			final_your=0;
			final_opponent=0;
		}
		else if((final_your==final_opponent)||(final_your<22)&&(final_opponent<22)){
			printf("����!\n\n");
			money=money+title[odds-1];
			final_your=0;
			final_opponent=0;
		}
	}
		else if (answer==2){// answer==1(�����U�`)
		int k,l;
			printf("�z���P:");
			for(k=0;k<3;k++){
	       		if(your_points[k] == 65 || your_points[k] == 74 || your_points[k] == 81|| your_points[k] == 75 )
					printf("(%d)%c%c\t",k+1,your_kinds[k],your_points[k]);	
				else	   
					printf("(%d)%c%d\t",k+1,your_kinds[k],your_points[k]);
	   		 }//�p�G�A���ƫ����Ʀr�O�^��N��%c�L�X�� 
		printf("\n");
		printf("\n");
		int n=0,nn=0,count2=2;
		
			for(n=0;n<2;n++){
				if (opponent_points[n] == 65){
					final_opponent = final_opponent+10;
					if (final_opponent>21){
						final_opponent = final_opponent-10;
						final_opponent = final_opponent+1;
					}//�p�G�`�I�Ƥj��21�AA�N�ܥ[1
				}//�p�G�I�ƬOA�N�[10
				else if ((opponent_points[n] == 74) || (opponent_points[n] == 81) || (opponent_points[n] == 75)){
					final_opponent = final_opponent+10; 
				}//�p�G�I�ƬOJKQ�N�[10
				else
					final_opponent = final_opponent + opponent_points[n];//�p�G�I�ƬO�Ʀr�N�[��Ʀr 
		}//���⪺�P���I�ƥ[�_�� 
				while(final_opponent<15){
					count2++;
					final_opponent=0;
					for(nn=0;nn<count2;nn++){
						if (opponent_points[nn] == 65){
							final_opponent = final_opponent+10;
							if (final_opponent>21){
								final_opponent = final_opponent-10;
								final_opponent = final_opponent+1;
							}//�p�G�`�I�Ƥj��21�AA�N�ܥ[1
						}//�p�G�I�ƬOA�N�[10
						else if ((opponent_points[nn] == 74) || (opponent_points[nn] == 81) || (opponent_points[nn] == 75)){
							final_opponent = final_opponent+10; 
						}//�p�G�I�ƬOJKQ�N�[10
						else
							final_opponent = final_opponent + opponent_points[nn];//�p�G�I�ƬO�Ʀr�N�[��Ʀr				 
					}
				}//�p�G��⪺�P���I�Ƥp��15�N�A��P�A�����⪺�P���I�Ƥj��15�I�A���ۦA���⪺�P���I�ƥ[�_�� 		
			printf("��⪺�P:");
			for(l=0;l<count2;l++){
		    	if(opponent_points[l] == 65 || opponent_points[l] == 74 || opponent_points[l] == 81|| opponent_points[l] == 75 )
					printf("(%d)%c%c\t",l+1,opponent_kinds[l],opponent_points[l]);	
				else	   
					printf("(%d)%c%d\t",l+1,opponent_kinds[l],opponent_points[l]);
			}//�p�G���ƫ����Ʀr�O�^��N��%c�L�X�� 
		printf("\n");
		printf("\n");		
		int m=0;				
			for(m=0;m<3;m++){
				if (your_points[m] == 65){
					final_your = final_your+10;
					if (final_your>21){
						final_your = final_your-10;
						final_your = final_your+1;
					}//�p�G�`�I�Ƥj��21�AA�N�ܥ[1
				}//�p�G�I�ƬOA�N�[10
				else if ((your_points[m] == 74) || (your_points[m] == 81) || (your_points[m] == 75)){
					final_your = final_your+10; 
				}//�p�G�I�ƬOJKQ�N�[10
				else
					final_your = final_your + your_points[m];//�p�G�I�ƬO�Ʀr�N�[��Ʀr 
		}//��A���P���I�ƥ[�_�� 
		printf("�z���I���`�M�O:%d\n\n",final_your);//�L�X�A���I�� 
		printf("��⪺�I���`�M�O:%d\n\n",final_opponent);//�L�X��⪺�I�� 	
				
		if(((final_your>final_opponent) || (final_opponent>21)) && (final_your<22)){
			if(final_opponent>21){
				printf("��⪺�I�Ƥj��21�I\n");
			}
			printf("�zĹ�F!\n");
			printf("���߱z��o%d��\n\n",title[odds-1]*2);
			money=money+(title[odds-1]*2);
			final_your=0;
			final_opponent=0;
			
		}
		else if(((final_your<final_opponent) || (final_your>21)) && (final_opponent<22)){
			if(final_your>21){
				printf("�z���I�Ƥj��21�I\n");
			}
			printf("�ܿ�ѡA�z��F!\n\n");
			final_your=0;
			final_opponent=0;
		}
		else if((final_your==final_opponent)&&(final_your<22)&&(final_opponent<22)){
			printf("����!\n\n");
			money=money+title[odds-1];
			final_your=0;
			final_opponent=0;
		}
	}
		else if (answer==3){// answer==3(�[�P)
				int o,p,pick_times=3;
				printf("�z���P:");
				for(o=0;o<pick_times;o++){
			        if(your_points[o] == 65 || your_points[o] == 74 || your_points[o] == 81|| your_points[o] == 75 )
						printf("(%d)%c%c\t",o+1,your_kinds[o],your_points[o]);	
					else	   
						printf("(%d)%c%d\t",o+1,your_kinds[o],your_points[o]);
			    }//�p�G�A���ƫ����Ʀr�O�^��N��%c�L�X�� 
				printf("\n");
				printf("\n");
				printf("��⪺�P:");
				for(p=0;p<1;p++){
			    	if(opponent_points[p] == 65 || opponent_points[p] == 74 || opponent_points[p] == 81|| opponent_points[p] == 75 )
						printf("(%d)%c%c\t",p+1,opponent_kinds[p],opponent_points[p]);	
					else	   
						printf("(%d)%c%d\t",p+1,opponent_kinds[p],opponent_points[p]);
				}//�p�G��⪺�ƫ����Ʀr�O�^��N��%c�L�X�� 
			printf("\n");				
			printf("1.���P\n");
			printf("3.���P\n");
			printf("�п�ܤU�@�B:");
			int after;
			scanf("%d",&after);
			printf("\n");
			if(after!=1 && after!=3){
				do {
					printf("�ЦA���s��J�@���ﶵ: ");
					scanf("%d",&after);
				}while(after!=1 && after!=3);
			}//�p�G��J���ﶵ�A���{�����A���ƿ�J����אּ�� 
			int q,r;
			if(after==1){//after==1(���P)
				printf("�z���P:");
				for(q=0;q<
				pick_times;q++){
			        if(your_points[q] == 65 || your_points[q] == 74 || your_points[q] == 81|| your_points[q] == 75 )
						printf("(%d)%c%c\t",q+1,your_kinds[q],your_points[q]);	
					else	   
						printf("(%d)%c%d\t",q+1,your_kinds[q],your_points[q]);
			    }//�p�G�A���ƫ����Ʀr�O�^��N��%c�L�X�� 
				printf("\n");
				printf("\n");
				int v=0,vv=0,count3=2;
				for(v=0;v<2;v++){
					if (opponent_points[v] == 65){
						final_opponent = final_opponent+10;
						if (final_opponent>21){
							final_opponent = final_opponent-10;
							final_opponent = final_opponent+1;
						}//�p�G�`�I�Ƥj��21�AA�N�ܥ[1
					}//�p�G�I�ƬOA�N�[10
					else if ((opponent_points[v] == 74) || (opponent_points[v] == 81) || (opponent_points[v] == 75)){
						final_opponent = final_opponent+10; 
					}//�p�G�I�ƬOJKQ�N�[10
					else
						final_opponent = final_opponent + opponent_points[v];//�p�G�I�ƬO�Ʀr�N�[��Ʀr 
				}//���⪺�P���I�ƥ[�_��
				while(final_opponent<15){
						count3++;
						final_opponent=0;
						for(vv=0;vv<count3;vv++){
							if (opponent_points[vv] == 65){
								final_opponent = final_opponent+10;
								if (final_opponent>21){
									final_opponent = final_opponent-10;
									final_opponent = final_opponent+1;
								}//�p�G�`�I�Ƥj��21�AA�N�ܥ[1 
							}//�p�G�I�ƬOA�N�[10
							else if ((opponent_points[vv] == 74) || (opponent_points[vv] == 81) || (opponent_points[vv] == 75)){
								final_opponent = final_opponent+10; 
							}//�p�G�I�ƬOJKQ�N�[10
							else
								final_opponent = final_opponent + opponent_points[vv]; 
						}//�p�G�I�ƬO�Ʀr�N�[��Ʀr
					}//�p�G��⪺�P���I�Ƥp��15�N�A��P�A�����⪺�P���I�Ƥj��15�I�A���ۦA���⪺�P���I�ƥ[�_��							
					printf("��⪺�P:");
					for(p=0;p<count3;p++){
				    	if(opponent_points[p] == 65 || opponent_points[p] == 74 || opponent_points[p] == 81|| opponent_points[p] == 75 )
							printf("(%d)%c%c\t",p+1,opponent_kinds[p],opponent_points[p]);	
						else	   
							printf("(%d)%c%d\t",p+1,opponent_kinds[p],opponent_points[p]);
					}//�p�G�A���ƫ����Ʀr�O�^��N��%c�L�X�� 
			}
			if(after==3){//after==1(�[�P)
				pick_times=4;
				printf("�z���P:");
				for(q=0;q<pick_times;q++){
			        if(your_points[q] == 65 || your_points[q] == 74 || your_points[q] == 81|| your_points[q] == 75 )
						printf("(%d)%c%c\t",q+1,your_kinds[q],your_points[q]);	
					else	   
						printf("(%d)%c%d\t",q+1,your_kinds[q],your_points[q]);
			    }//�p�G�A���ƫ����Ʀr�O�^��N��%c�L�X�� 
				printf("\n");
				printf("\n");
				printf("��⪺�P:");
				for(r=0;r<1;r++){
			    	if(opponent_points[r] == 65 || opponent_points[r] == 74 || opponent_points[r] == 81|| opponent_points[r] == 75 )
						printf("(%d)%c%c\t",r+1,opponent_kinds[r],opponent_points[r]);	
					else	   
						printf("(%d)%c%d\t",r+1,opponent_kinds[r],opponent_points[r]);
				}//�p�G��⪺�ƫ����Ʀr�O�^��N��%c�L�X��
				int after1;
				printf("\n");				
				printf("1.���P\n");
				printf("3.���P\n");
				printf("�п�ܤU�@�B:");
				scanf("%d",&after1);
				printf("\n");
				if(after1!=1 && after1!=3){
					do {
						printf("�ЦA���s��J�@���ﶵ: ");
						scanf("%d",&after1);
					}while(after1!=1 && after1!=3);
						}//�p�G��J���ﶵ�A���{�����A���ƿ�J����אּ�� 
				int s,t;
				if(after1==1){//after1==1(���P)
					pick_times=4;
					printf("�A���P:");
					for(s=0;s<pick_times;s++){
				        if(your_points[s] == 65 || your_points[s] == 74 || your_points[s] == 81|| your_points[s] == 75 )
							printf("(%d)%c%c\t",s+1,your_kinds[s],your_points[s]);	
						else	   
							printf("(%d)%c%d\t",s+1,your_kinds[s],your_points[s]);
				    }//�p�G�A���ƫ����Ʀr�O�^��N��%c�L�X�� 
					printf("\n");
					printf("\n");
				int v=0,vv=0,count3=2;
				for(v=0;v<2;v++){
					if (opponent_points[v] == 65){
						final_opponent = final_opponent+10;
						if (final_opponent>21){
							final_opponent = final_opponent-10;
							final_opponent = final_opponent+1;
						}//�p�G�`�I�Ƥj��21�AA�N�ܥ[1
					}//�p�G�I�ƬOA�N�[10
					else if ((opponent_points[v] == 74) || (opponent_points[v] == 81) || (opponent_points[v] == 75)){
						final_opponent = final_opponent+10; 
					}//�p�G�I�ƬOJKQ�N�[10
					else
						final_opponent = final_opponent + opponent_points[v];//�p�G�I�ƬO�Ʀr�N�[��Ʀr 
				}//���⪺�P���I�ƥ[�_��
				while(final_opponent<15){
						count3++;
						final_opponent=0;
						for(vv=0;vv<count3;vv++){
							if (opponent_points[vv] == 65){
								final_opponent = final_opponent+10;
								if (final_opponent>21){
									final_opponent = final_opponent-10;
									final_opponent = final_opponent+1;
								}//�p�G�`�I�Ƥj��21�AA�N�ܥ[1 
							}//�p�G�I�ƬOA�N�[10
							else if ((opponent_points[vv] == 74) || (opponent_points[vv] == 81) || (opponent_points[vv] == 75)){
								final_opponent = final_opponent+10; 
							}//�p�G�I�ƬOJKQ�N�[10
							else
								final_opponent = final_opponent + opponent_points[vv]; 
						}//�p�G�I�ƬO�Ʀr�N�[��Ʀr
					}//�p�G��⪺�P���I�Ƥp��15�N�A��P�A�����⪺�P���I�Ƥj��15�I�A���ۦA���⪺�P���I�ƥ[�_��
					printf("��⪺�P:");
					for(p=0;p<count3;p++){
				    	if(opponent_points[p] == 65 || opponent_points[p] == 74 || opponent_points[p] == 81|| opponent_points[p] == 75 )
							printf("(%d)%c%c\t",p+1,opponent_kinds[p],opponent_points[p]);	
						else	   
							printf("(%d)%c%d\t",p+1,opponent_kinds[p],opponent_points[p]);
					}//�p�G�A���ƫ����Ʀr�O�^��N��%c�L�X�� 
				}						
				if(after1==3){//after==1(�[�P)
					pick_times=5;
					printf("�z���P:");
					for(s=0;s<pick_times;s++){
				        if(your_points[s] == 65 || your_points[s] == 74 || your_points[s] == 81|| your_points[s] == 75 )
							printf("(%d)%c%c\t",s+1,your_kinds[s],your_points[s]);	
						else	   
							printf("(%d)%c%d\t",s+1,your_kinds[s],your_points[s]);
				    }//�p�G�A���ƫ����Ʀr�O�^��N��%c�L�X�� 
					printf("\n");
					printf("\n");
				int v=0,vv=0,count3=2;
				for(v=0;v<2;v++){
					if (opponent_points[v] == 65){
						final_opponent = final_opponent+10;
						if (final_opponent>21){
							final_opponent = final_opponent-10;
							final_opponent = final_opponent+1;
						}//�p�G�`�I�Ƥj��21�AA�N�ܥ[1
					}//�p�G�I�ƬOA�N�[10
					else if ((opponent_points[v] == 74) || (opponent_points[v] == 81) || (opponent_points[v] == 75)){
						final_opponent = final_opponent+10; 
					}//�p�G�I�ƬOJKQ�N�[10
					else
						final_opponent = final_opponent + opponent_points[v];//�p�G�I�ƬO�Ʀr�N�[��Ʀr 
				}//���⪺�P���I�ƥ[�_��
				while(final_opponent<15){
						count3++;
						final_opponent=0;
						for(vv=0;vv<count3;vv++){
							if (opponent_points[vv] == 65){
								final_opponent = final_opponent+10;
								if (final_opponent>21){
									final_opponent = final_opponent-10;
									final_opponent = final_opponent+1;
								}//�p�G�`�I�Ƥj��21�AA�N�ܥ[1 
							}//�p�G�I�ƬOA�N�[10
							else if ((opponent_points[vv] == 74) || (opponent_points[vv] == 81) || (opponent_points[vv] == 75)){
								final_opponent = final_opponent+10; 
							}//�p�G�I�ƬOJKQ�N�[10
							else
								final_opponent = final_opponent + opponent_points[vv]; 
						}//�p�G�I�ƬO�Ʀr�N�[��Ʀr
					}//�p�G��⪺�P���I�Ƥp��15�N�A��P�A�����⪺�P���I�Ƥj��15�I�A���ۦA���⪺�P���I�ƥ[�_��							
					printf("��⪺�P:");
					for(p=0;p<count3;p++){
				    	if(opponent_points[p] == 65 || opponent_points[p] == 74 || opponent_points[p] == 81|| opponent_points[p] == 75 )
							printf("(%d)%c%c\t",p+1,opponent_kinds[p],opponent_points[p]);	
						else	   
							printf("(%d)%c%d\t",p+1,opponent_kinds[p],opponent_points[p]);
					}//�p�G���ƫ����Ʀr�O�^��N��%c�L�X�� 
				}
			}
	 
			printf("\n");
			printf("\n");

			int u=0;
			for(u=0;u<pick_times;u++){
				if (your_points[u] == 65){
					final_your = final_your+10;
					if (final_your>21){
						final_your = final_your-10;
						final_your = final_your+1;
					}//�p�G�`�I�Ƥj��21�AA�N�ܥ[1
				}//�p�G�I�ƬOA�N�[10
				else if ((your_points[u] == 74) || (your_points[u] == 81) || (your_points[u] == 75)){
					final_your = final_your+10; 
				}//�p�G�I�ƬOJKQ�N�[10
				else
					final_your = final_your + your_points[u];//�p�G�I�ƬO�Ʀr�N�[��Ʀr 
		}//��A���P���I�ƥ[�_�� 
		printf("�z���I���`�M�O:%d\n\n",final_your);//�L�X�A���I�� 			
		printf("��⪺�I���`�M�O:%d\n\n",final_opponent);//�L�X��⪺�I�� 
			
		if(((final_your>final_opponent) || (final_opponent>21)) && (final_your<22)){
			if(final_opponent>21){
				printf("��⪺�I�Ƥj��21�I\n");
			}
			printf("�zĹ�F!\n");
			printf("���߱z��o%d��\n\n",title[odds-1]*2);
			money=money+(title[odds-1]*3);
			final_your=0;
			final_opponent=0;
			
		}
		else if(((final_your<final_opponent) || (final_your>21)) && (final_opponent<22)){
			if(final_your>21){
				printf("�z���I�Ƥj��21�I\n");
			}
			printf("�ܿ�ѡA�z��F!n\n");
			final_your=0;
			final_opponent=0;
		}
		else if((final_your==final_opponent)&&(final_your<22)&&(final_opponent<22)||
				((final_your>21)&&(final_opponent>21))){
			printf("����!\n\n");
			money=money+title[odds-1];
			final_your=0;
			final_opponent=0;
		
		}
	}		

		else
			money=money+title[odds-1];
	
	int finish;
	for(finish=0;finish<11;finish++){
		printf("\n");//�L�X11�Ӵ���Ÿ��H�K�e����� 
	}
	}
} 
