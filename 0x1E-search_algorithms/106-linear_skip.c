#include "search_algos.h"

/**
 * linear_skip - searches for a value in a skip list
 * @list: input list
 * @value: value to search in
 * Return: index of the number
*/

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tmp;

	if (list == NULL)
		return (NULL);

	tmp = list;

	do {
		list = tmp;
		tmp = tmp->express;
		printf("Value checked at index ");
		printf("[%d] = [%d]\n", (int)tmp->index, tmp->n);
	} while (tmp->express && tmp->n < value);

	if (tmp->express == NULL)
	{
		list = tmp;
		while (tmp->next)
			tmp = tmp->next;
	}

	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)list->index, (int)tmp->index);

	while (list != tmp->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)list->index, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}

	return (NULL);
}
