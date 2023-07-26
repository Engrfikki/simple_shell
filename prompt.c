#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"

#define MAX_COMMAND_LEN 100

/**
 * main - function that prints shell prompt
 *
 * Return: 0
*/

int main(void)
{
	char command[MAX_COMMAND_LEN];
	char **arg, *cmd_buff = NULL;
	int exitCondition = 0;
	int status = 0;


	while (!exitCondition)
	{
	printf("FikkiSam$ ");
			if (fgets(command, MAX_COMMAND_LEN, stdin) == NULL)
			break;

		command[strcspn(command, "\n")] = '\0';
		arg = dividestring(cmd_buff, " ");
		arg[0] = _path(arg[0]);
		if (arg[0] != NULL)
                        status = _fork(arg); /* Executes fork and execve function */
                else
                        perror("Not found"); /* Displays error's description if not forked */
                free(arg);
        }
        return (status);
}
