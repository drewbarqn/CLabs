#include <stdio.h>
int cubesumdig(int n);
int main() {
  int lg;
  int rg;
  scanf("%d", &lg);
  scanf("%d", &rg);
  if (lg >= rg) {
    printf("Input error\n");
    return 1;
  }
  for (int i = lg; i <= rg; i++) {
    if (cubesumdig(i) == 1) {
      printf("%d \n", i);
    }
  }
  return 0;
}
int cubesumdig(int n) {
  int x = 0;
  int y = n * n;
  while (n > 0) {
    x += n % 10;
    n /= 10;
  }
  x = x * x * x;
  if (x == y) {
    return 1;
  } else {
    return 0;
  }
}
