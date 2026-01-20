/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 chunk_based_sort.c									:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: kaze <kaze@student.42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/01/11 14:03:13 by kaze			   #+#	  #+#			  */
/*	 Updated: 2026/01/11 16:51:12 by kaze			  ###	########.fr		  */
/*																			  */
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

static int	find_biggest(t_stack *stack)
{
	t_node	*biggest;
	t_node	*current;
	int		i;
	int		j;

	biggest = stack->head;
	current = stack->head;
	i = 0;
	j = i;
	while (current)
	{
		if (current->item > biggest->item)
		{
			biggest = current;
			j = i;
		}
		i++;
		current = current->next;
	}
	return (j);
}

static void	butterfly_a_to_b(t_pushswap *data, int range)
{
	int	i;

	i = 0;
	while (data->a->length > 0)
	{
		if (data->a->head->item <= data->array[i])
		{
			pb(data);
			if ((int)data->a->length > range)
				i++;
			if (data->a->head->item > data->array[i + range])
				rr(data);
			else
				rb(data);
		}
		else if (data->a->head->item <= data->array[i + range])
		{
			pb(data);
			if ((int)data->a->length > range)
				i++;
		}
		else
			ra(data);
	}
}

static void	sort_b_to_a(t_pushswap *data)
{
	int	big_index;

	while (data->b->length > 0)
	{
		big_index = find_biggest(data->b);
		if (big_index < (int)data->b->length / 2)
		{
			while (big_index > 0)
			{
				rb(data);
				big_index--;
			}
		}
		else
		{
			while (big_index < (int)data->b->length)
			{
				rrb(data);
				big_index++;
			}
		}
		pa(data);
	}
}

void	butterfly_sort(t_pushswap *data)
{
	int	range;

	data->complexity = "O(n√n)";
	range = ft_sqrt((int)data->a->length);
	ft_printf("%d\n", range);
	create_sorted_array(data);
	if (!data->array)
		error_termination(data);
	butterfly_a_to_b(data, range);
	sort_b_to_a(data);
	free(data->array);
	data->array = NULL;
}
