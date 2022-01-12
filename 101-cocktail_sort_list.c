#include "sort.h"

size_t len(listint_t *list);
void swap(listint_t **, listint_t **, listint_t **);
/**
  * cocktail_sort_list - cocktail sort algorithm for a dll
  * @list: head of the list
  * Return: nothing
  */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr, *next;
	int swapped;

	if (list == NULL || *list == NULL || len(*list) < 2)
		return;

	curr = *list;
	swapped = 0;
	while (curr && curr->next)
	{
		next = curr->next;
		if (curr->n > next->n)
		{
			swapped = 1;
			swap(list, &curr, &next);
			curr = next->next;
		}
		else
			curr = next;
	}

	while (curr && curr->prev && swapped == 1)
	{
		next = curr->prev;
		if (next->n > curr->n)
		{
			swapped = 1;
			swap(list, &next, &curr);
			curr = next->prev;
		}
		else
			curr = next;
	}
	if (swapped == 0)
		return;

	cocktail_sort_list(list);
}

/**
  * swap - swaps the positions of two items in a dll
  * @head: head of the list
  * @first: the first item
  * @second: second item
  * Return: nothing
  */
void swap(listint_t **head, listint_t **first, listint_t **second)
{
	if (*first && (*first)->prev)
	{
		(*first)->prev->next = *second;
		(*second)->prev = (*first)->prev;
		if ((*second)->next)
			(*second)->next->prev = *first;
		(*first)->next = (*second)->next;
		(*first)->prev = *second;
		(*second)->next = *first;
		print_list(*head);
	}
	else if (*first)
	{
		(*first)->next = (*second)->next;
		(*second)->next->prev = *first;
		(*first)->prev = *second;
		(*second)->prev = NULL;
		(*second)->next = *first;
		*head = *second;
		print_list(*head);
	}
}

/**
  * len - computes the length of a list
  * @list: head of the list
  * Return: the length
  */
size_t len(listint_t *list)
{
	size_t i;
	listint_t *curr;

	curr = list;
	while (curr)
	{
		i += 1;
		curr = curr->next;
	}

	return (i);
}
