#include "sort.h"

/**
 * change_nodes - exchanges the values of two elements of type integer
 * @array: array
 * @a: integer
 * @b: integer
 * @size: size of the array
 */
void change_nodes(int *array, int a, int b, size_t size)
{
	int temp;

	if (array[a] != array[b])
	{
		temp = array[a];
		array[a] = array[b];
		array[b] = temp;
		print_array(array, size);
	}
}

/**
 * divide_array - array partitioning
 * @array: array
 * @left: integer
 * @right: integer
 * @size: size of the array
 * Return: int
 */
int divide_array(int *array, int left, int right, size_t size)
{
	int i = left, j, pivot = array[right];

	for (j = left; j <= right; j++)
	{
		if (array[j] < pivot)
		{
			change_nodes(array, i, j, size);
			i++;
		}
	}
	change_nodes(array, i, right, size);

	return (i);
}

/**
 * quicksort_recursion - function that sorts
 * an array of integers using recursion
 * @array: array
 * @left: integer
 * @right: integer
 * @size: size of the array
 */
void quicksort_recursion(int *array, int left, int right, size_t size)
{
	int partition;

	if (left > right)
	{
		return;
	}
	partition = divide_array(array, left, right, size);
	quicksort_recursion(array, left, partition - 1, size);
	quicksort_recursion(array, partition + 1, right, size);
}

/**
 * quick_sort - function that sorts
 * an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quicksort_recursion(array, 0, size - 1, size);
}
