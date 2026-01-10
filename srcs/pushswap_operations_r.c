/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_operations_r.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 10:59:00 by mpouillo          #+#    #+#             */
/*   Updated: 2026/01/10 10:59:05 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
