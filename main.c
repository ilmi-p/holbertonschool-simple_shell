#include "shell.h"
/**
 * main - shell program initializes to enters and read command from the user
 * Return: Always 0
 */
int main(void)
{
	char *stock = NULL;
	size_t buffer_size = 0;

	while (1) /* infinite loop */
	{
		if (isatty(STDIN_FILENO)) /* check for interactive mode */
			prompt(); /* display it if yes */
		if (getline(&stock, &buffer_size, stdin) == -1)  /* Read the user input using getline */
			break;
		if (strlen(stock) > 0) /* check if it's not empty */
		{
			if (user_command(stock) == -1) /* use the user_command function to process */
				fprintf(stderr, "error command: %s\n", stock);
		}
	}
	free(stock);
	return (0);
}
