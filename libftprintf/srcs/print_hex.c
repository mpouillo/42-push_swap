/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:50:30 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/03 12:42:15 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

static char	*apply_zpad(t_data *tab, char *s, unsigned long arg)
{
	int	buf;

	if (!s)
		return (NULL);
	if (tab->zpad && !tab->dash)
	{
		if (tab->hash && arg != 0)
			tab->width = get_max(0, tab->width - 2);
		buf = get_max(tab->width, ft_strlen(s));
		s = apply_padding(tab, s, buf, '0');
	}
	return (s);
}

void	print_hex(t_data *tab, const char *format, int pos)
{
	char				*s;
	unsigned long		arg;
	int					caps;

	arg = (unsigned) va_arg(tab->args, long);
	caps = (format[pos] == 'X');
	s = n_base_to_str(arg, 16, caps);
	s = apply_dot(tab, s);
	s = apply_zpad(tab, s, arg);
	s = apply_hash(tab, s, arg, caps);
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
