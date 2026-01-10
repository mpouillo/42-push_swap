/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_operations_rr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 10:59:25 by mpouillo          #+#    #+#             */
/*   Updated: 2026/01/10 10:59:29 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
