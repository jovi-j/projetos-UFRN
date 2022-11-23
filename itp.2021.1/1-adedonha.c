#include <stdio.h>

int main() {
  char ch = 64;
  int a, b, c, d, sum;
  scanf("%i %i %i %i", &a, &b, &c, &d);
  sum = a + b + c + d;
  if (sum) {
    while (sum > 26) {
        sum = sum - 26;
    }
    ch = ch + sum;
    printf("Letra: %c\n", ch);
  } else {
    printf("Ei! Ninguém colocou nada!");
  }
  return 0;
}
