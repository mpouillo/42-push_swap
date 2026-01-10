/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 08:32:05 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/27 08:32:05 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_termination(t_pushswap *data)
{
	delete_data(data);
	ft_dprintf(STDERR_FILENO, "Error\n");
	exit(EXIT_FAILURE);
}
