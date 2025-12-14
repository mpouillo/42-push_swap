/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:11:33 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/14 18:50:02 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests/tests.h"

void	print_stack(t_stack *stack)
{
	t_node	*cur;

	cur = stack->head;
	ft_printf("Printing current stack:\n");
	ft_printf("#--------------------------------------------#\n");
	ft_printf("| %-10s -> %-10s -> %-10s |\n", "PREV", "CURRENT (item)", "NEXT");
	ft_printf("#--------------------------------------------#\n");
	if (!cur)
		ft_printf("| %-42s |\n", "EMPTY");
	while (cur)
	{
		ft_printf("| %-10p -> %-10p (%i) -> %-10p |\n", cur->prev, cur, cur->item, cur->next);
		cur = cur->next;
	}
	ft_printf("#--------------------------------------------#\n");
}

int main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc > 2)
	{
		stack = stack_create(argv + 1, argc - 1);
		if (!stack)
		{
			ft_printf("An error occurred when creating the stack.\n");
			return (1);
		}
	}
	else
	{
		ft_printf("Creating empty stack (no arguments passed to the function)\n");
		stack = stack_create(NULL, 0);
		if (!stack)
		{
			ft_printf("An error occurred when creating the stack.\n");
			return (1);
		}
	}
	
	test_disorder(stack);
	test_stack(stack);
	
	stack_delete(stack);
	return (0);
}