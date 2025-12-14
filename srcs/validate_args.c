/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:19:20 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/14 13:52:32 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	validate_args(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
				return (ERROR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	stack_find_item(t_node *node, int item)
{
	while (node)
	{
		if (node->item == item)
			return (SUCCESS);
		node = node->next;
	}
	return (ERROR);
}

int	check_duplicate(t_stack *stack)
{
	t_node *node;

	node = stack->head;
	while (node)
	{
		if (stack_find_item(node->next, node->item) == SUCCESS)
			return (ERROR);
		node = node->next;
	}
	return (SUCCESS);
}