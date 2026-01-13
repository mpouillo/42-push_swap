/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 09:59:18 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/27 09:59:18 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	delete_data(t_pushswap *data)
{
	if (!data)
		return ;
	stack_delete(data->a);
	data->a = NULL;
	stack_delete(data->b);
	data->b = NULL;
	if (data->malloc == 1)
		free_array(data->argv);
	free(data);
	data = NULL;
}
