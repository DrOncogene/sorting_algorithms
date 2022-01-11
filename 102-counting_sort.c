#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

void countingsort(int *arr, size_t size, int max);
/**
  * counting_sort - sorts an array with counting sort
  * @array: the array
  * @size: size of arr
  * Return: nothing
  */
void counting_sort(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	countingsort(array, size, max);
}

/**
  * countingsort - the actual counting sort algorithm
  * @arr: array to be sorted
  * @size: size of arr
  * @max: maximum value in arr
  * Return: nothing
  */
void countingsort(int *arr, size_t size, int max)
{
	int *keys, *sorted, i, sort_idx;
	size_t k;
	ssize_t j;

	sorted = malloc(sizeof(int) * size);
	keys = malloc(sizeof(int) * (max + 1));
	for (i = 0; i <= max; i++)
		keys[i] = 0;
	for (k = 0; k < size; k++)
		keys[arr[k]] += 1;
	for (i = 1; i <= max; i++)
		keys[i] += keys[i - 1];

	print_array(keys, max + 1);

	for (j = size - 1; j >= 0; j--)
	{
		sort_idx = keys[arr[j] - 1];
		sorted[sort_idx] = arr[j];
		keys[arr[j]] -= 1;
	}
	for (k = 0; k < size; k++)
		arr[k] = sorted[k];

	free(keys);
	free(sorted);
}
