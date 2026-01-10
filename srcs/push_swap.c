/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 10:29:29 by mpouillo          #+#    #+#             */
/*   Updated: 2026/01/10 12:34:32 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	pick_algorithm_and_run(t_pushswap *data)
{
	if (data->strategy == STRATEGY_SIMPLE)
		bubble_sort(data);											// to modify
	else if (data->strategy == STRATEGY_MEDIUM)
		insertion_sort(data);										// to modify
	else if (data->strategy == STRATEGY_COMPLEX)
		selection_sort(data);										// to modify
	else
		if (data->disorder < 0.2)
			selection_sort(data);									// to modify
		else if (data->disorder >= 0.2 && data->disorder <= 0.5)
			selection_sort(data);									// to modify
		else
			selection_sort(data);									// to modify
}

static void	run_pushswap(t_pushswap *data)
{
	stack_init_a(data);
	if (!data->a)
		error_termination(data);
	stack_init_b(data);
	if (!data->b)
		error_termination(data);
	data->disorder = compute_disorder(*data->a);
	pick_algorithm_and_run(data);
	if (data->bench_mode == 1)
		print_benchmark(data);
}

int	main(int argc, char **argv)
{
	t_pushswap	*data;

	if (argc < 2)
		return (1);
	data = (t_pushswap *) ft_calloc(1, sizeof(t_pushswap));
	if (!data)
		error_termination(NULL);
	data->argc = --argc;
	data->argv = ++argv;
	parse_flags(data);
	validate_args(data);
	run_pushswap(data);
	delete_data(data);
	return (0);
}
