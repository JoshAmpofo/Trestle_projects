#include <stdio.h>
#include <stdlib.h>

/**
 * my_getline - custom made getline function
 * @lineptr: ptr to input from command line
 * @n: size of input string
 *
 * Return: input received, -1 on error
 */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t str_len = 0;
	size_t str_size = *n;
	int nread;
	char *temp;

	if (*lineptr == NULL) /* alloc memory to line buffer */
	{
		*lineptr = malloc(str_size);
		if (*lineptr == NULL) /* EOF or CTRL + D */
		{
			return (-1);
		}
	} /* read input till EOF or newline is encountered */
	while ((nread = fgetc(stream)) != EOF && nread != '\n')
	{
		(*lineptr)[str_len++] = (char)nread; /* append input chars to line buffer */

		if (str_len == str_size) /* double line buffer cap if full */
		{
			str_size *= 2;
			temp = realloc(*lineptr, str_size);
			if (temp == NULL)
			{
				return (-1);
			}
			*lineptr = temp;
			*n = str_size;
		}
	}
	if (str_len > 0) /* if buffer not empty, add null term char */
	{
		(*lineptr)[str_len] = '\0';
	} /* print num of characters or -1 if error */
	return (nread == EOF && str_len == 0) ? -1 : (ssize_t)str_len;
}
