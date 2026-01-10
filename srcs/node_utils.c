/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 10:50:51 by mpouillo          #+#    #+#             */
/*   Updated: 2026/01/10 12:23:12 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Create a new node and set its value to item.
t_node	*node_create(t_pushswap *data, int item)
{
	t_node	*node;

	node = (t_node *) ft_calloc(1, sizeof(t_node));
	if (!node)
		error_termination(data);
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
