#include "search_algos.h"
#include <math.h>

/**
 * jump_list - searches for a value in an array of
 * integers using the Jump search algorithm
 *
 * @list: input list
 * @size: size of the array
 * @value: value to search in
 * Return: index of the number
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t pos, i, index;
	listint_t *first, *last;

	if (list == NULL || size == 0)
		return (NULL);

	pos = (size_t)sqrt((double)size);
	last = list;
	index = 0;

	while (last->next && index < size && value > last->n)
	{
		first = last;
		index = last->index;
		for (i = 0; last->next != NULL && i < pos; i++)
		{
			last = last->next;
		}
		printf("Value checked at index [%lu] = [%d]\n", index, last->n);
	}

	printf("Value found between indexes ");
	printf("[%lu] and [%lu]\n", first->index, last->index);

	while (first != NULL && first->index <= last->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", first->index, first->n);
		if (first->n == value)
			return (first);
		first = first->next;
	}
	return (NULL);
}
