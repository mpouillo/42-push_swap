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

void	delete_data(t_pushswap *data)
{
	stack_delete(data->a);
	stack_delete(data->b);
	free(data);
}