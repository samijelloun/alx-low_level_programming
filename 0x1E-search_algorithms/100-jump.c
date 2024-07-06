#include "search_algos.h"
#include<math.h>

/**
 * jump_search - a function that searches for a value in an array of integers
 *using the Jump search algorithm
 *
 * @array: is a pointer to the first element of the array to search in.
 * @size:  is the number of elements in array.
 * @value: is the value to search for.
 *
 * Return: must return the first index where value is located
 *If value is not present or if array is NULL, your function must return -1
*/

int jump_search(int *array, size_t size, int value)
{
	int jump, step, prev, current;

	if (array == NULL || size == 0)
		return (-1);

	jump = (int)sqrt(size);
	step = 0;
	prev = current = 0;

	do {
		printf("Value checked array[%d] = [%d]\n", current, array[current]);

		if (array[current] == value)
			return (current);

		step++;
		prev = current;
		current = step * jump;
	} while (current < (int)size && array[current] < value);

	printf("Value found between indexes [%d] and [%d]\n", prev, current);

	for (; prev <= current && prev < (int)size; prev++)
	{
		printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
		if (array[prev] == value)
			return (prev);
	}

	return (-1);
}
