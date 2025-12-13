/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 08:57:40 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/03 12:29:06 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	putpadchar(t_data *tab, char c)
{
	int	retval;

	if (tab->dash)
	{
		retval = write(1, &c, sizeof(char));
		if (retval != sizeof(char))
			return (ERROR);
		tab->ret += retval;
	}
	while (tab->width > 0)
	{
		if (putstrl(tab, " ", sizeof(char)) == ERROR)
			return (ERROR);
		tab->width--;
	}
	if (!tab->dash)
	{
		retval = write(1, &c, sizeof(char));
		if (retval != sizeof(char))
			return (ERROR);
		tab->ret += retval;
	}
	return (SUCCESS);
}

void	print_char(t_data *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	tab->width = get_max(0, tab->width - 1);
	if (putpadchar(tab, c) == ERROR)
		tab->ret = ERROR;
}
