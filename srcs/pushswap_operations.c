/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:48:47 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/15 12:48:47 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// sa (swap a): Swap the first two elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	sa(t_stack *a)
{
	stack_swap(a);
	ft_printf("sa\n");
}

// sb (swap b): Swap the first two elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	sb(t_stack *b)
{
	stack_swap(b);
	ft_printf("sb\n");
}

// ss : sa and sb at the same time.
void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	ft_printf("ss\n");
}

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	pa(t_stack *a, t_stack *b)
{
	if (!a || !b || b->length == 0)
		return ;
	stack_push(a, stack_pop(b));
	ft_printf("pa\n");
}

// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	pb(t_stack *a, t_stack *b)
{
	if (!a || !b || a->length == 0)
		return ;
	stack_push(b, stack_pop(a));
	ft_printf("pb\n");
}

// ra (rotate a): Shift up all elements of stack a by one.
// The first element becomes the last one.
void	ra(t_stack *a)
{
	stack_rotate_up(a);
	ft_printf("ra\n");
}

// rb (rotate b): Shift up all elements of stack b by one.
// The first element becomes the last one.
void	rb(t_stack *b)
{
	stack_rotate_up(b);
	ft_printf("rb\n");
}

// rr : ra and rb at the same time.
void	rr(t_stack *a, t_stack *b)
{
	stack_rotate_up(a);
	stack_rotate_up(b);
	ft_printf("rr\n");
}
// rra (reverse rotate a): Shift down all elements of stack a by one.
// The last element becomes the first one.
void	rra(t_stack *a)
{
	stack_rotate_down(a);
	ft_printf("rra\n");
}

// rrb (reverse rotate b): Shift down all elements of stack b by one.
// The last element becomes the first one.
void	rrb(t_stack *b)
{
	stack_rotate_down(b);
	ft_printf("rrb\n");
}

// rrr : rra and rrb at the same time.
void	rrr(t_stack *a, t_stack *b)
{
	stack_rotate_down(a);
	stack_rotate_down(b);
	ft_printf("rrr\n");
}
