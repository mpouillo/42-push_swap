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

static t_node	*find_smallest(t_stack *stack)
{
	t_node	*current;
	t_node	*smallest;

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

static int	shortest_path_direction(t_stack *stack, t_node *goal)
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

static void	move_smallest_to_top(
	t_pushswap *data, t_node *target, void (*r_function)(t_pushswap *)
)
{
	while (data->a->head != target)
		r_function(data);
}

void	selection_sort(t_pushswap *data)
{
	t_node	*smallest;

	data->complexity = "O(n²)";
	if (check_stack_sorted(data->a) == SUCCESS)
		return ;
	while (data->a->length > 3)
	{
		if (check_stack_sorted(data->a) == SUCCESS)
			break ;
		smallest = find_smallest(data->a);
		if (shortest_path_direction(data->a, smallest) == CW)
			move_smallest_to_top(data, smallest, ra);
		else
			move_smallest_to_top(data, smallest, rra);
		pb(data);
	}
	sort_three(data);
	while (data->b->length > 0)
		pa(data);
}
