#include "list.h"

/**
* add_node_end - function to add a node at the end of a circular
* doubly linked list
* @list: the head of the linked list
* @str: the string that the new node contain
* Return: Address of the new node, or NULL on failure
*/
List *add_node_end(List **list, char *str)
{
	List *end_node;

	end_node = malloc(sizeof(List));
	if (!end_node)
		return (NULL);

	end_node->str = strdup(str);
	if (!end_node->str)
	{
		free(end_node);
		return (NULL);
	}
	end_node->next = NULL;
	end_node->prev = NULL;

	if (!list || !*list)
	{
		(*list) = end_node;
		return (*list);
	}

	if ((*list)->next == NULL)
	{
		(*list)->next = end_node;
		end_node->prev = *list;
		(*list)->prev = end_node;
		end_node->next = *list;
		return (end_node);
	}

	end_node->next = *list;
	(*list)->prev->next = end_node;
	end_node->prev = (*list)->prev;
	(*list)->prev = end_node;

	return (end_node);
}

/**
* add_node_begin - function to add a node at the beginning of a circular
* doubly linked list
* @list: the head of the linked list
* @str: the string that the new node contain
* Return: Address of the new node, or NULL on failure
*/
List *add_node_begin(List **list, char *str)
{
	List *start_node;

	start_node = malloc(sizeof(List));
	if (!start_node)
		return (NULL);

	start_node->str = strdup(str);
	if (!start_node->str)
	{
		free(start_node);
		return (NULL);
	}
	start_node->next = NULL;
	start_node->prev = NULL;

	if (!list || !*list)
	{
		(*list) = start_node;
		return (*list);
	}

	if ((*list)->next == NULL)
	{
		(*list)->next = start_node;
		start_node->prev = *list;
		start_node->next = *list;
		(*list)->prev = start_node;
		*list = start_node;
		return (*list);
	}

	start_node->next = *list;
	(*list)->prev->next = start_node;
	start_node->prev = (*list)->prev;
	(*list)->prev = start_node;
	(*list) = start_node;

	return (*list);
}
