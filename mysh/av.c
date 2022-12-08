#include <stdio.h>
#include <stdlib.h>

/**
 * main - printing command line args using av
 * @ac: argument count
 * @av: argument vector
 *
 * Return: number of arguments av
 */
int main(int ac, char **av)
{
	char **arg = av + 1; /* skip the first arg */

	(void)ac;

	while (*arg != NULL)
	{
		printf("%s\n", *arg);
		arg++;
	}

	return (0);
}
