#include "search_algos.h"

/**
* advanced_binary - searches for a value in a sorted array of integers
* @array: a pointer to the first element of the array to search in
* @size: the number of elements in array
* @value: the value to search for
* Return: the index where value is located otherwise -1
*/
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);

	return (advanced_binary_recurse(array, 0, size - 1, value));
}


/**
 * advanced_binary_recurse - function that searches for a value
 * in a sorted array of integers recursively
 * @array: pointer to the first element of the array to search in
 * @low: left index of the array
 * @high: right index of the array
 * @value: value to search for
 * Return: first index where value is located otherwise -1
 */

int advanced_binary_recurse(int *array, size_t low, size_t high, int value)
{
	size_t idx, mid;

	mid = (low + high) / 2;

	printf("Searching in array: ");
	for (idx = low; idx < high; idx++)
	{
		printf("%d, ", array[idx]);
	}
	printf("%d\n", array[idx]);

	if (low >= high)
		return (-1);

	if (array[mid] == value && array[mid - 1] != value)
		return (mid);

	if (value <= array[mid])
		return (advanced_binary_recurse(array, low, mid, value));

	return (advanced_binary_recurse(array, mid + 1, high, value));
}
