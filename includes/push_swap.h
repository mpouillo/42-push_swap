/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:15:41 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/15 13:07:04 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libftprintf/includes/ft_printf.h"
# include "../libftprintf/libft/libft.h"

typedef struct s_node
{
	int				item;
	struct s_node	*next;
	struct s_node	*prev;
} t_node;

typedef struct s_stack
{
	size_t	length;
	t_node	*head;
} t_stack;

t_stack	*stack_create(char **item_list, size_t size);

void	stack_delete(t_stack *stack);
int		compute_disorder(t_stack a);
int		validate_args(char **args);
int		check_duplicate(t_stack *stack);

t_node	*node_create(int item);
void	node_add_back(t_node **node, t_node *new);
t_node	*node_get_last(t_node *node);

//		stack_operations.c
int		stack_pop(t_stack *stack);
void	stack_push(t_stack *stack, int item);
void	stack_swap(t_stack *stack);
void	stack_rotate_up(t_stack *stack);
void	stack_rotate_down(t_stack *stack);

//		pushswap_operations.c
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif
