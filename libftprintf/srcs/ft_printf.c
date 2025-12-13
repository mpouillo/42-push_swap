/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:47:05 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/03 12:04:16 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	init_tab(t_data *tab)
{
	tab->dash = 0;
	tab->dot = 0;
	tab->error = 0;
	tab->hash = 0;
	tab->is_neg = 0;
	tab->plus = 0;
	tab->prec = 0;
	tab->space = 0;
	tab->width = 0;
	tab->zpad = 0;
}

static int	eval_format(t_data *tab, const char *format, int pos)
{
	init_tab(tab);
	if (tab->error != ERROR)
		pos = eval_flags(tab, format, pos);
	if (tab->error != ERROR)
		pos = eval_width(tab, format, pos);
	if (tab->error != ERROR)
		pos = eval_precision(tab, format, pos);
	if (tab->error != ERROR)
		pos = eval_specifier(tab, format, pos);
	return (pos);
}

static int	parse_format(t_data *tab, const char *format)
{
	int	headpos;
	int	pos;

	pos = 0;
	while (format[pos])
	{
		if (format[pos] == '%')
		{
			headpos = pos;
			pos = eval_format(tab, format, pos + 1);
			if (tab->error == ERROR)
			{
				if (error_putstrl(tab, (char *) format, headpos) == ERROR)
					return (ERROR);
			}
		}
		else if (putstrl(tab, (char *) &format[pos], sizeof(char)) == ERROR)
			return (ERROR);
		if (tab->ret == ERROR)
			return (ERROR);
		pos++;
	}
	return (SUCCESS);
}

int	ft_printf(const char *format, ...)
{
	t_data	*tab;
	int		ret;

	if (!format)
		return (-1);
	tab = (t_data *) ft_calloc(sizeof(t_data), 1);
	if (!tab)
		return (-1);
	tab->ret = 0;
	va_start(tab->args, format);
	if (parse_format(tab, format) == ERROR)
		ret = -1;
	else
		ret = tab->ret;
	va_end(tab->args);
	free(tab);
	return (ret);
}
