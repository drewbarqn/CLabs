#include<stdio.h>
#include "fun.h"
#include "proverk.h"
#include <stdlib.h>

int menu(int** a, int* n);

int main() {
int n = -1;
int* a = NULL;
int status = menu(&a, &n);
   if(a!=NULL){
   free(a);
   }
   if (status == -1){
   printf("\nEOF\n");
   return 1;
   }
  return 0;

}

int menu(int** a, int* n) {
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
    safe_exit(a);
    return -1;
    }
    if (*a == NULL && c != 'a' && *n < 0) {
    if (c != 'q'){ 
    printf("Сначала инициализируйте массив\n");
    continue;
    }
    else{
    printf("\nВыход\n");
    return 0;
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
      		return -1;	       
	 } 

	 *a = calloc(*n,sizeof(int));  
	 
	 if (*a == NULL) {    
		 printf("Ошибка: не удалось выделить память.\n"); 
		  *n = 0; 
		  return 1;
	 }

      printf("Введите элементы массива (целые числа):\n");
      
      for (int i = 0; i < *n; i++) {
       if (!inputcheck_value(&(*a)[i]))
       {
	       safe_exit(a);
	       return -1;
       }
      }
      print_a(a, n);
      break;

    case 'b':
      printf("Введите индекс вставки\n");
      int f = 0;
      if (!inputcheck_index_i(&f, n))
      {
      return -1;
      }
      vstavka(a, n, f);
      print_a(a, n);
      break;

    case 'c': 
      if (*n == 0){
      printf("Удаление невозможно\n");
      break;
      }
      printf("Введите индекс удаления\n");		      
      int k;
      if (!inputcheck_index_d(&k, n)){
      safe_exit(a);
      return -1;
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
      return 0;

    default:
      printf("Ошибка ввода. Попробуйте снова.\n");
      break;
    }
  }
}
