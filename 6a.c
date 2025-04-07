#include<stdio.h>
#define TOGETHER (8)
int main(void){ 
	int i = 0,entries = 15,repeat,left = 0;
	repeat = (entries / TOGETHER);
	left   = (entries % TOGETHER);
	while (repeat--){ 
		printf("process(%d)\n", i);
		printf("process(%d)\n", i + 1); 
		printf("process(%d)\n", i + 2); 
		printf("process(%d)\n", i + 3); 
		printf("process(%d)\n", i + 4); 
		printf("process(%d)\n", i + 5); 
		printf("process(%d)\n", i + 6); 
		printf("process(%d)\n", i + 7);
		i += TOGETHER; 
	}
	switch (left){
		case 7 : printf("process(%d)\n", i + 6);
		case 6 : printf("process(%d)\n", i + 5); 
		case 5 : printf("process(%d)\n", i + 4);  
		case 4 : printf("process(%d)\n", i + 3);  
		case 3 : printf("process(%d)\n", i + 2); 
		case 2 : printf("process(%d)\n", i + 1);
		case 1 : printf("process(%d)\n", i);
		case 0 : ;
	}
}
