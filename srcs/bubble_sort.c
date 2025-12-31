/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 09:11:21 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/31 09:11:21 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#define CW	1
#define CCW	-1

void	bubble_sort(t_pushswap *data)
{
	size_t	i;
	size_t	j;

	data->complexity = "O(n²)";
	i = 0;
	while (data->a->length > 2 && i < data->a->length)
	{
		j = 0;
		while (j < data->a->length - 1)
		{
			if (data->a->head->item > data->a->head->next->item)
				sa(data);
			ra(data);
			j++;
		}
		ra(data);
		i++;
	}
}
