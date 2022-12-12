#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
* insert_node - insert a node with a value to the correct place in the list
* head: the head of the list
* number: the number to insert in the node
* Return: the address of the new node, or NULL if it failed
*/
listint_t *insert_node(listint_t **head, int number) {

	listint_t *new_node, *tmp = *head;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);
	
	new_node->n = number;
	new_node->next = NULL;

	while(tmp->next && tmp->next->n < number){
		tmp = tmp->next;
	}

	if(tmp == *head){
		new_node->next = *head;
		*head = new_node;
	}
	else if(tmp->next == NULL){
		new_node->next = NULL;
		tmp->next = new_node;
	}
	else{
		new_node->next = tmp->next;
		tmp->next = new_node;
	}

	return(new_node);
}
