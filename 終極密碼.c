#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int main (void){
	
	srand(time(0));
	int i,n[3];
	// i=���ת��ĴX�Ӽ� 
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
	//�H�����|�Ӥ����ƪ���
	int a,b,c,d,e,sum[3],A=0,B=0,C=0;
	sum[0]=0;
	sum[1]=0;
	sum[2]=0;
	sum[3]=0;
	
	printf("�׷��K�X");
	while(0!=1){
		printf(" \n");
/////////////////////////////////
//		printf("%d",n[0]);     //
//		printf("%d",n[1]);     //   
//		printf("%d",n[2]);     //
//		printf("%d",n[3]);     //
//////////print�X����//////////// 		
		printf("�п�J�|��ƾ�� :");
		scanf("%d%d%d%d",&a,&b,&c,&d);
		sum[0]=a;
		sum[1]=b;
		sum[2]=c;
		sum[3]=d;
		printf("%d%d%d%d\t",a,b,c,d);
		//print�X�A�Ҳq���� 
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
								printf("����:");
								for (i=0;i<=3;i++){
									printf("%d",n[i]);
									}
								printf("\n");
								}
					/////////////////////////////////////////////////����� 
								
		printf("%dA%dB\n",A,B); //���ҥثe�XA�XB 
		C=C+1;  //�p��ثe�q�X�� 
		printf("�ثe�`�p%d��\n",C);

		if (A==4){
			printf("BINGO����F");
			break;
		}
		A=0,B=0;  //���C����A�MB���k�s 
	}
	return 0;
	}
