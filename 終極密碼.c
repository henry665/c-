#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int main (void){
	
	srand(time(0));
	int i,n[3];
	// i=答案的第幾個數 
	n[-1]=0;
	n[-2]=0;
	n[-3]=0;
	for (i=0;i<=3;i++){
		n[i] = (rand() % 9)+1;
		do{
			n[i] = (rand() % 9)+1;
		}while(n[i] == n[i-1] ||
		       n[i] == n[i-2] ||
		       n[i] == n[i-3] );	
	}
	//隨機取四個不重複的數
	int a,b,c,d,e,sum[3],A=0,B=0,C=0;
	sum[0]=0;
	sum[1]=0;
	sum[2]=0;
	sum[3]=0;
	
	printf("終極密碼");
	while(0!=1){
		printf(" \n");
/////////////////////////////////
//		printf("%d",n[0]);     //
//		printf("%d",n[1]);     //   
//		printf("%d",n[2]);     //
//		printf("%d",n[3]);     //
//////////print出答案//////////// 		
		printf("請輸入四位數整數 :");
		scanf("%d%d%d%d",&a,&b,&c,&d);
		sum[0]=a;
		sum[1]=b;
		sum[2]=c;
		sum[3]=d;
		printf("%d%d%d%d\t",a,b,c,d);
		//print出你所猜的數 
		if (n[0] == a){
			A=A+1;					
		}
		else if (n[0] == b || n[0] == c || n[0] == d ){
			B=B+1;
		}			
			if (n[1] == b){
				A=A+1;					
			}
			else if (n[1] == a || n[1] == c || n[1] == d ){
				B=B+1;
			}	
				if (n[2] == c){
					A=A+1;					
				}
				else if (n[2] == a || n[2] == b || n[2] == d ){
					B=B+1;
				}
			
					if (n[3] == d){
						A=A+1;					
					}
					else if (n[3] == a || n[3] == b || n[3] == c){
						B=B+1;
					}
					///////////////////////////////////////////////
							if ( a==9 && b==9 && c==9 && d==9){
								C=C-1;
								printf("答案:");
								for (i=0;i<=3;i++){
									printf("%d",n[i]);
									}
								printf("\n");
								}
					/////////////////////////////////////////////////金手指 
								
		printf("%dA%dB\n",A,B); //驗證目前幾A幾B 
		C=C+1;  //計算目前猜幾次 
		printf("目前總計%d次\n",C);

		if (A==4){
			printf("BINGO答對了");
			break;
		}
		A=0,B=0;  //讓遊戲的A和B樹歸零 
	}
	return 0;
	}
