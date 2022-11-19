/*老虎機*/
#include<stdio.h> 
#include<stdlib.h>
#include<conio.h> 
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
