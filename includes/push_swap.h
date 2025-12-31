/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:15:41 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/31 09:10:42 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libftprintf/includes/ft_printf.h"
# include "../libftprintf/libft/libft.h"

typedef struct	s_node
{
	int				item;
	struct s_node	*next;
	struct s_node	*prev;
} t_node;

typedef struct	s_stack
{
	size_t	length;
	t_node	*head;
} t_stack;

typedef struct	s_pushswap
{
	t_stack	*a;
	t_stack	*b;
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
} t_pushswap;

t_stack	*stack_create(char **item_list, size_t size);

void	stack_delete(t_stack *stack);
int		compute_disorder(t_stack a);
void	validate_args(char **args, int argc);

t_node	*node_create(int item);
void	node_add_back(t_node **node, t_node *new);
t_node	*node_get_last(t_node *node);

//		stack_operations.c
int		stack_pop(t_stack *stack);
void	stack_push(t_stack *stack, int item);
void	stack_swap(t_stack *stack);
void	stack_rotate_up(t_stack *stack);
void	stack_rotate_down(t_stack *stack);
int		check_stack_sorted(t_stack *stack);


//		pushswap_operations.c
void	sa(t_pushswap *data);
void	sb(t_pushswap *data);
void	ss(t_pushswap *data);
void	pa(t_pushswap *data);
void	pb(t_pushswap *data);
void	ra(t_pushswap *data);
void	rb(t_pushswap *data);
void	rr(t_pushswap *data);
void	rra(t_pushswap *data);
void	rrb(t_pushswap *data);
void	rrr(t_pushswap *data);

void	insertion_sort(t_pushswap *data);
void	selection_sort(t_pushswap *data);
void	bubble_sort(t_pushswap *data);

void	error_termination(void);
void	delete_data(t_pushswap *data);

#endif
