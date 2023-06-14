#include "lists.h"

/**
* find_listint_loop - finds the loop in a linked list
* @head: the beginning of the list
* Return: NULL if there is no loop, the address of the node where
* the loop start
*/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *turtle, *haze;

	turtle = head;
	haze = turtle;

	if (!head)
		return (NULL);

	while (turtle && haze && haze->next)
	{
		turtle = turtle->next;
		haze = haze->next->next;

		if (turtle == haze)
		{
			turtle = head;
			while (haze)
			{
				if (turtle == haze)
					return (turtle);
				turtle = turtle->next;
				haze = haze->next;
			}
		}
	}

	return (NULL);
}
