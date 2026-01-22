/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:03:11 by chafonta          #+#    #+#             */
/*   Updated: 2026/01/22 12:46:44 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/checker_bonus.h"

static void	parse_line(t_pushswap *data, char *line)
{
	if (ft_strncmp(line, "pa\n", 3) == 0)
		s_pa(data);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		s_pb(data);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		s_ra(data);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		s_rb(data);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		s_rr(data);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		s_rra(data);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		s_rrb(data);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		s_rrr(data);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		s_sa(data);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		s_sb(data);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		s_ss(data);
	else
		error_termination(data);
}

static void	run_checker(t_pushswap *data)
{
	char	*line;

	stack_init_a(data);
	if (!data->a)
		error_termination(data);
	stack_init_b(data);
	if (!data->b)
		error_termination(data);
	line = get_next_line(STDIN_FILENO);
	if (!line)
		error_termination(data);
	while (line)
	{
		parse_line(data, line);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
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
	parse_input(data);
	run_checker(data);
	if (check_stack_sorted(data->a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	delete_data(data);
	return (0);
}
