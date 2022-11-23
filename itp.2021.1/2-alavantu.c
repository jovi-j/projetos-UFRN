#include <stdio.h>

int main() {
    int bolo = 0;
    int canjica = 0;
    int milho = 0;
    int pamonha = 0;
    int pedemlk = 0;
    char inpt[50];
    fgets(&inpt, 50, stdin);
    for (int i = 0; i < 50; ++i) {
        if(inpt[i] == '\n' || inpt[i] == 'F'){
            break;
        }else{
            switch(inpt[i]){
                case 'B': 
                    bolo++;
                break;
                case 'C': 
                    canjica++;
                break;
                case 'M': 
                    milho++;
                break;
                case 'P': 
                    pamonha++;
                break;
                case 'Q': 
                    pedemlk++;
                break;
            }
        }
    }

    printf("Bolo: %d\n", bolo);
    printf("Canjica: %d\n", canjica);
    printf("Milho: %d\n", milho);
    printf("Pamonha: %d\n", pamonha);
    printf("Pé de Moleque: %d\n", pedemlk);

    return 0;
}
