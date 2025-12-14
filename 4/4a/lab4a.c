#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int cycle_sdvg(char *s);

int main() {

  char *line;
  while ((line = readline("\nВведите строку: ")) != NULL) {
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
  char *s = strdup(s1);
  int n;
  int c;
  printf("Введите сдвиг: ");
  if (scanf("%d", &n) != 1) {
    while ((c = getchar()) != '\n' && c != EOF)
      ;
    printf("\nEOF\n");
    free(s);
    return -1;
  }
  while ((c = getchar()) != '\n' && c != EOF)
    ;
  char **words = malloc(100 * sizeof(char *));
  if (words == NULL) {
    printf("Не хватило памяти");
    free(s);
    return -1;
  }
  int count = 0;
  char *token = strtok(s, " \t\n");
  while (token != NULL) {
    if (count < 100) {
      words[count] = token;
      count++;
      token = strtok(NULL, " \t\n");
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
      token = strtok(NULL, " \t\n");
    }
  }
  for (int i = 0; i < count; i++) {
    int len = strlen(words[i]);
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
  return 0;
}
