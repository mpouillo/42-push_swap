/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   silent_pushswap_operations_p_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:48:47 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/15 12:48:47 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// pa (push a): Take the first element at
// the top of b and put it at the top of a.
// Do nothing if b is empty.
void	s_pa(t_pushswap *data)
{
	if (!data->a || !data->b || data->b->length == 0)
		return ;
	stack_push(data, data->a, data->b->head->index, stack_pop(data->b));
	data->pa_count += 1;
	data->total_ops += 1;
}

// pb (push b): Take the first element at
// the top of a and put it at the top of b.
// Do nothing if a is empty.
void	s_pb(t_pushswap *data)
{
	if (!data->a || !data->b || data->a->length == 0)
		return ;
	stack_push(data, data->b, data->a->head->index, stack_pop(data->a));
	data->pb_count += 1;
	data->total_ops += 1;
}
