#include "shell.h"

/**
 * list_len - Calculates the length of a linked list.
 * @h: Pointer to the first node.
 *
<<<<<<< HEAD
 * Return: Size of the list.
=======
 * Return: The size of the list
>>>>>>> 8907973c0bdc5370888a0d6fd0e98294cbabb020
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
<<<<<<< HEAD
 * list_to_strings - Converts the 'str' elements of a linked list to an array of strings.
 * @head: Pointer to the first node.
=======
 * list_to_strings - a function that generates an array
 * of strings from the list->str elements
 * @head: A pointer to the initial node
>>>>>>> 8907973c0bdc5370888a0d6fd0e98294cbabb020
 *
 * Return: Array of strings.
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - Prints all elements of a list_t linked list.
 * @h: Pointer to the first node.
 *
 * Return: Size of the list.
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
<<<<<<< HEAD
 * node_starts_with - Returns the node whose string starts with the specified prefix.
 * @node: Pointer to the list head.
 * @prefix: String to match at the beginning.
 * @c: The next character after the prefix to match.
=======
 * node_starts_with - a function that returns the node in a linked list
 * whose string starts with a specified prefix.
 * @node: Pointer to the beginning of the list
 * @prefix: The string for matching
 * @c: The character immediately following the prefix to be matched
>>>>>>> 8907973c0bdc5370888a0d6fd0e98294cbabb020
 *
 * Return: The matching node or NULL if not found.
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - Retrieves the index of a specific node.
 * @head: Pointer to the list head.
 * @node: Pointer to the node.
 *
 * Return: Index of the node or -1 if not found.
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
