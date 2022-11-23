#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_to_int(char * num){
    if(strcmp(num,"um") == 0)
        return 1;
    else if(strcmp(num,"dois") == 0)
        return 2;
    else if(strcmp(num,"três") == 0)
        return 3;
    else if(strcmp(num,"quatro") == 0)
        return 4;
    else if(strcmp(num,"cinco") == 0)
        return 5;
    else
        return -1;
}


int* str_array_to_int_array(char entrada[]){
    int *vetor_numeros, i=0;
    char *numero = strtok(entrada, ", \n");
    while(numero != NULL){
        if (i==0)
            vetor_numeros = malloc(sizeof(int));
        else
            vetor_numeros = realloc(vetor_numeros, sizeof(int) * (i+1));
        vetor_numeros[i] = str_to_int(numero);
        numero = strtok(NULL,", \n");
        i++;
    }
    return vetor_numeros;
}
int main(){
    char entrada[501];
    fgets(entrada, 501, stdin);
    int *numeros = str_array_to_int_array(entrada);
    printf("%d\n", numeros[2]);
    free(numeros);
    return 0;
}
