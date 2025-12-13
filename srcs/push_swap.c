/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 10:29:29 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/13 16:08:07 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		item;

	if (argc < 2)
		return (-1);

	stack = stack_create(argv + 1, argc - 1);

	ft_printf("Popping input values:\n");
	while ((item = stack_pop(stack)))
		ft_printf("%i\n", item);

	ft_printf("Adding test values (1, 2, 3).\n");
	for (int i = 1; i < 4; i++)
		stack_push(stack, i);

	ft_printf("Popping test values:\n");
	while ((item = stack_pop(stack)))
		ft_printf("%i\n", item);
	return (0);
}