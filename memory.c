#include "shell.h"

/**
 * bfree - deallocates memory associated with a
 * pointer and sets the pointer to NULL
 * @ptr: The address of the pointer that needs to be freed
 *
 * Return: 1 if the pointer was successfully freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
