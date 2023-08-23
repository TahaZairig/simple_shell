#include "shell.h"

/**
 * _memset - populates memory with a consistent byte value
 * @s: The pointer pointing to the memory region
 * @b: The byte used to populate the memory pointed to by s
 * @n: The number of bytes to be populated
 * Return: (s) a pointer to the memory region referenced by s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - deallocates memory associated with a string of strings
 * @pp: A collection of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - dynamically adjusts the size of a memory block
 * @ptr: A pointer to a previously allocated (malloc'ed) memory block
 * @old_size: The size in bytes of the previously allocated memory block
 * @new_size: The size in bytes of the newly allocated memory block
 *
 * Return: A pointer to the old memory block that has been resized.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
