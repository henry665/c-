void enter()
{
	//設定變數// 
	extern int money;
	char choose;
	//加入遊戲函數// 
	void stud();
	void slot();
	void points();
	//標題// 
	printf("******************************************\n");
	printf("*                賭場入口                *\n");
	printf("******************************************\n\n");	
	printf("              歡迎來到賭場!\n");
	printf("           您目前共有%d元\n",money);
	printf("       請問您今天想遊玩哪種遊戲呢?\n\n");
	printf("              1. 電子梭哈\n");
	printf("              2.  老虎機\n");
	printf("              3.   21點\n");
	printf("              4. 離開賭場\n\n");
	//輸入選項// 
	do
	{
		printf("請輸入選項數字:");
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
	  			printf("\n期待您下次光臨!\n");
	  			printf("按下任意鍵以關閉遊戲\n");
	  			break;	
 	   }
	}while(choose!=4);  //輸入不為4，則持續循環// 
}
 
void stud(){
	//標題// 
	printf("********************************************************\n");
	printf("*                         電子梭哈		       *\n");
	printf("********************************************************\n\n");	
	
	int i,j,k,m,n,o,p,q;
	extern int money;//設定初始金額 
	int title[5]={100,500,1000,5000,10000};//賭金的選項 
	printf("\t\t");
	for(i=0;i<5;i++){
		printf("%d\t\t",title[i]);
	}//印出賭金選項 
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
				   {100,500,1000,5000,10000}};//顯示賠率 
	char* type[9]={"皇家同花順","同花順   ","四張     ",
				   "葫蘆      ","同花     ","順子     ",
				   "三張      ","兩對     ","一對J以上"};//顯示排型 
	for(j=0;j<9;j++){
		printf("%s",type[j]);
		for(k=0;k<5;k++){
			printf("\t%d\t",num[j][k]);
		}
		printf("\n");
	}
	printf("\n");
	//展示排型和賠率 
	
	printf("您目前共有%d元\n",money);
	//顯示目前金額
	int odds=999;//先隨便設odd的初始值為一個整數讓下面的while迴圈可以跑 
	while( money>0 || odds!=404){
		if(money<=0){
			printf("您已身無分文!遊戲結束!\n");
			printf("請按下任意鍵以關閉遊戲"); 
			getch();
  			exit(0);
		}//如果錢沒了遊戲就結束; 
		int final_odds[9];
		for(p=1;p<6;p++){
			printf("%d.%d\n",p,title[p-1]);
		}//印出可以選擇的賭金選項 
		printf("%d.%s\n",404,"結束");
		printf("請選擇賠率:");
		scanf("%d",&odds);
		if(odds<6 && odds>0){
			money=money-title[odds-1];
			printf("目前剩下%d元\n",money);
			for(q=0;q<9;q++){
			final_odds[q]=num[q][odds-1];
			}
		}//選擇完賠率後讓final_odds裡存入賭金對應的賠率選項 
		else if (odds==404 ){
			printf("\n剩餘%d元\n",money);
			printf("遊戲結束\n");
			printf("請按下任意鍵以返回入口");
			getch(); 
			system ("cls");
  			main();
		}//如果輸入404遊戲結束 
		else {
			do {
				printf("請再重新輸入一次選項\n");
				scanf("%d",&odds);
			}while(!(odds<6 && odds>0 || odds==404));
			money=money-title[odds-1];
			printf("您目前剩下%d元\n",money);
			for(q=0;q<9;q++){
			final_odds[q]=num[q][odds-1];
			}
		}//如果輸入錯選項，讓程式讓你重複輸入直到對為止 
		if (money<0 ){
			printf("您已身無分文!遊戲結束!\n");
			printf("請按下任意鍵以關閉遊戲"); 
			getch();
  			exit(0);
		}//如果你的本金沒錢，遊戲結束 
	 	//選擇賠率 
		srand(time(0)); 
		int poker_kinds[4]={6,3,4,5};//撲克牌的花色對應ascii : 黑桃 紅心 方塊 梅花
		int poker_points[13]={2,3,4,5,6,7,8,9,10,65,74,81,75};//撲克牌的數字對應 : 2,3,4,5,6,7,8,9,10,A,J,K,Q 
		int answer_kinds[5]={0,0,0,0,0};//設置一個對手的花色陣列 
		int answer_points[5]={0,0,0,0,0};//設置一個對手的數字陣列 
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
		//展示52張花色和數字 
		for(o=0;o<5;o++){
			do{
				answer_kinds[o] = poker_kinds[rand() % 4];
				answer_points[o] = poker_points[rand() % 13];//隨機抽五張牌
			}while((answer_kinds[o] == answer_kinds[o-1] && answer_points[o] == answer_points[o-1]) ||
				   (answer_kinds[o] == answer_kinds[o-2] && answer_points[o] == answer_points[o-2]) || 
				   (answer_kinds[o] == answer_kinds[o-3] && answer_points[o] == answer_points[o-3]) || 
				   (answer_kinds[o] == answer_kinds[o-4] && answer_points[o] == answer_points[o-4]) );//印出第一輪的排型，並且不會讓你的牌形重複 
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
	    }//將牌按照大小排列 
	    printf("現有的牌:\n");
	    int h;
	    for(h=0;h<5;h++){
	        if(answer_points[h] == 65 || answer_points[h] == 74 || answer_points[h] == 81|| answer_points[h] == 75 )
				printf("(%d)%c%c\t",h+1,answer_kinds[h],answer_points[h]);	
			else	   
				printf("(%d)%c%d\t",h+1,answer_kinds[h],answer_points[h]);
	    }//如果數字是英文就用%c印出來 
		printf("\n");

		int r=0,answer;
		int abandon[6]={0,0,0,0,0,0};//設計一個輸入捨棄牌的陣列 
		printf("請選擇要捨棄的牌(結束捨棄請輸入0): ");
		do{
			scanf("%d",&answer);
			abandon[r]=answer;
			r++;
		}while(answer != 0 && answer < 6 && answer > 0);	//輸入要捨棄的牌 直到你輸入0
		
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
		}//將你的選項所對應的位子的牌換一張新的並且不會與第一輪和現有的牌的重複 
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
	            }  //將換牌後的牌按照大小排列 
	        }
	    	}
	    	printf("\n換牌結果:\n");
			int d;
			for(d=0;d<5;d++){
				if(answer_points[d] == 65 || answer_points[d] ==74 || answer_points[d] ==81 || answer_points[d] == 75)
					printf("(%d)%c%c\t",d+1,answer_kinds[d],answer_points[d]);	
				else	   
					printf("(%d)%c%d\t",d+1,answer_kinds[d],answer_points[d]);
			}//列印出一組捨棄完後的牌 
			int decide;//判斷牌行(以最大牌形優先) 
			if (answer_kinds[0] == 6 && answer_kinds[1] == 6 && answer_kinds[2] == 6 && answer_kinds[3] == 6 && answer_kinds[4] == 6 &&
				answer_points[0] == 2 &&answer_points[1] == 65 && answer_points[2] == 74 && answer_points[3] == 75 &&answer_points[4] == 81 ){
				decide=1;
			}// 皇家同花順 黑桃2AJKQ 
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
			}//同花順  2345678910AJKQ 按順序選五張(可以JKQA2)並且同花色  
			else if ((answer_points[0] == answer_points[1] && answer_points[1] == answer_points[2] && answer_points[2] == answer_points[3])||
					 (answer_points[0] == answer_points[1] && answer_points[1] == answer_points[2] && answer_points[2] == answer_points[4])||
				     (answer_points[0] == answer_points[1] && answer_points[1] == answer_points[3] && answer_points[3] == answer_points[4])||
					 (answer_points[0] == answer_points[2] && answer_points[2] == answer_points[3] && answer_points[3] == answer_points[4])||
					 (answer_points[1] == answer_points[2] && answer_points[2] == answer_points[3] && answer_points[3] == answer_points[4] )){
				decide=3;
			}//四張 四張相同數字的牌(類似鐵支)  
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
			}//葫蘆 三張相同數字的牌加另外兩張相同數字的牌 
			else if (answer_kinds[0] == answer_kinds[1] && answer_kinds[1] == answer_kinds[2] && answer_kinds[2] == answer_kinds[3] &&
					 answer_kinds[3] == answer_kinds[4] && answer_kinds[4] == answer_kinds[0]){
				decide=5;
			}//同花 五張花色相同 
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
			}//順子  2345678910AJKQ 按順序選五張(可以JKQA2) 
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
			}//三張 三張相同數字的牌
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
			}// 兩對 兩張相同數字的牌加另外兩張相同數字的牌 
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
			}//一對J以上 兩張相同英文的牌(不包括A) 
			else{
				decide=10;
			}//再接再厲 
			if (decide==1){
				money=money+num[0][odds-1];
				printf("\n皇家同花順，恭喜您獲得%d元!\n\n",num[0][odds-1]);
				printf("您目前共有%d元\n",money);
			}
			else if (decide==2){
				money=money+num[1][odds-1];
				printf("\n同花順，恭喜您獲得%d元!\n\n",num[1][odds-1]);
				printf("您目前共有%d元\n",money);
			} 
			else if (decide==3){
				money=money+num[2][odds-1];
				printf("\n四張，恭喜您獲得%d元!\n\n",num[2][odds-1]);
				printf("您目前共有%d元\n",money);
			}
			else if (decide==4){
				money=money+num[3][odds-1];
				printf("\n葫蘆，恭喜您獲得%d元!\n\n",num[3][odds-1]);
				printf("您目前共有%d元\n",money);
			}
			else if (decide==5){
				money=money+num[4][odds-1];
				printf("\n同花，恭喜您獲得%d元!\n\n",num[4][odds-1]);
				printf("您目前共有%d元\n",money);
			}
			else if (decide==6){
				money=money+num[5][odds-1];
				printf("\n順子，恭喜您獲得%d元!\n\n",num[5][odds-1]);
				printf("您目前共有%d元\n",money);
			}
			else if (decide==7){
				money=money+num[6][odds-1];
				printf("\n三張，恭喜您獲得%d元!\n\n",num[6][odds-1]);
				printf("您目前共有%d元\n",money);
			}
			else if (decide==8){
				money=money+num[7][odds-1];
				printf("\n兩對，恭喜您獲得%d元!\n\n",num[7][odds-1]);
				printf("您目前共有%d元\n",money);
			}
			else if (decide==9){
				money=money+num[8][odds-1];
				printf("\n一對J以上，恭喜您獲得%d元!\n\n",num[8][odds-1]);
				printf("您目前共有%d元\n",money);
			}
			else if (decide==10){ 
				money=money;
				printf("\n再接再厲!\n\n");
				printf("您目前剩下%d元\n",money);
			}
		}
}

