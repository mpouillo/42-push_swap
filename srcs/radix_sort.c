/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 00:23:43 by marvin            #+#    #+#             */
/*   Updated: 2026/01/21 16:09:17 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static size_t	calculate_max_bits(t_pushswap *data)
{
	size_t	max_index;
	size_t	max_bits;

	max_index = data->a->length - 1;
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	index_stack(t_pushswap *data)
{
	t_node	*current;
	size_t	i;

	current = data->a->head;
	while (current)
	{
		i = 0;
		while (i < data->a->length)
		{
			if (current->item == data->array[i])
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

static void	sort(t_pushswap *data)
{
	size_t	length;
	size_t	max_bits;
	size_t	i;
	size_t	j;	

	length = data->a->length;
	max_bits = calculate_max_bits(data);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < length)
		{
			if (((data->a->head->index >> i) & 1) == 1)
				ra(data);
			else
				pb(data);
			j++;
		}
		while (data->b->length > 0)
			pa(data);
		i++;
	}
}

void	radix_sort(t_pushswap *data)
{
	data->complexity = "O(n log(n))";
	create_sorted_array(data);
	if (!data->array)
		error_termination(data);
	index_stack(data);
	sort(data);
	free(data->array);
	data->array = NULL;
}
