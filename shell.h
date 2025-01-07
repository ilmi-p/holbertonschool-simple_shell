#ifndef SHELL_H
#define SHELL_H

/* Bibliothèques standard */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <errno.h>

/* Prototypes des fonctions */
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
int lsh_ctrld(char **args);

int lsh_num_builtins(void);
int _fork_fun(char **arg, char **av, char **env, char *lineptr, int np, int c);
int _strcmp(char *str1, char *str2);

/* Liste des commandes internes, suivie de leurs fonctions correspondantes */
extern char *builtin_str[];
extern int (*builtin_func[]) (char **);

#endif
