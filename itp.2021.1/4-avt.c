#include <stdio.h>
void bubble_sort (int vetor[], int n) {
    int k, j, aux;
    for (k = 1; k < n; k++) {
        for (j = 0; j < n - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

int main(){
    int t1,t2;
    scanf("%d %d",&t1,&t2);
    int arr[t1+t2];
    for(int i = 0; i < t1; i++){
       scanf("%d", &arr[i]);
    }
    getchar();

    for(int i = t1; i < t1+t2; i++){
       scanf("%d", &arr[i]);
    }
    getchar();
    bubble_sort(arr, t1+t2);

    for(int i = 0; i < t1+t2; i++){
       printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
