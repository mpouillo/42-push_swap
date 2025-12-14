/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 10:29:29 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/14 13:03:49 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		item;

	if (argc < 2)
		return (-1);

	// validate args (all numbers, no duplicates)

	stack = stack_create(argv + 1, argc - 1);
	if (!stack)
		return (-1);

	ft_printf("Popping input values:\n");
	while ((item = stack_pop(stack)))
		ft_printf("%i\n", item);

	ft_printf("Adding test values (1, 2, 3).\n");
	for (int i = 1; i < 4; i++)
		stack_push(stack, i);

	ft_printf("Popping test values:\n");
	while ((item = stack_pop(stack)))
		ft_printf("%i\n", item);

	stack_delete(stack);

	return (0);
}
