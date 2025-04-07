#include<stdio.h>
#include<string.h>
char stack[20],temp;
int top=-1;
void push(char item){
  	if(top>=20){
    	printf("STACK OVERFLOW");
    	return;
	}
  	stack[++top]=item;
}
char pop(){
  	if(top<=-1){
    	printf("STACK UNDERFLOW");
    	return ' ';
  	}
  	char c;
  	c=stack[top--];
  	printf("Popped element:%c\n",c);
  	return c;
}
char TOS(){
  return stack[top];
}
int convert(char item){
  	switch(item){
    	case 'i':return 0;
    	case '+':return 1;
    	case '*':return 2;
    	case '$':return 3;
  	}
}
int main(){
  	char pt[4][4]={
        {'-','>','>','>'},
        {'<','>','<','>'},
        {'<','>','>','>'},
        {'<','<','<','1'}};
  	char input[20];
  	int lkh=0;
  	printf("Enter input with $ at the end\n");
  	scanf("%s",input);
  	push('$');
  	while(lkh<=strlen(input)){
    	if(TOS()=='$'&&input[lkh]=='$'){
      		printf("SUCCESS\n");
      		return 1;
    	}
    	else if(pt[convert(TOS())][convert(input[lkh])]=='<'){
      		push(input[lkh]);
      		printf("Push---%c\n",input[lkh]);
    	  	lkh++;
    	}
    	else	pop();
  	}
  	return 0;
}
