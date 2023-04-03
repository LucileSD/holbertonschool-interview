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

	if (!list)
		return (NULL);

	current = list->express;

	while (current->n < value && current->express)
	{
		printf("Value checked at index [%ld]= [%d]\n", current->index, current->n);
		prev = current;
		current = current->express;
	}
		printf("Value checked at index [%ld]= [%d]\n", prev->index, current->n);
	if (value < current->n)
	{
		printf("Value found between indexes [%ld] and [%ld]\n", prev->index, current->index);
	}
	else
	{
		prev = current;
		printf("Value found between indexes [%ld] and [%ld]\n", prev->index, current->index);
	}

	while (prev->n < value && prev->next)
	{
		printf("Value checked at index [%ld]= [%d]\n", prev->index, prev->n);
		prev = prev->next;
	}
	printf("Value checked at index [%ld]= [%d]\n", prev->index, prev->n);

	if (prev->n == value)
		return (prev);

	return (NULL);
}
