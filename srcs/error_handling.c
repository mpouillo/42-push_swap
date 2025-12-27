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

void	error_termination(void)
{
	ft_printf("Error\n"); // must display on the standard error, maybe code ft_fprintf?
	exit(EXIT_FAILURE);
}