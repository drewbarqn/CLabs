#include "fun.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int process_input(char* input);

int main() {
	    char *input;

	   while((input = 
myreadline("Введите строку и сдвиг(не забудьте отделить их хотя бы одним пробелом или символом табуляции: ")) != NULL){
		   if (input[0] == '\0'){
		   free(input);
		   continue;
		   } 
		   int result = process_input(input);
		        free(input);
	   }
return 0;
}

int process_input(char *input) {
  char *end = input + mystrlen(input);

  while (end > input && *(end - 1) == ' ') {
    end--;
  }

  if (end == input) {
    printf("Ошибка: пустой ввод\n");
    return 1;
  }

  char *num_start = end;
  while (num_start > input &&
         (*(num_start - 1) >= '0' && *(num_start - 1) <= '9' ||
          *(num_start - 1) == '-')) {
    num_start--;
  }

  if (num_start == end) {
    printf("Ошибка: не найдено число в конце\n");
    return 1;
  }

  int shift;
  if (sscanf(num_start, "%d", &shift) != 1) {
    printf("Ошибка: неверный формат числа\n");
    return 1;
  }

  if (num_start > input && *(num_start - 1) != ' ') {
    printf("Ошибка: число должно быть отделено пробелом\n");
    return 1;
  }

  if (num_start > input) {
    *(num_start - 1) = '\0';
  } else {
    input[0] = '\0';
  }

  char *text = mystrdup(input);
  if (!text) {
    return 1;
  }

  clock_t start = clock();

  if (text[0] == '\0') {
    printf("Пустая строка\n");
  } else {
    char **words = malloc(100 * sizeof(char *));
    if (!words) {
      printf("Не хватило памяти\n");
      free(text);
      return 1;
    }

    int count = 0;
    char *token = mystrtok(text, " \t\n");
    while (token != NULL) {
      if (count < 100) {
        words[count] = token;
        count++;
        token = mystrtok(NULL, " \t\n");
      } else {
        char **t = realloc(words, (count + 1) * sizeof(char *));
        if (!t) {
          printf("Ошибка памяти\n");
          free(words);
          free(text);
          return 1;
        }
        words = t;
        words[count] = token;
        count++;
        token = mystrtok(NULL, " \t\n");
      }
    }

    for (int i = 0; i < count; i++) {
      int len = mystrlen(words[i]);
      if (len == 0)
        continue;
      char new_word[len + 1];
      for (int j = 0; j < len; j++) {
        new_word[(j + shift) % len] = words[i][j];
      }
      new_word[len] = '\0';
      printf("%s ", new_word);
    }
    printf("\n");

    free(words);
  }

  clock_t end_time = clock();
  double cpu_time_used = ((double)(end_time - start)) / CLOCKS_PER_SEC;
  printf("\nВремя выполнения: %f секунд\n", cpu_time_used);

  free(text);
  return 0;
}
