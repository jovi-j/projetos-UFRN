#include <stdio.h>
#include <string.h>
#include <stdlib.h>


double* fromJsonString_double (char *string , int *tamanho) {
	char * token;
	double * listaConv;
	listaConv = (double*) calloc(sizeof(double), 100);
	string++;
	token = strtok(string, ", ");
	sscanf(token, "%lf", &listaConv[*tamanho]);
	*tamanho = 1;
	while(token != NULL){
		sscanf(token, "%lf", &listaConv[*tamanho]);
		(*tamanho)++;
		token = strtok(NULL, ", ");
	}
	return listaConv;
}
int* fromJsonString_int (char* string, int* tamanho) {
	char * token;
	int * listaConv;
	listaConv = (int*) calloc(sizeof(int), 100);
	string++;
	token = strtok(string, ", ");
	sscanf(token, "%i", &listaConv[*tamanho]);
	*tamanho = 1;
	while(token != NULL){
		sscanf(token, "%i", &listaConv[*tamanho]);
		(*tamanho)++;
		token = strtok(NULL, ", ");
	}
	return listaConv;
}

int main() {
	int tamanho=0, isDouble=0, vezes;
	char string[201]={0}, c;
	double * string_double;
	int * string_int;
	scanf("%i", &vezes);
	getchar();
	for (int i = 0; i < vezes; i++) {
		isDouble = 0;
		tamanho = 0;
		for(int j = 0; j < 201; j++){
			scanf("%c", &c);
			if(c != '\n'){
				string[j] = c;
				if(c == '.'){ isDouble = 1;}
			}else{
				string[j] = '\0';
				break;
			}
		}	
		if (strcmp(string, "[]") == 0 || strcmp(string, " ") == 0 || string[0] == '\0') {
			printf("valor inválido");
			break;	
		}
		if(isDouble){
			string_double = fromJsonString_double(string, &tamanho);
			for(int x = 1; x < tamanho; x++){
				printf("%lf ", string_double[x]);
			}
		}else{
			string_int = fromJsonString_int(string, &tamanho);
			for(int x = 1; x < tamanho; x++){
				printf("%i ", string_int[x]);
			}
		}
		printf("\n");
	}
	return 0;
}
