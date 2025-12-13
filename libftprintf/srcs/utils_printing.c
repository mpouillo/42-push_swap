/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouillo <mpouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:59:17 by mpouillo          #+#    #+#             */
/*   Updated: 2025/12/03 12:40:41 by mpouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	putstrl(t_data *tab, char *s, size_t sz)
{
	int	retval;

	retval = write(1, s, get_min(ft_strlen(s), sz));
	if (retval != (int) sz)
	{
		tab->ret = ERROR;
		return (ERROR);
	}
	else
	{
		tab->ret += retval;
		return (SUCCESS);
	}
}

static int	move_pos(char *s, size_t pos)
{
	if (s[pos] && s[pos] == '%')
		pos++;
	if (s[pos] == '\0')
		return (ERROR);
	while (s[pos] && ft_strchr("-+ #0", s[pos]))
		pos++;
	if (s[pos] == '*')
		pos++;
	while (ft_isdigit(s[pos]))
		pos++;
	if (s[pos] == '.')
		pos++;
	if (s[pos] == '*')
		pos++;
	while (ft_isdigit(s[pos]))
		pos++;
	if (s[pos])
		pos++;
	return (pos);
}

int	error_putstrl(t_data *tab, char *s, size_t headpos)
{
	int	endpos;
	int	sz;

	endpos = move_pos(s, headpos);
	if (endpos == ERROR)
		return (ERROR);
	sz = endpos - headpos;
	putstrl(tab, &s[headpos], sz);
	return (SUCCESS);
}
