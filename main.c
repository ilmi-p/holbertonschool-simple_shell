#include "shell.h"
/**
 * main - little shell program
 * Return: 0
 */
int main(void)
{
	char *stock = NULL;
	size_t buffer_size = 0; /* buff sizze for get line */

	while (1) /* infinite loop */
	{
		if (isatty(STDIN_FILENO)) /* check for interactive mode */
			prompt(); /* display it if yes */
		/* Read the user input using getline */
		if (getline(&stock, &buffer_size, stdin) == -1) /* if crtl D exit the loop */
			break;
		if (strlen(stock) > 0) /* check if it's not empty */
		{
			if (user_command(stock) == -1) /* use the user_command function to process*/
				fprintf(stderr, "error command: %s\n", stock);
		}
	}
	free(stock); /* free the allocated memory for stock */
	return (0);
}
