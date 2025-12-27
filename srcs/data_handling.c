/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 09:59:18 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/27 09:59:18 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	delete_data(t_pushswap *data)
{
	stack_delete(data->a);
	stack_delete(data->b);
	free(data);
}

void	init_data(t_pushswap *data)
{
	data->a = NULL;
	data->b = NULL;
	data->bench_mode = 0;
	data->disorder = 0;
	data->strategy = 0;
	data->complexity = NULL;
	data->total_ops = 0;
	data->sa_count = 0;
	data->sb_count = 0;
	data->ss_count = 0;
	data->pa_count = 0;
	data->pb_count = 0;
	data->ra_count = 0;
	data->rb_count = 0;
	data->rr_count = 0;
	data->rra_count = 0;
	data->rrb_count = 0;
	data->rrr_count = 0;
}