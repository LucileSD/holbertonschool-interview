#include "lists.h"

/**
* is_palindrome - checks if a singly linked list is a palindrome
* @head: the head of the linked list
* Return: 1 if it is a palindrome, 0 otherwhise
*/
int is_palindrome(listint_t **head)
{
	int total_nodes = 0, half_nodes = 0, count = 0;
	listint_t *queue = *head, *current = *head, *prev, *next, *half_list;
	listint_t *current_head = *head;

	if (!*head || !head || !(*head)->next)
		return (1);
	while (queue->next)
	{
		queue = queue->next;
		total_nodes++;
	}
	half_nodes = total_nodes / 2;
	while (count <= half_nodes)
	{
		current = current->next;
		count++;
	}
	prev = current;
	half_list = current;
	current = current->next;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	half_list->next = current;
	count = 0;
	while (count <= half_nodes && queue)
	{
		if (current_head->n != queue->n)
			return (0);

		current_head = current_head->next;
		queue = queue->next;
	}
	return (1);
}
