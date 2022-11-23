#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/getopt_posix.h> 

#include "terrainGenerator.h"
#include "ppmGenerator.h"

// * Valor seguindo a função 2^n + 1
#define LARGURA_MAX 1025

// * Altura máxima das montanhas
#define ALTURA_MAX 500

int main(int argc, char **argv)
{

	int desvio_max;
	char * nome_do_arquivo = malloc(sizeof(char)*30);

	// * Valores padrão
	desvio_max = 10;
	strcpy(nome_do_arquivo, "imagem.ppm");

	int valor_inicial = rand() % ALTURA_MAX;

	// * Array de tamanho pré-definido
	int * array = calloc(LARGURA_MAX, sizeof(int));

	// * Setando valores para o algorítimo iniciar os calculos
	array[0] = valor_inicial;
	array[LARGURA_MAX - 1] = valor_inicial;

	// * Pegando as opções usando getopt()
	int c;
	while ((c = getopt(argc, argv, "d:o:")) != -1){
		switch (c)
		{
		case 'd':
			if (optarg != "") desvio_max = atoi(optarg);
			break;
		case 'o':
			if (optarg != "") strcpy(nome_do_arquivo,optarg);
			break;
		case '?':
			fprintf(stderr, "Uso: %s -d [DESVIO_MAX] -o [NOME_DO_ARQUIVO.ppm] \n Exemplo:\n\t%s -d 8 -o imagem.ppm", argv[0], argv[0]);
			exit(EXIT_FAILURE);
			break;
		}
	}

	gerarTerreno(array,1,LARGURA_MAX,desvio_max);
	gerarPPM(LARGURA_MAX,ALTURA_MAX,array,nome_do_arquivo);
	free(array);
	return 0;
}