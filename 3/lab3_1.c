#include <stdio.h>
#include <stdlib.h>
#include "proverk.h"
#include "fun.h"

void menu (int** a, int* n);

int main() {
  printf("Введите количество элементов:");
  int n;
  inputchek_n(&n);
  int *a = malloc(n * sizeof(int));
  menu(&a,&n);
  }
void menu(int** a,int* n){
while (1){
	printf("(a) Инициализация массива. \n(b) Вставка нового элемента.\n(c) Удаление элемента.\n(d) Индивидуальное задание.\n(e) Вывод содержимого массива.\n");
char c;
inputcheck_menu(c); 
switch (c){
	case 'a':
	printf("Введите элементы массив (они должны быть одного типа)");                                                                                                                                                   for (int i = 0; i < n; i++) {                                                                                                                                                                                        inputcheck_value(a[i]);                                                                                                                                                                                          }         

	case 'b':
		int k;
		vstavka(a, n);
		break;

	case 'c': 
		int k;
		inputcheck_index_d(&k, n);
		udalenie(a, n);
		break;

	case 'd':
		individ();
		break;

	case 'e':
		if 
		for (int i = 0; i < n; i++) {
		printf("%d", *(a + i));
	}
}
}
}
