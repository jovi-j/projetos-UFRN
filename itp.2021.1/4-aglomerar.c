#include <stdio.h>

int isNotIn(int x, int n, int array[]){
    for(int i = 0; i < n; i++){
        if(x == array[i]){
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]){
    int n,i = 1;
    char c;
    scanf("%d ", &n);
    int n2 = n;
    int pessoas[n2];
    scanf("%d ", &c);
    pessoas[0] = c;
    while(c != EOF){
        if(c != ' ' && isNotIn(c, n2, pessoas)){
            pessoas[i] = c;
            i++;
        }
        if(scanf("%d", &c) == EOF){
            break;
        };
    }

    for(int j = 0; j < i; j++){
        printf("%d ", pessoas[j]);
    }
    printf("\n");
    return 0;
}
