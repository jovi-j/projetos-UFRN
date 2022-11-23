#include <stdio.h>

int main() {
  int x, y, l, a, px, py;
  scanf("%d %d %d %d", &x, &y, &l, &a);
  scanf("%d %d", &px, &py);
  if (px >= x && px <= l && py >= y && py <= a) {
    printf("Dentro!\n");
    return 0;
  }
  printf("Fora!\n");
  return 0;
}
