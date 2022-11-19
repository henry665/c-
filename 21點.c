/*21點*/
#include<stdio.h> 
#include<stdlib.h>
#include<conio.h> 
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
