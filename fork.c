#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * _fork - a function that executes fork
 * @arg: arguments
 *
 * Return: status
*/

int _fork(char **arg)
{
	pid_t pid = fork();
	int status = 0;
	char *envir[] = {NULL};

	if (pid < 0)
	{
		perror("Fork failure");
		exit(EXIT_FAILURE);
	}

	else if (pid == 0)
	{
		if (execve(arg[0], arg, envir) == -1)
		{
			perror("Not found");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}

	else
	{
		wait(&status);
	}

	return (0);
}
