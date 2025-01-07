#ifndef MAIN_H
#define MAIN_H

/* bibliothèques nécessaires */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* Déclaration des fnc pour le 1*/
char *_strcat(char *first, char *second);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
char *_strchr(char *str, char c);
char *_strdup(char *str);

#endif
