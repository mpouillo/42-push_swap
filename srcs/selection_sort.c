/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 11:03:56 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/25 11:03:56 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#define CW	1
#define CCW	-1

t_node	*find_smallest(t_stack *stack)
{
	t_node *current;
	t_node *smallest;

	smallest = stack->head;
	current = stack->head;
	while (current)
	{
		if (current->item < smallest->item)
			smallest = current;
		current = current->next;
	}
	return (smallest);
}

int	shortest_path_direction(t_stack *stack, t_node *goal)
{
	t_node	*start;
	size_t	i;

	if (!stack || !stack->head)
		return (0);
	start = stack->head;
	i = 0;
	while (start && start != goal)
	{
		i++;
		start = start->next;
	}
	if (i <= stack->length / 2)
		return (CW);
	else
		return (CCW);
}

size_t	select_node(t_stack* a, t_stack *b, t_node *target, void (*r_function)(t_stack *))
{
	size_t	ret;

	ret = 0;
	while (a->head != target)
	{
		r_function(a);
		ret++;
	}
	pb(a, b);
	ret++;
	return (ret);
}

size_t	selection_sort(t_stack *a, t_stack *b)
{
	t_node	*smallest;
	size_t	ret;

	ret = 0;
	while (a->length > 0)
	{
		smallest = find_smallest(a);
		if (shortest_path_direction(a, smallest) == CW)
			ret += select_node(a, b, smallest, ra);
		else
			ret += select_node(a, b, smallest, rra);
	}
	while (b->length > 0)
	{
		pa(a, b);
		ret++;
	}
	return (ret);
}