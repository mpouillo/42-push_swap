/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chafonta <chafonta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:38:15 by chafonta          #+#    #+#             */
/*   Updated: 2025/12/13 15:47:08 by chafonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#inlcude "push_swap.h"
#include <stdlib.h>

float	compute_disorder(t_stack a)
{
	size_t	mistakes;
	size_t	total_pairs;
	size_t	i;
	size_t	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size(a) - 1)
	{
		j = i + 1;
		while (j < size(a) - a)
		{
			total_pairs += 1;
			if (a[i] > a[j])
				mistakes += 1;
		}
	}
	return (mistakes / total_pairs);
}
