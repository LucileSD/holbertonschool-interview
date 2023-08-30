#include "substring.h"

/**
 * is_solution_valid - checks if a solution is valid
 *
 * @s: the string to scan
 * @words: the array of words all substring must be a
 * concatenation of
 * @nb_words: number of element in the array words
 * @word_len: the length of each word in words
 * @start: start index
 *
 * Return: 1 if the solution is valid, 0 otherwise
*/
int is_solution_valid(char const *s, char const **words,
		      int nb_words, int word_len, int start)
{
	int *found_words = calloc(nb_words, sizeof(int));
	int valid_solution = 1, i, j, word_start;
	char *substring;

	for (i = 0; i < nb_words; i++)
	{
		word_start = start + i * word_len;
		substring = strndup(s + word_start, word_len);

		for (j = 0; j < nb_words; j++)
		{
			if (!found_words[j] && strcmp(substring, words[j]) == 0)
			{
				found_words[j] = 1;
				break;
			}
		}

		free(substring);
	}

	for (i = 0; i < nb_words; i++)
	{
		if (!found_words[i])
		{
			valid_solution = 0;
			break;
		}
	}

	free(found_words);
	return (valid_solution);
}

/**
 * find_substring - finds all the possible substrings containing
 * a list of words, within a given string.
 *
 * @s: the string to scan
 * @words: the array of words all substring must be a
 * concatenation of
 * @nb_words: number of element in the array words
 * @n: holds the address at which to store the number of element
 * in the returned array
 *
 * Return: an allocated array, storing each index in s,
 * at which a substring was found or NULL
*/
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int word_len = strlen(words[0]);
	int s_len = strlen(s);
	int *indices = NULL;
	int count = 0;
	int i;

	for (i = 0; i <= s_len - nb_words * word_len; i++)
	{
		if (is_solution_valid(s, words, nb_words, word_len, i))
		{
			count++;
			indices = realloc(indices, count * sizeof(int));
			indices[count - 1] = i;
		}
	}

	*n = count;
	return (indices);
}
