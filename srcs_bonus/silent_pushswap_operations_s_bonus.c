/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_operations_s.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 10:58:11 by mpouillo          #+#    #+#             */
/*   Updated: 2026/01/10 10:58:18 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// sa (swap a): Swap the first two elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	s_sa(t_pushswap *data)
{
	stack_swap(data->a);
	data->sa_count += 1;
	data->total_ops += 1;
}

// sb (swap b): Swap the first two elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	s_sb(t_pushswap *data)
{
	stack_swap(data->b);
	data->sb_count += 1;
	data->total_ops += 1;
}

// ss : sa and sb at the same time.
void	s_ss(t_pushswap *data)
{
	stack_swap(data->a);
	stack_swap(data->b);
	data->ss_count += 1;
	data->total_ops += 1;
}
