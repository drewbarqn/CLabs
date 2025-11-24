#include<stdio.h>
#include "fun.h"
#include "proverk.h"
#include <stdlib.h>

void menu(int** a, int* n);

int main() {
int n = -1;
int* a = NULL;
   menu(&a, &n);
  free(a);
  return 0;
}

void menu(int** a, int* n) {
  while (1) {
    printf("\nМеню:\n");
    printf("(a) Инициализация массива\n");
    printf("(b) Вставка нового элемента\n");
    printf("(c) Удаление элемента\n");
    printf("(d) Индивидуальное задание\n");
    printf("(e) Вывод содержимого массива\n");
    printf("(q) Выход\n");

    char c;
    if(!inputcheck_menu(&c)){
    printf("\nEOF\n");
    safe_exit(a);
    return;
    }
    if (*a == NULL && c != 'a' && *n < 0) {
    if (c != 'q'){ 
    printf("Сначала инициализируйте массив\n");
    continue;
    }
    else{
    printf("\nВыход\n");
    return;
    }
    }
    switch (c) {
    case 'a':

	 if (*a!=NULL){
	 free(*a);
	 *a = NULL;
	 *n = 0;
	 }

	 printf("Введите количество элементов: ");     
	 
	 if (!inputcheck_n(n)){ 
		 printf("\nEOF\n");
	       safe_exit(a);
      		return;	       
	 } 

	 *a = calloc(*n,sizeof(int));  
	 
	 if (*a == NULL) {    
		 printf("Ошибка: не удалось выделить память.\n"); 
		  *n = 0; 
		  return;
	 }

      printf("Введите элементы массива (целые числа):\n");
      
      for (int i = 0; i < *n; i++) {
       if (!inputcheck_value(&(*a)[i]))
       {
	       printf("EOF");
	       safe_exit(a);
	       return;
       }
      }
      print_a(a, n);
      break;

    case 'b':
      printf("Введите индекс вставки\n");
      int f;
      if (!inputcheck_index_i(&f, n))
      {
      printf("\nEOF\n");      
      safe_exit(a);
      }
      vstavka(a, n, f);
      print_a(a, n);
      break;

    case 'c': 
      printf("Введите индекс удаления\n");		      
      int k;
      if (!inputcheck_index_d(&k, n)){
      printf("\nEOF\n");
      safe_exit(a);
      return;
      }
      udalenie(a, n, k);
      print_a(a, n);
      break;
    

    case 'd': { 
      individ(a, n); 
      break;
    }

    case 'e':
      printf("Массив: ");
      for (int i = 0; i < *n; i++) {
        printf("%d ", (*a)[i]);
      }
      printf("\n");
      break;

    case 'q':
      printf("Выход из программы.\n");
      safe_exit(a);
      return;

    default:
      printf("Ошибка ввода. Попробуйте снова.\n");
      break;
    }
  }
}
