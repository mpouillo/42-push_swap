/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:19:20 by mpouillo          #+#    #+#             */
/*   Updated: 2026/01/10 12:36:26 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_digits(char **args)
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

static int	stack_find_item(t_node *node, int item)
{
	while (node)
	{
		if (node->item == item)
			return (SUCCESS);
		node = node->next;
	}
	return (ERROR);
}

static int	check_duplicate(t_stack *stack)
{
	t_node	*node;

	node = stack->head;
	while (node)
	{
		if (stack_find_item(node->next, node->item) == SUCCESS)
			return (ERROR);
		node = node->next;
	}
	return (SUCCESS);
}

void	validate_args(t_pushswap *data)
{
	if (check_digits(data->argv) == ERROR)
		error_termination(data);
	stack_init_a(data);
	if (!data->a)
		error_termination(data);
	if (check_duplicate(data->a) == ERROR)
	{
		stack_delete(data->a);
		error_termination(data);
	}
	stack_delete(data->a);
}
