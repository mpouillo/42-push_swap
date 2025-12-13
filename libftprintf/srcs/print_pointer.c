/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:50:30 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/03 12:39:44 by mpouillo         ###   ########.fr       */
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
		if (tab->hash)
			tab->width = get_max(0, tab->width - 2);
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
		if (tab->prec)
			buf = get_max(0, (tab->prec - ft_strlen(s)));
		else
			buf = 0;
		s = apply_precision(s, buf);
	}
	return (s);
}

static char	*arg_p_to_str(t_data *tab, void *arg)
{
	char	*new_s;

	if (arg == NULL)
	{
		new_s = ft_strdup("(nil)");
		tab->plus = 0;
		tab->space = 0;
		tab->zpad = 0;
		tab->dot = 0;
	}
	else
	{
		new_s = n_base_to_str((unsigned long long) arg, 16, 0);
		tab->hash = 1;
	}
	return (new_s);
}

void	print_pointer(t_data *tab)
{
	void	*arg;
	char	*s;

	arg = va_arg(tab->args, void *);
	s = arg_p_to_str(tab, arg);
	s = apply_dot(tab, s);
	s = apply_zpad(tab, s);
	s = apply_hash(tab, s, (unsigned long) arg, 0);
	s = apply_plus(tab, s);
	s = apply_space(tab, s);
	s = apply_width(tab, s);
	if (!s)
	{
		tab->ret = ERROR;
		return ;
	}
	putstrl(tab, s, ft_strlen(s));
	free(s);
}
