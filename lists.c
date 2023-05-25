#include "shell.h"

/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *shell_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	shell_node = malloc(sizeof(list_t));
	if (!shell_node)
		return (NULL);

	_memset((void *)shell_node, 0, sizeof(list_t));
	shell_node->num = num;

	if (str)
	{
		shell_node->str = _strdup(str);
		if (!shell_node->str)
		{
			free(shell_node);
			return (NULL);
		}
	}

	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = shell_node;
	}
	else
		*head = shell_node;

	return (shell_node);
}

/**
 * free_list - frees all nodes of a list
 * @head_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}

/**
 * add_node - adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *shell_head;

	if (!head)
		return (NULL);
	shell_head = malloc(sizeof(list_t));
	if (!shell_head)
		return (NULL);

	_memset((void *)shell_head, 0, sizeof(list_t));
	shell_head->num = num;

	if (str)
	{
		shell_head->str = _strdup(str);
		if (!shell_head->str)
		{
			free(shell_head);
			return (NULL);
		}
	}

	shell_head->next = *head;
	*head = shell_head;

	return (shell_head);
}

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @h: pointer to first node
i *
 * Return: size of list
 */
size_t print_list_str(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * delete_node_at_index - deletes node at given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}

		i++;
		prev_node = node;
		node = node->next;
	}

	return (0);
}
