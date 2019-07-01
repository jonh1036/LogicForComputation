#include "functions.c"

void main(){
	int op, value;
	
	while(1){
		printf("\n(1) Mini Campo Minado 3x3\n(2) Mini Campo Minado 4x4\n\n");
		scanf("%d",&op);
		getchar();
		do{
			value = readFormat(op);	
		}while(!value);
		fileHelperW(op);
		system("cls");
	}
}
