#include "prototypes.h"

char p1[9], p2[9], p3[9], p4[9];
int cont = 0;

int readFormat(int cod){
	system("cls");
	if(cod == 1){
		gets(p1);	gets(p2);	gets(p3);
	}
	else if(cod == 2){
		gets(p1);	gets(p2);	gets(p3);	gets(p4);
	}
	
	if(!check(cod)){
		printf("\nFORMATO INVALIDO!");
		sleep(2);
		return 0;
	}
}

int check(int cod){
	int i, j;
	
	if(cod == 1){
		for(j=0; j<4; j++){
			for(i=0; i<6; i++){
				if(j == 0){
					if(i%2==0 && (i>=0  && i<=4) && (p1[i] != '1' && p1[i] != '-'))
						return 0;
					if(i%2!=0 && (i>=1 && i<=3) && (p1[i]) != ',')
						return 0;
					if(p1[5] != ';')
						return 0;
				}
				else if(j == 1){
					if(i%2==0 && (i>=0  && i<=4) && (p2[i] != '1' && p2[i] != '-'))
						return 0;
					if(i%2!=0 && (i>=1 && i<=3) && (p2[i]) != ',')
						return 0;
					if(p2[5] != ';')
						return 0;
				}
				else if(j == 2){
					if(i%2==0 && (i>=0  && i<=4) && (p3[i] != '1' && p3[i] != '-'))
						return 0;
					if(i%2!=0 && (i>=1 && i<=3) && (p3[i]) != ',')
						return 0;
					if(p3[5] != ';')
						return 0;
				}
			}
		}
	}
	else if(cod == 2){
		for(j=0; j<5; j++){
			for(i=0; i<7; i++){
				if(j == 0){
					if(i%2==0 && (i>=0  && i<=6) && (p1[i] != '1' && p1[i] != '-'))
						return 0;
					if(i%2!=0 && (i>=1 && i<=5) && (p1[i]) != ',')
						return 0;
					if(p1[7] != ';')
						return 0;
				}
				else if(j == 1){
					if(i%2==0 && (i>=0  && i<=6) && (p2[i] != '1' && p2[i] != '-'))
						return 0;
					if(i%2!=0 && (i>=1 && i<=5) && (p2[i]) != ',')
						return 0;
					if(p2[7] != ';')
						return 0;
				}
				else if(j == 2){
					if(i%2==0 && (i>=0  && i<=6) && (p3[i] != '1' && p3[i] != '-'))
						return 0;
					if(i%2!=0 && (i>=1 && i<=5) && (p3[i]) != ',')
						return 0;
					if(p3[7] != ';')
						return 0;
				}
				else if(j == 3){
					if(i%2==0 && (i>=0  && i<=6) && (p4[i] != '1' && p4[i] != '-'))
						return 0;
					if(i%2!=0 && (i>=1 && i<=5) && (p4[i]) != ',')
						return 0;
					if(p4[7] != ';')
						return 0;
				}
			}
		}
	}
	return 1;
}

void fileHelperW(int cod) { //Helper de file, para escrever as marcações de minas nas proximidades
	FILE *arq;
	int i, j;
	
	arq = fopen("Dimacs.txt", "w");  // Cria um arquivo texto para gravação
	if (arq == NULL) {	printf("Problemas na CRIACAO do arquivo\n"); return;}
	
	fprintf(arq, "p ");
	fprintf(arq, "cnf ");
	if(cod == 1){
		fprintf(arq, "9 ");
		fprintf(arq, "31 ");	
		
		for(j=0;j<3;j++){
			fprintf(arq, "\n");
			for(i=0;i<6;i++){
				set(arq, i, j, cod);
			}
			fprintf(arq, "0");
		}
		fprintf(arq, "\n");
		fprintf(arq, "-1 -2 0\n-1 -3 0\n-2 -3 0\n-4 -5 0\n-4 -6 0\n-5 -6 0\n-7 -8 0\n-7 -9 0\n-8 -9 0\n");	//Restrições na linha
		fprintf(arq, "-1 -4 0\n-1 -7 0\n-4 -7 0\n-2 -5 0\n-2 -8 0\n-5 -8 0\n-3 -6 0\n-3 -9 0\n-6 -9 0\n");	//Restrições na coluna
		fprintf(arq, "-1 -5 0\n-1 -9 0\n-5 -9 0\n-2 -4 0\n-2 -6 0\n-3 -5 0\n-3 -7 0\n-5 -7 0\n-4 -8 0\n-6 -8 0\n");	//Restrições na diagonal
	}
	
	else if(cod == 2){
		fprintf(arq, "16 ");
		fprintf(arq, "77 ");
		
		for(j=0;j<4;j++){
			fprintf(arq, "\n");
			for(i=0;i<8;i++){
				set(arq, i, j, cod);
			}
			fprintf(arq, "0");
		}
		fprintf(arq, "\n");
		fprintf(arq, "-1 -2 0\n-1 -3 0\n-1 -4 0\n-2 -3 0\n-2 -4 0\n-3 -4 0\n-5 -6 0\n-5 -7 0\n-5 -8 0\n-6 -7 0\n-6 -8 0\n-7 -8 0\n-9 -10 0\n-9 -11 0\n-9 -12 0\n-10 -11 0\n-10 -12 0\n-11 -12 0\n-13 -14 0\n-13 -15 0\n-13 -16 0\n-14 -15 0\n-14 -16 0\n-15 -16 0\n");	//Restrições na linha
		fprintf(arq, "-1 -5 0\n-1 -9 0\n-1 -13 0\n-5 -9 0\n-5 -13 0\n-9 -13 0\n-2 -6 0\n-2 -10 0\n-2 -14 0\n-6 -10 0\n-6 -14 0\n-10 -14 0\n-3 -7 0\n-3 -11 0\n-3 -15 0\n-7 -11 0\n-7 -15 0\n-11 -15 0\n-4 -8 0\n-4 -12 0\n-4 -16 0\n-8 -12 0\n-8 -16 0\n-12 -16 0\n");	//Restrições na coluna
		fprintf(arq, "-1 -6 0\n-1 -11 0\n-1 -16 0\n-2 -5 0\n-2 -7 0\n-2 -12 0\n-3 -8 0\n-3 -6 0\n-3 -9 0\n-4 -7 0\n-4 -10 0\n-4 -13 0\n-5 -10 0\n-5 -15 0\n-6 -9 0\n-6 -11 0\n-7 -10 0\n-7 -12 0\n-8 -11 0\n-9 -14 0\n-10 -13 0\n-10 -15 0\n-11 -14 0\n-11 -16 0\n-8 -15 0\n");	//Restrições na diagonal
	}
	fclose(arq);
	printf("\n\n Salvo com sucesso!");
	exit(0);
}

void set(FILE *arq, int i, int j, int cod){
	if(j == 0){
		if(p1[i] == '1'){
			cont++;
			fprintf(arq, "%d ",cont);
		}
	}
	else if(j == 1){
		if(p2[i] == '1'){
			cont++;
			fprintf(arq, "%d ",cont);	
		}
	}
	else if(j == 2){
		if(p3[i] == '1'){
			cont++;
			fprintf(arq, "%d ",cont);	
		}
	}
	if(cod == 2 && j == 3){
		if(p4[i] == '1'){
			cont++;
			fprintf(arq, "%d ",cont);	
		}
	}
}
