#include "lists.h"

/**
* find_listint_loop - finds the loop in a linked list
* @head: the beginning of the list
* Return: NULL if there is no loop, the address of the node where
* the loop start
*/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tmp, *nextNode;

	tmp = head;

	if (head == NULL)
		return (NULL);

	while (head != NULL)
	{
		if (head->next == NULL && head->next != tmp)
			return (NULL);

		nextNode = head->next;
		if (nextNode == tmp)
			return (head);

		head->next = tmp;
		head = nextNode;
	}

	return (NULL);
}
