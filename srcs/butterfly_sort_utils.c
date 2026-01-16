/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chafonta <chafonta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:19:55 by chafonta          #+#    #+#             */
/*   Updated: 2026/01/16 14:19:56 by chafonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i * i <= nb)
		i++;
	return (i - 1);
}

static void	fill_array(int arr[], t_stack *stack)
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

static void	insertion_sort_array(int arr[], int n)
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

int	*create_sorted_array(t_pushswap *data)
{
	int	*arr;

	arr = ft_calloc(data->a->length, sizeof(int));
	fill_array(arr, data->a);
	insertion_sort_array(arr, (int)data->a->length);
	return (arr);
}
