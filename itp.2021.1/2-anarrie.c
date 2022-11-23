#include <stdio.h>
int main() {
    int n, vencedor;
    float maior_nota = 0.0,n1,n2,n3;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
       scanf("%f %f %f", &n1, &n2, &n3);
       getchar();
       float sum = (n1 + n2 + n3) / 3;
       if( sum >= maior_nota ){
           maior_nota = sum;
           vencedor = i + 1;
       }
    }

    printf("Vencedor: %d\nNota: %.2f\n",vencedor, maior_nota);
    return 0;
}
