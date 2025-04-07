#include<stdio.h>
#include<ctype.h>
#include<string.h>
void Tp();
void Ep();
void E();
void T();
void check();
int count,flag;
char expr[10];
int main(){
  	count=0;
  	flag=0;
  	printf("\nEnter an Algebraic Expression:\t");
  	scanf("%s",expr);
  	E();
  	if((strlen(expr)==count)&&(flag==0))
    	printf("\nThe expression %s is valid\n",expr);
  	else
    	printf("\nThe expression %s is invalid\n",expr);
  	return 0;
}
void E(){
  	T();
  	Ep();
}
void T(){  
  	check();
  	Tp();
}
void Tp(){
  	if(expr[count]=='*'){
    	count++;
    	check();
    	Tp();
  	}
}
void check(){
  	if(isalnum(expr[count]))
    	count++;
  	else if(expr[count]=='('){
    	count++;
    	E();
    	if(expr[count]==')')	count++;
    	else	flag=1;
  	}
  	else	flag=1;
}
void Ep(){
  	if(expr[count]=='+'){    
    	count++;
    	T();
    	Ep();
  	}
}
