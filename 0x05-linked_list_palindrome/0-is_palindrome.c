#include "lists.h"
/**
 * length_list - calculates the length of the list
 * @h: head of the list
 * Return: length of a list
 */
int length_list(listint_t **h)
{
    listint_t *current;
    int cont = 0;

    current = *h;

    while (current)
    {
        cont += 1;
        /*printf("list val: %d, cont: %d\n", current->n, cont);*/
        current = current->next;
    }
    return (cont);

}

/**
 * mid - find the middle point of the list
 * @h: head of the list
 * @half: middle of the list
 * Return: the middle node of the list
 */
listint_t *mid(listint_t **h, int half)
{
    listint_t *current;
    int cont = 0;

    current = *h;

    while (cont < half)
    {
        cont += 1;
        current = current->next;
    }

    return (current);
}

/**
 * reverse_listint - reverse a listint_t linked list
 * @head: head of the list
 * Return: list in reverse
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *nx = NULL, *prev = NULL;

	while (*head)
	{
		nx = (*head)->next;
		(*head)->next = prev;
		prev = (*head);
		(*head) = nx;
	}
	(*head) = prev;
	return (*head);
}

/**
 * check3 - checks the 3 first cases.
 * @h: head of the list
 * @lg: length o the list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */

int check3(listint_t **h, int lg)
{
    listint_t *current, *aux1;

    current = *h;
    if (lg == 1)
    {
        return (1);
    }
    else if (lg == 2)
    {
        aux1 = current->next;
        if (aux1->n == current->n)
            return (1);
    }
    else
    {
        aux1 = current->next->next;
        if (current->n == aux1->n)
            return (1);
    }
    return (0);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: head of the list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
    int lg = 0, half = 0;
    listint_t *current, *new_head2, *new_head1;

    if (*head == NULL)
        return (1);
    lg = length_list(&(*head));
    if (lg <= 3)
        return (check3(&(*head), lg));
    new_head1 = *head;
    if (lg % 2 == 0)
    {
        half = lg / 2;
        current = mid(&(*head), half);
        new_head2 = reverse_listint(&current);
        while (new_head1 && new_head2)
        {
            if (new_head1->n != new_head2->n)
                return (0);
            new_head1 = new_head1->next;
            new_head2 = new_head2->next;
        }

    } 
    else
    {
        half = lg / 2;
        current = mid(&(*head), half + 1);
        new_head2 = reverse_listint(&(current));
        while (new_head1 && new_head2)
        {
            if (new_head1->n != new_head2->n)
                return (0);
            new_head1 = new_head1->next;
            new_head2 = new_head2->next;
        }
    }
    return (1);
}