#include<stdio.h> 
void safe_exit(int**a){
	if(*a == NULL){
		free(*a);
		*a = NULL;
	}
	exit(0);
}
}
int inputcheck_menu(char *n) {
  while (1) {
    int a = scanf(" %c", n);
    if (a == EOF) {
      printf("\nEOF\n");
      return 0;
    }
    if (a == 1) {
      if (*n == 'a' || *n == 'b' || *n == 'c' || *n == 'd' || *n == 'e'|| *n == 'q') {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
        break;
      }
      scanf("%*[^\n]");
      scanf("%*c");
      printf("Ошибка ввода, попробуйте еще раз: ");
    }
  }
  return 1;
}

int inputcheck_value(int *n) {
  while (1) {
    int a = scanf("%d", n);
    if (a == EOF) {
      printf("\nEOF\n");
      return 0;
    }
    if (a == 1) {
      break;
    }
    scanf("%*[^\n]");
    scanf("%*c");
    printf("Ошибка ввода, попробуйте еще раз: ");
  }
  return 1;
}

int inputcheck_index_i(int *index, int *n) {
  while (1) {
    int a = scanf("%d", index);
    if (a == EOF) {
      printf("\nEOF\n");
      return 0;
    }
    if (a == 1) {
      if (*index > *n) {
        printf("Индекс превышает максимальный -> вставка в конец\n");
        *index = *n;
        break;
      } else if (*index >= 0) {
        break;
      }
    }
    scanf("%*[^\n]");
    scanf("%*c");
    printf("Ошибка ввода, попробуйте еще раз: ");
  }
  return 1;
}

int inputcheck_index_d(int *index, int *n) {
  while (1) {
    int a = scanf("%d", index);
    if (a == EOF) {
      printf("\nEOF\n");
      return 0;
    }
    if (a == 1) {
      if (*index >= 0 && *index < *n)
        break;
    }
    scanf("%*[^\n]");
    scanf("%*c");
    printf("Ошибка ввода, попробуйте еще раз: ");
  }
  return 1;
}

int inputcheck_n(int *n) {
  while (1) {
    int a = scanf("%d", n);
    if (a == EOF) {
      printf("\nEOF\n");
      exit(0);
    }
    if (a == 1 && *n > 0) {
      break;
    }
    scanf("%*[^\n]");
    scanf("%*c");
    printf("Ошибка ввода (некорректно, либо не положительное число), "
           "попробуйте еще раз: ");
  }
  return 1;
}
