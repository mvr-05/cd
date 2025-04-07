#include<stdio.h>
#include<string.h>
int stack[20],top=-1;
void push(int item){
	if(top>=20){
 		printf("stack overflow");
		return;
	}
	stack[++top]=item;
}
int pop(){
	int ch;
	if(top<=-1){
		printf("underflow");
		return ' ';
	}
	ch=stack[top--];
	return ch;
}
char convert(int item){
	char ch;
	switch(item){
		case 0:return('E');
		case 1:return('e');
		case 2:return('T');
		case 3:return('t');
		case 4:return('F');
		case 5:return('i');
		case 6:return('+');
		case 7:return('*');
		case 8:return('(');
		case 9:return(')');
		case 10:return('$');
	}
}
void main(){
	int m[10][10],i,j,k;
	char ips[20];
	int ip[10],a,b,t;
  	m[0][0]=m[0][3]=21;
  	m[1][1]=621;
  	m[1][4]=m[1][5]=-2;
  	m[2][0]=m[2][3]=43;
  	m[3][1]=m[3][4]=m[3][5]=-2;
  	m[3][2]=743;
  	m[4][0]=5;
  	m[4][3]=809;
	printf("\nenter the input string with $ at the end (Ex: i+i*i$): ");
	scanf("%s",ips);
	for(i=0;i<strlen(ips);i++){
		switch(ips[i]){
 			case 'E':k=0;break;
 			case 'e':k=1;break;
 			case 'T':k=2;break;
 			case 't':k=3;break;
 			case 'F':k=4;break;
 			case 'i':k=5;break;
 			case '+':k=6;break;
 			case '*':k=7;break;
 			case '(':k=8;break;
 			case ')':k=9;break;
 			case '$':k=10;break;
		}
		ip[i]=k;
	}
	ip[i]=-1;
	push(10);
	push(0);
	i=0;
	printf("\tstack\t\t input \n");
	while(1){
 		printf("\t");
 		for(j=0;j<=top;j++)
  			printf("%c",convert(stack[j]));
 		printf("\t\t");
		for(k=i;ip[k]!=-1;k++)
			printf("%c",convert(ip[k]));
		printf("\n");
		if(stack[top]==ip[i]){
			if(ip[i]==10){
				printf("\t\t success\n");
				return;
			}
			else{
 				top--;
 				i++;
			}
		}
		else if(stack[top]<=4&&stack[top]>=0){
 			a=stack[top];
 			b=ip[i]-5;
 			t=m[a][b];
 			top--;
			while(t>0){
				push(t%10);
				t=t/10;
			}
		}
		else{
			printf("error\n");
			return;
		}
	}
}
