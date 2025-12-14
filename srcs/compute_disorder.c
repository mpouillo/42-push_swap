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

#include "../includes/push_swap.h"

float	compute_disorder(t_stack *a)
{
	size_t	mistakes;
	size_t	total_pairs;
	size_t	i;
	size_t	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < a->length - 1)
	{
		j = i + 1;
		while (j < a->length - 1)
		{
			total_pairs += 1;
			if (a->head->item > a->head->next->item)
				mistakes += 1;
			a->head = a->head->next;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}