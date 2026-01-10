/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 09:44:21 by mpouillo          #+#    #+#             */
/*   Updated: 2026/01/10 12:51:32 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	*get_strategy_string(t_pushswap *data)
{
	if (data->strategy == STRATEGY_SIMPLE)
		return ("Simple");
	else if (data->strategy == STRATEGY_MEDIUM)
		return ("Medium");
	else if (data->strategy == STRATEGY_COMPLEX)
		return ("Complex");
	else
		return ("Adaptive");
}

void	print_benchmark(t_pushswap *data)
{
	ft_dprintf(STDERR_FILENO, "[bench] disorder:  %.2i.%.2i%%\n",
		data->disorder / 10, data->disorder % 100);
	ft_dprintf(STDERR_FILENO, "[bench] strategy:  %s / %s\n",
		get_strategy_string(data), data->complexity);
	ft_dprintf(STDERR_FILENO, "[bench] total ops: %i\n",
		data->total_ops);
	ft_dprintf(STDERR_FILENO, "[bench] sa: %5u,  sb: %5u,  ss: %5u,  \
pa:  %5u,  pb:  %5u,\n", data->sa_count, data->sb_count,
		data->ss_count, data->pa_count, data->pb_count);
	ft_dprintf(STDERR_FILENO, "[bench] ra: %5u,  rb: %5u,  rr: %5u,  \
rra: %5u,  rrb: %5u,  rrr: %5u\n", data->ra_count, data->rb_count,
		data->rr_count, data->rra_count, data->rrb_count, data->rrr_count);
}
