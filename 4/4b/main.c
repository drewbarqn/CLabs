#include "fun.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int cycle_sdvg(char *s);

int main() {
  char *line;
  while ((line = myreadline("\nВведите строку и сдвиг (это должно быть целое число отделенное от основной строки хотя бы одним пробелом или символом табуляции): ")) != NULL) {
    printf("\"%s\"\n", line);

    clock_t start = clock();
    int status = cycle_sdvg(line);
    clock_t end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nВремя выполнения: %f секунд\n", cpu_time_used);
    free(line);
    if (status == -1)
      break;
  }
  return 0;
}

int cycle_sdvg(char *s1) {
  if (!s1)
    return -1;
  char *s = mystrdup(s1);

  char **words = malloc(100 * sizeof(char *));
  if (words == NULL) {
    printf("Не хватило памяти");
    free(s);
    return -1;
  }
  int count = 0;
  char *token = mystrtok(s, " \t\n");
  while (token != NULL) {
    if (count < 100) {
      words[count] = token;
      count++;
      token = mystrtok(NULL, " \t\n");
    } else {
      char **t = realloc(words, (count + 1) * sizeof(char *));
      if (t == NULL) {
        free(s);
        free(words);
        printf("Ошибка памяти");
        return -1;
      }
      words = t;
      words[count] = token;
      count++;
      token = mystrtok(NULL, " \t\n");
    }
  }
  int n;
  if (count == 0 || sscanf(words[count - 1], "%d", &n) != 1) {
    printf("Некорректный сдвиг\n");
    free(words);
    free(s);
    return -1;
  }

  for (int i = 0; i < count - 1; i++) {
    int len = mystrlen(words[i]);
    if (len == 0)
      continue;
    char new_word[len + 1];
    for (int j = 0; words[i][j] != '\0'; j++) {
      int shift = ((n % len) + len) % len;
      new_word[(j + shift) % len] = words[i][j]; 
    }
    new_word[len] = '\0';
    printf("%s ", new_word);
  }
  free(words);
  free(s);
  printf("\n");
  return 0;
}
