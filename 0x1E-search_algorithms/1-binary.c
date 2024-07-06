#include "search_algos.h"

/**
 * binary_search - a function that searches for a value in an array of integers
 *using the Linear search algorithm
 binary_search*
 * @array: is a pointer to the first element of the array to search in.
 * @size:  is the number of elements in array.
 * @value: is the value to search for.
 *
 * Return: must return the first index where value is located
 *If value is not present or if array is NULL, your function must return -1
*/

int binary_search(int *array, size_t size, int value)
{
	size_t start, mid, end, i;

	start = 0;
	end = size - 1;

	if (array == NULL || size == 0)
		return (-1);

	while (start <= end)
	{
		mid = (start + end) / 2;

		printf("Searching in array: ");
		for (i = start; i <= end; i++)
		{
			printf("%i", array[i]);
			if (i != end)
			{
				printf(", ");
			}
			else
			{
				printf("\n");
			}
		}
		if (array[mid] > value)
		{
			end = mid - 1;
		}
		else if (array[mid] < value)
		{
			start = mid + 1;
		}
		else
		{
			return (mid);
		}
	}
	return (-1);
}
