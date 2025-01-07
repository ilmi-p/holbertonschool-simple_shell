#ifndef SHELL_H
#define SHELL_H

/* Bibliothèques standards */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

/* Variables globales */
extern char **environ;

/* Constantes */
#define MAX_TOKENS 100
#define BUFFER_SIZE 1024

/**
 * struct builtin - Structure pour les commandes intégrées (builtins)
 * @name: Nom de la commande
 * @f: Fonction associée
 */
struct builtin
{
    char *name;
    void (*f)(char *, char **, int);
};

typedef struct builtin builtin_t;

/* Prototypes des commandes intégrées */
void print_env(char *command_line, char **args, int status);
void shell_exit(char *command_line, char **args, int status);
int execute_builtin(char *command_line, char **args, int status);

/* Prototypes pour la gestion de la mémoire */
void clean_command_array(char **args);

#endif
