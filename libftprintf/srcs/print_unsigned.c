/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:55:25 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/03 12:42:00 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*apply_zpad(t_data *tab, char *s)
{
	int	buf;

	if (!s)
		return (NULL);
	if (tab->zpad && !tab->dash)
	{
		buf = get_max(tab->width, ft_strlen(s));
		s = apply_padding(tab, s, buf, '0');
	}
	return (s);
}

static char	*apply_dot(t_data *tab, char *s)
{
	int	buf;

	if (!s)
		return (NULL);
	if (tab->dot)
	{
		tab->zpad = 0;
		buf = get_max(0, (tab->prec - ft_strlen(s)));
		s = apply_precision(s, buf);
	}
	return (s);
}

void	print_unsigned(t_data *tab)
{
	char			*s;
	unsigned int	arg;

	arg = (unsigned) va_arg(tab->args, int);
	s = n_base_to_str(arg, 10, 0);
	s = apply_dot(tab, s);
	s = apply_zpad(tab, s);
	s = handle_zero_nullprec(tab, arg, s);
	s = apply_width(tab, s);
	if (!s)
	{
		tab->ret = ERROR;
		return ;
	}
	putstrl(tab, s, ft_strlen(s));
	free(s);
}
