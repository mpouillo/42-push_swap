/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:19:55 by chafonta          #+#    #+#             */
/*   Updated: 2026/01/21 16:09:30 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	copy_stack_into_array(t_stack *stack, int *arr)
{
	t_node	*current;
	size_t	i;

	i = 0;
	current = stack->head;
	while (current)
	{
		arr[i] = current->item;
		current = current->next;
		i++;
	}
}

static void	insertion_sort_array(int *arr, int n)
{
	int	key;
	int	i;
	int	j;

	i = 1;
	while (i < n)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

void	create_sorted_array(t_pushswap *data)
{
	data->array = ft_calloc(data->a->length, sizeof(int));
	if (!data->array)
		error_termination(data);
	copy_stack_into_array(data->a, data->array);
	insertion_sort_array(data->array, (int) data->a->length);
}
