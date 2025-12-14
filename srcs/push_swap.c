/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 10:29:29 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/14 17:10:39 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*stack2;
	t_node	*cur;
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

	ft_printf("Adding test values (4, 3, 2 ,1).\n");
	for (int i = 4; i > 0; i--)
		stack_push(stack, i);

	ft_printf("Popping test values:\n");
	while ((item = stack_pop(stack)))
		ft_printf("%i\n", item);

	ft_printf("Adding test values (4, 3, 2, 1).\n");
	for (int i = 4; i > 0; i--)
		stack_push(stack, i);

	ft_printf("Rotating stack up by 1:\n");
	stack_rotate_up(stack);
	cur = stack->head;
	while (cur)
	{
		ft_printf("%i\n", cur->item);
		cur = cur->next;
	}

	ft_printf("Rotating stack down by 1:\n");
	stack_rotate_down(stack);
	cur = stack->head;
	while (cur)
	{
		ft_printf("%i\n", cur->item);
		cur = cur->next;
	}

	ft_printf("Creating stack 2 (5, 6, 7, 8):\n");
	char *arr[4] = {"5", "6", "7", "8"};
	stack2 = stack_create(arr, 4);
	cur = stack2->head;
	while (cur)
	{
		ft_printf("%i\n", cur->item);
		cur = cur->next;
	}
	ft_printf("Swapping both stacks' first element:");
	stack_swap(stack, stack2);
	ft_printf("Stack 1:\n");
	cur = stack->head;
	while (cur)
	{
		ft_printf("%i\n", cur->item);
		cur = cur->next;
	}
	ft_printf("Stack 2:\n");
	cur = stack2->head;
	while (cur)
	{
		ft_printf("%i\n", cur->item);
		cur = cur->next;
	}

	// free and return
	stack_delete(stack);
	stack_delete(stack2);
	return (0);
}
