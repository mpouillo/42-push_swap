/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 00:23:43 by marvin            #+#    #+#             */
/*   Updated: 2026/01/24 09:38:30 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static size_t	calculate_max_bits(t_pushswap *data)
{
	size_t	max_index;
	size_t	max_bits;

	max_index = data->a->length - 1;
	max_bits = 0;
	while (max_index >> max_bits != 0)
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

static void	push_back_to_a(t_pushswap *data, size_t i, size_t max_bits)
{
	size_t	length_b;
	size_t	j;

	j = 0;
	length_b = data->b->length;
	while (j < length_b)
	{
		if ((data->b->head->index >> (i + 1)) & 1 || i + 1 == max_bits)
			pa(data);
		else
			rb(data);
		j++;
	}
}

static void	sort(t_pushswap *data)
{
	size_t	length_a;
	size_t	max_bits;
	size_t	i;
	size_t	j;

	i = 0;
	max_bits = calculate_max_bits(data);
	while (i < max_bits)
	{
		j = 0;
		length_a = data->a->length;
		while (j < length_a)
		{
			if ((data->a->head->index >> i) & 1)
				ra(data);
			else if (check_stack_sorted(data->a) == -1)
				pb(data);
			j++;
		}
		push_back_to_a(data, i, max_bits);
		i++;
	}
}

void	radix_sort(t_pushswap *data)
{
	data->complexity = "O(nlog(n))";
	if (check_stack_sorted(data->a) == SUCCESS)
		return ;
	if (data->a->length <= 5)
	{
		selection_sort(data);
		return ;
	}
	create_sorted_array(data);
	index_stack(data);
	sort(data);
	free(data->array);
	data->array = NULL;
}
