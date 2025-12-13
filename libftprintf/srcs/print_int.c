/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:55:25 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/03 12:39:23 by mpouillo         ###   ########.fr       */
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
		if (tab->space || tab->is_neg || tab->plus)
			tab->width = get_max(0, tab->width - 1);
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

void	print_int(t_data *tab)
{
	char	*s;
	int		arg;

	arg = va_arg(tab->args, int);
	if (arg < 0)
		tab->is_neg = 1;
	s = n_base_to_str(get_abs(arg), 10, 0);
	s = handle_zero_nullprec(tab, arg, s);
	s = apply_dot(tab, s);
	s = apply_zpad(tab, s);
	s = apply_plus(tab, s);
	s = apply_space(tab, s);
	s = apply_neg(tab, s);
	s = apply_width(tab, s);
	if (!s)
	{
		tab->ret = ERROR;
		return ;
	}
	putstrl(tab, s, ft_strlen(s));
	free(s);
}
