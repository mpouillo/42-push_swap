/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 10:29:29 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/14 14:34:31 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		item;
	int		disorder;

	// validate input args
	if (argc < 2 || validate_args(argv + 1) == ERROR)
	{
		ft_printf("Invalid arguments. Only numbers are allowed.\n");
		return (1);
	}

	// create stack
	stack = stack_create(argv + 1, argc - 1);
	if (!stack)
	{
		ft_printf("An error occurred when creating the stack.\n");
		return (1);
	}

	// check for duplicate values
	if (check_duplicate(stack) == ERROR)
	{
		ft_printf("Invalid arguments. Duplicates are not allowed.\n");
		stack_delete(stack);
		return (1);
	}

	// compute disorder
	disorder = compute_disorder(*stack);
	ft_printf("Disorder = %i.%.2i\n", disorder / 100, disorder % 100);

	// tests
	ft_printf("Popping input values:\n");
	while ((item = stack_pop(stack)))
		ft_printf("%i\n", item);
	ft_printf("Adding test values (1, 2, 3).\n");
	for (int i = 1; i < 4; i++)
		stack_push(stack, i);
	ft_printf("Popping test values:\n");
	while ((item = stack_pop(stack)))
		ft_printf("%i\n", item);

	// free and return
	stack_delete(stack);
	return (0);
}
