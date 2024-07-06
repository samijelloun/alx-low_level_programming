#include "search_algos.h"

/**
 * interpolation_search - a function that searches for a value in an array
 *of integers sing the interpolation search algorithm
 *
 * @array: is a pointer to the first element of the array to search in.
 * @size:  is the number of elements in array.
 * @value: is the value to search for.
 *
 * Return: must return the first index where value is located
 *If value is not present or if array is NULL, your function must return -1
*/

int interpolation_search(int *array, size_t size, int value)
{
	size_t mid, lo, hi;
	double g;

	if (array == NULL)
		return (-1);

	lo = 0;
	hi = size - 1;

	while (size)
	{
		g = (double)(hi - lo) / (array[hi] - array[lo]) * (value - array[lo]);
		mid = (size_t)(lo + g);
		printf("Value checked array[%d]", (int)mid);

		if (mid >= size)
		{
			printf(" is out of range\n");
			break;
		}
		else
			printf(" = [%d]\n", array[mid]);

		if (array[mid] == value)
			return ((int)mid);
		if (array[mid] < value)
			lo = mid + 1;
		else
			hi = mid - 1;

		if (lo == hi)
			break;
	}
	return (-1);
}
