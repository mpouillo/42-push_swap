/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_based_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaze <kaze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:03:13 by kaze              #+#    #+#             */
/*   Updated: 2026/01/11 16:51:12 by kaze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


static size_t	get_minmax(t_stack *stack, char mode)
{
	t_node	*current;
	t_node	*to_find;

	to_find = stack->head;
	current = stack->head;
	if (mode == 'm')
	{
		while (current)
		{
			if (current->item < to_find->item)
				to_find = current;
			current = current->next;
		}
		return (to_find->item);
	}
	if (mode == 'M')
	{
		while (current)
		{
			if (current->item > to_find->item)
				to_find = current;
			current = current->next;
		}
		return (to_find->item);
	}
}

void	chunk_based_sort(t_pushswap *data)
{
	t_node	*current;
	size_t	min;
	size_t	max;
	size_t	step;
	size_t	i;

	data->complexity = "O(n√n)";
	min = get_minmax(data->a, 'm');
	max = get_minmax(data->a, 'M');
	step = (max - min) / ft_sqrt(data->a->length); //TODO
	i = 0;
	while (min + i * step < max)
	{
		current = data->a->head;
		while (current)
		{
			if (min + i * step <= data->a->head->item && data->a->head->item <= min + (i + 1) * step)
			{
				pb(data);
				if (data->a->head->item < ((min + i + 1 * step) - (min + i * step)) / 2)
					rb(data);
			}
			current = current->next;
		}
	}
}

