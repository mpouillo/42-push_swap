/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 08:32:29 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/24 08:32:29 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#define CW	1
#define CCW	-1

void	insertion_sort(t_pushswap *data)
{
	size_t	rotations;

	data->complexity = "O(n²)";
	if (check_stack_sorted(data->a))
			return;
	while (data->a->length > 0)
	{
		rotations = 0;
		if (data->b->length == 0)
		{
			pb(data);
			continue;
		}
		while (rotations < data->b->length && data->b->head->item > data->a->head->item)
		{
			rotations++;
			rb(data);
		}
		pb(data);
		while (rotations-- > 0)
			rrb(data);
	}
	while (data->b->length > 0)
		pa(data);
}
