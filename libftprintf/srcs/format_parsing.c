/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 11:58:49 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/03 11:14:36 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	eval_flags(t_data *tab, const char *format, int pos)
{
	while (format[pos] && ft_strchr("-+ #0", format[pos]))
	{
		if (format[pos] == '-')
			tab->dash = 1;
		else if (format[pos] == '+')
			tab->plus = 1;
		else if (format[pos] == ' ')
			tab->space = 1;
		else if (format[pos] == '#')
			tab->hash = 1;
		else if (format[pos] == '0')
			tab->zpad = 1;
		pos++;
	}
	return (pos);
}

int	eval_precision(t_data *tab, const char *format, int pos)
{
	tab->dot = (format[pos] == '.');
	if (!tab->dot)
		return (pos);
	pos++;
	if (format[pos] == '*')
	{
		tab->prec = va_arg(tab->args, int);
		if (tab->prec < 0)
			tab->dot = 0;
		return (pos + 1);
	}
	tab->prec = no_overflow_atoui(&format[pos]);
	while (ft_isdigit(format[pos]))
		pos++;
	if (tab->prec == ERROR)
		tab->ret = ERROR;
	return (pos);
}

int	eval_specifier(t_data *tab, const char *format, int pos)
{
	if (format[pos] == 'c')
		print_char(tab);
	else if (format[pos] == 's')
		print_string(tab);
	else if (format[pos] == 'p')
		print_pointer(tab);
	else if (format[pos] == 'd' || format[pos] == 'i')
		print_int(tab);
	else if (format[pos] == 'u')
		print_unsigned(tab);
	else if (format[pos] == 'x' || format[pos] == 'X')
		print_hex(tab, format, pos);
	else if (format[pos] == '%')
		print_percent(tab);
	else
		tab->error = ERROR;
	return (pos);
}

int	eval_width(t_data *tab, const char *format, int pos)
{
	if (format[pos] == '*')
	{
		tab->width = va_arg(tab->args, int);
		if (tab->width < 0)
		{
			tab->width = get_abs(tab->width);
			tab->dash = 1;
		}
		return (pos + 1);
	}
	tab->width = no_overflow_atoui(&format[pos]);
	while (ft_isdigit(format[pos]))
		pos++;
	if (tab->width == ERROR)
		tab->ret = ERROR;
	return (pos);
}
