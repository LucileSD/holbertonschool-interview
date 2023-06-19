#include "sort.h"
/**
 * merge_sort - sorts an array of integers in
 * ascending order using the Merge sort algorithm
 * @array: pointer on the array
 * @size: the size of the array
 * Return: None
 */
void merge_sort(int *array, size_t size)
{
	int *arr_tmp;

	if (!array || size < 2)
		return;

	arr_tmp = malloc(sizeof(int) * size);
	if (!arr_tmp)
		return;

	merge_sort_recursion(array, arr_tmp, 0, size);

	free(arr_tmp);
}

/**
 * merge_sort_recursion - recursion for divide the array
 * @array: pointer on the array
 * @arr_tmp: pointer on the sub array
 * @left: the left side of the array
 * @right: the right side of the array
 */
void merge_sort_recursion(int *array, int *arr_tmp, size_t left, size_t right)
{
	size_t middle;

	if ((right - left) > 1)
	{
		middle = left + (right - left) / 2;
		merge_sort_recursion(array, arr_tmp, left, middle);
		merge_sort_recursion(array, arr_tmp, middle, right);

		merge_sorted_arrays(array, arr_tmp, left, middle, right);
	}
}

/**
 * merge_sorted_arrays - sorts the different arrays
 * @array: pointer on the array
 * @arr_tmp: pointer on the sub array
 * @left: left side of the array
 * @middle: the pivot of the array
 * @right: right side of the array
 */
void merge_sorted_arrays(int *array, int *arr_tmp, size_t left,
size_t middle, size_t right)
{
	size_t i = left, j = middle, k;

	printf("Merging...\n[left]: ");
	print_array(array + left, middle - left);

	printf("[right]: ");
	print_array(array + middle, right - middle);


	for (k = left; k < right; k++)
	{
		if (i < middle && (j >= right || array[i] <= array[j]))
		{
			arr_tmp[k] = array[i];
			i++;
		}
		else
		{
			arr_tmp[k] = array[j];
			j++;
		}
	}
	for (i = left; i < right; i++)
		array[i] = arr_tmp[i];

	printf("[Done]: ");
	print_array(array + left, right - left);
}
