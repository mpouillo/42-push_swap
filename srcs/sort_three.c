/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chafonta <chafonta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:22:46 by chafonta          #+#    #+#             */
/*   Updated: 2026/01/21 15:22:46 by chafonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sort_three(t_pushswap *data)
{
	if (!data->array)
 		create_sorted_array(data);
	if (data->a->head->item == data->array[0])
	{
		sa(data);
		ra(data);
	}
	else if (data->a->head->item == data->array[1] && data->a->head->next->item == data->array[0])
		sa(data);
	else if (data->a->head->item == data->array[1] && data->a->head->next->item == data->array[2])
		rra(data);
	else if (data->a->head->next->item == data->array[0])
		ra(data);
	else
	{
		ra(data);
		sa(data);
	}
}
