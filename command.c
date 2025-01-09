#include "shell.h"
/**
 * user_command - executing the command of the user
 * @command: command of the user
 * Return: 0
 */
int user_command(char *command)
{
	char *args[2];
	char *token;
	pid_t pid;
	int stock;

	token = strtok(command, " \n");
	if (token == NULL)
	{
		fprintf(stderr, "Error: no command enterred\n");
		return (1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("error \n");
		return (1);
	}
	else if (pid == 0)
	{
		args[0] = token;
		args[1] = NULL;
		if (execve(args[0], args, environ) == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(pid, &stock, 0) == -1)
		{
			perror("Error: waitpid failed");
			return (1);
		}
	}
	return (0);
}
