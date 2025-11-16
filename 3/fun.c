#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "proverk.h"

void safe_exit(int**a){ 
	if(*a != NULL){
		free(*a); 
		*a = NULL;
	}
	exit(0);
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



void udalenie(int **a, int *n, int k) {
  if (*n > 0) {
    for (int i = k; i < *n - 1; i++) {
      (*a)[i] = (*a)[i + 1];
    }

    (*n)--;
    int *t = realloc(*a, (*n) * sizeof(int));
    if (t != NULL){
    *a = t;
    }
  } else {
    printf("Удаление невозможно\n");
    return;
  }
}



int *individ(int **a, int *n) {
  int k = 0;
  int *b = malloc(*n * sizeof(int));

  for (int i = 0; i < *n; i++) {
    int x = (*a)[i];
    bool flag = true;
    int d = (x / 10) % 10 - x % 10;

    while (x > 100) {
      if ((x / 10) % 10 - x % 10 != d) {
        flag = false;
        break;
      }
      x /= 10;
    }

    if (flag) {
      int *t = realloc(b, (k + 1) * sizeof(int));
      if (t == NULL) {
        printf("Не удалось выделить память!\n");
        free(b);
        return NULL;
      }

      b = t;
      b[k] = (*a)[i];
      udalenie(a, n, i);
      k++;
      i--;
    }
  }

  if (k > 0) {
    return b;
  } else {
    free(b);
    return NULL;
  }
}
