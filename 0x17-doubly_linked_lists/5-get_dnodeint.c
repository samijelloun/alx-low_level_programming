#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list
 * @head: Head of the list
 * @index: Index of the nth node
 * Return: Nth node
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;

	if (head == NULL)
		return (NULL);

	/* Move to the beginning of the list */
	while (head->prev != NULL)
		head = head->prev;

	i = 0;

	/* Traverse the list to find the nth node */
	while (head != NULL)
	{
		if (i == index)
			break;
		head = head->next;
		i++;
	}

	return (head);
}
