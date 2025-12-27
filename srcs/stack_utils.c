/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:20:19 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/27 10:25:13 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Create a new node and set its value to item.
t_node	*node_create(int item)
{
	t_node	*node;

	node = (t_node *) ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node->item = item;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

// Get the last node from a list of nodes.
t_node	*node_get_last(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

// Add new to the end of of a list of nodes.
void	node_add_back(t_node **node, t_node *new)
{
	t_node	*last;

	if (!*node)
		*node = new;
	else
	{
		last = node_get_last(*node);
		last->next = new;
		new->prev = last;
	}
}

// Initialize a stack.
t_stack	*stack_init(t_stack *stack, char **item_list, int size)
{
	int		i;
	t_node	*node;

	stack->head = NULL;
	stack->length = 0;
	i = 0;
	while (i < size)
	{
		node = node_create(ft_atoi(item_list[i]));
		if (!node)
		{
			stack_delete(stack);
			return (NULL);
		}
		node_add_back(&(stack->head), node);
		stack->length += 1;
		i++;
	}
	return (stack);
}

// Create a stack and fill it with a list of items.
t_stack	*stack_create(char **item_list, size_t size)
{
	t_stack *stack;

	stack = (t_stack *) ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack = stack_init(stack, item_list, size);
	if (!stack)
		return (NULL);
	return (stack);
}

void	stack_delete(t_stack *stack)
{
	t_node *current;
	t_node	*tmp;

	if (!stack)
		return ;
	current = stack->head;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(stack);
	stack = NULL;
}