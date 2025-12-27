/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:19:20 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/27 08:54:33 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_digits(char **args)
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

void	validate_args(char **argv, int argc)
{
	t_stack *stack;

	if (check_digits(argv) == ERROR)
		error_termination();
	stack = stack_create(argv, argc);
	if (check_duplicate(stack) == ERROR)
	{
		stack_delete(stack);
		error_termination();
	}
	stack_delete(stack);
}