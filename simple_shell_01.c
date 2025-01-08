#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PROMPT "#cisfun$ "
#define MAX_INPUT 1024

extern char **environ;

int main(void)
{
    char input[MAX_INPUT];
    char *args[2];
    pid_t pid;
    int status;

    while (1)
    {
        /* Display the prompt */
        write(STDOUT_FILENO, PROMPT, strlen(PROMPT));

        /* Read user input */
        if (fgets(input, MAX_INPUT, stdin) == NULL)
        {
            /* Handle EOF (Ctrl+D) */
            write(STDOUT_FILENO, "\n", 1);
            break;
        }

        /* Remove the newline character */
        input[strcspn(input, "\n")] = '\0';

        /* Check if the input is empty */
        if (strlen(input) == 0)
            continue;

        /* Prepare arguments for execve */
        args[0] = input;
        args[1] = NULL;

        /* Fork a child process */
        pid = fork();
        if (pid == -1)
        {
            perror("Error");
            continue;
        }
        if (pid == 0)
        {
            /* In child process, execute the command */
            if (execve(args[0], args, environ) == -1)
            {
                perror("./shell");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            /* In parent process, wait for the child to finish */
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}
