/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:11:28 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/14 18:52:24 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_stack(t_stack *stack)
{
	int		item;

	print_stack(stack);

	ft_printf("Popping input values...\n");
	while ((item = stack_pop(stack)))
		ft_printf("%i\n", item);
	print_stack(stack);
	
	ft_printf("Adding test values (4, 3, 2, 1)...\n");
	for (int i = 4; i > 0; i--)
		stack_push(stack, i);
	print_stack(stack);

	ft_printf("Popping test values...\n");
	while ((item = stack_pop(stack)))
		ft_printf("%i\n", item);
	print_stack(stack);

	ft_printf("Adding test values (4, 3, 2, 1)...\n");
	for (int i = 4; i > 0; i--)
		stack_push(stack, i);
	print_stack(stack);

	ft_printf("Rotating stack up by 1...\n");
	stack_rotate_up(stack);
	print_stack(stack);

	ft_printf("Rotating stack down by 1...\n");
	stack_rotate_down(stack);
	print_stack(stack);

	ft_printf("Swapping the stack's first two elements...\n");
	stack_swap(stack);
	print_stack(stack);
}