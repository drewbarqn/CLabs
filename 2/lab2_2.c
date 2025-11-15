#include <math.h>
#include <stdio.h>
double sh(double x, int n);
int inputcheckn(int *n);
int inputcheckx(double *x);
int main() {
  int n;
  double x;
<<<<<<< HEAD
  inputcheckx(&x);
  inputcheckn(&n);
  sh(x, n);
  double f1 = (expl(x) - expl(-x)) / 2;
printf("Библиотечное значение: %.*lf\n", 15, f1);
=======
  int m = inputcheckx(&x);
  if (m == 0){
  printf("Принудительное завершение\n");
  return 0;
  }
  m = inputcheckn(&n);
  if (m == 0){
  printf("Принудительное завершение\n");
  return 0;
  }
  sh(x, n);
  double f1 = (expl(x) - expl(-x)) / 2;
  printf("Библиотечное значение: %.*lf\n", 15, f1);
>>>>>>> 58e4756 (Сохранение текущих изменений перед pull)
  return 0;
}
int inputcheckn(int *n) {
  printf("Введите количество знаков после запятой: ");
  while (1) {
    int a = scanf("%d", n);
    if (a == EOF) {
      printf("\nEOF\n");
      return 0;
    }
    if (a == 1) {
      if (*n > 0)
        break;
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
  while (1) {
    double next_t = t * (x * x) / ((2 * i + 2) * (2 * i + 3));
    if (fabsl(next_t) < powl(10, -n))
      break;
    t = next_t;
    s += t;
    i++;
  }
<<<<<<< HEAD
  if (n>15) printf("Значение с помощью ряда: %.*lf\n", 15, s);
  else printf("Значение с помощью ряда: %.*lf\n", n, s);
=======
  if (n > 15)
    printf("Значение с помощью ряда: %.*lf\n", 15, s);
  else
    printf("Значение с помощью ряда: %.*lf\n", n, s);
>>>>>>> 58e4756 (Сохранение текущих изменений перед pull)
  printf("Количество членов: %d\n", i);
}
