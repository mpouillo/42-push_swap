/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 10:29:29 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/27 12:16:06 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#define STRATEGY_SIMPLE		1
#define STRATEGY_MEDIUM		2
#define STRATEGY_COMPLEX	3
#define STRATEGY_ADAPTIVE	4

static int	parse_strategy(char ***argv, int *argc)
{
	if (ft_strncmp((*argv)[1], "--simple", ft_strlen("--simple")) == 0)
	{
		*argv += 1;
		*argc -= 1;
		return (STRATEGY_SIMPLE);
	}
	else if (ft_strncmp((*argv)[1], "--medium", ft_strlen("--medium")) == 0)
	{
		*argv += 1;
		*argc -= 1;
		return (STRATEGY_MEDIUM);
	}
	else if (ft_strncmp((*argv)[1], "--complex", ft_strlen("--complex")) == 0)
	{
		*argv += 1;
		*argc -= 1;
		return (STRATEGY_COMPLEX);
	}
	else if (ft_strncmp((*argv)[1], "--adaptive", ft_strlen("--adaptive")) == 0)
	{
		*argv += 1;
		*argc -= 1;
		return (STRATEGY_ADAPTIVE);
	}
	return (STRATEGY_ADAPTIVE);
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
}

int	main(int argc, char **argv)
{
	t_pushswap *data;
	
	if (argc < 2)
		return (1);
	data = (t_pushswap *) ft_calloc(1, sizeof(t_pushswap));
	init_data(data);
	data->strategy = parse_strategy(&argv, &argc);
	validate_args(argv + 1, argc - 1);
	run_pushswap(data, argv + 1, argc - 1);
	delete_data(data);
	return (0);
}