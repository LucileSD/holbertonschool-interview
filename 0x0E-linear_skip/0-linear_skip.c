#include "search.h"

/**
* linear_skip - Linear search in a skip list
* @list: a pointer to the head of the skip list to search in
* @value: the value to search for
* Return: a pointer on the first node where value is located
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current, *prev = list;
	int index = 0;

	if (!list)
		return (NULL);

	current = list->express;

	while (current->n < value && current->express)
	{
		index += 4;
		printf("Value checked at index [%d]= [%d]\n", index, current->n);
		prev = current;
		current = current->express;
	}
	index += 4;
		printf("Value checked at index [%d]= [%d]\n", index, current->n);
	if (value < current->n)
	{
		index -= 4;
		printf("Value found between indexes [%d] and [%d]\n", index, index + 4);
	}
	else
	{
		prev = current;
		printf("Value found between indexes [%d] and [%d]\n", index, index + 3);
	}

	while (prev->n < value && prev->next)
	{
		printf("Value checked at index [%d]= [%d]\n", index, prev->n);
		index++;
		prev = prev->next;
	}
	printf("Value checked at index [%d]= [%d]\n", index, prev->n);

	if (prev->n == value)
		return (prev);

	return (NULL);
}
