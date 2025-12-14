/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:38:15 by chafonta          #+#    #+#             */
/*   Updated: 2025/12/14 12:19:38 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	compute_disorder(t_stack a)
{
	t_node	*temp;
	size_t	mistakes;
	size_t	total_pairs;
	size_t	i;
	size_t	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < a.length)
	{
		temp = a.head;
		j = i + 1;
		while (j < a.length)
		{
			total_pairs += 1;
			if (temp->item > temp->next->item)
				mistakes += 1;
			temp = temp->next;
			j++;
		}
		a.head = a.head->next;
		i++;
	}
	int ret = (mistakes / total_pairs) * 100 + (mistakes * 100 / total_pairs);
	return (ret);
}
