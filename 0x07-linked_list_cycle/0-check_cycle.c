#include "lists.h"

/**
* check_cycle - check if a list is in cycle
* @list: the head of the list
* Return: 1 if linked list has a cycle otherwise 0
*/
int check_cycle(listint_t *list)
{
	listint_t *turtle = list;
	listint_t *haze = list;

	if (!list)
		return (0);

	while (haze->next->next && turtle->next)
	{
		haze = haze->next->next;
		if (haze->n == turtle->n)
			return (1);
		turtle = turtle->next;
	}
	return (0);
}
