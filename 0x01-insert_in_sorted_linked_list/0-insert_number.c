#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * insert_node - prints all elements of a listint_t list
 * @head: pointer to head of list
 * @number: Value of the new node
 * Return: new node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *current;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	current = *head;
	new->n = number;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
	}
	else {
		if (new->n < current->n)
		{
			new->next = *head;
			*head = new;
			return (new);
		}

		while (current->next != NULL)
		{
			printf("current node %d, new node %d\n", current->n, new->n);
			if (new->n <= current->next->n)
			{
				new->next = current->next;
				current->next = new;
				break;
			}
			current = current->next;
		}

		if (current->next == NULL)
			current->next = new;
		printf("value of the current node %d\n", current->n);
	}

	return (new);
}
