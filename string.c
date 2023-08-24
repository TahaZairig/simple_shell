#include "shell.h"

/**
 * _strlen - provides the length of a string
 * @s: The string for which to determine the length
 *
 * Return: Integer representing the length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - conducts a lexicographic comparison between two strings.
 * @s1: The first string
 * @s2: The second string
 *
 * Return: Negative if s1 < s2, positive if s1 > s2,
 * and zero if s1 is equal to s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - verifies if the string "needle"
 * begins with the contents of the string "haystack."
 * @haystack: The string to be searched
 * @needle: The substring to locate.
 * Return: Address of the next character in "haystack" or NULL if not found
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - combines two strings
 * @dest: The destination buffer
 * @src: The source buffer
 *
 * Return: A pointer to the destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
