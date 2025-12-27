/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:49:07 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/27 14:55:16 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// DEPRECATED.
// Remove and return the topmost item from a stack.
// SIGSEV if stack is empty.
int	stack_pop(t_stack *stack)
{
	t_node	*node;
	int		item;

	node = stack->head;
	stack->head = stack->head->next;
	if (stack->head)
		stack->head->prev = NULL;
	item = node->item;
	free(node);
	stack->length -= 1;
	return (item);
}

// Add an item to the top of the stack.
void	stack_push(t_stack *stack, int item)
{
	t_node	*node;

	node = node_create(item);
	node->next = stack->head;
	node->prev = NULL;
	if (stack->head)
		stack->head->prev = node;
	stack->head = node;
	stack->length += 1;
}

// Swap the first two elements at the top of the stack.
// Do nothing if there is only one or no elements.
void	stack_swap(t_stack *stack)
{
	t_node *node;

	if (!stack || stack->length < 2)
		return ;
	node = stack->head->next;
	stack->head->prev = node;
	stack->head->next = node->next;
	node->prev = NULL;
	node->next = stack->head;
	stack->head = node;
}

// Shift up all elements of stack a by one.
// The first element becomes the last one.
void	stack_rotate_up(t_stack *stack)
{
	t_node	*node;
	t_node	*last;

	if (!stack || stack->length < 2)
		return ;
	last = node_get_last(stack->head);
	node = stack->head->next;
	node->prev = NULL;
	stack->head->prev = last;
	stack->head->next = NULL;
	last->next = stack->head;
	stack->head = node;
}

// Shift down all elements of stack a by one.
// The last element becomes the first one.
void	stack_rotate_down(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->length < 2)
		return ;
	node = node_get_last(stack->head);
	node->next = stack->head;
	node->prev->next = NULL;
	node->prev = NULL;
	stack->head->prev = node;
	stack->head = node;
}

int	check_stack_sorted(t_stack *stack)
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
