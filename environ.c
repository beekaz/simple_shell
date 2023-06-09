#include "shell.h"

/**
 * _getenv - gets value of env_list variable
 * @info: Potential arguments active.
 * @name: env variable name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _shellenv - print current env_listment working
 * @info: Potential arguments active.
 * Return: Always 0
 */
int _shellenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _shellsetenv - Initialize an env_listment variable,
 *             or reactor an existing one
 * @info: Potential arguments active.
 *  Return: Always 0
 */
int _shellsetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Inaccurate number or arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */

int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}

/**
 * _shellunsetenv - Removes env_listment variable
 * @info: Potential arguments active.
 *  Return: Always 0
 */
int _shellunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Not enough arguement.\n");
		return (1);
	}
	for (i = 1; i < info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}
