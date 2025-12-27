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
void	sa(t_pushswap *data)
{
	stack_swap(data->a);
	data->sa_count += 1;
	data->total_ops += 1;
	ft_printf("sa\n");
}

// sb (swap b): Swap the first two elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	sb(t_pushswap *data)
{
	stack_swap(data->b);
	data->sb_count += 1;
	data->total_ops += 1;
	ft_printf("sb\n");
}

// ss : sa and sb at the same time.
void	ss(t_pushswap *data)
{
	stack_swap(data->a);
	stack_swap(data->b);
	data->ss_count += 1;
	data->total_ops += 1;
	ft_printf("ss\n");
}

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	pa(t_pushswap *data)
{
	if (!data->a || !data->b || data->b->length == 0)
		return ;
	stack_push(data->a, stack_pop(data->b));
	data->pa_count += 1;
	data->total_ops += 1;
	ft_printf("pa\n");
}

// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	pb(t_pushswap *data)
{
	if (!data->a || !data->b || data->a->length == 0)
		return ;
	stack_push(data->b, stack_pop(data->a));
	data->pb_count += 1;
	data->total_ops += 1;
	ft_printf("pb\n");
}

// ra (rotate a): Shift up all elements of stack a by one.
// The first element becomes the last one.
void	ra(t_pushswap *data)
{
	stack_rotate_up(data->a);
	data->ra_count += 1;
	data->total_ops += 1;
	ft_printf("ra\n");
}

// rb (rotate b): Shift up all elements of stack b by one.
// The first element becomes the last one.
void	rb(t_pushswap *data)
{
	stack_rotate_up(data->b);
	data->rb_count += 1;
	data->total_ops += 1;
	ft_printf("rb\n");
}

// rr : ra and rb at the same time.
void	rr(t_pushswap *data)
{
	stack_rotate_up(data->a);
	stack_rotate_up(data->b);
	data->rr_count += 1;
	data->total_ops += 1;
	ft_printf("rr\n");
}
// rra (reverse rotate a): Shift down all elements of stack a by one.
// The last element becomes the first one.
void	rra(t_pushswap *data)
{
	stack_rotate_down(data->a);
	data->rra_count += 1;
	data->total_ops += 1;
	ft_printf("rra\n");
}

// rrb (reverse rotate b): Shift down all elements of stack b by one.
// The last element becomes the first one.
void	rrb(t_pushswap *data)
{
	stack_rotate_down(data->b);
	data->rrb_count += 1;
	data->total_ops += 1;
	ft_printf("rrb\n");
}

// rrr : rra and rrb at the same time.
void	rrr(t_pushswap *data)
{
	stack_rotate_down(data->a);
	stack_rotate_down(data->b);
	data->rrr_count += 1;
	data->total_ops += 1;
	ft_printf("rrr\n");
}
