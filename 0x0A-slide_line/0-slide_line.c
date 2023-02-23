#include "slide_line.h"

/**
* swap - switch 2 numbers
* @line: the pointer to the array
* @source: the first number
* @dest: the second number to swap
*/
void swap(int *line, int source, int dest)
{
	int tmp;

	tmp = line[source];
	line[source] = line[dest];
	line[dest] = tmp;
}

/**
* add - function to add 2 number if they are identocal
* @line: the pointer to the array
* @src: the first number
* @dest: the second number
* @size: the number of element in the array
* @findNext: the flag
* Return: the sum
*/
int add(int *line, int src, int dest, size_t size, int findNext)
{
	if (line[src] == line[dest])
	{
		line[src] = line[src] + line[dest];
		line[dest] = 0;
		if (findNext == 1)
			dest = find_number(src + 1, size, line);
	}
	return (dest);
}

/**
* find_number - find the next number that is not 0
* @idx: the index to begin
* @size: the number of elements in the array
* @line: the pointer on the array
* Return: the index or 0
*/
int find_number(int idx, int size, int *line)
{
	int j;

	for (j = idx; j < size; j++)
		if (line[j] != 0)
			return (j);
	return (0);
}

/**
* reverse - reverse the array
* @line: the pointer on the array
* @size: the number of element in the array
* Return: the reversed array
*/
int *reverse(int *line, int size)
{
	int idx;

	for (idx = 0; idx < size; idx++, size--)
	{
		swap(line, idx, size);
	}
	return (line);
}

/**
* slide_line - slide & merge an array to the direction represented
* by direction. direction
* @line: points to an array of integers
* @size: numbers of elements of the array
* @direction: can be either SLIDE_LEFT or SLIDE_RIGHT
* Return: 1 upon success, or 0 upon failure
*/
int slide_line(int *line, size_t size, int direction)
{
	size_t idx, compare;

	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	for (idx = 0; idx < size; idx++)
	{
		compare = find_number(idx + 1, size, line);
		if (compare == 0)
			break;

		compare = add(line, idx - 1, compare, size, 1);
		compare = add(line, idx, compare, size, 0);

		if (line[idx] == 0 && compare != 0)
		{
			swap(line, idx, compare);
		}
	}
	if (direction == SLIDE_RIGHT)
		reverse(line, size - 1);
	return (1);
}
