#include "simple_shell.h"

/**
 * main - Entry point for the shell
 * @argc: Number of arguments (unused)
 * @argv: Array of arguments
 * @envp: Environment variables
 * Return: 0 on success, or error code on failure
 */
int main(int argc, char **argv, char **envp)
{
	char *command_line = NULL;
	size_t bufsize = 0;
	ssize_t nread;
	char *args[2];

	(void)argc;

	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);

		nread = getline(&command_line, &bufsize, stdin);
		if (nread == -1)
		{
			free(command_line);
			write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}

		command_line[strcspn(command_line, "\n")] = '\0';

		if (command_line[0] == '\0')
			continue;

		args[0] = command_line;
		args[1] = NULL;

		if (execve(args[0], args, envp) == -1)
			perror(argv[0]);
	}

	free(command_line);
	return (0);
}
