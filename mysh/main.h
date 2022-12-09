#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
char *split_string (char *lineptr, const char *delim);
#endif /* _MAIN_H */
