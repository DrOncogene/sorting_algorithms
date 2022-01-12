#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void mergesort(int *, size_t, size_t, int *);
void merge(int *, size_t, size_t, size_t, int *);
/**
  * merge_sort - sorts an array with merge sort
  * @arr: the array
  * @size: size of arr
  * Return: nothing
  */
void merge_sort(int *arr, size_t size)
{
	int *copy;
	size_t i;

	if (arr == NULL || size <= 2)
		return;

	copy = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
		copy[i] = arr[i];

	mergesort(arr, 0, size - 1, copy);
	free(copy);
}

/**
  * mergesort - recursively splits the array and marges array
  * @arr: the array
  * @st: start of the current subarray
  * @end: last index
  * @copy: a duplicate array
  * Return: nothing
  */
void mergesort(int *arr, size_t st, size_t end, int *copy)
{
	size_t mid, i;
	ssize_t size;

	size = end - st + 1;
	if (size <= 1)
		return;

	mid = (st + end) / 2;
	if (size % 2 == 0)
		mid++;

	mergesort(arr, st, mid - 1, copy);
	mergesort(arr, mid, end, copy);

	printf("Merging...\n");
	printf("[left]: ");
	for (i = st; i < mid; i++)
	{
		if (i > st)
			printf(", ");
		printf("%d", copy[i]);
	}
	printf("\n[right]: ");
	for (i = mid; i <= end; i++)
	{
		if (i > mid)
			printf(", ");
		printf("%d", copy[i]);
	}

	merge(arr, st, mid, end, copy);
	printf("\n[Done]: ");
	for (i = st; i <= end; i++)
	{
		if (i > st)
			printf(", ");
		printf("%d", copy[i]);
	}
	printf("\n");
}

/**
  * merge - merges the right and left subarrays
  * @arr: the array being sorted
  * @st: start of subarray
  * @mid: mid point
  * @end: last index
  * @copy: duplicate array
  * Return: nothing
  */
void merge(int *arr, size_t st, size_t mid, size_t end, int *copy)
{
	size_t i, j, k;

	i = k = st;
	j = mid;
	while (i < mid && j <= end)
	{
		if (arr[i] <= arr[j])
			copy[k] = arr[i++];
		else
			copy[k] = arr[j++];
		k++;
	}
	while (i < mid)
		copy[k++] = arr[i++];

	while (j <= end)
		copy[k++] = arr[j++];

	for (i = st; i <= end; i++)
		arr[i] = copy[i];
}