void slot()
{
	//標題// 
	printf("********************************************************\n");
	printf("                         老虎機\n"							);
	printf("********************************************************\n\n");	
	//規則// 
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
	int type[6]={55,11,12,36,64,37};	//各類圖示對應的ASCII碼//
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
	//開始遊戲// 
   	int a,b,c,t;											 
   	printf("您目前共有為%d\n",money);
	while(1)
	{		 
		//下注金額類型//	
   		for(t=1;t<=3;t++)					
		{
			printf("%d.%d\n",t,title[t-1]);
		}
		printf("%d.%s\n",4,"結束遊戲");
		//選擇下注類型// 
   		printf("請選擇下注金額:");
		scanf("%d",&t);	
		while(1)
   		{ 
   			if(t<1||t>3&&t!=4)
   			{
   				do 			//輸入不符合選項，出現提示並重新輸入// 
				{
				printf("您的輸入不符合選項!請重新輸入!\n請選擇下注金額:"); 
				scanf("%d",&t);
				}
				while(t<1&&t>3&&t!=4);
			}
			else if(t==4)		//輸入4，結束遊戲// 
			{		
				printf("\n結束遊戲\n");				
   				printf("您目前共有%d元\n",money);
   				printf("按下任一鍵以返回入口"); 
				getch();
				system("cls"); 
				main();
			}
			else	//輸入正確，結束迴圈// 
				break;
		}
		//轉盤結果// 
		printf("\n結果如下\n");									
		srand(time(0));
		a=type[rand()%6];
  		b=type[rand()%6];
  		c=type[rand()%6];
  		printf("%c %c %c\n",a,b,c);
  		//判斷是否得獎及中獎類型// 
  		if(a==55 && b==55 && c==55)
  		{
      	 	printf("中了頭獎!\n");
   			printf("恭喜您贏得%d元!\n",num[0][t-1]);
      		money=money+num[0][t-1];
      		printf("\n您目前共有%d元\n",money);
    	}
    	else if(a==11 && b==11 && c==11)
    	{
      	 	printf("中了二等獎!\n");
   			printf("恭喜您贏得%d元!\n",num[1][t-1]);
      		money=money+num[1][t-1];
      		printf("\n您目前共有%d元\n",money);
    	}
    	else if(a==12 && b==12 && c==12)
    	{
      	 	printf("中了三等獎!\n");
   			printf("恭喜您贏得%d元!\n",num[2][t-1]);
      		money=money+num[2][t-1];
      		printf("\n您目前共有%d元\n",money);
    	}
    	else if(a==36 && b==36 && c==36)
    	{
      	 	printf("中了四等獎!\n");
   			printf("恭喜您贏得%d元!\n",num[3][t-1]);
      		money=money+num[3][t-1];
      		printf("\n您目前共有%d元\n",money);
    	}
    	else if(a==64 && b==64 && c==64)
    	{
      	 	printf("中了五等獎!\n");
   			printf("恭喜您贏得%d元!\n",num[4][t-1]);
      		money=money+num[4][t-1];
      		printf("\n您目前共有%d元\n",money);
    	}
    	else if(a==37 && b==37 && c==37)
    	{
      	 	printf("中了六等獎!\n");
   			printf("恭喜您贏得%d元!\n",num[5][t-1]);
      		money=money+num[5][t-1];
      		printf("\n您目前共有%d元\n",money);
    	}
    	else if((a==64 && b==64 && c!=64)||(b==64 && c==64 && a!=64)||(a==64 && c==64 && b!=64))
    	{
      	 	printf("中了七等獎!\n");
   			printf("恭喜您贏得%d元!\n",num[6][t-1]);
      		money=money+num[6][t-1];
      		printf("\n您目前共有%d元\n",money);
    	}
    	else if((a==37 && b==37 && c!=37)||(b==37 && c==37 && a!=37)||(a==37 && c==37 && b!=37))
    	{
      	 	printf("中了八等獎!\n");
   			printf("恭喜您贏得%d元!\n",num[7][t-1]);
      		money=money+num[7][t-1];
      		printf("\n您目前共有%d元\n",money);
    	}
    	else
   	 	{	
    		printf("很遺憾，您未中獎\n");
    		printf("您損失了%d元!\n",title[t-1]);
    		money=money-title[t-1];
    		if(money<=0)		//如果損失所有的錢，則結束遊戲// 
    		{
    			printf("您已身無分文!遊戲結束!\n");		 
				printf("請按下任意鍵以關閉遊戲"); 
    			getch();
				system("cls");
				exit(0);
    		}
    		else
    		{
    			printf("\n您目前剩下%d元\n",money);
   		 	}
		}
	}
}

