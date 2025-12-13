/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:20:19 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/13 16:05:43 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_init(t_stack *stack, char **item_list, int size)
{
	int		i;
	t_node	*node;

	stack->head = node;
	i = 0;
	while (i < size)
	{
		node = node_create(ft_atoi(item_list[i]));
		node = node->next;
		i++;
	}
	stack->length = size;
}

t_stack	*stack_create(char **item_list, int size)
{
	t_stack *stack;

	stack = (t_stack *) ft_calloc(1, sizeof(t_stack));
	stack_init(stack, item_list, size);
	return (stack);
}

// Creates a new node and sets its value to item.
t_node	*node_create(int item)
{
	t_node	*node;

	node = (t_node *) ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node->item = item;
	node->next = NULL;
	return (node);
}

void	stack_push(t_stack *stack, int item)
{
	t_node	*node;

	node = node_create(item);
	node->next = stack->head;
	stack->head = node;
	stack->length += 1;
}

t_node	*stack_pop(t_stack *stack)
{
	t_node	*node;

	node = stack->head;
	stack->head = node->next;
	stack->length -= 1;
	return (node);
}
