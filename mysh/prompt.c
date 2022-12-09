#include "main.h"

/**
 * main - print a prompt and wait for user to enter a command
 * @ac: arg count
 * @av: arg vector
 *
 * Return: string on success, -1 on exit
 */
int main (void)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t nread;
	char *token;
	char *delim = " \n";

	lineptr = malloc(sizeof(*lineptr));
	printf("$ "); /* print prompt */
	nread = getline(&lineptr, &n, stdin); /* get user inpt */

	if (nread == -1) /* EOF or CTRL+D */
	{
		printf("\n");
		return (-1);
	}
	if (lineptr == NULL) /* check if getline failed to alloc mem */
	{
		printf("Error: failed to allocate memory\n");
		return (-1);
	}
	token = split_string(lineptr, delim); /* split string to tokens */

	if (token == NULL)
	{
		printf("\n");
		free(lineptr);
		return (-1);
	}

	/* Loop through each token and print it */
	while (token != NULL)
	{
		printf("%s\n", token);

		/* Get next token */
		token = strtok(NULL, delim);
	}
	free(lineptr);
	
	return (0);
}
