#include <math.h>
#include <stdio.h>

double sh(double x, int n);
int inputcheckn(int *n);
int inputcheckx(double *x);
int main() {
  int n;
  double x;
  inputcheckx(&x);
  inputcheckn(&n);
  double f = sh(x, n);
  printf("Значение с помощью ряда: %.*lf\n", 15, f);

  double f1 = (expl(x) - expl(-x)) / 2;
  printf("Библиотечное значение: %.*lf\n", 15, f1);

  return 0;
}
int inputcheckn(int *n) {
  printf("Введите количество членов ряда: ");
  while (1) {
    int a = scanf("%d", n);
    if (a == EOF) {
      printf("\nEOF\n");
      return 0;
    }
    if (a == 1) {
	if (*n>0) break;
    }
    scanf("%*[^\n]");
    scanf("%*c");
    printf("Ошибка ввода попробуйте еще раз:");
  }
  return 1;
}
int inputcheckx(double *x) {
  printf("Введите x: ");
  while (1) {
    double result = scanf("%lf", x);
    if (result == EOF) {
      printf("\nEOF\n");
      return 0;
    }
    if (result == 1) {
      break;
    }
    scanf("%*[^\n]");
    scanf("%*c");
    printf("Ошибка ввода попробуйте еще раз:");
  }
  return 1;
}
double sh(double x, int n) {
  double s = x;
  double t = x;
  int i = 0;

  while (i < n + 1) {
    t /= (2 * i + 2) * (2 * i + 3);
    t *= x * x;
    s += t;
    i++;
  }

  return s;
}
