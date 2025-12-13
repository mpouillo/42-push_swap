/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:58:15 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/03 12:37:42 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*apply_prec_str(t_data *tab, char *s)
{
	char	*new_s;
	size_t	trunc;

	if (!s)
		return (NULL);
	trunc = get_max(0, get_min(ft_strlen(s), ft_strlen(s) - tab->prec));
	new_s = ft_substr(s, 0, ft_strlen(s) - trunc);
	if (!new_s)
	{
		free(s);
		return (NULL);
	}
	free(s);
	return (new_s);
}

static char	*apply_dot(t_data *tab, char *s)
{
	if (tab->dot)
	{
		tab->zpad = 0;
		s = apply_prec_str(tab, s);
	}
	return (s);
}

static char	*arg_s_to_str(t_data *tab, char *arg)
{
	char	*new_s;

	if (arg == NULL)
	{
		arg = "(null)";
		if (tab->dot && tab->prec < 6)
			arg = "";
	}
	new_s = ft_strdup(arg);
	if (!new_s)
		return (NULL);
	return (new_s);
}

void	print_string(t_data *tab)
{
	char	*arg;
	char	*s;

	arg = (char *) va_arg(tab->args, void *);
	s = arg_s_to_str(tab, arg);
	s = apply_dot(tab, s);
	s = apply_width(tab, s);
	if (!s)
	{
		tab->ret = ERROR;
		return ;
	}
	if (putstrl(tab, s, ft_strlen(s)) == ERROR)
		tab->ret = ERROR;
	free(s);
}
