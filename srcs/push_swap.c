/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 10:29:29 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/26 23:00:41 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2 || validate_args(argv + 1) == ERROR)
	{
		ft_printf("Invalid arguments. Only numbers are allowed.\n");
		return (1);
	}

	a = stack_create(argv + 1, argc - 1);
	if (!a)
	{
		ft_printf("An error occurred when creating the stack.\n");
		return (1);
	}

	if (check_duplicate(a) == ERROR)
	{
		ft_printf("Invalid arguments. Duplicates are not allowed.\n");
		stack_delete(a);
		return (1);
	}

	b = stack_create(NULL, 0);
	selection_sort(a, b);

	stack_delete(a);
	stack_delete(b);
	return (0);
}
