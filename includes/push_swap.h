/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:15:41 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/14 13:52:18 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libftprintf/includes/ft_printf.h"
# include "../libftprintf/libft/libft.h"

# ifndef SUCCESS
#  define SUCCESS	1
# endif

# ifndef ERROR
#  define ERROR		0
# endif

typedef struct s_node
{
	int		item;
	void	*next;
	void	*prev;
} t_node;

typedef struct s_stack
{
	size_t	length;
	t_node	*head;
} t_stack;

t_stack	*stack_create(char **item_list, size_t size);
void	stack_push(t_stack *stack, int item);
int		stack_pop(t_stack *stack);
void	stack_delete(t_stack *stack);
int		validate_args(char **args);
int		check_duplicate(t_stack *stack);

#endif