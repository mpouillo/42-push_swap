/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:38:15 by chafonta          #+#    #+#             */
/*   Updated: 2026/01/22 15:53:42 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	compute_disorder(t_stack stack)
{
	t_node	*temp;
	size_t	mistakes;
	size_t	total_pairs;
	size_t	i;
	size_t	j;

	if (stack.length < 2)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	i = -1;
	while (++i < stack.length)
	{
		temp = stack.head;
		j = i + 1;
		while (j < stack.length)
		{
			total_pairs += 1;
			mistakes += (temp->item > temp->next->item);
			temp = temp->next;
			j++;
		}
		stack.head = stack.head->next;
	}
	return ((((long long) mistakes * 1000) + (total_pairs / 2)) / total_pairs);
}
