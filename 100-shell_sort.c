#include "sort.h"

void insertion_sort(int *arr, size_t size);

/**
  * shell_sort - sorts an array using shell sort with knuth seq
  * @arr: the array to be sorted
  * @size: size of array
  * Return: nothing
  */
void shell_sort(int *arr, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (arr == NULL || size <= 2)
		return;
	gap = 1;
	while (gap < size)
		gap = (gap * 3) + 1;

	while (gap > 1)
	{
		gap = (gap - 1) / 3;
		print_array(arr, size);
		if (gap <= 1)
			break;

		for (i = 0; i < size - gap; i++)
		{
			j = i;
			while (j < size)
			{
				j += gap;
				if (j >= size)
					break;

				if (arr[j - gap] <= arr[j])
					continue;
				temp = arr[j];
				arr[j] = arr[j - gap];
				arr[j - gap] = temp;
			}
		}
	}
	insertion_sort(arr, size);
}

/**
  * insertion_sort - sorts an array using insertion sort
  * @arr: the array
  * @size: size of arr
  * Return: nothing
  */
void insertion_sort(int *arr, size_t size)
{
	size_t i;
	ssize_t j;
	int temp;

	if (arr == NULL || size <= 2)
		return;

	for (i = 1; i < size; i++)
	{
		j = i;
		while (arr[j - 1] > arr[j] && j >= 0)
		{
			temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}
	}
}
