#include "lists.h"

/**
 * free_dlistint - Frees a dlistint_t list
 * @head: Head of the list
 * Return: No return
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	if (head != NULL)
	{
		/* Move to the beginning of the list */
		while (head->prev != NULL)
			head = head->prev;

		/* Free each node in the list */
		while ((temp = head) != NULL)
		{
			head = head->next;
			free(temp);
		}
	}
}
