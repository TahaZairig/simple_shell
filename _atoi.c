#include "shell.h"

/**
 * interactive - Determines whether the shell is in interactive mode or not.
 * @info: a struct that holds address information
 *
 * Return:  1 if the shell is in interactive mode
 * and 0 if it's not interactive.
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - Determines whether a character is a delimiter or not.
 * @c: the character to be checked
 * @delim: the string containing delimiters
 * Return: Returns 1 if the character is a delimiter, and 0 otherwise.
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - Determines whether a character is an alphabetic character or not.
 * @c: The character to be analyzed
 * Return: Returns 1 if 'c' is an alphabetic character, otherwise returns 0.
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - Transforms a string into an integer.
 * @s: The input string to be converted.
 * Return: Returns 0 if there are no numbers in the string;
 * otherwise, it returns the converted integer.
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

