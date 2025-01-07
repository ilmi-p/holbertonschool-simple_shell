#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

int main(int argc, char *argv[])
{
    char *command_line = NULL;
    size_t len = 0;
    ssize_t nread;
    char *args[2];
    pid_t pid;
    int status;

    (void)argc;
    (void)argv;

    while (1)
    {
        printf("$ ");
        fflush(stdout);

        nread = getline(&command_line, &len, stdin);
        if (nread == -1)
        {
            free(command_line);
            exit(0);
        }

        command_line[strcspn(command_line, "\n")] = 0;

        if (strlen(command_line) == 0)
            continue;

        args[0] = command_line;
        args[1] = NULL;

        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            free(command_line);
            exit(1);
        }
        else if (pid == 0)
        {
            if (execve(command_line, args, environ) == -1)
            {
                perror(command_line);
                exit(1);
            }
        }
        else
        {
            wait(&status);
        }
    }

    return 0;
}
