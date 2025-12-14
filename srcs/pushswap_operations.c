/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 23:13:28 by marvin            #+#    #+#             */
/*   Updated: 2025/12/14 23:13:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// sa (swap a): Swap the first two elements at the top of stack a.
// Do nothing if there is only one or no elements.
void    sa(t_stack *a)
{
    stack_swap(a);
}

// sb (swap b): Swap the first two elements at the top of stack b.
// Do nothing if there is only one or no elements.
void    sb(t_stack *b)
{
    stack_swap(b);
}

// ss : sa and sb at the same time.
void    ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
}

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	pa(t_stack *a, t_stack *b)
{
    if (!a || !b || b->length == 0)
        return ;
	stack_push(a, stack_pop(b));
}

// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	pb(t_stack *a, t_stack *b)
{
    if (!a || !b || a->length == 0)
        return ;
	stack_push(b, stack_pop(a));
}

// ra (rotate a): Shift up all elements of stack a by one.
// The first element becomes the last one.
void    ra(t_stack *a)
{
    stack_rotate_up(a);
}

// rb (rotate b): Shift up all elements of stack b by one.
// The first element becomes the last one.
void    rb(t_stack *b)
{
    stack_rotate_up(b);
}

// rr : ra and rb at the same time.
void    rr(t_stack *a, t_stack *b)
{
    stack_rotate_up(a);
    stack_rotate_up(b);
}
// rra (reverse rotate a): Shift down all elements of stack a by one.
// The last element becomes the first one.
void    rra(t_stack *a)
{
    stack_rotate_down(a);
}

// rrb (reverse rotate b): Shift down all elements of stack b by one.
// The last element becomes the first one.
void    rrb(t_stack *b)
{
    stack_rotate_down(b);
}

// rrr : rra and rrb at the same time.
void    rrr(t_stack *a, t_stack *b)
{
    stack_rotate_down(a);
    stack_rotate_down(b);
}