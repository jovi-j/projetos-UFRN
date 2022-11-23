#include <stdio.h>
int main() {
    char str[50];
    int n;
    scanf("%d", &n);
    if (n == 0) {
        return 0;
    }
    getchar();
    fgets(str, 50, stdin);
    for (int i = 0; i < 50; i++) {
        char num = str[i];
        if(num == '\n' || num == '\0'){
            return 0;
        }
        if(num == ' '){
            continue;
        }
        else{
            num = num - '0';
            for (int j = 0; j < num; j++) {
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}
