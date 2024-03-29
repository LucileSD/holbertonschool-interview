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

	while (haze && haze->next)
	{
		haze = haze->next->next;
		turtle = turtle->next;
		if (haze == turtle)
			return (1);
	}
	return (0);
}
