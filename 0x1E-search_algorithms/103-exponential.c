#include "search_algos.h"

/**
 * _binary_search - a function that searches for a value
 *in an array of integers using the Linear search algorithm
 binary_search*
 * @array: is a pointer to the first element of the array to search in.
 * @value: is the value to search for.
 * @left: The starting index of the [sub]array to search.
 * @right: The ending index of the [sub]array to search.
 *
 * Return: must return the first index where value is located
 *If value is not present or if array is NULL, your function must return -1
*/

int _binary_search(int *array, size_t left, size_t right, int value)
{
	size_t j;

	if (array == NULL)
		return (-1);

	while (right >= left)
	{
		printf("Searching in array: ");
		for (j = left; j < right; j++)
			printf("%d, ", array[j]);
		printf("%d\n", array[j]);

		j = left + (right - left) / 2;
		if (array[j] == value)
			return (j);
		if (array[j] > value)
			right = j - 1;
		else
			left = j + 1;
	}

	return (-1);
}

/**
 * exponential_search - a function that searches for a value
 *in an array of integers
 *using the Linear search algorithm binary_search
 * @array: is a pointer to the first element of the array to search in.
 * @size:  is the number of elements in array.
 * @value: is the value to search for.
 *
 * Return: must return the first index where value is located
 *If value is not present or if array is NULL, your function must return -1
*/

int exponential_search(int *array, size_t size, int value)
{
	size_t i = 0, right;

	if (array == NULL)
		return (-1);

	if (array[0] != value)
	{
		for (i = 1; i < size && array[i] <= value; i = i * 2)
			printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	}

	right = i < size ? i : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", i / 2, right);

	return (_binary_search(array, i / 2, right, value));
}
