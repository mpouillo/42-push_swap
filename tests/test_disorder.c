/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_disorder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:11:41 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/14 18:11:43 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests/tests.h"

void	test_disorder(t_stack *stack)
{
	int	disorder;

	disorder = compute_disorder(*stack);
	ft_printf("Disorder = %i.%.2i\n", disorder / 100, disorder % 100);
}