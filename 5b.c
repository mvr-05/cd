#include<stdio.h>
#include<string.h>
int st[20],top=-1; 
char input[20]; 
int encode(char ch){ 
	switch(ch) { 
		case 'i':return 0; 
		case '+':return 1; 
		case '*':return 2; 
		case '(':return 3; 
		case ')':return 4; 
		case '$':return 5; 
		case 'E':return 6; 
		case 'T':return 7; 
		case 'F':return 8; 
	} 
	return -1; 
} 
char decode(int n){
	switch(n){ 
		case 0:return('i'); 
		case 1:return('+'); 
		case 2:return('*'); 
		case 3:return('('); 
		case 4:return(')'); 
		case 5:return('$'); 
		case 6:return('E'); 
		case 7:return('T'); 
		case 8:return('F'); 
	}
	return 'z';
} 
void push(int n){ 
	st[++top]=n; 
} 
int pop(){ 
	return(st[top--]); 
} 
void display(int p,char *ptr){ 
	int l; 
	for(l=0;l<=top;l++){ 
		if(l%2==1) 
			printf("%c",decode(st[l])); 
		else 
			printf("%d",st[l]); 
	} 
	printf("\t"); 
	for(l=p;ptr[l];l++) 
		printf("%c",ptr[l]);
	printf("\n"); 
} 
int main(){ 
	char t1[20][20],pr[20][20],xy; 
	int inp[20],t2[20][20],gt[20][20],i,k,x,y,tx=0,ty=0,len;
	strcpy(pr[1],"E E+T"); 
	strcpy(pr[2],"E T"); 
	strcpy(pr[3],"T T*F"); 
	strcpy(pr[4],"T F"); 
	strcpy(pr[5],"F (E)"); 
	strcpy(pr[6],"F i"); 
	t2[2][1]=t2[2][4]=t2[2][5]=2; 
	t2[3][1]=t2[3][2]=t2[3][4]=t2[3][5]=4; 
	t2[5][1]=t2[5][2]=t2[5][4]=t2[5][5]=6; 
	t2[9][1]=t2[9][4]=t2[9][5]=1; 
	t2[10][1]=t2[10][2]=t2[10][4]=t2[10][5]=3; 
	t2[11][2]=t2[11][1]=t2[11][4]=t2[11][5]=5; 
	t1[2][1]=t1[2][4]=t1[2][5]='r'; 
	t1[3][1]=t1[3][2]=t1[3][4]='r'; 
	t1[3][5]=t1[5][1]=t1[5][2]='r'; 
	t1[5][4]=t1[5][5]=t1[9][1]=t1[9][4]='r'; 
	t1[9][5]=t1[10][1]=t1[10][2]=t1[10][4]=t1[10][5]='r'; 
	t1[11][1]=t1[11][4]=t1[11][2]=t1[11][5]='r'; 
	t1[0][0]=t1[4][0]=t1[6][0]=t1[7][0]=t1[0][3]=t1[4][3]=t1[6][3]='s'; 
	t1[2][2]=t1[9][2]=t1[8][4]=t1[1][1]=t1[8][1]=t1[7][3]='s'; 
	t1[1][5]='a'; 
	t2[0][0]=t2[4][0]=t2[6][0]=t2[7][0]=5;
	t2[0][3]=t2[4][3]=t2[6][3]=t2[7][3]=4;
	t2[2][2]=t2[9][2]=7; 
	t2[8][4]=11; 
	t2[1][1]=t2[8][1]=6; 
	gt[0][6]=1;
	gt[0][7]=gt[4][7]=2; 
	gt[0][8]=gt[4][8]=gt[6][8]=3; 
	gt[4][6]=8;gt[6][7]=9;gt[7][8]=10; 
	printf("Enter String: ");
	scanf("%s",input);
	for(k=0;input[k];k++){ 
		inp[k]=encode(input[k]); 
		if(input[k]<0||inp[k]>5) 
			printf("\n error in input"); 
	} 
	push(0); 
	i=0; 
	while(1){ 
		x=st[top];y=inp[i]; 
		display(i,input); 
		if(t1[x][y]=='a'){
			printf("String is Accepted \n");
			return 0; 
		}
		else if(t1[x][y]=='s'){
			push(inp[i]);
			push(t2[x][y]); 
			i++; 
		}
		else if(t1[x][y]=='r'){
			len=strlen(pr[t2[x][y]])-2; 
			xy=pr[t2[x][y]][0]; 
			ty=encode(xy); 
			for(k=1;k<=2*len;k++)	pop();
			tx=st[top];
			push(ty); 
			push(gt[tx][ty]);
		} 
		else 
			printf("\n error in parsing");
	}
}
