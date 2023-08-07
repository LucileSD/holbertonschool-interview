#include "holberton.h"

/**
 * wildcmp_recurse - recursive function to move along strings without loops
 * @s1: pointer on the first string
 * @s2: pointer on the second string
 * Return: 1 if match 0 otherwise
 */
int wildcmp_recurse(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s1 == *s2)
		return (wildcmp_recurse(s1 + 1, s2 + 1));

	if (*s2 == '*')
	{
		if (wildcmp_recurse(s1, s2 + 1))
			return (1);

		if (*s1 != '\0' && wildcmp_recurse(s1 + 1, s2))
			return (1);
	}

	return (0);
}

/**
 * wildcmp - function to compare 2 strings
 * @s1: pointer on the first string
 * @s2: pointer on the second string
 * Return: 1 if match 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	return (wildcmp_recurse(s1, s2));
}
