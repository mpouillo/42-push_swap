/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 10:29:29 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/27 14:38:36 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#define STRATEGY_ADAPTIVE	0
#define STRATEGY_SIMPLE		1
#define STRATEGY_MEDIUM		2
#define STRATEGY_COMPLEX	3

static int	parse_strategy(char ***argv, int *argc)
{
	if (ft_strncmp(**argv, "--simple", ft_strlen("--simple")) == 0)
	{
		*argv += 1;
		*argc -= 1;
		return (STRATEGY_SIMPLE);
	}
	else if (ft_strncmp(**argv, "--medium", ft_strlen("--medium")) == 0)
	{
		*argv += 1;
		*argc -= 1;
		return (STRATEGY_MEDIUM);
	}
	else if (ft_strncmp(**argv, "--complex", ft_strlen("--complex")) == 0)
	{
		*argv += 1;
		*argc -= 1;
		return (STRATEGY_COMPLEX);
	}
	else if (ft_strncmp(**argv, "--adaptive", ft_strlen("--adaptive")) == 0)
	{
		*argv += 1;
		*argc -= 1;
		return (STRATEGY_ADAPTIVE);
	}
	return (STRATEGY_ADAPTIVE);
}

static int	parse_bench_mode(char ***argv, int *argc)
{
	if (ft_strncmp(**argv, "--bench", ft_strlen("--bench")) == 0)
	{
		*argv += 1;
		*argc -= 1;
		return (1);
	}
	return (0);
}

static void	pick_algorithm_and_run(t_pushswap *data)
{
	if (data->strategy == STRATEGY_SIMPLE)
		selection_sort(data);
	else if (data->strategy == STRATEGY_MEDIUM)
		selection_sort(data); // to modify
	else if (data->strategy == STRATEGY_COMPLEX)
		selection_sort(data); // to modify
	else
		selection_sort(data); // to modify
}

char *get_strategy_string(t_pushswap *data)
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
	ft_dprintf(STDERR_FILENO, "[bench] disorder:          %.2i.%.2i%%\n", data->disorder / 10, data->disorder % 100);
	ft_dprintf(STDERR_FILENO, "[bench] strategy:          %s / %s\n", get_strategy_string(data), data->complexity);
	ft_dprintf(STDERR_FILENO, "[bench] total operations:  %i\n", data->total_ops);
	ft_dprintf(STDERR_FILENO, "[bench] sa: %5u,  sb: %5u,  ss: %5u,  pa:  %5u,  pb:  %5u,\n", 
		data->sa_count, data->sb_count, data->ss_count, data->pa_count, data->pb_count);
	ft_dprintf(STDERR_FILENO, "[bench] ra: %5u,  rb: %5u,  rr: %5u,  rra: %5u,  rrb: %5u,  rrr: %5u\n", 
		data->ra_count, data->rb_count, data->rr_count, data->rra_count, data->rrb_count, data->rrr_count);
}

static void	run_pushswap(t_pushswap *data, char **argv, int argc)
{
	data->a = stack_create(argv, argc);
	if (!data->a)
		error_termination();
	data->b = stack_create(NULL, 0);
	if (!data->b)
	{
		stack_delete(data->a);
		error_termination();
	}
	data->disorder = compute_disorder(*data->a);
	pick_algorithm_and_run(data);
	print_benchmark(data); // print to stderr
}

int	main(int argc, char **argv)
{
	t_pushswap *data;
	
	if (argc < 2)
		return (1);
	argc--;
	argv++;
	data = (t_pushswap *) ft_calloc(1, sizeof(t_pushswap));
	init_data(data);
	data->bench_mode = parse_bench_mode(&argv, &argc);
	data->strategy = parse_strategy(&argv, &argc);
	validate_args(argv, argc);
	run_pushswap(data, argv, argc);
	delete_data(data);
	return (0);
}