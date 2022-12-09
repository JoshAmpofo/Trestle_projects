#include "main.h"

/**
 * split_string - split a string into tokens
 * @lineptr: the string to split
 * @delim: the delimiter to use
 * 
 * Return: the first token on success, NULL on failure
 */
char *split_string (char *lineptr, const char *delim)
{
	char *token = strtok(lineptr, delim);

	return (token);
}
