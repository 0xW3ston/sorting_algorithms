#include "s_header.h"
#include <stdio.h>
/**
 *swap_node - swap a nd
 *@nd: ND'th
 *@list: ND'th qrr
 *Return: return [PTR]
 */
listint_t *swap_node(listint_t *nd, listint_t **list)
{
	listint_t *_back = nd->prev, *curre = nd;

	_back->next = curre->next;
	if (curre->next)
		curre->next->prev = _back;
	curre->next = _back;
	curre->prev = _back->prev;
	_back->prev = curre;
	if (curre->prev)
		curre->prev->next = curre;
	else
		*list = curre;
	return (curre);
}
/**
 *cocktail_sort_list - this is a cocktail
 *@list: list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *nd;
	int end_swap = 1;

	if (list == '\0' || (*list) == '\0' || (*list)->next == '\0')
		return;
	nd = *list;
	while (end_swap == 1)
	{
		end_swap = 0;
		while (nd->next)
		{
			if (nd->n > nd->next->n)
			{
				nd = swap_node(nd->next, list);
				end_swap = 1;
				print_list(*list);
			}
			nd = nd->next;
		}
		if (end_swap == 0)
			break;
		end_swap = 0;
		while (nd->prev)
		{
			if (nd->n < nd->prev->n)
			{
				nd = swap_node(nd, list);
				end_swap = 1;
				print_list(*list);
			}
			else
				nd = nd->prev;
		}
	}
}
