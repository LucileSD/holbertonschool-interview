#include "regex.h"
/**
* regex_match_helper - recursive function to travel strings and compare
* @str: the string to scan
* @pattern: the regular expression
* Return: 1 if the pattern matches the string, or 0 otherwise
*/
int regex_match_helper(const char *str, const char *pattern)
{
	if (*str == '\0' && *pattern == '\0')
		return (1);

	if (*pattern == '\0')
		return (0);

	if (*(pattern + 1) == '*')
	{
		while (*str != '\0' && (*str == *pattern || *pattern == '.'))
		{
			if (regex_match_helper(str, pattern + 2))
				return (1);
			str++;
		}
		return (regex_match_helper(str, pattern + 2));
	}

	if (*str != '\0' && (*str == *pattern || *pattern == '.'))
		return (regex_match_helper(str + 1, pattern + 1));

	return (0);
}

/**
* regex_match - function that checks whether a given pattern matches
* a given string
* @str: the string to scan
* @pattern: the regular expression
* Return: 1 if the pattern matches the string, or 0 otherwise
*/

int regex_match(char const *str, char const *pattern)
{
	return (regex_match_helper(str, pattern));
}
