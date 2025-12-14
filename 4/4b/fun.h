#ifndef FUN_H
#define FUN_H
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
char* myreadline(const char* prompt);
char* mystrtok(char* str, const char* delim);
size_t mystrlen(const char* str);
char* mystrdup(const char* str);
#endif
