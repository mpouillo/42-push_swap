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

size_t	insertion_sort(t_stack *a, t_stack *b)
{
	size_t	i;
	size_t	ret;

	i = 0;
	ret = 0;
	while (i < a->length)
	{
		i = 0;
		pb(a, b);
		ret++;
		while (i < a->length && b->head->item < node_get_last(a->head)->item)
		{
			rra(a);
			ret++;
			i++;
		}
		pa(a, b);
		ret++;
		if (check_all_good(a))
			break ;
		ra(a);
		ret++;
	}
	return (ret);
}