#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "proverk.h"

void safe_exit(int**a){ 
	if(a && *a) {
		free(*a); 
		*a = NULL;
	}
}

    void vstavka(int **a, int *n, int k) {
  int *t = realloc(*a, (*n + 1) * sizeof(int));
  if (t == NULL) {
    printf("Не удалось выделить память!\n");
    return;
  }

  *a = t;
  for (int i = *n; i > k; i--) {
    (*a)[i] = (*a)[i - 1];
  }

  printf("Введите число: ");
  int u = inputcheck_value(&(*a)[k]);
  if (u == 0){
  (*n)--;
  *a = realloc(*a, *n * sizeof(int));
  return;
  }
  (*n)++;
}

void print_a (int** a, int* n){
if (a == NULL || *a == NULL || *n <= 0){
printf("Массив пуст\n");
return;
}
printf("\nРезультат: ");
for(int i = 0; i < *n; i++){
printf("%d ", (*a)[i]);
}
printf("\n");
}


void udalenie(int **a, int *n, int k) {
  if (*n > 0) {
    for (int i = k; i < *n - 1; i++) {
      (*a)[i] = (*a)[i + 1];
    }
    (*n)--;
    if (*n>0)
    {
    int *t = realloc(*a, (*n) * sizeof(int));
        if (t != NULL)
	{
	*a = t;
	}
    }

    else 
    {
    free(*a);
    *a = NULL;
    }
  }
    else
    {
    printf("Удаление невозможно\n");
    return;
    }
}



void individ(int **a, int *n)
{
    if (*n == 0 || *a == NULL) {
        printf("Массив пуст\n");
        return;
    }
    int *indices = malloc((*n) * sizeof(int));
    if (!indices) {
        printf("Ошибка памяти\n");
        return;
    }

    int count = 0;
    for (int i = 0; i < *n; i++) {
        int x = (*a)[i];
        if (x < 0) x = -x;

        bool flag = true;
        if (x >= 100) {
            int d = (x / 10) % 10 - x % 10;
            int temp = x;
            while (temp >= 100) {
                temp /= 10;
                if ((temp / 10) % 10 - temp % 10 != d) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
            indices[count++] = i;
    }

    printf("Нужная последовательность:\n");
    if (count == 0) {
        printf("(нет подходящих чисел)\n");
    } else {
        for (int i = 0; i < count; i++)
            printf("%d ", (*a)[indices[i]]);
        printf("\n");
    }

     for (int i = count - 1; i >= 0; i--)
        udalenie(a, n, indices[i]);

    free(indices);
}
