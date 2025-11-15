#include<stdio.h>
#include<stdlib.h>
#include<stdiobool.h>
void vstavka(int** a, int* n) {
  int k;
  inputcheck_index_i(&k, *n);
  *t = realloc(*a, (*n+1)*sizeof(int));
  if (t == NULL){
  printf("Не удалось выделить память!\n");
  return;
  }
  *a = t;
  for (int i = *n; i > k; i--) {
  (*a)[i] = (*a)[i - 1];
			    }
  printf("Введите число:");
  inputcheck_value(&(*a)[k]);
  (*n)++;
}
void udalenie (int** a, int* n, int k){
if (*n>0){
for(int i = k; i<*n-1; i++){
(*a)[i] = (*a)[i+1];
}
(*n)--;
*a = realloc(*a, (*n) * sizeof(int)); 
}
else{
printf("Удаление невозможно\n");
return;
}
}
int* individ(int** a,int* n){
int k = 0;
int* b = NULL;
for (int i = 0; i < *n; i++){ 
int x = (*a)[i];
bool flag = true;
int d = (x/10)%10 - x%10;
while (x>=100){
x/=10;
if ((x/10)%10 - x%10 != d){
flag = false;
break
}
}
if (flag){
t = realloc(b, (k+1) * sizeof(int));
if (t == NULL){
printf("Не удалось выделить память!\n");
free(b);
return NULL;
}
b[k] = (*a)[i];
udalenie(a, n, i);
k++;
i--;
}
if (k>0){
return b;
}
else {
free(b);
return NULL;
}
}
}
