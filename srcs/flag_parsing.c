/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 09:41:44 by mpouillo          #+#    #+#             */
/*   Updated: 2026/01/22 16:01:25 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Sets data->strategy and consumes an argv
static void	apply_strategy(t_pushswap *data, int strategy)
{
	data->strategy = strategy;
	data->argc -= 1;
	data->argv += 1;
}

// Checks the first 2 elements of data->argv and
// update strategy and bench_mode accordingly
void	parse_flags(t_pushswap *data)
{
	int	i;

	i = 0;
	while (data->argv[i] && (ft_strncmp(data->argv[i], "--", 2) == 0))
	{
		if (ft_strncmp(data->argv[i], "--bench", 8) == 0)
		{
			if (data->bench_mode)
				error_termination(data);
			data->bench_mode = 1;
			data->argv++;
			data->argc--;
		}
		else if (data->strategy)
			error_termination(data);
		if (ft_strncmp(data->argv[i], "--simple", 9) == 0)
			apply_strategy(data, STRATEGY_SIMPLE);
		else if (ft_strncmp(data->argv[i], "--medium", 9) == 0)
			apply_strategy(data, STRATEGY_MEDIUM);
		else if (ft_strncmp(data->argv[i], "--complex", 10) == 0)
			apply_strategy(data, STRATEGY_COMPLEX);
		else if (ft_strncmp(data->argv[i], "--adaptive", 11) == 0)
			apply_strategy(data, STRATEGY_ADAPTIVE);
		i++;
	}
}
