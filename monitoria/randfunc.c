#include <stdio.h>
#include <string.h>

int rand_int_range(int min, int max){
    int range = max - min + 1;
    return min + rand()%range;     
}

int* criarVetorAleatorio(int tamanho, int minimo, int maximo){
    int vetorAleatorio[tamanho+3];
    vetorAleatorio[0] = tamanho;
    vetorAleatorio[1] = minimo;
    vetorAleatorio[2] = maximo;
    for (i = 2; i < tamanho; ++i) {
        vetorAleatorio[i] = rand_int_range(minimo, maximo);
    }
    return vetorAleatorio;
}

int* criarHistograma(int* valores){
    int tamanho = valores[0];
    int vezesQueAparece[tamanho+3];
    vezesQueAparece[0] = valores[1];
    vezesQueAparece[1] = valores[2];
    vezesQueAparece[2] = tamanho;

    for (i = 2; i < tamanho; ++i) {
        vezesQueAparece[i] = 0;
        for (j = i; j < tamanho; ++j) {
            if (valores[i+3] == valores[j+3]) {
                vezesQueAparece[i]++;
            }
        }
        
    }
}

float* criarPorcentagens(int* histograma){
    int porcentagens[histograma[2]];
    for (i = 0; i < histograma[2]; ++i) {
        porcentagens[i] = histograma[i+2] / histograma[2];    
    }
    return porcentagens;
}

void imprimePorcentagens(float porcentagens[], int histograma[]){
    
}
void liberar(valores, porcentagens, histograma){

}
int main(){
    int tamanho, maximo, minimo;
    scanf("%d", &tamanho);
    scanf("%d %d", &minimo, &maximo);
    int *valores = criarVetorAleatorio(tamanho, minimo, maximo);
    int *histograma = criarHistograma(valores);
    float *porcentagens = criarPorcentagens(histograma);
    imprimePorcentagens(porcentagens, histograma);
    liberar(valores, porcentagens, histograma);   
    return 0;
}
