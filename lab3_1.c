#include <stdio.h>
#include <stdlib.h>
void vstavka(int a[], int n);
void udalenie(int a[], int n);
void individ(int a[], int n);
void vivod(int a[], int n);
int inputcheck_length(int *length);
int inputcheck_value(double *value)
int inputcheck_menu(char *choice);
int inputcheck_index(int *index);
int main() {
  printf("Введите количество элементов:");
  int n;
  scanf("%d", &n);
  double *a = malloc(n * sizeof(double));
  printf("Введите элементы массив (они должны быть одного типа)");
  for (int i = 0; i < n; i++) {
    inputcheck_value(a[i]);
  }
  while (1) {
    printf("\n(b) Вставка нового элемента.\n(c) Удаление элемента.\n(d) "
           "Индивидуальное задание.\n(e) Вывод содержимого массива.\n");
    char c;
    inputcheck_menu(c);
    if (c == 'b') {
      int k;
      vstavka(a, k);
    }
    if (c == 'c') {
      int k;
      udalenie(a, k)
    }
    if (c == 'd') {
      individ();
    }
    if (c == 'e') {
      for (int i = 0; i < n; i++) {
        printf("%lf", *(a + i));
      }
    }
  }
}
int inputcheck_menu(char *n) {
  while (1) {
    int a = scanf("%c", n);
    if (a == EOF) {
      printf("\nEOF\n");
      return 0;
    }
    if (a == 1) {
      if (*n == 'b' || *n == 'c' || *n == 'd' || *n == 'e')
        break;
    }
    scanf("%*[^\n]");
    scanf("%*c");
    printf("Ошибка ввода попробуйте еще раз:");
  }
  return 1;
}
int inputcheck_value(double *n) {
  while (1) {
    int a = scanf("%lf", n);
    if (a == EOF) {
      printf("\nEOF\n");
      return 0;
    }
    if (a == 1) {
      break;
    }
    scanf("%*[^\n]");
    scanf("%*c");
    printf("Ошибка ввода попробуйте еще раз:");
  }
  return 1;
}
int inputcheck_index(int *n, int n) {
  while (1) {
    int a = scanf("%d", n);
    if (a == EOF) {
      printf("\nEOF\n");
      return 0;
    }
    if (a == 1 && *n>=0 && *n<=n) {
      break;
    }
    scanf("%*[^\n]");
    scanf("%*c");
    printf("Ошибка ввода попробуйте еще раз:");
  }
  return 1;
}
double* vstavka(double** a, int* n) {
  int k;
  printf("Введите индекс вставки:");
  inputcheck_index(&k, n);
  *a = realloc(*a, (n+1)*sizeof(double));
  if (a == NULL){
  return NULL;
  }
  int i = n-1;
  while (i>k-1){
	a[i+1] = a[i];
	i--;
  }
  printf("Введите число:");
  inputcheck_value(&a[k]);
  *n++;
}
double* udalenie (double** a, int* n){
int k;
printf("Введите индекс удаления:");
inputcheck_index(&k, *n);
for(int i = k; i<*n-1; i++){
a[i] = a[i+1];
}
if (a!=NULL){
a = realloc(a, (*n-1)*sizeof(double));
}
return a;
*n--;
}
}
