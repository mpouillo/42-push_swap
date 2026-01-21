/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:20:19 by mpouillo          #+#    #+#             */
/*   Updated: 2026/01/21 14:55:01 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Create stack a and fill it with values from argv
void	stack_init_a(t_pushswap *data)
{
	int		i;
	t_node	*node;

	data->a = (t_stack *) ft_calloc(1, sizeof(t_stack));
	if (!data->a)
		error_termination(data);
	data->a->head = NULL;
	data->a->length = 0;
	i = 0;
	while (data->argv[i])
	{
		node = node_create(data, ft_atoi(data->argv[i]), 0);
		node_add_back(&(data->a->head), node);
		data->a->length += 1;
		i++;
	}
}

// Create an empty stack b
void	stack_init_b(t_pushswap *data)
{
	data->b = (t_stack *) ft_calloc(1, sizeof(t_stack));
	if (!data->b)
		error_termination(data);
	data->b->head = NULL;
	data->b->length = 0;
}

void	stack_delete(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;

	if (!stack)
		return ;
	current = stack->head;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
		tmp = NULL;
	}
	free(stack);
}

int	check_stack_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->head;
	while (node && node->next)
	{
		if (node->item > node->next->item)
			return (ERROR);
		node = node->next;
	}
	return (SUCCESS);
}
