/*�Ѫ��*/
#include<stdio.h> 
#include<stdlib.h>
#include<conio.h> 
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
