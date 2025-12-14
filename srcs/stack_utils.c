/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:20:19 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/14 13:13:19 by mpouillo         ###   ########.fr       */
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
static void	node_add_back(t_node **node, t_node *new)
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

	if (!item_list)
		return (NULL);
	stack = (t_stack *) ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack = stack_init(stack, item_list, size);
	if (!stack)
		return (NULL);
	return (stack);
}

// Add an item to the top of a stack.
void	stack_push(t_stack *stack, int item)
{
	t_node	*node;

	if (!stack)
		return ;
	node = node_create(item);
	node->next = stack->head;
	stack->head = node;
	stack->length += 1;
}

// Remove and return the topmost item from a stack.
int	stack_pop(t_stack *stack)
{
	t_node	*node;
	int		item;

	if (!stack)
		return (0); // jsp ce qu'on est censé return si la liste est vide
	node = stack->head;
	if (node == NULL)
		return (0); // jsp ce qu'on est censé return si la liste est vide
	stack->head = node->next;
	item = node->item;
	free(node);
	stack->length -= 1;
	return (item);
}

void	stack_delete(t_stack *stack)
{
	t_node *current;
	t_node	*tmp;

	current = stack->head;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(stack);
}