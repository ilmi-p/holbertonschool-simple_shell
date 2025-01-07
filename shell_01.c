#include "shell.h"

 /* print_env - Imprime l'environnement actuel
 * @command_line : Ligne de commande (non utilisée)
 * @args : Arguments de commande (inutilisé)
 * @status : Statut de sortie (non utilisé)
 */
void print_env(char *command_line __attribute__((unused)),
		char **args __attribute__((unused)), int status)
{
	int i = 0;

	(void)status;
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

/**
 * shell_exit - Quitte le shell avec le statut donné
 * @command_line: Ligne de commande à libérer
 * @args: Arguments de la commande
 * @status: Statut de sortie actuel
 */

void shell_exit(char *command_line, char **args, int status)
{
	int exit_code = status;

	if (args[1])
	{
		exit_code = atoi(args[1]);
		if (exit_code < 0)
		{
			fprintf(stderr, "./hsh: exit: Illegal number: %s\n", args[1]);
			exit_code = 2;
		}
	}

	clean_command_array(args);
	free(command_line);
	exit(exit_code);
}
/**
 * execute_builtin - Exécute une commande interne si elle existe
 * @command_line: Ligne de commande originale
 * @args: Arguments de la commande
 * @status: Statut de sortie actuel
 * Retourne: 1 si la commande interne est exécutée, 0 sinon
 */

int execute_builtin(char *command_line, char **args, int status)
{
	int i = 0;
	builtin_t builtins[] = {
		{"env", print_env},
		{"exit", shell_exit},
		{NULL, NULL}
	};

	if (!args || !args[0])
		return (0);

	while (builtins[i].name)
	{
		if (strcmp(args[0], builtins[i].name) == 0)
		{
			builtins[i].f(command_line, args, status);
			return (1);
		}
		i++;
	}

	return (0);
}
