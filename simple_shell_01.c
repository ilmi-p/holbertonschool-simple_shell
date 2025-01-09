#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PROMPT "#cisfun$ "
#define MAX_INPUT 1024

extern char **environ;

/**
 * main - basic unix shell function
 * Return: 0
 */
int main(void)
{
	char max_input[MAX_INPUT];
	char *args[2];
	pid_t pid;
	int stock;

	while (1)
	{
		if (isatty(STDIN_FILENO)) /* Display the prompt for the non-interactive mode */
			write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
		if (fgets(max_input, MAX_INPUT, stdin) == NULL) /* Display the "shell" for the non-interactive mode */
		{
			if (isatty(STDIN_FILENO)) /* Handle Ctrl+D */
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		max_input[strcspn(max_input, "\n")] = '\0'; /* Remove \n */
		if (strlen(max_input) == 0) /* Check if the input is empty */
			continue;
		args[0] = max_input; /* Arguments for execve */
		args[1] = NULL;
		pid = fork(); /* Child fork process */
		if (pid == -1)
		{
			perror("Error");
			continue;
		}
		if (pid == 0)
		{
			if (execve(args[0], args, environ) == -1) /* Exe the command in the child process */
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}
		else
			waitpid(pid, &stock, 0); /* Wait for the child to finish */
	}
	return (0);
}
