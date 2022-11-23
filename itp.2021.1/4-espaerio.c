#include <stdio.h>

int main(){
    int t, nEquipes, tempValores[3];
    scanf("%d %d", &t, &nEquipes);
    int mapaCidade[++t];
    for(int i = 0; i < t; i++){
        mapaCidade[i] = 0;
    }
    for(int i = 0; i < nEquipes; i++){
        scanf("%d %d %d", &tempValores[0], &tempValores[1], &tempValores[2]);
        for(int j = tempValores[0]; j <= tempValores[1]; j++){
           if(tempValores[2] > mapaCidade[j]){
               mapaCidade[j] = tempValores[2];
           } 
        }
    }

    for(int i = 0; i < t; i++){
        printf("%d ", mapaCidade[i]);
    }
    printf("\n");
    return 0;
}
