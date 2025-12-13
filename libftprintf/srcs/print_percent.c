/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 10:55:51 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/03 12:30:06 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_percent(t_data *tab)
{
	if (putstrl(tab, "%", sizeof(char)) == ERROR)
		tab->ret = ERROR;
}
