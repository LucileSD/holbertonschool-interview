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
	int count = 0;

	if (!list)
		return (NULL);

	current = list->express;

	while (current->n < value && current->express)
	{
		count += 4;
		printf("Value checked at index [%d]= [%d]\n", count, current->n);
		prev = current;
		current = current->express;
	}
	count += 4;
		printf("Value checked at index [%d]= [%d]\n", count, current->n);
	if (value < current->n)
	{
		count -= 4;
		printf("Value found between indexes [%d] and [%d]\n", count, count + 4);
	}
	else
	{
		prev = current;
		printf("Value found between indexes [%d] and [%d]\n", count, count + 3);
	}

	while (prev->n < value && prev->next)
	{
		printf("Value checked at index [%d]= [%d]\n", count, prev->n);
		count += 1;
		prev = prev->next;
	}
	printf("Value checked at index [%d]= [%d]\n", count, prev->n);

	if (prev->n == value)
		return (prev);

	return (NULL);
}
