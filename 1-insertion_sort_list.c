#include "sort.h"

void swap(listint_t **, listint_t **, listint_t **);
/**
  * insertion_sort_list - uses insertion sort to sort a dll
  * @list: the list to be sorted
  * Return: nothing
  */
void insertion_sort_list(listint_t **list)
{
	listint_t *prev, *curr, *next;

	curr = (*list)->next;
	while (curr)
	{
		next = curr;
		while (next && next->prev && next->prev->n > next->n)
		{
			prev = next->prev;
			swap(list, &prev, &next);
		}

		curr = curr->next;
	}
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
