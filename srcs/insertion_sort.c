/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 08:32:29 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/24 08:32:29 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_all_good(t_stack *stack)
{
	t_node	*node;

	node = stack->head;
	while (node && node->next)
	{
		if (node->item > node->next->item)
			return (0);
		node = node->next;
	}
	return (1);
}

void	insertion_sort(t_pushswap *data)
{
	size_t	i;

	i = 0;
	while (i < data->a->length)
	{
		i = 0;
		pb(data);
		while (i < data->a->length && data->b->head->item < node_get_last(data->a->head)->item)
		{
			rra(data);
			i++;
		}
		pa(data);
		if (check_all_good(data->a))
			break ;
		ra(data);
	}
}