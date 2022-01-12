#include "sort.h"
#include <stdio.h>

void quicksort(int *arr, ssize_t, ssize_t, size_t);
ssize_t partition(int *, ssize_t, ssize_t, size_t);
void swap(int *, int *, int *, size_t);
/**
  * quick_sort - sort an array using quicksort
  * @array: the array to be sorted
  * @size: size of array
  * Return: nothing
  */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}

/**
  * quicksort - the actual quicksort algorithm
  * @arr: the array to be sorted
  * @st: starting index
  * @end: last index
  * @size: size of arr (mainly for printing in partition)
  * Return: nothing
  */
void quicksort(int *arr, ssize_t st, ssize_t end, size_t size)
{
	ssize_t p_idx;

	if (st >= end)
		return;

	p_idx = partition(arr, st, end, size);

	quicksort(arr, st, p_idx - 1, size);
	quicksort(arr, p_idx + 1, end, size);
}

/**
  * partition - divides the array using the Lomuto partition scheme
  * @arr: the array
  * @st: starting index for the range to be partitioned
  * @end: last index
  * @size: size of arr (mainly for the printing)
  * Return: index of the pivot
  */
ssize_t partition(int *arr, ssize_t st, ssize_t end, size_t size)
{
	ssize_t i, j;
	int pivot;

	pivot = arr[end];
	i = st - 1;
	for (j = st; j < end; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j], arr, size);
		}
	}
	i++;
	swap(&arr[i], &arr[end], arr, size);

	return (i);
}

/**
  * swap - interchanges two items
  * @num1: first number
  * @num2: second number
  * @arr: the arr (just for the printing)
  * @size: size of arr (for printing)
  * Return: nothing
  */
void swap(int *num1, int *num2, int *arr, size_t size)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
	if (*num1 != *num2)
		print_array(arr, size);
}
