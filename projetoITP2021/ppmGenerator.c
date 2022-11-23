#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Cor da montanha
#define MONTANHA_R 0
#define MONTANHA_G 0
#define MONTANHA_B 0
#define MONTANHA_BORDA 1


void gerarPPM(int tamanho_array, int altura_maxima, int * array, char * nome_do_arquivo){

	// * Valores iniciais do gradiente para o fundo
	int fundo_GRD_r = 1;
	int fundo_GRD_g = 0;
	int fundo_GRD_b = 36;

	// * RAND seed
	srand(time(NULL));


	FILE * fp;
	fp = fopen(nome_do_arquivo, "w+");
	if (!fp){
		printf("Erro na leitura do arquivo \"%s\".", nome_do_arquivo);
		return;
	}
	
	fprintf(fp, "P3\n%d %d\n255\n", tamanho_array, altura_maxima);

	for (int i = 0; i < altura_maxima; i++){
		for (int j = 0; j < tamanho_array; j++){
			if(array[j] < i - MONTANHA_BORDA){
				fprintf(fp, "%d %d %d\n", MONTANHA_R, MONTANHA_G, MONTANHA_B);
			}else if(array[j] < i) {
				fprintf(fp, "0 0 0\n");
			}else{
				// * Estrelas :)
				if (rand() % 1000 == 1){
					fprintf(fp, "255 255 255\n");
				}else{
					int chance = rand() % 10;

					if (fundo_GRD_r != 42 && chance){
						fundo_GRD_r += 1;
					}

					if (fundo_GRD_g != 41 && chance){
						fundo_GRD_g += 1;
					}
					
					if (fundo_GRD_b != 77 && chance){
						fundo_GRD_b += 1;
					}
					fprintf(fp, "%d %d %d\n", fundo_GRD_r,fundo_GRD_g,fundo_GRD_b);
				}
			}
	}
		
	}
}