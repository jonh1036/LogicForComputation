#include "prototypes.h"

char p1[9], p2[9], p3[9], p4[9];

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
	
	arq = fopen("Dynamics.txt", "w");  // Cria um arquivo texto para gravação
	if (arq == NULL) {	printf("Problemas na CRIACAO do arquivo\n"); return;}
	
	fprintf(arq, "p ");
	fprintf(arq, "cnf ");
	if(cod == 1){
		fprintf(arq, "9 ");
		fprintf(arq, "3 ");	
		
		for(j=0;j<3;j++){
			fprintf(arq, "\n");
			for(i=0;i<6;i++){
				set(arq, i, j, cod);
			}
			fprintf(arq, "0");
		}
	}
	
	else if(cod == 2){
		fprintf(arq, "16 ");
		fprintf(arq, "4 \n");
		
		for(j=0;j<4;j++){
			fprintf(arq, "\n");
			for(i=0;i<8;i++){
				set(arq, i, j, cod);
			}
			fprintf(arq, "0");
		}
	}
	fclose(arq);
	printf("\n\n Salvo com sucesso!");
	exit(0);
}

void set(FILE *arq, int i, int j, int cod){
	if(j == 0){
		if(p1[i] == '1')
			fprintf(arq, "1 ");
		else if(p1[i] == '-')
			fprintf(arq, "-1 ");
	}
	else if(j == 1){
		if(p2[i] == '1')
			fprintf(arq, "1 ");
		else if(p2[i] == '-')
			fprintf(arq, "-1 ");
	}
	else if(j == 2){
		if(p3[i] == '1')
			fprintf(arq, "1 ");
		else if(p3[i] == '-')
			fprintf(arq, "-1 ");
	}
	if(cod == 2 && j == 3){
		if(p4[i] == '1')
			fprintf(arq, "1 ");
		else if(p4[i] == '-')
			fprintf(arq, "-1 ");
	}
}