void points(){
	//標題// 
	printf("********************************************************\n");
	printf("*                         21點		               *\n");
	printf("********************************************************\n\n");	
	//規則// 
	extern int money;
	
	int odds=999;//先隨便設odd的初始值為一個整數讓下面的while迴圈可以跑 
	while( money>0 || odds!=404){
		if(money<=0){
			printf("您已身無分文!遊戲結束!\n");
			printf("請按下任意鍵以關閉遊戲"); 
			getch();
  			exit(0);
		}//如果錢沒了遊戲就結束; 
		int title[5]={100,500,1000,5000,money};//賭金的選項(money是all in)
		int a,b,c;
		printf("目前共有%d元\n",money);//顯示目前金額
		for(a=1;a<6;a++){
			printf("%d.%d",a,title[a-1]);
			if(a==5)
				printf("\t all in");
			printf("\n");
		}//印出可以選擇的賭金選項 
		printf("%d.%s\n",404,"結束");
		printf("請選擇賠率:");
		scanf("%d",&odds);
		if(odds<6 && odds>0){
			money=money-title[odds-1];
			printf("\n目前剩下%d元\n",money);
			printf("\n");
		}//如果輸入1~5遊戲開始並且先扣掉賭金 
		else if (odds==404 ){
			printf("\n遊戲結束\n");
			printf("您目前共有%d元\n",money);
			printf("按下任意鍵以返回入口"); 
			getch(); 
			system ("cls");
  			main();
		}//如果輸入404遊戲結束 
		else {
			do {
				printf("請再重新輸入一次選項\n");
				scanf("%d",&odds);
			}while(!(odds<6 && odds>0 || odds==404));
			money=money-title[odds-1];
			printf("\n目前剩下%d元\n",money);
			printf("\n");
		}//如果輸入錯選項，讓程式讓你重複輸入直到對為止 
		if (money<0 ){
			printf("您已身無分文!遊戲結束!\n");
			printf("請按下任意鍵以關閉遊戲");
			getch(); 
			exit(0) ;
		}//如果你的本金沒錢，遊戲結束 
	srand(time(0)); 
	int poker_kinds[4]={6,3,4,5};//撲克牌的花色對應ascii : 黑桃 紅心 方塊 梅花
	int poker_points[13]={2,3,4,5,6,7,8,9,10,65,74,81,75};//撲克牌的數字對應 : 2,3,4,5,6,7,8,9,10,A,J,K,Q 
	int your_kinds[5]={0,0,0,0,0};//設置一個對手的花色陣列 
	int your_points[5]={0,0,0,0,0};//設置一個你的數字陣列 
	int opponent_kinds[5]={0,0,0,0,0};//設置一個對手的花色陣列 
	int opponent_points[5]={0,0,0,0,0};//設置一個對手的數字陣列 
	int d,dd;
	do{
		for(d=0;d<5;d++){
			your_kinds[d] = poker_kinds[rand() % 4];
			your_points[d] = poker_points[rand() % 13];
		}//隨機抽五張你的牌 
		for(dd=0;dd<5;dd++){
			opponent_kinds[dd] = poker_kinds[rand() % 4];
			opponent_points[dd] = poker_points[rand() % 13];
		}//隨機抽五張牌對手的牌
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
			(your_kinds[3]==opponent_kinds[4] && your_points[3]== opponent_points[4] ));//生成你的排型和對手的排型，並且不會讓兩者的牌型重複 
	int e;
	printf("您的牌:");
	for(e=0;e<2;e++){
	        if(your_points[e] == 65 || your_points[e] == 74 || your_points[e] == 81|| your_points[e] == 75 )
				printf("(%d)%c%c\t",e+1,your_kinds[e],your_points[e]);	
			else	   
				printf("(%d)%c%d\t",e+1,your_kinds[e],your_points[e]);
	    }//如果你的排型的數字是英文就用%c印出來 
	printf("\n");
	printf("\n");
	printf("對手的牌:");
	    	if(opponent_points[0] == 65 || opponent_points[0] == 74 || opponent_points[0] == 81|| opponent_points[0] == 75 )
				printf("(%d)%c%c\t",1,opponent_kinds[0],opponent_points[0]);	
			else	   
				printf("(%d)%c%d\t",1,opponent_kinds[0],opponent_points[0]);
		//如果對手排型的數字是英文就用%c印出來 
	printf("\n");		
	printf("\n");		
	char* then[4]={"停牌","雙倍下注","拿牌",}; 
	int f,answer,final_your=0,final_opponent=0;
		if(odds==5){
					printf("%d.%s",1,then[0]);
					printf("\n");
					printf("%d.%s",3,then[2]);
				}//如果剛開始選all in 則不會顯示雙倍下注 
		else
			for(f=0;f<3;f++){ 
					printf("%d.%s",f+1,then[f]);
					printf("\n");
				}//印出可以選擇的選項 		
		printf("\n");

		printf("請選擇下一步:");
		scanf("%d",&answer);
		printf("\n");
		int g,h;
		if(answer!=1 && answer!=2 && answer!=3){
			do {
				printf("請再重新輸入一次選項: ");
				scanf("%d",&answer);
			}while(answer!=1 && answer!=2 && answer!=3);
		}//如果輸入錯選項，讓程式讓你重複輸入直到對為止 
		
		if (answer==1){// answer==1(停牌)
			printf("您的牌:");
			for(g=0;g<2;g++){
		        if(your_points[g] == 65 || your_points[g] == 74 || your_points[g] == 81|| your_points[g] == 75 )
					printf("(%d)%c%c\t",g+1,your_kinds[g],your_points[g]);	
				else	   
					printf("(%d)%c%d\t",g+1,your_kinds[g],your_points[g]);
		    }//如果你的排型的數字是英文就用%c印出來 
		printf("\n");
		printf("\n");
		int j=0,jj=0,count1=2;	
			for(j=0;j<2;j++){
				if (opponent_points[j] == 65){
					final_opponent = final_opponent+10;
					if (final_opponent>21){
						final_opponent = final_opponent-10;
						final_opponent = final_opponent+1;
					}//如果總點數大於21，A就變加1 
				}//如果點數是A就加10 
				else if ((opponent_points[j] == 74) || (opponent_points[j] == 81) || (opponent_points[j] == 75)){
					final_opponent = final_opponent+10; 
				}//如果點數是JKQ就加10  
				else
					final_opponent = final_opponent + opponent_points[j];//如果點數是數字就加其數字	 
		}//把對手的牌的點數加起來 
			while(final_opponent<15){
				count1++;
				final_opponent=0;
				for(jj=0;jj<count1;jj++){
					if (opponent_points[jj] == 65){
						final_opponent = final_opponent+10;
						if (final_opponent>21){
							final_opponent = final_opponent-10;
							final_opponent = final_opponent+1;
						}//如果總點數大於21，A就變加1 
					}//如果點數是A就加10
					else if ((opponent_points[jj] == 74) || (opponent_points[jj] == 81) || (opponent_points[jj] == 75)){
						final_opponent = final_opponent+10; 
					}//如果點數是JKQ就加10 
					else
						final_opponent = final_opponent + opponent_points[jj]; 
					//如果點數是數字就加其數字
				}
			}//如果對手的牌的點數小於15就再抽牌，直到對手的牌的點數大於15點，接著再把對手的牌的點數加起來
			printf("對手的牌:");
			for(h=0;h<count1;h++){
		    	if(opponent_points[h] == 65 || opponent_points[h] == 74 || opponent_points[h] == 81|| opponent_points[h] == 75 )
					printf("(%d)%c%c\t",h+1,opponent_kinds[h],opponent_points[h]);	
				else	   
					printf("(%d)%c%d\t",h+1,opponent_kinds[h],opponent_points[h]);
			}//如果對手排型的數字是英文就用%c印出來 
			
			printf("\n");
			printf("\n");
			int i=0;
			for(i=0;i<2;i++){
				if (your_points[i] == 65){
					final_your = final_your+10;
					if (final_your>21){
						final_your = final_your-10;
						final_your = final_your+1;
					}//如果總點數大於21，A就變加1
				}//如果點數是A就加10
				else if ((your_points[i] == 74) || (your_points[i] == 81) || (your_points[i] == 75)){
					final_your = final_your+10; 
				}//如果點數是JKQ就加10
				else
					final_your = final_your + your_points[i];//如果點數是數字就加其數字 
		}//把你的牌的點數加起來 
		printf("您的點數總和是:%d\n\n",final_your);//印出你的點數 
		printf("對手的點數總和是:%d\n\n",final_opponent);//印出對手的點數 
			
		if(((final_your>final_opponent) || (final_opponent>21)) && (final_your<22)){
			if(final_opponent>21){
				printf("對手的點數大於21點\n");
			}
			printf("您贏了!\n");
			printf("恭喜您獲得%d元\n\n",title[odds-1]*2);
			money=money+(title[odds-1]*2);
			final_your=0;
			final_opponent=0;
			
		}
		else if(((final_your<final_opponent) || (final_your>21)) && (final_opponent<22)){
			if(final_your>21){
				printf("您的點數大於21點\n");
			}
			printf("很遺憾，您輸了!\n\n");
			final_your=0;
			final_opponent=0;
		}
		else if((final_your==final_opponent)||(final_your<22)&&(final_opponent<22)){
			printf("平手!\n\n");
			money=money+title[odds-1];
			final_your=0;
			final_opponent=0;
		}
	}
		else if (answer==2){// answer==1(雙倍下注)
		int k,l;
			printf("您的牌:");
			for(k=0;k<3;k++){
	       		if(your_points[k] == 65 || your_points[k] == 74 || your_points[k] == 81|| your_points[k] == 75 )
					printf("(%d)%c%c\t",k+1,your_kinds[k],your_points[k]);	
				else	   
					printf("(%d)%c%d\t",k+1,your_kinds[k],your_points[k]);
	   		 }//如果你的排型的數字是英文就用%c印出來 
		printf("\n");
		printf("\n");
		int n=0,nn=0,count2=2;
		
			for(n=0;n<2;n++){
				if (opponent_points[n] == 65){
					final_opponent = final_opponent+10;
					if (final_opponent>21){
						final_opponent = final_opponent-10;
						final_opponent = final_opponent+1;
					}//如果總點數大於21，A就變加1
				}//如果點數是A就加10
				else if ((opponent_points[n] == 74) || (opponent_points[n] == 81) || (opponent_points[n] == 75)){
					final_opponent = final_opponent+10; 
				}//如果點數是JKQ就加10
				else
					final_opponent = final_opponent + opponent_points[n];//如果點數是數字就加其數字 
		}//把對手的牌的點數加起來 
				while(final_opponent<15){
					count2++;
					final_opponent=0;
					for(nn=0;nn<count2;nn++){
						if (opponent_points[nn] == 65){
							final_opponent = final_opponent+10;
							if (final_opponent>21){
								final_opponent = final_opponent-10;
								final_opponent = final_opponent+1;
							}//如果總點數大於21，A就變加1
						}//如果點數是A就加10
						else if ((opponent_points[nn] == 74) || (opponent_points[nn] == 81) || (opponent_points[nn] == 75)){
							final_opponent = final_opponent+10; 
						}//如果點數是JKQ就加10
						else
							final_opponent = final_opponent + opponent_points[nn];//如果點數是數字就加其數字				 
					}
				}//如果對手的牌的點數小於15就再抽牌，直到對手的牌的點數大於15點，接著再把對手的牌的點數加起來 		
			printf("對手的牌:");
			for(l=0;l<count2;l++){
		    	if(opponent_points[l] == 65 || opponent_points[l] == 74 || opponent_points[l] == 81|| opponent_points[l] == 75 )
					printf("(%d)%c%c\t",l+1,opponent_kinds[l],opponent_points[l]);	
				else	   
					printf("(%d)%c%d\t",l+1,opponent_kinds[l],opponent_points[l]);
			}//如果對手排型的數字是英文就用%c印出來 
		printf("\n");
		printf("\n");		
		int m=0;				
			for(m=0;m<3;m++){
				if (your_points[m] == 65){
					final_your = final_your+10;
					if (final_your>21){
						final_your = final_your-10;
						final_your = final_your+1;
					}//如果總點數大於21，A就變加1
				}//如果點數是A就加10
				else if ((your_points[m] == 74) || (your_points[m] == 81) || (your_points[m] == 75)){
					final_your = final_your+10; 
				}//如果點數是JKQ就加10
				else
					final_your = final_your + your_points[m];//如果點數是數字就加其數字 
		}//把你的牌的點數加起來 
		printf("您的點數總和是:%d\n\n",final_your);//印出你的點數 
		printf("對手的點數總和是:%d\n\n",final_opponent);//印出對手的點數 	
				
		if(((final_your>final_opponent) || (final_opponent>21)) && (final_your<22)){
			if(final_opponent>21){
				printf("對手的點數大於21點\n");
			}
			printf("您贏了!\n");
			printf("恭喜您獲得%d元\n\n",title[odds-1]*2);
			money=money+(title[odds-1]*2);
			final_your=0;
			final_opponent=0;
			
		}
		else if(((final_your<final_opponent) || (final_your>21)) && (final_opponent<22)){
			if(final_your>21){
				printf("您的點數大於21點\n");
			}
			printf("很遺憾，您輸了!\n\n");
			final_your=0;
			final_opponent=0;
		}
		else if((final_your==final_opponent)&&(final_your<22)&&(final_opponent<22)){
			printf("平手!\n\n");
			money=money+title[odds-1];
			final_your=0;
			final_opponent=0;
		}
	}
		else if (answer==3){// answer==3(加牌)
				int o,p,pick_times=3;
				printf("您的牌:");
				for(o=0;o<pick_times;o++){
			        if(your_points[o] == 65 || your_points[o] == 74 || your_points[o] == 81|| your_points[o] == 75 )
						printf("(%d)%c%c\t",o+1,your_kinds[o],your_points[o]);	
					else	   
						printf("(%d)%c%d\t",o+1,your_kinds[o],your_points[o]);
			    }//如果你的排型的數字是英文就用%c印出來 
				printf("\n");
				printf("\n");
				printf("對手的牌:");
				for(p=0;p<1;p++){
			    	if(opponent_points[p] == 65 || opponent_points[p] == 74 || opponent_points[p] == 81|| opponent_points[p] == 75 )
						printf("(%d)%c%c\t",p+1,opponent_kinds[p],opponent_points[p]);	
					else	   
						printf("(%d)%c%d\t",p+1,opponent_kinds[p],opponent_points[p]);
				}//如果對手的排型的數字是英文就用%c印出來 
			printf("\n");				
			printf("1.停牌\n");
			printf("3.拿牌\n");
			printf("請選擇下一步:");
			int after;
			scanf("%d",&after);
			printf("\n");
			if(after!=1 && after!=3){
				do {
					printf("請再重新輸入一次選項: ");
					scanf("%d",&after);
				}while(after!=1 && after!=3);
			}//如果輸入錯選項，讓程式讓你重複輸入直到對為止 
			int q,r;
			if(after==1){//after==1(停牌)
				printf("您的牌:");
				for(q=0;q<
				pick_times;q++){
			        if(your_points[q] == 65 || your_points[q] == 74 || your_points[q] == 81|| your_points[q] == 75 )
						printf("(%d)%c%c\t",q+1,your_kinds[q],your_points[q]);	
					else	   
						printf("(%d)%c%d\t",q+1,your_kinds[q],your_points[q]);
			    }//如果你的排型的數字是英文就用%c印出來 
				printf("\n");
				printf("\n");
				int v=0,vv=0,count3=2;
				for(v=0;v<2;v++){
					if (opponent_points[v] == 65){
						final_opponent = final_opponent+10;
						if (final_opponent>21){
							final_opponent = final_opponent-10;
							final_opponent = final_opponent+1;
						}//如果總點數大於21，A就變加1
					}//如果點數是A就加10
					else if ((opponent_points[v] == 74) || (opponent_points[v] == 81) || (opponent_points[v] == 75)){
						final_opponent = final_opponent+10; 
					}//如果點數是JKQ就加10
					else
						final_opponent = final_opponent + opponent_points[v];//如果點數是數字就加其數字 
				}//把對手的牌的點數加起來
				while(final_opponent<15){
						count3++;
						final_opponent=0;
						for(vv=0;vv<count3;vv++){
							if (opponent_points[vv] == 65){
								final_opponent = final_opponent+10;
								if (final_opponent>21){
									final_opponent = final_opponent-10;
									final_opponent = final_opponent+1;
								}//如果總點數大於21，A就變加1 
							}//如果點數是A就加10
							else if ((opponent_points[vv] == 74) || (opponent_points[vv] == 81) || (opponent_points[vv] == 75)){
								final_opponent = final_opponent+10; 
							}//如果點數是JKQ就加10
							else
								final_opponent = final_opponent + opponent_points[vv]; 
						}//如果點數是數字就加其數字
					}//如果對手的牌的點數小於15就再抽牌，直到對手的牌的點數大於15點，接著再把對手的牌的點數加起來							
					printf("對手的牌:");
					for(p=0;p<count3;p++){
				    	if(opponent_points[p] == 65 || opponent_points[p] == 74 || opponent_points[p] == 81|| opponent_points[p] == 75 )
							printf("(%d)%c%c\t",p+1,opponent_kinds[p],opponent_points[p]);	
						else	   
							printf("(%d)%c%d\t",p+1,opponent_kinds[p],opponent_points[p]);
					}//如果你的排型的數字是英文就用%c印出來 
			}
			if(after==3){//after==1(加牌)
				pick_times=4;
				printf("您的牌:");
				for(q=0;q<pick_times;q++){
			        if(your_points[q] == 65 || your_points[q] == 74 || your_points[q] == 81|| your_points[q] == 75 )
						printf("(%d)%c%c\t",q+1,your_kinds[q],your_points[q]);	
					else	   
						printf("(%d)%c%d\t",q+1,your_kinds[q],your_points[q]);
			    }//如果你的排型的數字是英文就用%c印出來 
				printf("\n");
				printf("\n");
				printf("對手的牌:");
				for(r=0;r<1;r++){
			    	if(opponent_points[r] == 65 || opponent_points[r] == 74 || opponent_points[r] == 81|| opponent_points[r] == 75 )
						printf("(%d)%c%c\t",r+1,opponent_kinds[r],opponent_points[r]);	
					else	   
						printf("(%d)%c%d\t",r+1,opponent_kinds[r],opponent_points[r]);
				}//如果對手的排型的數字是英文就用%c印出來
				int after1;
				printf("\n");				
				printf("1.停牌\n");
				printf("3.拿牌\n");
				printf("請選擇下一步:");
				scanf("%d",&after1);
				printf("\n");
				if(after1!=1 && after1!=3){
					do {
						printf("請再重新輸入一次選項: ");
						scanf("%d",&after1);
					}while(after1!=1 && after1!=3);
						}//如果輸入錯選項，讓程式讓你重複輸入直到對為止 
				int s,t;
				if(after1==1){//after1==1(停牌)
					pick_times=4;
					printf("你的牌:");
					for(s=0;s<pick_times;s++){
				        if(your_points[s] == 65 || your_points[s] == 74 || your_points[s] == 81|| your_points[s] == 75 )
							printf("(%d)%c%c\t",s+1,your_kinds[s],your_points[s]);	
						else	   
							printf("(%d)%c%d\t",s+1,your_kinds[s],your_points[s]);
				    }//如果你的排型的數字是英文就用%c印出來 
					printf("\n");
					printf("\n");
				int v=0,vv=0,count3=2;
				for(v=0;v<2;v++){
					if (opponent_points[v] == 65){
						final_opponent = final_opponent+10;
						if (final_opponent>21){
							final_opponent = final_opponent-10;
							final_opponent = final_opponent+1;
						}//如果總點數大於21，A就變加1
					}//如果點數是A就加10
					else if ((opponent_points[v] == 74) || (opponent_points[v] == 81) || (opponent_points[v] == 75)){
						final_opponent = final_opponent+10; 
					}//如果點數是JKQ就加10
					else
						final_opponent = final_opponent + opponent_points[v];//如果點數是數字就加其數字 
				}//把對手的牌的點數加起來
				while(final_opponent<15){
						count3++;
						final_opponent=0;
						for(vv=0;vv<count3;vv++){
							if (opponent_points[vv] == 65){
								final_opponent = final_opponent+10;
								if (final_opponent>21){
									final_opponent = final_opponent-10;
									final_opponent = final_opponent+1;
								}//如果總點數大於21，A就變加1 
							}//如果點數是A就加10
							else if ((opponent_points[vv] == 74) || (opponent_points[vv] == 81) || (opponent_points[vv] == 75)){
								final_opponent = final_opponent+10; 
							}//如果點數是JKQ就加10
							else
								final_opponent = final_opponent + opponent_points[vv]; 
						}//如果點數是數字就加其數字
					}//如果對手的牌的點數小於15就再抽牌，直到對手的牌的點數大於15點，接著再把對手的牌的點數加起來
					printf("對手的牌:");
					for(p=0;p<count3;p++){
				    	if(opponent_points[p] == 65 || opponent_points[p] == 74 || opponent_points[p] == 81|| opponent_points[p] == 75 )
							printf("(%d)%c%c\t",p+1,opponent_kinds[p],opponent_points[p]);	
						else	   
							printf("(%d)%c%d\t",p+1,opponent_kinds[p],opponent_points[p]);
					}//如果你的排型的數字是英文就用%c印出來 
				}						
				if(after1==3){//after==1(加牌)
					pick_times=5;
					printf("您的牌:");
					for(s=0;s<pick_times;s++){
				        if(your_points[s] == 65 || your_points[s] == 74 || your_points[s] == 81|| your_points[s] == 75 )
							printf("(%d)%c%c\t",s+1,your_kinds[s],your_points[s]);	
						else	   
							printf("(%d)%c%d\t",s+1,your_kinds[s],your_points[s]);
				    }//如果你的排型的數字是英文就用%c印出來 
					printf("\n");
					printf("\n");
				int v=0,vv=0,count3=2;
				for(v=0;v<2;v++){
					if (opponent_points[v] == 65){
						final_opponent = final_opponent+10;
						if (final_opponent>21){
							final_opponent = final_opponent-10;
							final_opponent = final_opponent+1;
						}//如果總點數大於21，A就變加1
					}//如果點數是A就加10
					else if ((opponent_points[v] == 74) || (opponent_points[v] == 81) || (opponent_points[v] == 75)){
						final_opponent = final_opponent+10; 
					}//如果點數是JKQ就加10
					else
						final_opponent = final_opponent + opponent_points[v];//如果點數是數字就加其數字 
				}//把對手的牌的點數加起來
				while(final_opponent<15){
						count3++;
						final_opponent=0;
						for(vv=0;vv<count3;vv++){
							if (opponent_points[vv] == 65){
								final_opponent = final_opponent+10;
								if (final_opponent>21){
									final_opponent = final_opponent-10;
									final_opponent = final_opponent+1;
								}//如果總點數大於21，A就變加1 
							}//如果點數是A就加10
							else if ((opponent_points[vv] == 74) || (opponent_points[vv] == 81) || (opponent_points[vv] == 75)){
								final_opponent = final_opponent+10; 
							}//如果點數是JKQ就加10
							else
								final_opponent = final_opponent + opponent_points[vv]; 
						}//如果點數是數字就加其數字
					}//如果對手的牌的點數小於15就再抽牌，直到對手的牌的點數大於15點，接著再把對手的牌的點數加起來							
					printf("對手的牌:");
					for(p=0;p<count3;p++){
				    	if(opponent_points[p] == 65 || opponent_points[p] == 74 || opponent_points[p] == 81|| opponent_points[p] == 75 )
							printf("(%d)%c%c\t",p+1,opponent_kinds[p],opponent_points[p]);	
						else	   
							printf("(%d)%c%d\t",p+1,opponent_kinds[p],opponent_points[p]);
					}//如果對手排型的數字是英文就用%c印出來 
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
					}//如果總點數大於21，A就變加1
				}//如果點數是A就加10
				else if ((your_points[u] == 74) || (your_points[u] == 81) || (your_points[u] == 75)){
					final_your = final_your+10; 
				}//如果點數是JKQ就加10
				else
					final_your = final_your + your_points[u];//如果點數是數字就加其數字 
		}//把你的牌的點數加起來 
		printf("您的點數總和是:%d\n\n",final_your);//印出你的點數 			
		printf("對手的點數總和是:%d\n\n",final_opponent);//印出對手的點數 
			
		if(((final_your>final_opponent) || (final_opponent>21)) && (final_your<22)){
			if(final_opponent>21){
				printf("對手的點數大於21點\n");
			}
			printf("您贏了!\n");
			printf("恭喜您獲得%d元\n\n",title[odds-1]*2);
			money=money+(title[odds-1]*3);
			final_your=0;
			final_opponent=0;
			
		}
		else if(((final_your<final_opponent) || (final_your>21)) && (final_opponent<22)){
			if(final_your>21){
				printf("您的點數大於21點\n");
			}
			printf("很遺憾，您輸了!n\n");
			final_your=0;
			final_opponent=0;
		}
		else if((final_your==final_opponent)&&(final_your<22)&&(final_opponent<22)||
				((final_your>21)&&(final_opponent>21))){
			printf("平手!\n\n");
			money=money+title[odds-1];
			final_your=0;
			final_opponent=0;
		
		}
	}		

		else
			money=money+title[odds-1];
	
	int finish;
	for(finish=0;finish<11;finish++){
		printf("\n");//印出11個換行符號以便畫面整齊 
	}
	}
} 
