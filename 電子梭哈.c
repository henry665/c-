/*電子梭哈*/
/*按順序 2345678910AJKQ */ 
#include<stdio.h> 
#include<stdlib.h>
#include<conio.h> 
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
