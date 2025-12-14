/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:17:51 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/14 17:37:46 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Remove and return the topmost item from a stack.
int	stack_pop(t_stack *stack)
{
	t_node	*node;
	int		item;

	if (!stack || stack->length < 1)
		return (0); // jsp ce qu'on est censé return si la liste est vide
	node = stack->head;
	stack->head = node->next;
	if (stack->head)
		stack->head->prev = NULL;
	item = node->item;
	free(node);
	stack->length -= 1;
	return (item);
}

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.

// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.

// Add an item at the top of a stack.
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

/*
void	pa(t_stack *b, t_stack *a)
{
	stack_push(a, stack_pop(b));
}
*/

// sa (swap a): Swap the first two elements at the top of stack a.
// Do nothing if there is only one or no elements.

// sb (swap b): Swap the first two elements at the top of stack b.
// Do nothing if there is only one or no elements.

// ss : sa and sb at the same time.

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

// ra (rotate a): Shift up all elements of stack a by one.
// The first element becomes the last one.

// rb (rotate b): Shift up all elements of stack b by one.
// The first element becomes the last one.

// rr : ra and rb at the same time.

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

// rra (reverse rotate a): Shift down all elements of stack a by one.
// The last element becomes the first one.

// rrb (reverse rotate b): Shift down all elements of stack b by one.
// The last element becomes the first one.

// rrr : rra and rrb at the same time.

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