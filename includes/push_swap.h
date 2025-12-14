/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:15:41 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/13 16:02:26 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libftprintf/includes/ft_printf.h"
# include "../libftprintf/libft/libft.h"

# define SUCCESS	1
# define ERROR		-1

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

t_stack	*stack_create(char **item_list, int size);
void	stack_push(t_stack *stack, int item);
int		stack_pop(t_stack *stack);

#endif