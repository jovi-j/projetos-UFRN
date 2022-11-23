#include <stdio.h>
void checkValues(int n){
        int total = 0;
        for (int i = 0; i < n; ++i) {
            char letra;
            int qtd;
            scanf("%d %c ", &qtd, &letra);
            switch(letra){
                case 'S':
                    total += 120*qtd;
                    break;
                case 'O':
                    total += 60*qtd;
                    break;
                case 'M':
                    total += 85*qtd;
                    break;
                case 'G':
                    total += 74*qtd;
                    break;
                case 'N':
                    total += 56*qtd;
                    break;
                case 'L':
                    total += 50*qtd;
                    break;
                case 'B':
                    total += 34*qtd;
                    break;
            }
        }
        if(total >= 110 && total <= 130){
            printf("%d mg\n", total);
        }else if(total > 130){
            printf("Menos %d mg\n", total - 130);
        }else if(total < 110){
            printf("Mais %d mg\n", 110 - total);
        }

}
int main(int argc, char *argv[])
{
    int n;
    scanf("%d", &n);
    while(n != 0){
        checkValues(n);
        scanf("%d", &n);
    }
    return 0;
}
