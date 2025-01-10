#include "shell.h"
/**
 * user_command - executing the command of the user
 * @command: command of the user
 * Return: 0
 */
int user_command(char *command)
{
	char *args[2]; /* array with the command and arguments */
	char *token; /* pointer to split the string with the commands */
	pid_t pid; /* pid of the child process */
	int stock; /* statut of the child process */

	token = strtok(command, " \n"); /* split the string accordind to space or \n */
	if (token == NULL) /* check if any command was write */
	{
		fprintf(stderr, "Error: no command enterred\n");
		return (1);
	}
	pid = fork(); /* create a new process */
	if (pid < 0) /* if fork fail */
	{
		perror("error \n");
		return (1);
	}
	else if (pid == 0) /* child process block */
	{
		args[0] = token; /* the first argument is the command */
		args[1] = NULL;
		if (execve(args[0], args, environ) == -1) /* command, arguments and env variables */
		{
			perror("./hsh");
			exit(EXIT_FAILURE); /* exit the child process if execve fail */
		}
	}
	else /* parents process */
	{
		if (waitpid(pid, &stock, 0) == -1) /* wait for the child process to finish and take the statut (stock) */
		{
			perror("Error: waitpid failed");
			return (1);
		}
	}
	return (0);
}
