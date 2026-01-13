/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:15:41 by mpouillo          #+#    #+#             */
/*   Updated: 2026/01/13 07:49:01 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libftprintf/includes/ft_printf.h"
# include "../libftprintf/libft/libft.h"

# define STRATEGY_ADAPTIVE	0
# define STRATEGY_SIMPLE	1
# define STRATEGY_MEDIUM	2
# define STRATEGY_COMPLEX	3

typedef struct s_node
{
	int				item;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	size_t	length;
	t_node	*head;
}	t_stack;

typedef struct s_pushswap
{
	t_stack	*a;
	t_stack	*b;
	int		argc;
	char	**argv;
	int		malloc;
	int		bench_mode;
	int		disorder;
	int		strategy;
	char	*complexity;
	size_t	total_ops;
	size_t	sa_count;
	size_t	sb_count;
	size_t	ss_count;
	size_t	pa_count;
	size_t	pb_count;
	size_t	ra_count;
	size_t	rb_count;
	size_t	rr_count;
	size_t	rra_count;
	size_t	rrb_count;
	size_t	rrr_count;
}	t_pushswap;

//		benchmark_utils.c
void	print_benchmark(t_pushswap *data);

//		bubble_sort.c
void	bubble_sort(t_pushswap *data);

//		compute_disorder.c
int		compute_disorder(t_stack a);

//		data_handling.c
void	delete_data(t_pushswap *data);

//		error_handling.c
void	error_termination(t_pushswap *data);

//		input_parsing.c
void	parse_input(t_pushswap *data);

//		insertion_sort.c
void	insertion_sort(t_pushswap *data);

//		node_utils.c
t_node	*node_create(t_pushswap *data, int item);
t_node	*node_get_last(t_node *node);
void	node_add_back(t_node **node, t_node *new);

//		parsing_handling.c
void	parse_flags(t_pushswap *data);

//		push_swap.c

//		pushswap_operations_p.c
void	pa(t_pushswap *data);
void	pb(t_pushswap *data);

//		pushswap_operations_r.c
void	ra(t_pushswap *data);
void	rb(t_pushswap *data);
void	rr(t_pushswap *data);

//		pushswap_operations_rr.c
void	rra(t_pushswap *data);
void	rrb(t_pushswap *data);
void	rrr(t_pushswap *data);

//		pushswap_operations_s.c
void	sa(t_pushswap *data);
void	sb(t_pushswap *data);
void	ss(t_pushswap *data);

//		selection_sort.c
void	selection_sort(t_pushswap *data);

//		stack_operations.c
int		stack_pop(t_stack *stack);
void	stack_push(t_pushswap *data, t_stack *stack, int item);
void	stack_swap(t_stack *stack);
void	stack_rotate_up(t_stack *stack);
void	stack_rotate_down(t_stack *stack);

//		stack_utils.c
void	stack_init_a(t_pushswap *data);
void	stack_init_b(t_pushswap *data);
void	stack_delete(t_stack *stack);
int		check_stack_sorted(t_stack *stack);

#endif
