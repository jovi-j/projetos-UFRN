#include <stdlib.h>
#include <math.h>

void gerarTerreno(int * arr, int posStart, int posEnd, int max_desvio){
	
	// Como todos os valores tem que ter um valor central, caso a divisão da soma de 
	// ambos não dê um valor exato, então significa que não há valores entre eles.
	if ((posStart + posEnd) % 2 == 0){
		if(rand() % 2){
			arr[((posStart+posEnd)/2)-1] = floor((arr[posStart-1] + arr[posEnd-1]) / 2) + max_desvio; 
		}
		else{
			arr[((posStart+posEnd)/2)-1] = floor((arr[posStart-1] + arr[posEnd-1]) / 2) - max_desvio; 
		}

		// Chamando a função recursivamente, da nova posição 
		// em diante, e da nova posição para trás
		gerarTerreno(arr, posStart, (posStart+posEnd)/2, max_desvio);
		gerarTerreno(arr, (posStart+posEnd)/2, posEnd ,max_desvio);
	}
	else{
		return;
	}
}