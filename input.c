#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * _getline - function that reads input line
 * @n: buffer
 * Return: input
*/

char *_getline(size_t *n)
{
	char *input = NULL;
	char *new_input = (char *)realloc(input, *n);
	int c;
	size_t i = 0;

	while ((c = getchar()) != '\n' && c != EOF)
	{
		if (i == 0)
		{
			*n = 2;
			input = (char *)malloc(*n);
			if (input == NULL)
			{
				perror("Memory allocation failed");
				exit(EXIT_FAILURE);
			}
		}

		if (i >= *n - 1)
		{
			*n *= 2;
	if (new_input == NULL)
	{
		free(input);
		perror("Memory reallocation failed");
		exit(EXIT_FAILURE);
	}
		input = new_input;
		}
		input[i++] = c;
	}
		if (input != NULL)
		{
			input[i] = '\0';
		}
	return (input);
}
