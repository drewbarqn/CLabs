#include<stdio.h>
#include "fun.h"
#include "proverk.h"
#include <stdlib.h>

void menu(int **a, int *n);

int main() {
  printf("Введите количество элементов: ");
  int n;
  inputcheck_n(&n);

  int *a = malloc(n * sizeof(int));
  if (a == NULL) {
    printf("Ошибка: не удалось выделить память.\n");
    return 1;
  }

  menu(&a, &n);
  free(a);
  return 0;
}

void menu(int **a, int *n) {
  while (1) {
    printf("\nМеню:\n");
    printf("(a) Инициализация массива\n");
    printf("(b) Вставка нового элемента\n");
    printf("(c) Удаление элемента\n");
    printf("(d) Индивидуальное задание\n");
    printf("(e) Вывод содержимого массива\n");
    printf("(q) Выход\n");

    char c;
    inputcheck_menu(&c);
    switch (c) {
    case 'a':
      printf("Введите элементы массива (целые числа):\n");
      for (int i = 0; i < *n; i++) {
       int m = inputcheck_value(&(*a)[i]);
       if (m == 0){
	       free(*a);
	       return;
       }
      }
      break;

    case 'b':
      printf("Введите индекс вставки\n");
      vstavka(a, n);
      break;

    case 'c': 
      printf("Введите индекс удаления\n");		      
      int k;
      int m = inputcheck_index_d(&k, n);
      if (m == 0){
      free(*a);
      return;
      }
      udalenie(a, n, k);
      break;
    

    case 'd': 
      int *b = individ(a, n);
      if (b != NULL) {
        printf("Нужная последовательность: ");
        for (int i = 0; i < *n; i++) {
          printf("%d ", (*a)[i]);
        }
        printf("\n");
        free(b);
      }
      else {
        printf("Подходящих чисел не найдено.\n");
      }
      break;
    

    case 'e':
      printf("Массив: ");
      for (int i = 0; i < *n; i++) {
        printf("%d ", (*a)[i]);
      }
      printf("\n");
      break;

    case 'q':
      printf("Выход из программы.\n");
      free (*a);
      exit(0);
      return;

    default:
      printf("Ошибка ввода. Попробуйте снова.\n");
      break;
    }
  }
}
