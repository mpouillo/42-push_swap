/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 10:29:29 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/14 18:09:37 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2 || validate_args(argv + 1) == ERROR)
	{
		ft_printf("Invalid arguments. Only numbers are allowed.\n");
		return (1);
	}

	stack = stack_create(argv + 1, argc - 1);
	if (!stack)
	{
		ft_printf("An error occurred when creating the stack.\n");
		return (1);
	}

	if (check_duplicate(stack) == ERROR)
	{
		ft_printf("Invalid arguments. Duplicates are not allowed.\n");
		stack_delete(stack);
		return (1);
	}
	stack_delete(stack);
	return (0);
}
