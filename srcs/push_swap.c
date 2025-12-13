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

	(void) argc;
	(void) argv;
	char	tmp[] = {1, 2, 3};
	stack = stack_create(tmp, 3);
	__builtin_printf("%i\n", (stack->head)->item);
	stack_pop(stack);
	__builtin_printf("%i\n", (stack->head)->item);
	return (0);
}