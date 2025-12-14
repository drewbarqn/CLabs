#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t mystrlen(const char *s) {
  int i = 0;
  while (s[i] != '\0') {
    i++;
  }
  return i;
}

void *mymemcpy(void *kuda, const void *otkuda, size_t n) {
  unsigned char *d = (unsigned char *)kuda;
  const unsigned char *s = (const unsigned char *)otkuda;
  for (size_t i = 0; i < n; i++) {
    d[i] = s[i];
  }
  return kuda;
}

char *mystrtok(char *str, const char *delim) {
  static char *next_start = NULL;
  if (str != NULL) {
    next_start = str;
  }
  if (next_start == NULL || *next_start == '\0') {
    return NULL;
  } // если это не конец строки, строка пустая или указатель на NULL ниче не
    // делаем вернем NULL

  while (
      *next_start !=
      '\0') { // пройдемся по строке пока не встретим разделитель в строке delim
    int is_delim = 0;
    for (int i = 0; delim[i] != '\0'; i++) {
      if (*next_start == delim[i]) {
        is_delim = 1;
        break;
      }
    }
    if (!is_delim)
      break; // если не разделитель то выходим
    next_start++;
  }
  if (*next_start == '\0') {
    next_start = NULL;
    return NULL;
  }
  char *token_start = next_start;

  while (*next_start != '\0') {
    int is_delim = 0;
    for (int i = 0; delim[i] != '\0'; i++) {
      if (*next_start == delim[i]) {
        is_delim = 1;
        break;
      }
    }
    if (is_delim)
      break;
    next_start++;
  }
  if (*next_start == '\0') {
    next_start = NULL;
    return token_start;
  } else {
    *next_start = '\0';
    next_start++;
    return token_start;
  }
}

char *mystrdup(const char *s) {
  if (s == NULL)
    return NULL;
  size_t len = mystrlen(s) + 1;
  char *copy = malloc(len); // выделить память
  if (copy == NULL)
    return NULL;          // не хватило памяти
  mymemcpy(copy, s, len); // скопировать байты (включая '\0')
  return copy;
}

char *mystrcat(const char *a, const char *b) {
	    size_t la = mystrlen(a);
	        size_t lb = mystrlen(b);

		    char *res = malloc(la + lb + 1);
		        if (!res)
				        return NULL;

			    mymemcpy(res, b, lb);
			        mymemcpy(res + lb, a, la + 1);
				    return res;
}


char *myreadline(char *msg) {
  if (msg) {
    printf("%s", msg);
    fflush(stdout);
  }
  char s[82] = {0};
  char *res = malloc(1);
  if (!res)
	      return NULL;
  res[0] = '\0';
  int in = scanf("%81[^\n]", s);
  if (in==EOF){
  free(res);
  return NULL;
  }
  if (in == 0) {
    scanf("%*c");
    in = scanf("%81[^\n]", s);
    if (in==EOF){
    return res;
    }
  }
  while (in > 0) {
    char *new_res = mystrcat(s, res);
    if (!new_res) {
      free(res);
      return NULL;
    }

    free(res);
    res = new_res;

    in = scanf("%81[^\n]", s);
    if (in == EOF) break;
  }

  return res;
}
