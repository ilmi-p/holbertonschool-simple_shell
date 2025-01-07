#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * main - Minimal UNIX shell
 * @argc: Number of arguments (unused)
 * @argv: Array of arguments
 * Return: 0 on success, or exit status on failure
 */
int main(int argc, char **argv)
{
    char *command_line = NULL;
    size_t bufsize = 0;
    ssize_t nread;
    char *args[2];

    (void)argc;

    while (1)
    {
        printf("#cisfun$ ");
        fflush(stdout);

        nread = getline(&command_line, &bufsize, stdin);
        if (nread == -1)
        {
            free(command_line);
            putchar('\n');
            exit(0);
        }

        command_line[strcspn(command_line, "\n")] = '\0';
        if (command_line[0] == '\0')
            continue;

        args[0] = command_line;
        args[1] = NULL;

        if (execve(args[0], args, NULL) == -1)
        {
            perror(argv[0]);
        }
    }

    free(command_line);
    return (0);
}
