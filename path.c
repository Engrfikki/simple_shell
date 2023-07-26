#include <stdio.h>
#include <string.h>
#include "shell.h"

#define MAX_LENGTH 100

char div_string[MAX_LENGTH];

/**
 * _path - A function that checks if the address of an array exists
 *
 * @cmd_buff: The command buffer
 * Return: The path of the command if found, and NULL if not found
*/

char *_path(char *cmd_buff)
{
	char *arr_path;
	char *div_string;
	char **main_arr;
	char *str = getenv("PATH");
	int q, len, chk = 0;
	struct stat info;

	if (stat(cmd_buff, &info) == 0)
	{
		return (cmd_buff);
	}
	/*div_string = malloc(strlen(str) + 1);*/
	/*div_string = _strcpy(div_string, str);*/
	div_string = malloc(strlen(str) + 1);
	if (div_string != NULL)
		{
		strcpy(div_string, str); /* Now you can copy the source string to the dynamically allocated memory*/
		/* Rest of your code, you can use div_string here*/

		free(div_string); /* Don't forget to free the allocated memory when you're done using it*/
		} 
	else 
	{
		/* Memory allocation failed*/
	perror("Memory allocation failed!");
	}
	main_arr = dividestring(div_string, ";");

	for (q = 0; main_arr[q] != NULL; q++)
	{
		len = _strlen(main_arr[q]);
		if (main_arr[q][len - 1] != '/')
		{
			arr_path = _strcat(main_arr[q], "/");
		}
		arr_path = _strcat(main_arr[q], cmd_buff);

		if (stat(arr_path, &info) == 0)
		{
			chk = 1;
			break;
		}
	}
	if (chk == 0)
		return (NULL);
	free(div_string);
	free(main_arr);
	return (arr_path);
}
