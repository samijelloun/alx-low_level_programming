#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position
 * @h: Head of the list
 * @idx: Index of the new node
 * @n: Value of the new node
 * Return: The address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new = NULL;
	dlistint_t *head = *h;
	unsigned int i = 1;

	if (idx == 0)
		new = add_dnodeint(h, n);
	else
	{
		/* Move to the beginning of the list */
		while (head != NULL && head->prev != NULL)
			head = head->prev;

		/* Traverse the list to find the insertion point */
		while (head != NULL)
		{
			if (i == idx)
			{
				/* Check if the insertion is at the end */
				if (head->next == NULL)
					new = add_dnodeint_end(h, n);
				else
				{
					new = malloc(sizeof(dlistint_t));
					if (new != NULL)
					{
						new->n = n;
						new->next = head->next;
						new->prev = head;
						head->next->prev = new;
						head->next = new;
					}
				}
				break;
			}
			head = head->next;
			i++;
		}
	}

	return (new);
}
